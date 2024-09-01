/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:33:30 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/30 18:57:59 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>

int main(void)
{
    int id;

    id = getpid();
    ft_putstr_fd("server ID : ", 1);
    ft_putnbr_fd(id, 1);
    return (0);
}
