#include "../includes/philo.h"

void	ft_print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(philo->status);
	if (philo->data->died)
	{
		pthread_mutex_unlock(philo->status);
		return ;
	}
	else
		printf("%ld %d %s\n", ft_get_time() - philo->time_start,
			philo->id, status);
	if (philo->data->sign_died)
		philo->data->died = 1;
	pthread_mutex_unlock(philo->status);
}

int	check_number_of_meal(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->num_of_philo)
	{
		if (philo[i].eat_status == 0)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	tmp;
	t_data	*data;

	data = &tmp;
	data->num_args = argc;
	if (argc != 5 && argc != 6)
	{
		ft_errors("Error: bad arguments\n");
		return (1);
	}
	if (ft_parse(data, argv))
		return (1);
	if (ft_create_philo(data))
		return (1);
	return (0);
}
