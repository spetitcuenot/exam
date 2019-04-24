nclude <stdlib.h>

#include <stdio.h>



int		sizeint(unsigned int d)

{

	int i;



	i = 0;

	while (d > 10)

	{

		i++;

		d = d / 10;

	}

	i++;

	return (i);

}



char	*ft_strncat(char *dest, char *src)

{

	char *new;

	int i;

	int j;

	int k;



	i = 0;

	j = 0;

	new = NULL;

	while (dest[i] != '\0')

		i++;

	while (src[j] != '.')

		j++;

	k = i + j + 1;

	if (!(new = (char *)malloc((i + j + 1) * sizeof(char))))

		return (NULL);

	i = 0;

	j = 0;

	while (dest[j] != '\0')

	{

		new[i] = dest[j];

		i++;

		j++;

	}

	j = 0;

	while (src[j] != '\0')

	{

		new[i] = src[j];

		i++;

		j++;

	}

	new[k] = '\0';

	return (new);

}



char	*ft_strconv(unsigned int d)

{

	char *str;

	int rest;

	int j;

	int i;



	rest = 0;

	j = sizeint(d);

	i = 0;

	if (!(str = (char *)malloc((j + 1) * sizeof(str))))

		return (NULL);

	while (d >= 10)

	{

		rest = d % 10;

		str[i] = rest + '0';

		d = d/ 10;

		i++;

	}

	str[i] = d + '0';

	printf ("str = %s\n", str);

	return (str);

}



char	*ft_strnrev(char *str)

{

	char tmp;

	int i;

	int j;

	int k;



	tmp = '\0';

	i = 0;

	j = 0;

	while (str[j] != '\0')

		j++;

	k = j;

	j = j - 1;

	while (i < j)

	{

		tmp = str[i];

		str[i] = str[j];

		str[j] = tmp;

		i++;

		j--;

	}

	str[k] ='\0';

	return (str);

}





char    *moment(unsigned int duration)

{

	char *new;

	int sec;

	int min;

	int hour;

	int day;

	int month;



	sec = duration % 60;

	min = duration / 60;

	hour = duration / 3600;

	day = duration / 86400;

	month = duration / 2592000;

	new = NULL;

	if (duration < 60)

	{

		new = ft_strconv(sec);

		new = ft_strnrev(new);

		new =((sec == 1) ? ft_strncat(new, " second ago.") : ft_strncat(new, " seconds ago."));

	}

	else if (duration < 3600)

	{

		new = ft_strconv(min);

		new = ft_strnrev(new);

		new =((min == 1) ? ft_strncat(new, " minute ago.") : ft_strncat(new, " minutes ago."));

	}

	else if (duration < 86400)

	{	new = ft_strconv(hour);

		new = ft_strnrev(new);

		new =((hour == 1) ? ft_strncat(new, " hour ago.") : ft_strncat(new, " hours ago."));

	}

	else if (duration < 2592000)

	{	new = ft_strconv(day);

		new = ft_strnrev(new);

		new =((day == 1) ? ft_strncat(new, " day ago.") : ft_strncat(new, " days ago."));

	}

	else if (duration >= 2592000)

	{	new = ft_strconv(month);

		new = ft_strnrev(new);

		new =((month == 1) ? ft_strncat(new, " month ago.") : ft_strncat(new, " months ago."));

	}

	return (new);

}







int		main()

{

	unsigned int d;

	char *str;



	d = 878377;



	str = moment(d);



	printf ("%s", str);



}
