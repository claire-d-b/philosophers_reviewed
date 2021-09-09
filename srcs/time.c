#include "philosophers.h"

unsigned long get_time(t_philo *philo)
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL) == -1)
        return (print_error("Error in getting time\n", philo));
    return ((tv.tv_sec * 1000 + tv.tv_usec / 1000) - philo->data->start_time);
}

unsigned long get_start_time()
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL) == -1)
        return (print_error("Error in getting time\n", NULL));
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int    wait_action(t_philo *philo, unsigned long time)
{
    unsigned long cumul_time;
    unsigned long diff;

    cumul_time = get_time(philo);
    if (philo->time_cmp)
        diff = cumul_time % philo->time_cmp;
    else
        diff = 0;
    pthread_mutex_lock(&philo->data->time_mutex);
    philo->data->time = get_time(philo);
    pthread_mutex_unlock(&philo->data->time_mutex);
    while (1)
    {
        pthread_mutex_lock(&philo->data->time_mutex);
        philo->data->time = get_time(philo);
        if (philo->data->time > cumul_time + time - diff)
        {
            pthread_mutex_unlock(&philo->data->time_mutex);
            break ;
        }
        pthread_mutex_unlock(&philo->data->time_mutex);
        if (usleep(1000) == -1)
            return (print_error("Error in waiting time\n", philo));
    }
    philo->time_cmp += time;
    return (TRUE);
}