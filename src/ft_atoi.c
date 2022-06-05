#include "../includes/philo.h"

static int	sp(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int	ft_sign(char *str, int i)
{
	int	sign;

	if (str[i] == 45)
		sign = -1;
	else
		sign = 1;
	return (sign);
}

static int	ft_num(char *str, int i, int sign)
{
	long	num;

	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num > (num * 10 + (str[i] - 48)))
		{
			if (sign == 1)
				return (-1);
			if (sign == -1)
				return (0);
		}
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num);
}

int	ft_atoi(char *str)
{
	int		i;
	long	num;
	int		sign;

	if (ft_strlen(str) == 0)
		return (0);
	i = sp(str);
	sign = ft_sign(str, i);
	if (str[i] == '-' || str[i] == '+')
		i++;
	num = ft_num(str, i, sign);
	return ((int)num * sign);
}
