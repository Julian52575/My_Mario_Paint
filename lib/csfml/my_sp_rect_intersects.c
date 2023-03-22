/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** my_sp_rect_intersects
*/
#include "my_csfml.h"
#include <stdbool.h>

bool my_sp_rect_intersects(sfSprite *sp, sfRectangleShape *rect)
{
    const sfFloatRect s = (const sfFloatRect) sfSprite_getGlobalBounds(sp);
    const sfFloatRect r = (const sfFloatRect)
                            sfRectangleShape_getGlobalBounds(rect);
    if (sfFloatRect_intersects(&s, &r, NULL) == sfTrue)
        return true;
    return false;
}
