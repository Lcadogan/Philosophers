#include "../includes/philo.h"

void	ft_check_status(t_philo *philo)
{
	int	time;
	int	i;

	while (!philo->data->died)
	{
		i = 0;
		while (i < philo->data->num_of_philo)
		{
			if (philo[i].eat_status == 0)
			{
				time = ft_get_time() - philo[i].time_eat;
				if (time >= philo[i].data->time_to_die + 10)
				{
					philo->data->sign_died = 1;
					ft_print_status(&philo[i], DIE);
				}
				i++;
			}
			else
				if (!check_number_of_meal(philo))
					return ;
		}
	}
}

int	ft_create_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->num_of_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, simulation, &philo[i]))
		{
			ft_errors("Error tread create\n");
			return (1);
		}
		if (pthread_detach(philo[i].thread))
		{
			ft_errors("Error pthread detach\n");
			return (1);
		}
		i++;
	}
	ft_check_status (philo);
	return (0);
}

t_philo	*ft_init_philo_str(t_data *data, pthread_mutex_t *status)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->num_of_philo);
	if (philo == NULL)
	{
		ft_errors("Error malloc allocate\n");
		return (NULL);
	}
	while (i < data->num_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].lfork = &data->forks[i];
		philo[i].rfork = &data->forks[(i + 1) % data->num_of_philo];
		philo[i].status = status;
		philo[i].time_start = ft_get_time();
		philo[i].time_eat = ft_get_time();
		philo[i].eat_status = 0;
		philo[i].count_of_meal = 0;
		i++;
	}
	return (philo);
}

pthread_mutex_t	*mutex_init(t_data *data)
{
	int	i;

	i = 0;
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->num_of_philo);
	if (data->forks == NULL)
	{
		ft_errors("Error memory allocation\n");
		return (NULL);
	}
	while (i < data->num_of_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
		{
			ft_errors("Error mutex init\n");
			return (NULL);
		}
		i++;
	}
	return (data->forks);
}

int	ft_create_philo(t_data *data)
{
	pthread_mutex_t	status;
	t_philo			*philo;

	data->forks = mutex_init(data);
	pthread_mutex_init(&status, NULL);
	if (!data->forks)
		return (1);
	philo = ft_init_philo_str(data, &status);
	if (philo == NULL)
		return (1);
	ft_create_threads (philo);
	ft_free_all(philo);
	return (0);
}
