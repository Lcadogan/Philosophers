#include "../includes/philo.h"

void	ft_usleep(int time_ms)
{
	long	time;

	time = ft_get_time();
	while (ft_get_time() - time < time_ms)
		usleep(100);
}

void	ft_philo_think(t_philo *philo)
{
	ft_print_status(philo, THINK);
}

void	ft_philo_sleep(t_philo *philo)
{
	ft_print_status(philo, SLEEP);
	ft_usleep(philo->data->time_to_sleep);
}

void	ft_philo_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	ft_print_status(philo, FORK);
	pthread_mutex_lock(philo->rfork);
	ft_print_status(philo, FORK);
	ft_print_status(philo, EAT);
	philo->count_of_meal++;
	philo->time_eat = ft_get_time();
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
}

void	*simulation(void *philos)
{
	t_philo	*philo;

	philo = philos;
	if (!(philo->id % 2))
		ft_usleep(philo->data->time_to_sleep - 10);
	while (!philo->data->died)
	{
		ft_philo_eating(philo);
		if (philo->data->number_of_meal)
		{
			if (philo->count_of_meal == philo->data->number_of_meal)
			{
				philo->eat_status = 1;
				ft_print_status(philo, ALL_ATE);
				return (NULL);
			}
		}
		ft_philo_sleep(philo);
		ft_philo_think(philo);
	}
	return (NULL);
}
