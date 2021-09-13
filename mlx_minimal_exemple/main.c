#include "minilibx/mlx.h"
#include "fcntl.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define TEXTURE_COUNT 1

# define APP_NAME "boulette"
# define SPRITE_PATH "sprite.xpm"


# define GRID_SIZE_X 10
# define GRID_SIZE_Y 8

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307

int clamp(int min, int max, int val)
{
    if(min > max)
        return 0;
    if (val > max)
        return max;
    if (val < min)
        return min;
    return val;
}

typedef struct  s_game_state
{
    int player_x;
    int player_y;
    // whatever
}               t_game_state; 

typedef struct	s_texture
{
    void		*img;
    char		*data;
    int			bpp;
    int			endian;
    int			size;
    int         width;
    int         height;
}				t_texture;

typedef struct  s_app
{
    void *mlx;
    void *image;
    void *window;
    int width;
    int height;
	int image_is_destroyed;
    t_texture sprites;
    t_game_state game_state;
}               t_app;


void load_image(t_app *app, t_texture *texture, char *file)
{
    if (open(file, O_RDONLY) <= 0)
    {
        // ERROR MANAGEMENT
        return;
    }
    texture->img = mlx_xpm_file_to_image(app->mlx, file, &(texture->width), &(texture->height));
    texture->data = mlx_get_data_addr(texture->img, &(texture->bpp), &(texture->size), &(texture->endian));
}

void    init_app(t_app *app, char *title, int w, int h)
{
    app->mlx = mlx_init();
    load_image(app, &(app->sprites), SPRITE_PATH);
    app->width = w * app->sprites.width;
    app->height = h * app->sprites.height;
    app->window = mlx_new_window(app->mlx, app->width, app->height, title);
    app->game_state.player_y = 0;
    app->game_state.player_x = 0;
	app->image_is_destroyed = 0;
}

void draw_sprite_at_position(t_app *app, void *dest, t_texture *texture, int x, int y)
{
    int i;
    int start;
    int bpp = texture->bpp / 8; // should be 4

    i = 0;
    start = bpp * (x + y * app->width);
    while (i < texture->height)
    {
        memcpy(dest + start + i * app->width * bpp, texture->data + bpp * texture->width * i, bpp * texture->width);
        i++;
    }
}

int routine(void *data)
{
    // Prepare the data
    t_app       *app = (t_app *)(data);
    t_texture   *sprite = &(app->sprites);
	app->image_is_destroyed = 0;

	int         discard; // this one has no use but in mlx_get_data_addr requires an int
    void        *image_data;

    // create a buffer image
    app->image = mlx_new_image(app->mlx, app->width, app->height);
    image_data = mlx_get_data_addr(app->image, &discard, &discard, &discard);

    int x = app->game_state.player_x * sprite->width;
    int y = app->game_state.player_y * sprite->height;

    // draws the sprite in the buffer
    draw_sprite_at_position(app, image_data, sprite, x, y);

    // puts the buffer image in the windows
    mlx_put_image_to_window(app->mlx, app->window, app->image, 0, 0);
	mlx_destroy_image(app->mlx, app->image);
	app->image = NULL;
	app->image_is_destroyed = 1;
	return (0);
}

int    destroy_game_data(void *data)
{
	t_app *app = (t_app *)data;

	mlx_destroy_image(app->mlx, app->sprites.img);
	if (app->image_is_destroyed == 0)
		mlx_destroy_image(app->mlx, app->image);
	mlx_destroy_window(app->mlx, app->window);
	mlx_destroy_display(app->mlx);
    exit(0);
}

int    player_input(int keycode, void *data)
{
    t_app * app = (t_app *)(data);

    printf("key code %d \n", keycode);

    if (keycode == LEFT)
        app->game_state.player_x += -1;
    else if (keycode == RIGHT)
        app->game_state.player_x += 1;
    else if (keycode == DOWN)
        app->game_state.player_y += 1;
    else if (keycode == UP)
        app->game_state.player_y += -1;
    else if (keycode == ESC)
        destroy_game_data(app);


    // make sure the position is within the grid
    app->game_state.player_x = clamp(0, (app->width / app->sprites.width) - 1, app->game_state.player_x);
    app->game_state.player_y = clamp(0, (app->height / app->sprites.height) -1, app->game_state.player_y);

    // other checks etc...
    //
    //
    return 1;
}

int main()
{
    t_app app;

    // grid size * spite dimension
    init_app(&app, APP_NAME, GRID_SIZE_X, GRID_SIZE_Y);


    mlx_key_hook(app.window, &player_input, &app);
	mlx_hook(app.window, 17, 0, destroy_game_data, &app); // close window with mouse
	mlx_loop_hook(app.mlx, &routine, &app);
    mlx_loop(app.mlx);
}
