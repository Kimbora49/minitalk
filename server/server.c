/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:33:30 by tmazan            #+#    #+#             */
/*   Updated: 2024/09/04 17:59:49 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../server.h"
#include <signal.h>
#include <unistd.h>
static char binofchar[9];
int ratio = 0;

char ft_binary_to_char(char *s)
{
    int somme;
    int i;
    int val_bi;

    i = 0;
    val_bi = 128;
    somme = 0;
    while(s[i])
    {
        if(s[i] == '1')
            somme += val_bi;
        val_bi /= 2;
        i++;
    }
    return (somme);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void signalhandler(int pid)
{
    printf("bit reçu\n");
    if (binofchar[ratio])
    {
        if (pid == SIGUSR1)
        {
            printf("recu : 0\n");
            binofchar[ratio] = '0';
            printf("char mis dans le tab : %c", binofchar[ratio]);
        }
        else if (pid == SIGUSR2)
        {
            printf("recu : 1\n");
            binofchar[ratio] = '1';
            printf("char mis dans le tab : %c", binofchar[ratio]);
        }
        ratio++;
        printf("\nratio : %d\n", ratio);
    }
    if (binofchar[ratio] == '\0')
    {
        ratio = 0;
        printf("\nchar transmis :%c\n", ft_binary_to_char(binofchar));
    }
}

int main(void)
{
    int id;
    int i;

    id = getpid();
    ft_putstr_fd("server ID : ", 1);
    ft_putnbr_fd(id, 1);
    ft_putchar_fd('\n', 1);
    i = 0;
    while (i < 8)
    {
        binofchar[i] = '0';
        i++;
    }
    binofchar[8] = '\0';
    i = 0;
    signal(SIGUSR1, signalhandler);
    signal(SIGUSR2, signalhandler);
    while(1)
    {
        pause();
    }
    return (0);
}

// bool pid_compare(int c)
// {
//     if (c == getpid())
//         return (true);
//     return (false);
// }