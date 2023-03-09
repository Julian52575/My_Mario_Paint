/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** free_ct
*/
#include "my_paint.h"

void free_ct(struct csfml_tools *ct)
{
    sfRenderWindow_destroy(ct->window);
    sfClock_destroy(ct->clock);
    sfView_destroy(ct->view);
    sfView_destroy(ct->upper_view);
    sfView_destroy(ct->lower_view);
    free(ct);
}
