/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:27:23 by mhaksal           #+#    #+#             */
/*   Updated: 2022/03/02 09:33:36 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

void	ft_putnbr(int nb);

int		ft_putchar(char c);
int		ft_printf(const char *s, ...);
int		ft_putstr(char *s);
int		ft_extract(char c, unsigned int nb);
int		ft_extract2(char c, int a);
int		ft_vdptr(unsigned long ptr);

char	*ft_strrev(char *s);

#endif
