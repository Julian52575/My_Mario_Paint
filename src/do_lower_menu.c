/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** do_lower_menu
*/
#include "my_paint.h"

void do_lower_menu(struct csfml_tools *ct, struct my_paint *paint)
{
    sfView_setViewport(ct->lower_view,
    (sfFloatRect) {0.0f, 1.0f - 0.1176f, 1.0f, 0.1176f } );
    sfRenderWindow_setView(ct->window, ct->lower_view);

    sfRenderWindow_drawRectangleShape(ct->window,
    paint->lower_background, NULL);
    sfRenderWindow_drawSprite(ct->window, paint->lower_arrow, NULL);
}
