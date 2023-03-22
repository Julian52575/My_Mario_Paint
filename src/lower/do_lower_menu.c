/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** do_lower_menu
*/
#include "my_paint.h"

static void draw_lower_menu(struct csfml_tools *ct, struct my_paint *paint)
{
    for (int x = 0; x < 6; x++)
        sfRenderWindow_drawSprite(ct->window,
            paint->lower_list[0][x].sprite, NULL);
}

void do_lower_menu(struct csfml_tools *ct, struct my_paint *paint)
{
    sfRenderWindow_setView(ct->window, ct->lower_view);

    sfRenderWindow_drawRectangleShape(ct->window,
    paint->lower_background, NULL);
    sfRenderWindow_drawSprite(ct->window, paint->lower_help, NULL);
    sfRenderWindow_drawSprite(ct->window, paint->save_button, NULL);
    sfRenderWindow_drawSprite(ct->window, paint->preview_button, NULL);
    draw_lower_menu(ct, paint);
}
