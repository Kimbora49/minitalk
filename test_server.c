/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:50:24 by tmazan            #+#    #+#             */
/*   Updated: 2024/09/03 17:49:43 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void signalhandler(int pid)
{
    if (pid == SIGUSR1)
        write(1, "0\n", 2);
    else if(pid == SIGUSR2)
        write(1, "1\n", 2);
}

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
 
    signal(SIGUSR1, signalhandler);
    signal(SIGUSR2, signalhandler);
    printf("pid : %d\n", getpid());

    while(1)
    {
        pause();
    }
    return (0);
}