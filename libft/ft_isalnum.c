/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:39:17 by etanguy           #+#    #+#             */
/*   Updated: 2022/11/08 20:27:23 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c < 65 || c > 90) && (c < 97 || c > 122) && (c < 48 || c > 57))
		return (0);
	return (1);
}
/*
int	main(int argc, char **argv)
{
    printf("%d", ft_isalnum(argv[1][0]));
}
*/