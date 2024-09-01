/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:33:30 by tmazan            #+#    #+#             */
/*   Updated: 2024/09/01 18:15:25 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../server.h"
#include <unistd.h>

int main(void)
{
    int id;

    id = getpid();
    ft_putstr_fd("server ID : ", 1);
    ft_putnbr_fd(id, 1);
    ft_putchar_fd('\n', 1);
    while()
    {
        printf("%c", ft_binary_to_char(char *));
    }
    return (0);
}

// bool pid_compare(int c)
// {
//     if (c == getpid())
//         return (true);
//     return (false);
// }