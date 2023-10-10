#include "mycube.h"

int	key_press_handler(int key, t_data *data)
{
	if (key == XK_w)
		data->player.move_y = 1;
	if (key == XK_a)
		data->player.move_x = -1;
	if (key == XK_s)
		data->player.move_y = -1;
	if (key == XK_d)
		data->player.move_x = 1;
	if (key == 65363)
		data->player.rotate -= 1;
	if (key == 65361)
		data->player.rotate += 1;
	return (0);
}

void	listen_for_input(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, key_press_handler, data);
}