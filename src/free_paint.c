/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** free_paint
*/
#include "my_paint.h"


static void free_upper_paint(struct my_paint *paint)
{
    sfRectangleShape_destroy(paint->upper_background);
    my_sfsprite_destroy(paint->movie_wheel);

    for (int y = 0; y < 14; y++) {
        for (int x = 0; x < 15; x++) {
            my_sfsprite_destroy(paint->upper_list[y][x].sprite );
            sfImage_destroy(paint->pattern_list[y][x].image);
            sfTexture_destroy(paint->pattern_list[y][x].texture);
        }
        free(paint->upper_list[y]);
        free(paint->pattern_list[y]);
    }
    free(paint->upper_list);
    free(paint->pattern_list);
    my_sfsprite_destroy(paint->save);
    my_sfsprite_destroy(paint->quit);
    free(paint->file_name);
    sfFont_destroy(paint->font);
    sfText_destroy(paint->file_name_t);
}

static void free_lower_paint(struct my_paint *paint)
{
    my_sfsprite_destroy(paint->lower_help);
    sfRectangleShape_destroy(paint->lower_background);
    my_sfsprite_destroy(paint->save_button);

    for (int x = 0; x < 6; x++)
        my_sfsprite_destroy(paint->lower_list[0][x].sprite);
    free(paint->lower_list[0]);
    free(paint->lower_list);
}

void free_paint(struct my_paint *paint)
{
    free_upper_paint(paint);
    free_lower_paint(paint);
    my_sfsprite_destroy(paint->cursor);
    sfRectangleShape_destroy(paint->cursor_hitbox);
    free(paint);
}
