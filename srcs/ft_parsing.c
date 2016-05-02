#include "lem-in.h"

int     ft_cmp_name(char *tun, char **room)
{
    int i;
    
    i = 0;
    while (room[i])
    {
        if (!ft_strcmp(tun, room[i++]))
            return (1);
    }
    return (0);
}

char    **ft_chtun(char **tab, int id, t_global *glob)
{
    char    **tun;
    char    *str;
    int     i;
    
    tun = ft_strsplit(tab[id], '-');
    if (!tun[1] || tun[2] || !ft_strcmp(tun[0], tun[1])
    || !ft_cmp_name(tun[0], glob->room) || !ft_cmp_name(tun[1], glob->room))
    {
        i = 0;
        str = glob->hill;
        while (i++ < id)
            str = ft_strchr(&str[1], '\n');
        str[1] = '\0';
        //tun à free
        return (NULL);
    }
    return (tun);
}

char    ***ft_pars_tunnel(t_global *glob)
{
    int     i;
    int     lth;
    char    **tab;
    char    ***tunnel;
    
    i = 0;
    tab = ft_strsplit(glob->hill, '\n');
    while (tab[i] && (ft_strchr(tab[i], ' ') || tab[i][0] == '#'))
        i++;
    lth = 0;
    while (tab[i + lth])
        lth++;
    tunnel = (char***)ft_memalloc(sizeof(char**) * (lth + 1));
    lth = -1;
    while (tab[i + ++lth])
    {
        if (!(tunnel[lth] = ft_chtun(tab, i + lth, glob)))
            break;
    }
    tunnel[lth] = NULL;
    //clear tab
    return (tunnel);
}

int     ft_length_partone(char **tab)
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

char    ***ft_pars_room(char **tab)
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
    //clear tab
    return (room);
}

void    ft_stock_room(t_global *glob, char ***room)
{
    int     i;
    int     id;
    
    i = 0;
    id = 2;
    glob->room = (char**)ft_memalloc(sizeof(char*) * glob->length + 1);
    while (room[i])
    {
        if (!ft_strcmp(room[i][0], "##start"))
            glob->room[0] = room[++i][0];
        else if (!ft_strcmp(room[i][0], "##end"))
            glob->room[1] = room[++i][0];
        else
            glob->room[id++] = room[i][0];
        i++;
    }
    glob->room[glob->length] = NULL;
}

int     ft_find_idroom(char **room, char *name)
{
    int i;
    
    i = 0;
    while (room[i])
    {
        if (!ft_strcmp(room[i++], name))
            return (i - 1);
    }
    return (-1);
}

int     **ft_stock_tunnel(t_global *glob, char ***tunnel)
{
    int     i;
    int     **matrice;
    int     x;
    int     y;

    matrice = (int**)ft_memalloc(sizeof(int*) * glob->length);
    i = 0;
    while (i < glob->length)
        matrice[i++] = (int*)ft_memalloc(sizeof(int) * glob->length);
    i = 0;
    while (tunnel[i])
    {
        x = ft_find_idroom(glob->room, tunnel[i][0]);
        y = ft_find_idroom(glob->room, tunnel[i][1]);
        matrice[x][y] = 1;
        matrice[y][x] = 1;
        i++;
    }
    return (matrice);
}

int     ft_cnt_room(char ***room)
{
    int i;
    int cnt;
    
    i = 0;
    cnt = 0;
    while (room[i])
    {
        if (!ft_strcmp(room[i][0], "##start")
        || !ft_strcmp(room[i][0], "##end"))
        {
            i++;
            cnt++;
        }
        else
            cnt++;
        i++;
    }
    return (cnt);
}

void    ft_check_double(char **room)
{
    int i;
    int j;
    
    i = 0;
    while (room[i])
    {
        if (ft_strchr(room[i], '-'))
            ft_error();
        j = i;
        while (room[++j])
        {
            if (!ft_strcmp(room[i], room[j]))
                ft_error();
        }
        i++;
    }
}

void    ft_pars(t_global *glob)
{
    char    ***tunnel;
    char    ***room;

    room = ft_pars_room(ft_strsplit(glob->hill, '\n'));
    glob->length = ft_cnt_room(room);
    ft_stock_room(glob, room);
    tunnel = ft_pars_tunnel(glob);
    ft_check_double(glob->room);
    glob->matrice = ft_stock_tunnel(glob, tunnel);
    /************************************************/
    //     ft_printf("***parsing matrice***\n");
    // int i = 0;
    // int j;
    // ft_printf("  ");
    // while (i < glob->length)
    //     ft_printf("%d ", i++);
    // ft_putchar('\n');
    // i = 0;
    // while (i < glob->length)
    // {
    //     j = 0;
    //     ft_printf("%d ", i);
    //     while (j < glob->length)
    //       ft_printf("%d ", glob->matrice[i][j++]);
    //     ft_putchar('\n');
    //     i++;
    // }
    // ft_printf("********************\n");
    //  ft_printf("***parsing room***\n");
    // i = 0;
    // while (room[i])
    // {
    //     j = 0;
    //     while (room[i][j])
    //         ft_printf("%s ", room[i][j++]);
    //     ft_putchar('\n');
    //     i++;
    // }
    // ft_printf("********************\n");
}