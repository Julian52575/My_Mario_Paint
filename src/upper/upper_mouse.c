/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** upper_mouse
*/
#include "my_paint.h"

static void set_image_behind_movie_wheel(struct my_paint *paint)
{
    sfSprite_setTexture(paint->behind_movie_wheel,
    paint->pattern_list[paint->current_y][paint->current_x].texture, sfTrue);
}

static void button_pressed(struct my_paint *paint, int x)
{
    paint->current_y = paint->upper_id;
    paint->current_x = x;
    set_image_behind_movie_wheel(paint);
    sfIntRect c = sfSprite_getTextureRect(paint->cursor);
    c.top = 32 * x;
    sfSprite_setTextureRect(paint->cursor, c);
}

static void lol(struct csfml_tools *ct, struct my_paint *paint)
{
    if (my_sp_rect_intersects(paint->upper_gugus, paint->cursor_hitbox)
    == true) {
        paint->upper_id += paint->upper_id >= 13 ? -13 : 1;
        sfIntRect rect = sfSprite_getTextureRect(paint->upper_gugus);
        rect.top = paint->upper_id * 15 + paint->upper_id;
        sfSprite_setTextureRect(paint->upper_gugus, rect);
        ct->event_buffer = 0.0;
    }
    for (int x = 0; x < 15; x++) {
        if (my_sp_rect_intersects(
        paint->upper_list[paint->upper_id][x].sprite, paint->cursor_hitbox )
        == true) {
            button_pressed(paint, x);
            break;
        }
    }
}

void upper_mouse(struct csfml_tools *ct, struct my_paint *paint)
{
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(
        (const sfRenderWindow *) ct->window,
        sfMouse_getPositionRenderWindow(ct->window),
        (const sfView *) ct->upper_view);
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
    && ct->event_buffer > 0.2) {
        lol(ct, paint);
    }

    sfSprite_setPosition(paint->cursor, mouse);
    sfRectangleShape_setPosition(paint->cursor_hitbox, mouse);
    sfRenderWindow_setView(ct->window, ct->upper_view);
    sfRenderWindow_drawSprite(ct->window, paint->cursor, NULL);
}
