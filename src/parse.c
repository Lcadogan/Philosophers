#include "../includes/philo.h"

int	ft_check_struct(t_data *data)
{
	if (data->num_of_philo < 1 || data->time_to_die < 60
		|| data->time_to_eat < 60 || data->time_to_sleep < 60
		|| (data->num_args == 6 && data->number_of_meal <= 0))
	{
		ft_errors("Error: bad arguments\n");
		return (1);
	}
	return (0);
}

int	ft_init_data(int i, t_data *data, char **argv)
{
	if (i == 1)
		data->num_of_philo = ft_atoi(argv[i]);
	if (i == 2)
		data->time_to_die = ft_atoi(argv[i]);
	if (i == 3)
		data->time_to_eat = ft_atoi(argv[i]);
	if (i == 4)
		data->time_to_sleep = ft_atoi(argv[i]);
	if (i == 5)
		data->number_of_meal = ft_atoi(argv[i]);
	return (0);
}

void	ft_init_struct(t_data *data)
{
	data->num_of_philo = 0;
	data->number_of_meal = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->died = 0;
	data->sign_died = 0;
}

int	ft_check_numbers(int i, char **argv)
{
	int	j;

	j = 0;
	while (argv[i][j])
	{
		if (!ft_isdigit(argv[i][j]))
		{
			ft_errors("Error: bad arguments\n");
			return (1);
		}
		j++;
	}
	if (j > 11 || ((ft_atoi(argv[i]) > 2147483647)
			|| (ft_atoi(argv[i]) < -2147483648)))
	{
		ft_errors("Error: bad arguments\n");
		return (1);
	}
	return (0);
}

int	ft_parse(t_data *data, char **argv)
{
	int	i;

	i = 1;
	ft_init_struct(data);
	while (i < data->num_args)
	{
		if (ft_check_numbers(i, argv))
			return (1);
		ft_init_data(i, data, argv);
		i++;
	}
	if (ft_check_struct(data))
		return (1);
	return (0);
}
