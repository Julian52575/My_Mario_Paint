/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** create_upper_paint
*/
#include "my_paint.h"


static void create_pattern(struct my_paint *paint, int y, int x)
{
    char *str_x = my_int_to_str(x);
    char *str_y = my_int_to_str(y);

    char *id = my_str_combine(str_y, str_x, '-');
    char *name = my_str_combine("assets/patterns/p", id, '\0');
    char *full = my_str_combine(name, ".png", '\0');
    write(1, "-> loaded ", 11);
    write(1, full, strlen(full));
    write(1, "\n", 1);
    paint->pattern_list[y][x].image = sfImage_createFromFile(full);
    if (paint->pattern_list[y][x].image)
        paint->pattern_list[y][x].texture =
            sfTexture_createFromImage( paint->pattern_list[y][x].image, NULL);
    free(str_x);
    free(str_y);
    free(id);
    free(name);
    free(full);
}

static void create_upper_buttons(struct my_paint *paint)
{
    paint->upper_list = malloc(sizeof(struct upper_buttons *) * 16);
    paint->pattern_list = malloc(sizeof(struct pattern * ) * 16);
    int y = 0;
    for (; y < 14; y++) {
        paint->upper_list[y] = malloc(sizeof(struct upper_buttons) * 16);
        paint->pattern_list[y] = malloc(sizeof(struct pattern) * 16);
        int x = 0;
        for (; x < 15; x++) {
            sfSprite_setPosition(
                ( (paint->upper_list[y][x]).sprite =
                    create_sprite("assets/upper_buttons.png", 6, 6,
                        &((sfIntRect) {.top = y * 15 + y, .left = x * 14,
                        .width = 14, .height = 15}) )
                ), (sfVector2f) {300 + (15 * 6) * x, -385} );
        create_pattern(paint, y, x);
        }
    }
}

static void create_upper_gugus(struct my_paint *paint)
{
    sfSprite_setPosition(
        (paint->upper_gugus =
        create_sprite("assets/upper_buttons.png", 6, 6, NULL)
        ), (sfVector2f) {1800, -385} );
    sfSprite_setTextureRect(paint->upper_gugus, (sfIntRect)
            {.top = 0, .left = 212, .width = 18, .height = 15 } );
}

static void create_saving_menu(struct my_paint *paint)
{
    paint->file_name = malloc(sizeof(char) * 50);
    for (int i = 0; i < 50; i++)
        paint->file_name[i] = '\0';
    paint->font = sfFont_createFromFile("assets/Super-Mario-World.ttf");
    paint->save = create_sprite("assets/save.png", 2, 2, NULL);
    sfSprite_setPosition(paint->save, (sfVector2f) {1786, -400} );
    paint->quit = create_sprite("assets/quit.png", 2, 2, NULL);
    sfSprite_setPosition(paint->quit, (sfVector2f) {40, -400} );
    paint->file_name_i = 0;
    paint->file_name_t = sfText_create();
    sfText_setFont(paint->file_name_t, paint->font);
    sfText_setColor(paint->file_name_t, sfWhite);
    sfText_setPosition(paint->file_name_t, (sfVector2f) {300, -360} );
}

void create_upper_menu(struct my_paint *paint)
{
    paint->upper_background = create_rectangle(1920, 200, -0, -400);
    sfRectangleShape_setFillColor( paint->upper_background,
    sfColor_fromRGB(150, 70, 160));
    create_upper_buttons(paint);
    paint->movie_wheel = create_sprite("assets/movie_wheel.png", 6, 6, NULL);
    sfSprite_setPosition(paint->movie_wheel, (sfVector2f) {40, -385} );
    paint->behind_movie_wheel = create_sprite(NULL, 6.2, 6, NULL);
    create_upper_gugus(paint);
    sfSprite_setPosition(paint->behind_movie_wheel, (sfVector2f) {55, -385});
    sfSprite_setTexture(paint->behind_movie_wheel,
        paint->pattern_list[0][0].texture, sfFalse );
    paint->upper_id = 0;
    paint->current_y = 0;
    paint->current_x = 0;
    create_saving_menu(paint);
}
