/*
** EPITECH PROJECT, 2022
** create
** File description:
** and render a window
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdlib.h>

sfRenderWindow * create_renderwindow(unsigned int x, unsigned int y
, unsigned int bpp, char *title)
{
    sfVideoMode video_mode = {x, y, bpp};
    sfRenderWindow *window = sfRenderWindow_create(video_mode, title, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setPosition(window, (sfVector2i) {0, 0} );
    return window;
}
