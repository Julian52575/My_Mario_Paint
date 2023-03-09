/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** do_main
*/
#include "my_paint.h"

void do_main(struct csfml_tools *ct)
{
    sfView_setViewport(ct->view,
    (sfFloatRect) {0.0f, 0.1176f, 1.0f, 1.0f - 0.1176f * 2} );
    sfRenderWindow_setView(ct->window, ct->view);
}
