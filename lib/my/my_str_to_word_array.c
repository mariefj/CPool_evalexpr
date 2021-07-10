#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "my.h"

static int	my_isalpha(char letter)
{
	if (!(letter >= 'a' && letter <= 'z') && !(letter >= 'A' && letter <= 'Z'))
	{
		return (0);
	}

	return (1);
}

static int	my_get_nb_words(char const *str)
{
	int i = 0;
	int nb_words = 0;

	while (i <= my_strlen(str))
	{
		if (my_isalpha(str[i]) == 1 && my_isalpha(str[i + 1]) == 0)
		{
			nb_words++;
		}
		i++;
	}

	return (nb_words);
}

static int	my_nb_words(char const *str, int nb_words, int i)
{
	if (i == 0 && my_isalpha(str[i]) == 1)
	{
		return (1);
	}
	if (i > 0 && my_isalpha(str[i - 1]) == 0 && my_isalpha(str[i]) == 1)
	{
		return (nb_words + 1);
	}

	return(nb_words);
}

static char	*my_get_word(char const *str, int nb)
{
	int i = 0;
	int nb_words = 0;
	char *word = (char *)malloc(1 * sizeof(char));

	if (word == NULL || nb < 0 || nb > my_get_nb_words(str))
		return (NULL);
	while (str[i] != '\0')
	{
		nb_words = my_nb_words(str, nb_words, i);
		if (nb_words == nb)
		{
			word[0] = str[i++];
			while (my_isalpha(str[i]) == 1)
			{
				word = my_append_c(word, str[i]);
				i++;
			}

			return (word);
		}
		i++;
	}

	return (NULL);
}

char	**my_str_to_word_array(char const *str)
{
	int i = 0;
	char **array;

	if (str == NULL)
		return (NULL);
	array = (char **)malloc((my_get_nb_words(str) + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (i < my_get_nb_words(str))
	{
		array[i] = my_get_word(str, i + 1);
		i++;
	}
	array[i] = NULL;

	return (array);
}