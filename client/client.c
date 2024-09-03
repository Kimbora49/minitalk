/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:48:26 by tmazan            #+#    #+#             */
/*   Updated: 2024/09/03 17:38:05 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

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

int main(int argc, char **argv) // client -> 
{
    int i;
    int j;
    char *binofchar;

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
    j = 0;
    i = 0;
    while (argv[2])
    {
        binofchar = ft_char_to_binary(argv[2][j]);
        while (binofchar[i])
        {
            if(binofchar[i] == '0')
                kill(atoi(argv[1]), SIGUSR1);
            else if(binofchar[i] == '1')
                kill(atoi(argv[1]), SIGUSR2);
            i++;
        }
        j++;
    }
    
    // envoyer via le pid;
    return (0);
}