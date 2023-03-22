/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** create_lower_paint
*/
#include "my_paint.h"

static void get_assets(struct my_paint *paint, int x)
{
    char *str_x = my_int_to_str(x);

    char *id = my_str_combine("assets/lower_buttons/b0-", str_x, '\0');

    char *file = my_str_combine(id, ".png", '\0');
    write(1, "-> loaded ", 10);
    write(1, file, strlen(file));
    write(1, "\n", 1);
    paint->lower_list[0][x].sprite =
        create_sprite(file, 6, 6, NULL);

    free(str_x);
    free(id);
    free(file);
}

static void create_lower_buttons(struct my_paint *paint)
{
    paint->lower_list = malloc(sizeof(struct lower_buttons*) * 2);
    paint->lower_list[0] = malloc(sizeof(struct lower_buttons) * 7 );

    for (int x = 0; x < 6; x++) {
        get_assets(paint, x);
        sfSprite_setPosition(paint->lower_list[0][x].sprite,
                (sfVector2f) {400 + (x * 150), -190} );
        sfSprite_setTextureRect(paint->lower_list[0][x].sprite,
            (sfIntRect) {.top = 0, .left = 0, .width = 16, .height = 19} );
        paint->lower_list[0][x].selected = false;
    }
}

static void create_some_buttons(struct my_paint *paint)
{
    paint->lower_help = create_sprite("assets/help.png", 6, 6, NULL);
    sfSprite_setPosition(paint->lower_help, (sfVector2f) {1700, -190} );
    paint->preview_button = create_sprite("assets/lower_buttons/preview.png",
            6, 6, NULL);
    paint->save_button = create_sprite("assets/lower_buttons/save.png",
            6, 6, NULL);
    sfSprite_setPosition(paint->save_button, (sfVector2f) {200, -190} );
    sfSprite_setTextureRect(paint->save_button,
        (sfIntRect) {.top = 0, .left = 0, .width = 16, .height = 19} );
    paint->preview_button = create_sprite("assets/lower_buttons/preview.png",
            6, 6, NULL);
    sfSprite_setPosition(paint->preview_button, (sfVector2f) {400 + 6 * 150,
            -190} );
}

void create_lower_menu(struct my_paint *paint)
{
    paint->lower_background = create_rectangle(1920, 200, -0, -200);
    sfRectangleShape_setFillColor( paint->lower_background,
    sfColor_fromRGB(248, 176, 248) );
    create_some_buttons(paint);
    create_lower_buttons(paint);
    paint->lower_list[0][0].selected = true;
    sfSprite_setTextureRect(paint->lower_list[0][0].sprite,
        (sfIntRect) {.top = 38, .left = 0, .width = 16, .height = 19});
}
