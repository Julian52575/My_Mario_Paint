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
    my_sfSprite_destroy(paint->movie_wheel); 

    for (int y = 0; y < 15; y++) {
        for (int x = 0; x < 15; x++) {
            my_sfSprite_destroy(paint->upper_list[y][x].sprite );
        }
        free(paint->upper_list[y]);
    }
    free(paint->upper_list);
}

static void free_lower_paint(struct my_paint *paint)
{
    my_sfSprite_destroy(paint->lower_arrow);
    sfRectangleShape_destroy(paint->lower_background);
}

void free_paint(struct my_paint *paint)
{
    free_upper_paint(paint);
    free_lower_paint(paint);
    my_sfSprite_destroy(paint->cursor);
   	free(paint);
    
}
