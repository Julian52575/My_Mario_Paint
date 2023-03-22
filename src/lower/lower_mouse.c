/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** lower_mouse
*/
#include "my_paint.h"

static void reset_buttons(struct my_paint *paint, int start)
{
    for (int i = 1; start - i >= 0; i++)
        paint->lower_list[0][start - i].selected = false;
    for (int i = 1; start + i < 6; i++)
        paint->lower_list[0][start + i].selected = false;
}

static void button_pressed(struct my_paint *paint, int x)
{
    sfSprite_setTextureRect(paint->lower_list[0][x].sprite,
        (sfIntRect) {.top = 38, .left = 0, .width = 16, .height = 19});
    reset_buttons(paint, x);
    paint->lower_list[0][x].selected = true;

    paint->pen_type = x;

    sfIntRect c = sfSprite_getTextureRect(paint->cursor);
    c.left = 16 * x;
    sfSprite_setTextureRect(paint->cursor, c);
}

static void button_check2(struct my_paint *paint, int x)
{
    if (my_sp_rect_intersects(
    paint->lower_list[0][x].sprite, paint->cursor_hitbox) == true ) {

        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            button_pressed(paint, x);
        } else {
            sfSprite_setTextureRect(paint->lower_list[0][x].sprite,
                (sfIntRect) {.top = 19, .left = 0, .width = 16, .height = 19});
        }

    } else {
        sfSprite_setTextureRect(paint->lower_list[0][x].sprite,
            (sfIntRect) {.top = 0, .left = 0, .width = 16, .height = 19} );
    }

}

static void button_check(struct csfml_tools *ct, struct my_paint *paint)
{
    for (int x = 0; x < 6; x++) {
        if (paint->lower_list[0][x].selected == false)
            button_check2(paint, x);
    }

    if (my_sp_rect_intersects(paint->lower_help, paint->cursor_hitbox) == true
    && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        help(ct, paint);

    if (my_sp_rect_intersects(paint->save_button,
    paint->cursor_hitbox) == true) {
        sfSprite_setTextureRect(paint->save_button,
        (sfIntRect) {.top = 19, .left = 0, .width = 16, .height = 19});
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            saving(ct, paint);
    } else {
        sfSprite_setTextureRect(paint->save_button,
        (sfIntRect) {.top = 0, .left = 0, .width = 16, .height = 19});
    }
}

void lower_mouse(struct csfml_tools *ct, struct my_paint *paint)
{
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(
            (const sfRenderWindow *) ct->window,
            sfMouse_getPositionRenderWindow(ct->window),
            (const sfView *) ct->upper_view
            );
    mouse.y -= 750;
    sfSprite_setPosition(paint->cursor, mouse);
    sfRectangleShape_setPosition(paint->cursor_hitbox, mouse);
    sfRenderWindow_setView(ct->window, ct->lower_view);
    sfRenderWindow_drawSprite(ct->window, paint->cursor, NULL);
    button_check(ct, paint);
    preview(ct, paint);
}
