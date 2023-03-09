/*
** EPITECH PROJECT, 2022
** main
** File description:
** main for my radar
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>
#include <stdio.h>
#include "my_csfml.h"

struct csfml_tools *create_ct(char *name)
{
    struct csfml_tools *ct = malloc(sizeof(struct csfml_tools) );
    if (!ct)
        return NULL;
    ct->window = create_renderwindow(1920, 1080, 32, name);
    ct->clock = sfClock_create();
    ct->time = sfClock_getElapsedTime( ct->clock);
    ct->time_buffer = 0.0;
    ct->event_buffer = 0.0;
    ct->mouvement_buffer = 0.0;
    ct->player_animation_buffer = 0.0;
    ct->view = sfView_createFromRect( (sfFloatRect) {0, 0, 1920, 1080});
    ct->upper_view = sfView_createFromRect( (sfFloatRect) {0, -400, 1920,
            1080 * 0.1176} );
    ct->lower_view = sfView_createFromRect( (sfFloatRect) {0, -200, 1920,
            1080 * 0.1176} ); 
    return ct;
}
