/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** create_paint
*/
#include "my_paint.h"

static void create_pattern(struct my_paint *paint, int y, int x)
{
    //assets/patterns/p y x .hdr
    char *str_x = my_int_to_str(x);
    char *str_y = my_int_to_str(y);
    char *test = my_str_combine("assets/patterns/p", str_x, str_y);
    char h[3];
    h[0] = '.';
    h[1] = '\0';
    char *full = my_str_combine(test, "hdr", h);
    printf("-> (%d, %d) %s\n", y, x, full);
    sfImage_createFromFile(full);//
    free(str_x);
    free(str_y);
    free(test);
    free(full);
}

static void create_upper_buttons(struct my_paint *paint)
{
    paint->upper_list = malloc(sizeof(struct upper_buttons *) * 16);
    int y = 0;
    for (; y < 15; y++) {
        paint->upper_list[y] = malloc(sizeof(struct upper_buttons) * 16);
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
    sfSprite_setPosition(
        (paint->upper_gugus = 
        create_sprite("assets/upper_buttons.png", 6, 6, NULL)
        ), (sfVector2f) {1800, -385 } );
    sfSprite_setTextureRect(paint->upper_gugus, (sfIntRect) 
            {.top = 0, .left = 212, .width = 18, .height = 15 } );
}

static void create_upper_menu(struct my_paint *paint)
{
    paint->upper_background = create_rectangle(1920, 200, -0, -400);
    sfRectangleShape_setFillColor( paint->upper_background,
    sfColor_fromRGB(150, 70, 160));
    create_upper_buttons(paint);
    paint->movie_wheel = create_sprite("assets/movie_wheel.png", 6, 6, NULL);
    sfSprite_setPosition(paint->movie_wheel, (sfVector2f) {40, -385} );
    paint->upper_id = 0;

    paint->current_color = 0;


}

static void create_lower_menu(struct my_paint *paint)
{
    paint->lower_background = create_rectangle(1920, 200, -0, -200);
    sfRectangleShape_setFillColor( paint->lower_background,
    sfColor_fromRGB(42, 42, 42));
    paint->lower_arrow = create_sprite("assets/upper_arrow.png", 6, 6,
                        &(sfIntRect) {.top = 0, .left = 0,
                                .width = 7, .height = 10});
    sfSprite_setPosition(paint->lower_arrow, (sfVector2f) {1700, -180} );

}

struct my_paint *create_paint(void)
{
    struct my_paint *paint = malloc(sizeof(struct my_paint));
    if (!paint)
        return NULL;
    create_upper_menu(paint);
    create_lower_menu(paint);
    paint->cursor = create_sprite("assets/Cursors.png", 3, 3, NULL);

    sfSprite_setTextureRect(paint->cursor, (sfIntRect) {0, 0, 17, 14} );
    return paint;
}
