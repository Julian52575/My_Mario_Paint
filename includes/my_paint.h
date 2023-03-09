/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** my_paint
*/

#include <stdbool.h>
#include <stdio.h>
#include "my_csfml.h"
#include "my.h"

enum state { HOVER, PRESSED, CLICKED };

struct pattern {
    sfImage *pattern;
};

struct upper_buttons {
    sfSprite *sprite;
    unsigned short state;
    
};

struct my_paint {
    sfRectangleShape *upper_background;
    struct upper_buttons **upper_list;
    sfImage **pattern_list;
    sfSprite *movie_wheel;

    sfSprite *upper_gugus;
    sfRectangleShape *upper_border;
 
    //
    sfRectangleShape *lower_background;
    sfSprite *lower_arrow;
    //
    sfSprite *cursor;
    //
    unsigned short upper_id;
    sfImage *current_pattern;
    unsigned short current_color;  // (y * 15) + x
};

struct my_paint *create_paint(void);
void free_paint(struct my_paint *paint);

void do_upper_menu(struct csfml_tools *ct, struct my_paint *paint);
void do_lower_menu(struct csfml_tools *ct, struct my_paint *paint);
void do_main(struct csfml_tools *ct);
