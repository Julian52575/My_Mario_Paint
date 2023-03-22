/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** drawing
*/
#include "my_paint.h"
#include "time.h"
#include <stdlib.h>

static void draw_tag(struct csfml_tools *ct, struct my_paint *paint,
unsigned int x, unsigned int y)
{
    for (int i = 0; i < 48; i++) {
        unsigned int j = rand() % 16;
        unsigned int i = rand() % 16;
        if (x + i > paint->image_width - 1)
            return;
        if (y + j > paint->image_height - 1)
            return;

        sfImage_setPixel(paint->paper_sheet,
            x + i, y + j, get_color_of_pattern(paint, x + i, y + j));
        if (i % 10 == 0) {
            sfTexture_updateFromImage(paint->paper_texture,
                paint->paper_sheet, 0, 0);
            sfSprite_setTexture(paint->paper_sprite,
                paint->paper_texture, sfFalse );
            sfRenderWindow_drawSprite(ct->window, paint->paper_sprite, NULL);
        }
    }
}

//update the image, texture and sprite of the paper sheet
static void draw_pencil(struct my_paint *paint,
unsigned int x, unsigned int y)
{
    if (y > paint->image_height - 1)
        return;

    for (unsigned int i = 0; i <= (paint->pen_type * 20) + 5; i++) {
        if (x + i > paint->image_width - 1)
            return;
        sfImage_setPixel(paint->paper_sheet,
            x + i, y, get_color_of_pattern(paint, x + i, y));
    }
}

static void draw_stamp(struct my_paint *paint, sfVector2f m)
{
    sfImage_copyImage 	( paint->paper_sheet,
        (const sfImage *) paint->pattern_list
                                [paint->current_y][paint->current_x].image,
        m.x,
        m.y,
        (sfIntRect) {0, 0, 16, 16},
        sfTrue );
}

static void draw_eraser(struct my_paint *paint, unsigned int x, unsigned int y)
{
    if (y > paint->image_height - 1)
        return;
    for (int i = 0; i <= 16 * 3; i++) {
        if (x + i > paint->image_width - 1)
            return;
        sfImage_setPixel(paint->paper_sheet, x + i, y, sfTransparent);
    }
}

void drawing(struct csfml_tools *ct,
struct my_paint *paint, sfVector2f m)
{
    switch (paint->pen_type) {
        case (STAMP):
            draw_stamp(paint, m);
            break;
        case (TAG):
            srand(time(NULL));
            draw_tag(ct, paint, (unsigned int) m.x, (unsigned int) m.y);
            break;
        case (ERASER):
            for (unsigned int j = 0; j < 15 * 3; j++)
                draw_eraser(paint, (unsigned int) m.x, (unsigned int) m.y + j);
            break;
        default:
            for (unsigned int j = 0; j < (paint->pen_type * 20) + 5; j++)
                draw_pencil(paint,
                    (unsigned int) m.x, (unsigned int) m.y + j);
            break;
    }
}
