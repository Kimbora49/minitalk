/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaire_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:48:31 by tmazan            #+#    #+#             */
/*   Updated: 2024/08/30 20:00:35 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int binaire_convert(int c)
{
    int j;
    int storage[8];
    
    j = 0;
    while(c > 0)
    {
        if (c % 2 == 1)
            storage[j] = 1;
        else if (c % 2 == 0)
            storage[j] = 0;
        c = c / 2;
        j++;
    }
    j = 0;
    while(j < 7)
        j++;
    while(j >= 0)
    {
        ft_putchar(storage[j] + 48);
        j--;
    }
    return (0);
}

int main()
{
    binaire_convert(175);
    return (0);
}

// 25

// 1   128
// 0   64
// 1   32
// 0   16

// 1   8
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