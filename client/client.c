/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:48:26 by tmazan            #+#    #+#             */
/*   Updated: 2024/09/01 17:54:12 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int main(int argc, char **argv) // client -> 
{
    int i;

    i = 0;
    if (argc != 3)
    {
        write(2, "Error detected, argument format should be [pid] [text]\n", 55);
        return (0);
    }
    while(argv[1][i])
    {
        if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
        {
            write(2, "Error detected, a pid must contain only numbers\n", 49);
            return (0);
        }
        i++;
    }
    ft_char_to_binary(argv[1]);
    // envoyer via le pid;
    return (0);
}