/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_to_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:30:08 by tmazan            #+#    #+#             */
/*   Updated: 2024/09/01 16:10:37 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

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
#include <stdio.h>

int main(void)
{
    printf("%c\n", ft_binary_to_char("01100011"));
    return (0);
}
