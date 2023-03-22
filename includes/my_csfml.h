/*
** EPITECH PROJECT, 2022
** my csfml.h
** File description:
** all the prototypes (and structs ?) for my csfml projects
*/
#pragma once

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>
#include <stdbool.h>

sfRectangleShape *create_rectangle(int x_perimeter, int y_perimeter
, int x_position, int y_position);

sfCircleShape *create_circle(int radius, int x_position, int y_position);

sfSprite *create_sprite(char *image_path, float x_scale,
float y_scale, sfIntRect *rect);
sfSprite *create_sprite_from_texture(sfImage *image);

sfSound *create_sound(char *file_path);
sfIntRect create_texture_rect(int width, int height, int x, int y);
sfText *create_text(char *str, char *font_file, unsigned int size);

sfIntRect update_texture_rect(sfSprite *sp, int x, int y);

float get_angle(sfVector2f vector1, sfVector2f vector2);
float produit_scalaire(sfVector2f U, sfVector2f V, int abs);
int two_vector_colision(sfVector2f v, sfVector2f u);

bool my_sprite_intersects(sfSprite *sp1, sfSprite *sp2);
bool my_sp_rect_intersects(sfSprite *sp, sfRectangleShape *rect);

void my_sfsprite_destroy(sfSprite *sprite);

struct chained_sprites {
    sfSprite *entity;
    sfIntRect rect;
    int hidden;
    char name;
    struct chained_sprites *next;
};
typedef struct chained_sprites csprites;

struct chained_text {
    sfText *entity;
    int hidden;
    struct chained_text *next;
};
typedef struct chained_text ctext;

struct chained_menu {
    sfSprite *entity;
    sfIntRect rect;
    sfMusic *music;
    csprites *cs;
    ctext *ct;
    char name;
    struct chained_menu *next;
};
typedef struct chained_menu cmenu;

struct csfml_tools {
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
    sfTime time;
    float time_buffer;
    float event_buffer;
    float mouvement_buffer;
    float sound_buffer;
    float player_animation_buffer;
    sfView *view;
    sfView *upper_view;
    sfView *lower_view;
    sfRectangleShape *debug;
};

struct csfml_tools *create_ct(char *name);
sfRenderWindow * create_renderwindow(unsigned int x, unsigned int y
, unsigned int bpp, char *title);
void free_ct(struct csfml_tools *ct);

void update_ct_time(struct csfml_tools *ct);

void create_icon(sfRenderWindow *window, char *image_path);

int display_chained_text(sfRenderWindow *window, ctext *ct);
int display_chained_sprites(sfRenderWindow *window, csprites *cs);

void create_blank_sprite(sfSprite *blank);
void create_black_sprite(sfSprite *blank);
sfSprite *create_background_sprite(void);

int is_txt(void);

void reverse_visible(csprites *cs, ctext *ct);
void reverse_visible_sprites(csprites *cs);
void reverse_visible_text(ctext *ct);

int destroy_chained_sprites(csprites *cs);
