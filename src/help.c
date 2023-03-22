/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** help
*/
#include "my_paint.h"

void help(struct csfml_tools *ct, struct my_paint *paint)
{
    sfSprite *help = create_sprite("assets/h.jpg", 1, 1, NULL);
    sfRenderWindow_clear(ct->window, sfBlack);
    sfView_destroy(ct->view);
    ct->view = sfView_createFromRect( (sfFloatRect) {0, 0, 1920, 1080});
    sfView_setViewport(ct->view,
        (sfFloatRect) {0.0f, 0.1176f, 1.0f, 1.0f - 0.1176 * 2});
    while (sfKeyboard_isKeyPressed(sfKeyEscape) == sfFalse) {
        sfRenderWindow_display(ct->window);
        sfRenderWindow_setView(ct->window, ct->view);
        sfRenderWindow_drawSprite(ct->window, help, NULL);
        do_upper_menu(ct, paint);
        do_lower_menu(ct, paint);
    }
    my_sfsprite_destroy(help);
}
