/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:50:25 by tmazan            #+#    #+#             */
/*   Updated: 2024/09/03 17:19:55 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    (void) argc;

    if (argv[2][0] == '0')
        kill(atoi(argv[1]), SIGUSR1);
    else if (argv[2][0] == '1')
        kill(atoi(argv[1]), SIGUSR2);
    return (0);
}