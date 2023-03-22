/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** my_destroy
*/
#include "my_csfml.h"

void my_sfsprite_destroy(sfSprite *sprite)
{
    sfTexture_destroy( (sfTexture *)
            sfSprite_getTexture(sprite));
    sfSprite_destroy(sprite);
}
