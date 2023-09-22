
#include "cube.h"

void	first_draft(t_data *data)
{
	t_player p = data->player;

	p.fov = 3.14159 / 4;
	for(int x = 0; x < 1000; x++)
	{
		p.ray_angle = (p.a - p.fov / 2.0f) + ((float)x / 1000) * p.fov;
		p.eyex = sinf(p.ray_angle);
		p.eyey = cosf(p.ray_angle);
		int obstacle = 0;
		p.distance_to_wall = 0;
		while (obstacle == 0 && p.distance_to_wall < 16)
		{
			p.distance_to_wall += 0.01;
			int testx = (int)(p.x + p.eyex * p.distance_to_wall);
			int testy = (int)(p.y + p.eyey * p.distance_to_wall);
			if (testx < 0 || testx >= 1000 || testy < 0 || testy >= 1000)
			{
				obstacle=1;
				p.distance_to_wall = 16;
			}
			else if ((data->maptmp[testy][testx]) == '1')
				obstacle = 1;
		}
			int ceiling = (float)(1000 / 2.0) - 1000 / ((float)p.distance_to_wall);
			int floor = 1000 - ceiling;
			for (int y = 0; y < 1000; y++)
			{
				if (y < ceiling)
					img_pix_put(&data->img, x, y, 0xffffff + y/10);
				else if (y > ceiling && y <= floor)
				{
					img_pix_put(&data->img, x, y, 0x582030 - (int)(p.distance_to_wall) * 10);
				}
				else
					img_pix_put(&data->img, x, y, 0xffffff + y/10);
			}
	}
}
