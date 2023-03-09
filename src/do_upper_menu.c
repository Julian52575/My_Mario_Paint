/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** do_upper_menu
*/
#include "my_paint.h"

static void menu_interaction(struct csfml_tools *ct,
struct my_paint *paint)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
        && ct->event_buffer > 0.2) {
            if (my_sprite_intersects(paint->cursor, paint->upper_gugus) == true) {
                paint->upper_id += paint->upper_id >= 14 ? -14 : 1;
                sfIntRect rect = sfSprite_getTextureRect(paint->upper_gugus);
                rect.top = paint->upper_id * 15 + paint->upper_id;
                sfSprite_setTextureRect(paint->upper_gugus, rect);
                ct->event_buffer = 0.0;
            }
    }
}

void do_upper_menu(struct csfml_tools *ct, struct my_paint *paint)
{

    sfView_setViewport(ct->upper_view,
    (sfFloatRect) {0.0f, 0.0f, 1.0f, 0.1176f} );
    sfRenderWindow_setView(ct->window, ct->upper_view);

    sfRenderWindow_drawRectangleShape(ct->window,
    paint->upper_background, NULL);
    sfRenderWindow_drawSprite(ct->window, paint->movie_wheel, NULL);
    sfRenderWindow_drawSprite(ct->window, paint->upper_gugus, NULL);
    for (int x = 0; x < 15; x++)
        sfRenderWindow_drawSprite(ct->window,
                paint->upper_list[paint->upper_id][x].sprite , NULL);
    
    menu_interaction(ct, paint);
}
