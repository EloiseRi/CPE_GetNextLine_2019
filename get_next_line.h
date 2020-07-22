/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** get_next_line
*/

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef READ_SIZE
#define READ_SIZE (40)
#endif

typedef struct memory_s
{
    char *overflow;
} memory_t;

int my_strlen(char *str);
char *check_overflow(char *ovrflw);
char *str_cat(char *line, int *i, memory_t *tmp, char *mem);
char *get_next_line(int fd);

#endif /* !GET_NEXT_LINE_H */
