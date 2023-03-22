/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** do_upper_menu
*/
#include "my_paint.h"

void do_upper_menu(struct csfml_tools *ct, struct my_paint *paint)
{
    sfRenderWindow_setView(ct->window, ct->upper_view);

    sfRenderWindow_drawRectangleShape(ct->window,
    paint->upper_background, NULL);
    sfRenderWindow_drawSprite(ct->window, paint->upper_gugus, NULL);
    for (int x = 0; x < 15; x++)
        sfRenderWindow_drawSprite(ct->window,
                paint->upper_list[paint->upper_id][x].sprite , NULL);

    sfRenderWindow_drawSprite(ct->window, paint->behind_movie_wheel, NULL);
    sfRenderWindow_drawSprite(ct->window, paint->movie_wheel, NULL);
}
