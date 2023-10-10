# ifndef MYCUBE_H
# define MYCUBE_H

#include <math.h>
#include <X11/Xlib.h>
# include "mlx_int.h"
# include "mlx.h"
#include "../source/gnl/get_next_line.h"
#include "libft.h"
# include "mlx_basics.h"
# include "render.h"



# define ERR_MLX_START "Could not start mlx"
# define ERR_MLX_WIN "Could not create mlx window"
# define ERR_MLX_IMG "Could not create mlx image"
# define ERR_MALLOC "Could not allocate memory"

// Taille de la fenêtre
# define WIN_WIDTH 640
# define WIN_HEIGHT 480

# define MOVESPEED 0.05
# define ROTEDSPEED 0.05

# define DIST_EDGE_MOUSE_WRAP 10

// taille ttextures mures
# define TEX_SIZE 64

# define NORTH 0
# define WEST 1
# define SOUTH 2
# define EAST 3


typedef struct s_imge
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_imge;

typedef struct s_texinfo
{
	char			*north;			// path de la texture
	char			*south;			// path de la texture
	char			*west;			// path de la texture
	char			*east;			// path de la texture
	int				*floor;			// à retirer
	int				*ceiling;		// à retirer
	unsigned long	hex_floor;		// couleur en valeur hexadécimale
	unsigned long	hex_ceiling;	// couleur en valeur hexadécimale
	int				size;			// taille de la texture (ici, carrée et 64)
	int				index;			// définit l'orientation (S, E, W, N) pour récup son image dans data.textures[index]
	double			step;			// Le pas auquel on se déplace dans l'image de la texture
	double			pos;			// position actuelle du pixel en hauteur
	int				x;				// position x sur la map
	int				y;				// position y sur la map
}	t_texinfo;


typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		moved;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player;

typedef struct s_ray
{
	double	camera_x;		// 
	double	dir_x;			// 
	double	dir_y;			// 
	int		map_x;			// position x de la case de la map
	int		map_y;			// position y de la case de la map
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;	// distance au prochaine coordonnée
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;	// hauteur du mur
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_data
{
	void		*mlx;				// pointeur de l'affichage
	void		*win;				// pointeur de la fenetre
	int			win_height;			// longueur de la fenetre
	int			win_width;			// hauteur de la fenetre
	int			map_height;			// longeur de la map
	int			map_width;			// hauteur de la map
	int			**textures;			// tableau des images des images des textures converties depuis xpm
	int			**texture_pixels;	// tableau des pixels pour les images
	char		**map;	
	int			trigger;	
		long		timer;
	int		trig;		// layout de la map
	t_texinfo	texinfo;			// info sur les textures
	t_player	player;				// info sur le player
	t_ray		ray;				// raycasting
}	t_data;

void	init_ray(t_ray *ray);
void	init_img(t_data *data, t_imge *image, int width, int height);
int		move_player(t_data *data);
void	init_player(t_player *player);
void	init_ray(t_ray *ray);
void	init_texinfo(t_texinfo *textures);
void	init_mlx(t_data *data);
void	init_textures(t_data *data);
void	render_images(t_data *data);
void	listen_for_input(t_data *data);
int	render(t_data *data);

#endif