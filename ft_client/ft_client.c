/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:48:26 by tmazan            #+#    #+#             */
/*   Updated: 2024/10/08 10:19:00 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

bool	error_gestion(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		write(2, "Error detected, argument format should be [pid] [text]\n", 55);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
		{
			write(2, "Error detected, a pid must contain only numbers\n", 49);
			return (0);
		}
		i++;
	}
	return (1);
}

char	*ft_char_to_binary(char c)
{
	int			j;
	static char	storage[9];

	j = 7;
	while (c > 0)
	{
		if (c % 2 == 1)
			storage[j] = '1';
		else if (c % 2 == 0)
			storage[j] = '0';
		c = c / 2;
		j--;
	}
	while (j >= 0)
	{
		storage[j] = '0';
		j--;
	}
	storage[8] = '\0';
	return (storage);
}

void	convert_n_send(char **argv)
{
	int		i;
	int		j;
	char	binofchar[9];

	j = 0;
	i = 0;
	while (argv[2][j] != '\0')
	{
		i = 0;
		ft_strcpy(binofchar, ft_char_to_binary(argv[2][j]));
		while (binofchar[i])
		{
			if (binofchar[i] == '0')
				kill(ft_atoi(argv[1]), SIGUSR1);
			else if (binofchar[i] == '1')
				kill(ft_atoi(argv[1]), SIGUSR2);
			usleep(400);
			i++;
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	if (error_gestion(argc, argv) == 0)
		return (0);
	convert_n_send(argv);
	return (0);
}
