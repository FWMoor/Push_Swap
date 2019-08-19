/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 19:53:00 by fwmoor            #+#    #+#             */
/*   Updated: 2019/08/19 07:34:10 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_factorial(int nb)
{
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	if (nb > 1)
		return (nb * (ft_factorial(nb - 1)));
	else
		return (nb);
}

int			ft_power(int nb, int pwr)
{
	if (pwr < 0)
		return (0);
	if (pwr == 0)
		return (1);
	if (pwr > 1)
		return (nb * (ft_power(nb, pwr - 1)));
	else
		return (nb);
}

int			ft_sqrt(int nb)
{
	int i;

	i = 1;
	while (i < (nb / 2))
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
