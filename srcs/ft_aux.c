#include "../includes/cub3d.h"

int		count_words(char const *s, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			words++;
		}
	}
	return (words);
}

char	**fill_cols(char **matrix, char const *s, char c)
{
	int row;
	int i;
	int letters;

	row = 0;
	i = 0;
	while (s[i] != '\0')
	{
		letters = 0;
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i] != '\0')
			{
				i++;
				letters++;
			}
			if (!(matrix[row] = (char *)malloc(letters * sizeof(char) + 1)))
				return (NULL);
			row++;
		}
	}
	return (matrix);
}

char	**fill_matrix(char **matrix, char const *s, char c)
{
	int row;
	int i;
	int col;

	row = 0;
	i = 0;
	while (s[i] != '\0')
	{
		col = 0;
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i] != '\0')
			{
				matrix[row][col] = s[i];
				col++;
				i++;
			}
			matrix[row][col] = '\0';
			row++;
		}
	}
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**mat;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	if (!(mat = (char **)malloc((words + 1) * sizeof(char*))))
		return (NULL);
	fill_cols(mat, s, c);
	fill_matrix(mat, s, c);
	mat[words] = 0;
	return (mat);
}

int	ft_strncmp(const char *s1, const char *s2, unsigned long int n)
{
	unsigned long int	i;
	unsigned char		*auxs1;
	unsigned char		*auxs2;

	auxs1 = (unsigned char *)s1;
	auxs2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (auxs1[i] != 0 || auxs2[i] != 0))
		if (auxs1[i] == auxs2[i])
			i++;
		else
			return (auxs1[i] - auxs2[i]);
	return (0);
}