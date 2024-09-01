/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   training.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:30:26 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/30 17:23:59 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    int ret_fork;
    
    ret_fork = fork();
    
    if (ret_fork == 0)
        printf("\npid of child : %d\n", getpid());
    else
    {
        printf("pid of parent : %d\n", getpid());
        printf("id of parent : %d\n", ret_fork);
    }
}
// return value du fork :
//   (PID child)  (0)
//        P        C
//        |        |
//        |________|
//             |
//             |