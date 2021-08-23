/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:41:53 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/22 16:18:20 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define TRUE 0
# define FALSE 1
# define ERROR -1
# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_data
{
    unsigned long philo_number;
    unsigned long time_to_die;
    unsigned long time_to_eat;
    unsigned long time_to_sleep;
    unsigned long nb_of_times_eat;
    unsigned long time;
    unsigned long eat_count;
    pthread_mutex_t mutex;
}           t_data;

typedef struct s_philo
{
    unsigned long id;
    int           odd_or_even;
    int           change_state;
    int           state;
    unsigned long ret;
    t_data        *data;
}           t_philo;

void	ft_putstr_fd(char *s, int fd);
int	ft_isdigit(char c);
int	ft_atoi(const char *str);
void    init_struct_philo(t_philo *philo);
int print_error();
void    *start_routine(void *philo);
int    take_fork(t_philo *philo, unsigned long philo_number);
int    wait_for_thread(t_philo *philo, unsigned long time);
int    start_threads(t_philo *philo, unsigned long philo_number);

#endif