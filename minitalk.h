/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:58:14 by tmazan            #+#    #+#             */
/*   Updated: 2024/10/08 10:15:36 by tmazan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include<unistd.h> //write
# include<signal.h> //signal
# include<stdbool.h> //bool
# include<stddef.h> //size_t

//prototype
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
size_t	ft_strcpy(char *dst, const char *src);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif