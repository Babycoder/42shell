#include "functions_headerfile.h"

int     test_c(char c)
{
    if ((c >= 'a' && c <= 'z')
    || (c >= 'A' && c <= 'Z')
    || (c >= '0' && c <= '9')
    || (c == '_')
    || (c == '$'))
        return (1);
    return (0);
}

ssize_t     find_valid_dollar(char *slice)// returns index of the first valid dollar sign
{
    int i;
    char c;

    i = 0;
    while (slice[i] != 0)
    {
       while (slice[i] != 0
        && ((ft_test_char("\'\"$", slice[i]) == 0)
        || (ft_test_char("\'\"$", slice[i]) == 1 && back_slash_presence(slice, i - 1) == 1)))
            i++;
        if (ft_test_char("\'\"", slice[i]) == 1)
            i = skip_quotes(slice, i) + 1;
        if (slice[i] == '$' && back_slash_presence(slice, i - 1) == 0)
            return (i);
        if (slice[i] != 0)
            i++;
    }
    return (-1);
}

char    *fetch_var_name(char *slice, int i) //return the variable name
{
    int start;
    int end;
    char *result;

    start  = i;
    while (slice[i] != 0 && test_c(slice[i]) == 1)
        i++;
    end = i - 1;
    result = ft_substr(slice, start, end);
    return (result);
}

char    *var_replacement(t_var_rep *data)//replaces the dollar + variable name with the latters content
{
    char *tmp_1;
    char *tmp_2;

    tmp_1 = ft_substr(data->slice, 0, data->dollar_position - 1);
    tmp_2 = ft_substr(data->slice, data->dollar_position + ft_strlen(data->variable_name) + 1, ft_strlen(data->slice));
    tmp_1 = m_strjoin(tmp_1, data->variable_content);
    tmp_1 = m_strjoin(tmp_1, tmp_2);
    return(tmp_1);
}

char    *dollar_treatment(char *slice)
{
    int i = 0;
    t_var_rep *data = malloc(sizeof(t_var_rep));
    data->slice = slice;
    while (data->slice[i] != 0)
    {
        i = find_valid_dollar(data->slice);
        if (i == -1)
            break ;
        data->dollar_position = i++;
        if (data->slice[i] == '?')
            data->variable_name = ft_substr("?", 0, ft_strlen("?"));
        else
            data->variable_name = fetch_var_name(data->slice, i);
        data->variable_content = ft_substr("WHATEVER", 0, ft_strlen("WHATEVER"));//aymen function goes here
        data->slice = var_replacement(data);
    }
    return (data->slice);
}