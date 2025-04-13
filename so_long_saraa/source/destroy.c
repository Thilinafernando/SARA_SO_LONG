
# include "../so_long.h"

void    dest_img(t_play *play)
{
    if (play -> floor)
        mlx_destroy_image(play -> mlx, play -> floor);
    if (play -> wall)
         mlx_destroy_image(play -> mlx, play -> wall);
    if (play -> player)
         mlx_destroy_image(play -> mlx, play -> player);
    if (play -> coll)
         mlx_destroy_image(play -> mlx, play -> coll);
    if (play -> exit)
        mlx_destroy_image(play -> mlx, play -> exit);
    dest_win(play);
}

void dest_win(t_play *play)
{
    if(!play)
        return;
    if (play -> map.base)
        freemtx(play->map.base);
    if (play -> map.dmap)
        freemtx(play -> map.dmap);
    if(play -> win)
        mlx_destroy_window(play -> mlx, play -> win);
    if (play -> mlx)
    {
        mlx_destroy_display(play -> mlx);
        free(play -> mlx);
    }
}
