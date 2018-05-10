/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** Day04/Task05
*/

int	before_nbr(char const *str)
{
	int	i = 0;

	while (str[i] < '0' || str[i]> '9') {
		if (str[i] == '\n' || str[i] == '\0')
			return (-3);
		i = i + 1;
	}
	return (i);
}

int	my_getnbr(char const *str)
{
	int	i = 0;
	int	nb = 0;
	int	compteur = 0;

	before_nbr(str);
	i = before_nbr(str);
	if (i == -3)
		return (-3);
	while (str[i] >= '0' &&  str[i] <= '9') {
		nb = nb * 10 + str[i] - 48;
		i = i + 1;
		compteur = compteur + 1;
	}
	if (compteur >= 9)
		return (0);
	else
		return (nb);
}
