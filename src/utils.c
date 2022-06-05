#include "../includes/philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_errors(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	ft_free_all(t_philo *philo)
{
	if (philo != NULL)
		free(philo);
	if (philo->data->forks != NULL)
		free(philo->data->forks);
}

int	ft_get_time(void)
{
	struct timeval	get_time;
	int				time;

	if ((gettimeofday(&get_time, NULL) == (-1)))
	{
		ft_errors("Error time\n");
		return (1);
	}
	time = (get_time.tv_sec * 1000) + (get_time.tv_usec / 1000);
	return (time);
}
