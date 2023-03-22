/*
** EPITECH PROJECT, 2022
** my str combine
** File description:
** str 1 + delimeter + str 2 = 1 big str
*/
#include <stdlib.h>
int my_strlen(char *str);

//fuses the 2 strings and the delimeter in between (unless delimeter == NULL);
char *my_str_combine(char *goku, char *vegeta, char delimeter)
{
    char *vegetto = malloc( sizeof(char) *
    (my_strlen(goku) + my_strlen(vegeta) + 2) );
    vegetto[my_strlen(goku) + my_strlen(vegeta) + 1] = '\0';
    int i = 0;
    for (; i < my_strlen(goku); i++) {
        vegetto[i] = goku[i];
    }
    if (delimeter)
        vegetto[i++] = delimeter;
    int j = 0;
    for (; j < my_strlen(vegeta); j++) {
        vegetto[i + j] = vegeta[j];
    }
    vegetto[i + j] = '\0';
    return vegetto;
}
