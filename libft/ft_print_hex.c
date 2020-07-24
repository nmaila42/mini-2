#include "libft.h"

void	ft_print_hex(int n)
{
	int		i;
	int		x;
	char	hex[9];

	i = 8;
	x = 0;
	hex[8] = 0;
	while (i--)
	{
		x = n % 16;
		if (x <= 9)
			hex[i] = x + '0';
		else
			hex[i] = x - 10 + 'a';
		n /= 16;
	}
	ft_putstr("0x");
	ft_putstr(hex);
}
