/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** saving
*/
#include "my_paint.h"

static void do_upper_saving_menu(struct csfml_tools *ct,
struct my_paint *paint)
{
    update_ct_time(ct);
    sfRenderWindow_display(ct->window);
    do_main(ct, paint);
    do_lower_menu(ct, paint);

    sfRenderWindow_setView(ct->window, ct->upper_view);
    if (my_strlen(paint->file_name) ) {
        sfText_setString(paint->file_name_t, paint->file_name);
    } else {
        sfText_setString(paint->file_name_t, "enter your file name here");
    }

    sfRenderWindow_drawRectangleShape(ct->window,
        paint->upper_background, NULL);
    sfRenderWindow_drawText(ct->window, paint->file_name_t, NULL);
    sfRenderWindow_drawSprite(ct->window, paint->save, NULL);
    sfRenderWindow_drawSprite(ct->window, paint->quit, NULL);
}

static bool file_name_entering(struct csfml_tools *ct, struct my_paint *paint)
{
    while (sfKeyboard_isKeyPressed(sfKeyEscape) == sfFalse
    && sfKeyboard_isKeyPressed(sfKeyEnter) == sfFalse
    && sfRenderWindow_hasFocus(ct->window) == sfTrue) {
        do_upper_saving_menu(ct, paint);
        while (sfRenderWindow_pollEvent(ct->window, &ct->event) == sfTrue
        && ct->event.type == sfEvtTextEntered
        && paint->file_name_i < 48 && ct->event_buffer > 0.01) {
            paint->file_name[paint->file_name_i++] = ct->event.text.unicode;
            paint->file_name[paint->file_name_i] = '\0';
            ct->event_buffer = 0.0;
        } if (sfKeyboard_isKeyPressed(sfKeyBack) == sfTrue
        && paint->file_name_i > 0 && ct->event_buffer > 0.1) {
            paint->file_name[paint->file_name_i--] = '\0';
            ct->event_buffer = 0.0;
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyEnter) == sfTrue)
        return true;
    return false;
}

void saving(struct csfml_tools *ct, struct my_paint *paint)
{
    sfRenderWindow_clear(ct->window, sfBlack);

    if (file_name_entering(ct, paint) == true
    && my_strlen(paint->file_name) > 0) {
        char *full = my_str_combine(paint->file_name, "jpg", '.');
        write(1, "-saving ", 8);
        write(1, full, my_strlen(full));
        write(1, "\n", 1);
        sfImage_saveToFile(paint->paper_sheet, full);
        free(full);
    }
}
