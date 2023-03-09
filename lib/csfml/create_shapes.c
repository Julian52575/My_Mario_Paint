/*
** EPITECH PROJECT, 2022
** add new data
** File description:
** get the data from the .rdr file
*/
#include "my_csfml.h"

sfRectangleShape *create_rectangle(int x_perimeter, int y_perimeter
, int x_position, int y_position)
{
    sfVector2f pos2 = {x_position, y_position};
    sfVector2f size = {x_perimeter, y_perimeter};
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect, pos2);

    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setOutlineColor(rect, sfBlack);
    return rect;
}

sfCircleShape *create_circle(int radius, int x_position, int y_position)
{
    sfVector2f pos = {x_position, y_position};
    sfCircleShape *circle = sfCircleShape_create();
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setPosition(circle, pos);

    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineThickness(circle, 3.01);
    sfCircleShape_setOutlineColor(circle, sfBlue);
    return circle;
}
