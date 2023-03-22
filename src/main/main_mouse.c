/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** cursor
*/
#include "my_paint.h"
static void move_cursor(struct csfml_tools *ct, struct my_paint *paint)
{
    sfVector2i mouseWindow = sfMouse_getPositionRenderWindow(ct->window);
    if (mouseWindow.y < 117) {
        return;
    } else if (mouseWindow.y > 880) {
        return;
    }
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(
    (const sfRenderWindow *) ct->window,
    sfMouse_getPositionRenderWindow(ct->window), (const sfView *) ct->view);

    sfRectangleShape_setPosition(paint->cursor_hitbox,
        (sfVector2f) {mouse.x, mouse.y});
    sfSprite_setPosition(paint->cursor, (sfVector2f) {mouse.x, mouse.y} );
    sfRenderWindow_drawSprite(ct->window, paint->cursor, NULL);
}

void main_mouse(struct csfml_tools *ct, struct my_paint *paint)
{
    sfVector2f m = sfRenderWindow_mapPixelToCoords (
            (const sfRenderWindow *) ct->window,
            sfMouse_getPositionRenderWindow(ct->window),
            (const sfView *) ct->view );

    if ( (m.y > 0 && m.y < 1080) && (m.x > 0 && m.x < 1920) ) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            drawing(ct, paint, m);
            sfTexture_updateFromImage(paint->paper_texture,
                    paint->paper_sheet, 0, 0);
            sfSprite_setTexture(paint->paper_sprite,
                paint->paper_texture, sfFalse );
        }
    }
    return move_cursor(ct, paint);
}
