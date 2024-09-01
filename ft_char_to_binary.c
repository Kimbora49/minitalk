/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_binary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:48:31 by tmazan            #+#    #+#             */
/*   Updated: 2024/09/01 15:45:23 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char *ft_char_to_binary(char c)
{
    int j;
    static char storage[9];

    j = 7;
    while(c > 0)
    {
        if (c % 2 == 1)
            storage[j] = '1';
        else if (c % 2 == 0)
            storage[j] = '0';
        c = c / 2;
        j--;
    }
    while(j >= 0)
    {
        storage[j] = '0';
        j--;
    }
    storage[8] = '\0';
    return (storage);
}

#include <stdio.h>

int main(int ac, char **av)
{
    (void) ac;
    
    printf("%s\n", ft_char_to_binary(av[1][0]));
    return (0);
}

// 25

// 0   128
// 0   64
// 0   32
// 0   16

// 0   8
// 1   4
// 1   2
// 1   1

//  25
//  12.5 = % = 1
//  12 = % = 0
//  6 = % = 0
//  3 = % = 1
//  1.5 = % = 1
//  0 = % = 0
// 25