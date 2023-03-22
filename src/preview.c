/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** preview
*/
#include "my_paint.h"

static void preview_loop(struct csfml_tools *ct, struct my_paint *paint)
{
    sfView_destroy(ct->view);
    ct->view = sfView_createFromRect( (sfFloatRect) {0, 0, 1920, 1080});
    sfView_setViewport(ct->view,
        (sfFloatRect) {0.0f, 0.1176f, 1.0f, 1.0f - 0.1176 * 2});
    sfView_zoom(ct->view, 1.42);
}

void preview(struct csfml_tools *ct, struct my_paint *paint)
{
    if (my_sp_rect_intersects(paint->preview_button, paint->cursor_hitbox)
    == true) {
        sfSprite_setTextureRect(paint->preview_button,
        (sfIntRect) {.top = 19, .left = 0, .width = 16, .height = 19});
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            sfSprite_setTextureRect(paint->preview_button,
            (sfIntRect) {.top = 38, .left = 0, .width = 16, .height = 19});
            preview_loop(ct, paint);
        }
    } else {
        sfSprite_setTextureRect(paint->save_button,
        (sfIntRect) {.top = 0, .left = 0, .width = 16, .height = 19});
    }
}
