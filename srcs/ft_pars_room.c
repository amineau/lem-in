#include "lem-in.h"

static int  ft_length_partone(char **tab)
{
    int     start;
    int     end;
    int     i;

    i = 0;
    start = 0;
    end = 0;
    while (tab[i] && (ft_strchr(tab[i], ' ') || tab[i][0] == '#'))
    {
        if (!ft_strcmp(tab[i], "##start"))
            start++;
        if (!ft_strcmp(tab[i], "##end"))
            end++;
        i++;
    }
    if (start != 1 || end != 1)
        ft_error();
    return (i);
}

char        ***ft_pars_room(char **tab)
{
    int     i;
    int     length;
    char    ***room;

    length = ft_length_partone(tab);
    room = (char***)ft_memalloc(sizeof(char**) * (length + 1));
    i = -1;
    while (++i < length)
        room[i] = ft_strsplit(tab[i], ' ');
    room[length] = NULL;
    ft_clear_tabchar(tab);
    return (room);
}

void        ft_stock_room(t_global *glob, char ***room)
{
    int     i;
    int     id;
    
    i = 0;
    id = 2;
    glob->room = (char**)ft_memalloc(sizeof(char*) * glob->length);
    while (room[i])
    {
        if (!ft_strcmp(room[i][0], "##start"))
            glob->room[0] = ft_strdup(room[++i][0]);
        else if (!ft_strcmp(room[i][0], "##end"))
            glob->room[1] = ft_strdup(room[++i][0]);
        else if (room[i][0][0] != '#')
            glob->room[id++] = ft_strdup(room[i][0]);
        i++;
    }
}