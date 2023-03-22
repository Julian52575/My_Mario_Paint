/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** do_main
*/
#include "my_paint.h"

//draw stuff on the main view and, if a imput is detected, calls the others fun
void do_main(struct csfml_tools *ct, struct my_paint *paint)
{
    sfRenderWindow_setView(ct->window, ct->view);
    sfRenderWindow_drawSprite(ct->window, paint->drawing_board, NULL);
    sfRenderWindow_drawSprite(ct->window, paint->paper_sprite, NULL);
} //These functions deals with the main window // the drawing window
