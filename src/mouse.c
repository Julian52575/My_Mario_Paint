/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** cursor
*/
#include "my_paint.h"

void mouse(struct csfml_tools *ct, struct my_paint *paint)
{
    if (sfRenderWindow_hasFocus((const sfRenderWindow *)ct->window) == sfFalse)
        return;
    sfVector2i mouseWindow = sfMouse_getPositionRenderWindow(ct->window);
    if (mouseWindow.y < 117) {
        upper_mouse(ct, paint);
        return;
    }
    if (mouseWindow.y > 880) {
        lower_mouse(ct, paint);
        return;
    }
    main_mouse(ct, paint);
}
