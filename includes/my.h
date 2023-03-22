/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** lib
*/

#pragma once

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

int my_compute_power_rec(int nb, int p);
int my_get_unit(int nb);
int my_getnbr(char *str);
int my_isneg(int nb);
int my_put_double(double db, long precision);
void put_expo(double db, int count, int precision);
int my_put_exponential(double db, int precision);
int my_put_float(float fl, long precision);
int my_put_nbr(int nb);
unsigned int my_put_octal(unsigned int nb);
void my_putchar(char c);
int my_putstr (char const *str);
int my_str_to_int(char *str);
int is_char(char c);
int count_lines(char const *str);
int get_word(char const *str, int index, char *arr);
char **my_str_to_word_array(char const *str);
char *my_strcpy (char *dest, char const *src);
int my_strlen(char const *str);
void my_swap(int *a, int *b);
unsigned int my_unsigned_int(unsigned int nb);
unsigned int my_put_binary(unsigned int nb);
char **my_str_to_word_array(char const *str);
void my_put_array(char **array, char del);
int my_is_alpha(char *str1, char *str2);
int my_putstr(char const *str);
char *my_str_combine(char *goku, char *vegeta, char delimeter);
int my_str_compare(char *str1, char *str2);
int my_get_file_size(char *file_path, struct stat *prev_sb);
char *my_int_to_str(int nb);
int get_int_lenght(int nb);
double my_str_to_double(char *str);
char *my_get_str_until_c(char *str, char end);
int my_str_append_until(char *str, char end, char *buffer, int b_start);
int my_get_int_lenght(int nb);
int my_ascii_test(char c);
