#include "../include/mycube.h"

int	check_pos(t_data *data, double pos_x, double pos_y)
{
	int test;

	test = 0;
	if (pos_x > 0 && pos_x < data->map_width
		&& pos_y > 0 && pos_y < data->map_height)
		test = 1;
	return (test);
}

int	move_player_forward(t_data *data)
{
	double	pos_x;
	double	pos_y;

	pos_x = data->player.pos_x + data->player.dir_x * MOVESPEED;
	pos_y = data->player.pos_y + data->player.dir_y * MOVESPEED;
	if (check_pos(data, pos_x, pos_y))
	{
		data->player.pos_x = pos_x;
		data->player.pos_y = pos_y;
		return (1);
	}
	return (0);
}

int	move_player_backward(t_data *data)
{
	double	pos_x;
	double	pos_y;

	pos_x = data->player.pos_x - data->player.dir_x * MOVESPEED;
	pos_y = data->player.pos_y - data->player.dir_y * MOVESPEED;
	if (check_pos(data, pos_x, pos_y))
	{
		data->player.pos_x = pos_x;
		data->player.pos_y = pos_y;
		return (1);
	}
	return (0);
}

int	move_player_left(t_data *data)
{
	double	pos_x;
	double	pos_y;

	pos_x = data->player.pos_x + data->player.dir_y * MOVESPEED;
	pos_y = data->player.pos_y - data->player.dir_x * MOVESPEED;
	if (check_pos(data, pos_x, pos_y))
	{
		data->player.pos_x = pos_x;
		data->player.pos_y = pos_y;
		return (1);
	}
	return (0);
}

int	move_player_right(t_data *data)
{
	double	pos_x;
	double	pos_y;

	pos_x = data->player.pos_x - data->player.dir_y * MOVESPEED;
	pos_y = data->player.pos_y + data->player.dir_x * MOVESPEED;
	if (check_pos(data, pos_x, pos_y))
	{
		data->player.pos_x = pos_x;
		data->player.pos_y = pos_y;
		return (1);
	}
	return (0);
}

int	rotate_player(t_data *data, double rotdir)
{
	double x;
	double y;
	double O;

	O = ROTEDSPEED * rotdir;
	x = data->player.dir_x;
	y = data->player.dir_y;
	data->player.dir_x = cos(O) * x - sin(O) * y;
	data->player.dir_y = cos(O) * y + sin(O) * x;
	x = data->player.plane_x;
	y = data->player.plane_y;
	data->player.plane_x = cos(O) * x - sin(O) * y;
	data->player.plane_y = cos(O) * y + sin(O) * x;
	return (1);
}

int	move_player(t_data *data)
{
	int	moved;
    (void) data;

	moved = 0;
	if (data->player.move_y == 1)
		moved += move_player_forward(data);
	if (data->player.move_y == -1)
		moved += move_player_backward(data);
	if (data->player.move_x == -1)
		moved += move_player_left(data);
	if (data->player.move_x == 1)
		moved += move_player_right(data);
	if (data->player.rotate != 0)
		moved += rotate_player(data, data->player.rotate);
	return (moved);
}