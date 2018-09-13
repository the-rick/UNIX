#include "libft.h"

char    *n_join(char const *s1, char const *s2, size_t n)
{
    char *new = NULL;
    int len;

    len = ft_strlen(s1) + ft_strlen(s2);
    new = (char*)malloc(sizeof(char) * len);
    if (!new)
    {
        return (NULL);
    }
    ft_strcpy(new, s1);
    ft_strncat(new, s2, n);
    return (new);
}
