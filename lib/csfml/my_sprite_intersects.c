/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** my_sprite_intersects
*/
#include "my_csfml.h"

bool my_sprite_intersects(sfSprite *sp1, sfSprite *sp2)
{
    const sfFloatRect tmp1 = (const sfFloatRect) sfSprite_getGlobalBounds(sp1);
    const sfFloatRect tmp2 = (const sfFloatRect) sfSprite_getGlobalBounds(sp2);

    if (sfFloatRect_intersects(&tmp1, &tmp2, NULL) == sfTrue)
        return true;
    return false;
}
