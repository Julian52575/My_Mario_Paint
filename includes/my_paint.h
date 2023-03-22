/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** my_paint
*/

#pragma once


#include <stdbool.h>
#include <stdio.h>
#include "my_csfml.h"
#include "my.h"

typedef enum {SMALL, MEDIUM, LARGE, STAMP, TAG, ERASER} PENCIL;

struct upper_buttons {
    sfSprite *sprite;
    unsigned short state;
};

struct lower_buttons {
    sfSprite *sprite;
    bool selected;
};

struct pattern {
    sfImage *image;
    sfTexture *texture;
};

typedef void (*drawing_function)
    (struct csfml_tools *ct, void * *paint, sfVector2f m);

struct my_paint {
    sfSprite *drawing_board;
    unsigned int image_width;
    unsigned int image_height;
    PENCIL pen_type;

    sfRectangleShape *upper_background;
    struct upper_buttons **upper_list;
    struct pattern **pattern_list;
    sfSprite *movie_wheel;
    sfSprite *behind_movie_wheel;
    sfSprite *upper_gugus;
    sfSprite *save;
    sfSprite *quit;
    sfFont *font;
    char *file_name;
    sfText *file_name_t;
    unsigned short file_name_i;

    sfRectangleShape *lower_background;
    sfSprite *lower_help;
    struct lower_buttons **lower_list;
    sfSprite *save_button;
    sfSprite *preview_button;

    sfSprite *cursor;
    sfTexture *cursor_texture;
    sfRectangleShape *cursor_hitbox;

    sfImage *paper_sheet;
    sfTexture *paper_texture;
    sfSprite *paper_sprite;
    unsigned short upper_id;
    unsigned short current_y;
    unsigned short current_x;
};

struct my_paint *create_paint(unsigned int height, unsigned int width);
void free_paint(struct my_paint *paint);

void create_upper_menu(struct my_paint *paint);
void create_lower_menu(struct my_paint *paint);

void do_upper_menu(struct csfml_tools *ct, struct my_paint *paint);
void do_lower_menu(struct csfml_tools *ct, struct my_paint *paint);
void do_main(struct csfml_tools *ct, struct my_paint *paint);

void mouse(struct csfml_tools *ct, struct my_paint *paint);
void lower_mouse(struct csfml_tools *ct, struct my_paint *paint);
void upper_mouse(struct csfml_tools *ct, struct my_paint *paint);
void main_mouse(struct csfml_tools *ct, struct my_paint *paint);

void drawing(struct csfml_tools *ct,
struct my_paint *paint, sfVector2f m);
sfColor get_color_of_pattern(struct my_paint *paint,
unsigned int x, unsigned int y);

void saving(struct csfml_tools *ct, struct my_paint *paint);
void help(struct csfml_tools *ct, struct my_paint *paint);
