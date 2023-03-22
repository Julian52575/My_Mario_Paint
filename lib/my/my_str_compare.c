/*
** EPITECH PROJECT, 2022
** my str compare
** File description:
** 1 if both are the same
*/
static int my_str_compare2(char s1, char s2);

//returns 1 if both str are the same, 0 if not
int my_str_compare(char *str1, char *str2)
{
    int a = 1;
    while ( str1[0] && str2[0] && a == 1) {
        a = my_str_compare2(str1[0], str2[0]);
        str1++;
        str2++;
    }
    if (str1[0] && !str2[0]) return 0;
    if (!str1[0] && str2[0]) return 0;
    return a;
}

static int my_str_compare2(char s1, char s2)
{
    if (s1 != s2) return 0;
    return 1;
}
