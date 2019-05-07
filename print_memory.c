/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:11:41 by akhossan          #+#    #+#             */
/*   Updated: 2019/05/07 23:01:32 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hex(unsigned char c)
{
	char	*set;

	set = "0123456789abcdef";
	ft_putchar(set[c / 16]);
	ft_putchar(set[c % 16]);
}

void	print_memory(const void *addr, size_t size)
{
	unsigned char	*mem;
	size_t			i;
	size_t			j;

	mem = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < 16 && i + j < size)
		{
			print_hex(mem[i + j]);
			if (i + j && (i + j) % 2)
				write(1, " ", 1);
			j++;
		}
		while (j < 16)
		{
			write(1, "  ", 2);
			if (j % 2 == 0)
				write(1, " ", 1);
			j++;
		}
		j = 0;
		while (j < 16 && i + j < size)
		{
			if (mem[i + j] < 32 || mem[i + j] > 126)
				write(1, ".", 1);
			else
				write(1, &mem[i + j], 1);
			j++;
		}
		write(1, "\n", 1);
		i += j;
	}
}

int		main(void)
{
	int		arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	print_memory(arr, sizeof(arr));
}
