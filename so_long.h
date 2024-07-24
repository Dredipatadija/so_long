#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>

typedef struct s_map
{
    int     nposition;
    int     nexit;
    int     ncollectable;
    int     nwall;
    int     nspace;
    int     width;
    int     height;
    int     x_exit;
    int     y_exit;
    char    **map;
}               t_map;

#endif