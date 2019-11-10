//
// Created by Katharine Psylocke on 10/11/2019.
//

int ft_strchr_pos(const char *str, int c)
{
	int		pos;
	char	cc;
	char	*temp;

	pos = 0;
	temp = (char *)str;
	cc = (char)c;
	while (str[pos] != '\0')
	{
		if (str[pos] == cc)
			return (pos);
		pos++;
	}
	if (str[pos] == cc)
		return (pos);
	return (-1);
}