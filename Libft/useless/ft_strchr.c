char *ft_strchr(const char *s, int c)
{
    int i;

    if (!s)
        return (0);
    i = 0;
    while (s[i] || s[i] == (char)c)
    {
        if ((char)c == s[i])
            return ((char *)(s + i));
        i++;
    }
    return (0);
}
