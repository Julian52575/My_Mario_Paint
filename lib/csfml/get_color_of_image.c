/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** get_color_of_image
*/
#include "my_paint.h"

//returns the color of pixel (x, y) of the current pattern
sfColor get_color_of_pattern(struct my_paint *paint,
unsigned int x, unsigned int y)
{
    sfColor lol = sfImage_getPixel (
        paint->pattern_list[paint->current_y][paint->current_x].image,
        x % 16,
        y % 16);
    return lol;
}
