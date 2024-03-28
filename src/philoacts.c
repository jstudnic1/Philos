/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philoacts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstudnic <studnicka.jakub04@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:44:54 by jstudnic          #+#    #+#             */
/*   Updated: 2024/03/27 21:48:39 by jstudnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*one_philo(void *p)
{
	t_philo	*ph;

	ph = (t_philo *)p;
	pthread_mutex_lock(&ph->args->fork[ph->l_fork]);
	print(ph, "has taken a fork");
	ph->t_lastmeal = timestamp(ph->args);
	ft_sleep(ph, ph->args->t_to_die);
	print(ph, "died");
	ph->args->game_over = TRUE;
	return (NULL);
}

void	ph_eat(t_philo *ph)
{
	if (ph->args->game_over == FALSE)
	{
		pthread_mutex_lock(&ph->args->fork[ph->l_fork]);
		print(ph, "has taken a fork");
		pthread_mutex_lock(&ph->args->fork[ph->r_fork]);
		print(ph, "has taken a fork");
		print(ph, "is eating");
		ph->t_lastmeal = timestamp(ph->args);
		ph->meals_eaten += 1;
		ft_sleep(ph, ph->args->t_to_eat);
		pthread_mutex_unlock(&ph->args->fork[ph->l_fork]);
		pthread_mutex_unlock(&ph->args->fork[ph->r_fork]);
	}
}

void	ph_think(t_philo *ph)
{
	if (ph->args->game_over == FALSE)
		print(ph, "is thinking");
}

void	ph_sleep(t_philo *ph)
{
	if (ph->args->game_over == FALSE)
	{
		print(ph, "is sleeping");
		ft_sleep(ph, ph->args->t_to_sleep);
	}
}
