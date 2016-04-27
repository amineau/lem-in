#include "lem-in.h"

char    ***ft_pars_tunnel(char **tab)
{
    int     i;
    int     length;
    char    ***tunnel;
    
    i = 0;
    while (tab[i] && (ft_strchr(tab[i], ' ') || tab[i][0] == '#'))
        i++;
    length = 0;
    while (tab[i + length])
        length++;
    tunnel = (char***)ft_memalloc(sizeof(char**) * (length + 1));
    length = -1;
    while (tab[i + ++length])
        tunnel[length] = ft_strsplit(tab[i + length], '-');
    tunnel[length] = NULL;
    //clear tab
    return (tunnel);
}

char    ***ft_pars_room(char **tab)
{
    int     i;
    int     length;
    char    ***room;
    
    length = 0;
    while (tab[length] && (ft_strchr(tab[length], ' ') || tab[length][0] == '#'))
        length++;
    room = (char***)ft_memalloc(sizeof(char**) * (length + 1));
    i = -1;
    while (++i < length)
        room[i] = ft_strsplit(tab[i], ' ');
    room[length] = NULL;
    //clear tab
    return (room);
}

int     ft_stock_room(t_global *glob, char ***room)
{
    int i;
    int id;
    
    i = 0;
    id = 2;
    
    glob->room = (t_room**)ft_memalloc(sizeof(t_room*));
    
    while (room[i])
    {
        if (!ft_strcmp(room[i][0], "##start"))
            ft_listadd_room(glob->room, room[++i], 0);
        else if (!ft_strcmp(room[i][0], "##end"))
            ft_listadd_room(glob->room, room[++i], 1);
        else
            ft_listadd_room(glob->room, room[i], id++);
        i++;
    }
    return (id);
}

int     ft_find_idroom(t_room **room, char *name)
{
    t_room  *tmp;
    
    tmp = *room;
    while (tmp)
    {
        if (!ft_strcmp(tmp->name, name))
            return (tmp->pos);
        tmp = tmp->next;
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
    return matrice;
}

void    ft_pars(t_global *glob)
{
    char    ***tunnel;
    char    ***room;

    room = ft_pars_room(ft_strsplit(glob->hill, '\n'));
    tunnel = ft_pars_tunnel(ft_strsplit(glob->hill, '\n'));
    glob->length = ft_stock_room(glob, room);
    glob->matrice = ft_stock_tunnel(glob, tunnel);
    ft_strdel(&glob->hill);
    
    /****************Display room****************/
   /* int i;
    int j;
    
   

    ft_printf("***parsing tunnel***\n");
    i = 0;
    while (tunnel[i])
    {
        j = 0;
        while (tunnel[i][j])
           ft_printf("%s ", tunnel[i][j++]);
        ft_putchar('\n');
        i++;
    }
    ft_printf("********************\n");

    ft_printf("***stockage room***\n");
    t_room *tmp;
    tmp = *(glob->room);
    while (tmp)
    {
        ft_printf("name : %4s | x : %2d | y = %2d | pos : %d)\n", tmp->name, tmp->x, tmp->y, tmp->pos);
        tmp = tmp->next;
    }
    ft_printf("********************\n"); */
    /************************************************/
    //     ft_printf("***parsing tunnel***\n");
    // int i = 0;
    // int j;
    // while (tunnel[i])
    // {
    //     j = 0;
    //     while (tunnel[i][j])
    //       ft_printf("%s ", tunnel[i][j++]);
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
    // ft_printf("***stockage room***\n");
    // t_room *tmp;
    // tmp = *(glob->room);
    // while (tmp)
    // {
    //     ft_printf("name : %4s | x : %2d | y = %2d | pos : %d)\n", tmp->name, tmp->x, tmp->y, tmp->pos);
    //     tmp = tmp->next;
    // }
    // ft_printf("********************\n");
}