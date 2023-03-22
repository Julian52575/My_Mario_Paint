/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** create_paint
*/
#include "my_paint.h"

struct my_paint *create_paint(unsigned int width, unsigned int height)
{
    struct my_paint *paint = malloc(sizeof(struct my_paint));
    if (!paint)
        return NULL;
    paint->drawing_board = create_sprite("assets/mario_paint_artwork.png",
    2, 2, NULL);
    sfSprite_setPosition(paint->drawing_board, (sfVector2f) {-300, -200});
    paint->image_height = height;
    paint->image_width = width;
    paint->pen_type = SMALL;
    create_upper_menu(paint);
    create_lower_menu(paint);
    paint->cursor = create_sprite("assets/Cursors.png", 3, 3, NULL);
    sfSprite_setTextureRect(paint->cursor, (sfIntRect) {0, 0, 16, 16} );
    paint->cursor_hitbox = create_rectangle(1, 1, 0, 0);
    sfRectangleShape_setFillColor(paint->cursor_hitbox, sfTransparent);
    paint->paper_sheet = sfImage_createFromColor(width, height, sfWhite);
    paint->paper_texture = sfTexture_createFromImage(paint->paper_sheet, NULL);
    paint->paper_sprite = create_sprite(NULL, 1, 1, NULL);
    sfSprite_setTexture(paint->paper_sprite, paint->paper_texture, sfFalse);
    return paint;
}
