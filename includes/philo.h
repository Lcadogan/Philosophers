#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define FORK		"took a fork"
# define EAT		"eating"
# define SLEEP		"sleeping"
# define THINK		"thinking"
# define DIE		"died"
# define ALL_ATE	"full"

typedef struct s_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meal;
	int				sign_died;
	int				died;
	int				start;
	int				num_args;
	pthread_mutex_t	*forks;
}				t_data;

typedef struct s_philo
{
	int				id;
	int				eat_status;
	int				count_of_meal;
	long			time_eat;
	long			time_start;
	t_data			*data;
	pthread_t		thread;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*status;
	pthread_mutex_t	*die;
}				t_philo;

void		ft_print_status(t_philo *philo, char *status);
void		ft_free_all(t_philo *philo);
int			ft_create_philo(t_data *data);
int			ft_create_threads(t_philo *philo);
t_philo		*ft_init_philo_str(t_data *data, pthread_mutex_t *status);
void		ft_usleep(int time_ms);
int			ft_get_time(void);
int			ft_strlen(char *str);
int			ft_parse(t_data *data, char **argv);
int			ft_isdigit(int c);
int			ft_check_numbers(int i, char **argv);
int			ft_sign(char *str, int i);
int			ft_atoi(char *str);
void		ft_errors(char *str);
void		ft_check_status(t_philo *philo);
int			check_number_of_meal(t_philo *philo);
void		*simulation(void *philos);

#endif