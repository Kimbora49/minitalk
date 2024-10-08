/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:33:30 by tmazan            #+#    #+#             */
/*   Updated: 2024/10/08 10:57:27 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

char	ft_binary_to_char(char *s)
{
	int	somme;
	int	i;
	int	val_bi;

	i = 0;
	val_bi = 128;
	somme = 0;
	while (s[i])
	{
		if (s[i] == '1')
			somme += val_bi;
		val_bi /= 2;
		i++;
	}
	return (somme);
}

void	signalhandler(int pid)
{
	static char	binofchar[9];
	static int	ratio;
	int			i;
	char		chartowrite;

	if (ratio == 0)
	{
		i = 0;
		while (i < 8)
			binofchar[i++] = '0';
		binofchar[8] = '\0';
	}
	if (pid == SIGUSR1)
		binofchar[ratio] = '0';
	else if (pid == SIGUSR2)
		binofchar[ratio] = '1';
	ratio++;
	if (binofchar[ratio] == '\0')
	{
		ratio = 0;
		chartowrite = ft_binary_to_char(binofchar);
		write(1, &chartowrite, 1);
	}
}

int	main(void)
{
	int	id;

	id = getpid();
	write(1, "server ID : ", 12);
	ft_putnbr_fd(id, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, signalhandler);
	signal(SIGUSR2, signalhandler);
	while (1)
		pause();
	return (0);
}
