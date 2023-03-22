/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** main
*/
#include "my_paint.h"
#include <stdio.h>

static void moving(struct csfml_tools *ct)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
        sfView_move(ct->view, (sfVector2f) {5, 0});
    } else if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
        sfView_move(ct->view, (sfVector2f) {-5, 0});
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
        sfView_move(ct->view, (sfVector2f) {0, -5});
    } else if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
        sfView_move(ct->view, (sfVector2f) {0, 5});
    }
}

static void zooming(struct csfml_tools *ct)
{
    if (sfKeyboard_isKeyPressed(sfKeySubtract) == sfTrue) {
        sfView_zoom(ct->view, 1.01);
    } else if (sfKeyboard_isKeyPressed(sfKeyAdd) == sfTrue) {
        sfView_zoom(ct->view, 0.99);
    }
}

static void user_interactions(struct csfml_tools *ct)
{
    while (sfRenderWindow_pollEvent(ct->window, &ct->event) == sfTrue) {
        if (ct->event.type == sfEvtClosed)
            return sfRenderWindow_close(ct->window);
    }
    if (ct->mouvement_buffer > 0.02) {
        moving(ct);
        zooming(ct);
        ct->mouvement_buffer = 0.0;
    }
}

static void loop(struct csfml_tools *ct, struct my_paint *paint)
{
    write(1, "\n", 1);
    sfRenderWindow_mapPixelToCoords(ct->window,
            sfMouse_getPositionRenderWindow(ct->window), ct->view);
    while (sfRenderWindow_isOpen(ct->window)) {
        update_ct_time(ct);
        sfRenderWindow_display(ct->window);
        sfRenderWindow_clear(ct->window, sfBlack);

        do_upper_menu(ct, paint);
        do_lower_menu(ct, paint);
        do_main(ct, paint);

        mouse(ct, paint);
        user_interactions(ct);
    }
}

int main(int ac, char **av)
{
    if (ac > 1 && my_str_compare(av[1], "-h") == 1) {
        write(1, "click on the '?' block !\n", 25);
        return 0;
    }
    struct my_paint *paint = create_paint(1920, 1080);
    if (!paint)
        return 84;
    struct csfml_tools *ct = create_ct("my_mario_paint");
    if (!ct)
        return 84;

    loop(ct, paint);
    free_ct(ct);
    free_paint(paint);
    return 0;
}
