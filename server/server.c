/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:33:30 by tmazan            #+#    #+#             */
/*   Updated: 2024/09/03 17:58:06 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../server.h"
#include <signal.h>
#include <unistd.h>

void signalhandler(int pid)
{
    static char binofchar[9];
    int i;

    i = 0;
    while (i <= 8)
    {
        binofchar[i] = '0';
        i++;
    }
    binofchar[9] = '\0';
    i = 0;
    while (binofchar[i])
    {
        if (pid == SIGUSR1)
            binofchar[i] = '0';
        else if(pid == SIGUSR2)
            binofchar[i] = '1';
        i++;
    }

    //convert binofchar to int
    //print the char corresponding to the int value 
}

int main(void)
{
    int id;

    id = getpid();
    ft_putstr_fd("server ID : ", 1);
    ft_putnbr_fd(id, 1);
    ft_putchar_fd('\n', 1);
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