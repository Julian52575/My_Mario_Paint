/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** main
*/
#include "my_paint.h"
#include <stdio.h>

static void user_interactions(struct csfml_tools *ct)
{
    while (sfRenderWindow_pollEvent(ct->window, &ct->event) == sfTrue) {
        if (ct->event.type == sfEvtClosed)
            return sfRenderWindow_close(ct->window);
    }

    if (sfKeyboard_isKeyPressed(sfKeySubtract) == sfTrue)
        sfRenderWindow_setView(ct->window, 
         sfRenderWindow_getDefaultView(ct->window)  );
}

static void move_cursor(struct csfml_tools *ct, struct my_paint *paint)
{
    sfRenderWindow_setView(ct->window, ct->view);
    sfVector2i mouse = sfMouse_getPosition( (const sfWindow *)
                        ct->window);

    if (sfMouse_isButtonPressed (sfMouseLeft) )
            printf("-> Mouse position relative to window is (%d, %d)\n", mouse.y, mouse.x);

    if (mouse.y <= 127.01) {
        sfRenderWindow_setView(ct->window, ct->upper_view);
        mouse.y -= 400;
    } else if (mouse.y >= 890) {
        sfRenderWindow_setView(ct->window, ct->lower_view);
        mouse.y -= 1080;
    }

    if (sfMouse_isButtonPressed (sfMouseLeft) )
            printf("Actual mouse position is (%d, %d)\n", mouse.y, mouse.x);


    sfSprite_setPosition(paint->cursor, (sfVector2f) {mouse.x, mouse.y} );
    sfRenderWindow_drawSprite(ct->window, paint->cursor, NULL);
}

int main(int ac, char **av)
{
    //mapCoordsToPixel
    //mapPixelToCoords

    struct my_paint *paint = create_paint();
    if (!paint)
        return 84;
    struct csfml_tools *ct = create_ct("my_mario_paint");
    if (!ct)
        return 84;

    while (sfRenderWindow_isOpen(ct->window)) {
        update_ct_time(ct);
        sfRenderWindow_display(ct->window);
        sfRenderWindow_clear(ct->window, sfWhite);

        do_upper_menu(ct, paint);
        do_lower_menu(ct, paint);
        do_main(ct);

        move_cursor(ct, paint);
        user_interactions(ct);
    }

    free_ct(ct);
    free_paint(paint);
    return 0;
}

//1080 * 0.1176 == 127.01
