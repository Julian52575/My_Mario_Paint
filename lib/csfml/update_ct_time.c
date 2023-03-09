/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** update_ct_time
*/
#include "my_csfml.h"

void update_ct_time(struct csfml_tools *ct)
{
    ct->time = sfClock_getElapsedTime(ct->clock);
    ct->time_buffer += ct->time.microseconds / 1000000.0;
    ct->event_buffer += ct->time.microseconds / 1000000.0;
    ct->mouvement_buffer += ct->time.microseconds / 1000000.0;
    ct->sound_buffer += ct->time.microseconds / 1000000.0;
    ct->player_animation_buffer += ct->time.microseconds / 1000000.0;
    sfClock_restart(ct->clock);
}
