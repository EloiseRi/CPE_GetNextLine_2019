/*
** EPITECH PROJECT, 2019
** getnextline
** File description:
** gnl
*/

#include "get_next_line.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != '\n')
        i++;

    return (i);
}

char *str_cat(char *line, int *i, memory_t *tmp, char *mem)
{
    int a = -1, b = 0, size;
    char *cat;

    size = my_strlen(line) + my_strlen(mem);
    if (size == 0)
        cat = line;
    else {
        cat = malloc(size + 1);
        if (cat == NULL) return (-1);
        while (line[++a])
            cat[a] = line[a];
        while (mem[b] != '\0' && mem[b] != '\n')
            cat[a++] = mem[b++];
        cat[a] = '\0';
    }
    *i = mem[b] == '\n' ? 1 : 0;
    line = cat;
    tmp->overflow = check_overflow(mem);
    return (line);
}

char *check_overflow(char *mem)
{
    int i = 0, j = 0, size = 0;
    char *ovrflow;

    while (mem[size])
        size++;
    while (mem[i] != '\0' && mem[i] != '\n')
        i++;
    i = (mem[i] == '\0') ? i : (i + 1);
    size = size - i;
    if (size == 0) return (NULL);
    ovrflow = malloc(size + 1);
    if (ovrflow == NULL) return (NULL);
    while (mem[i])
        ovrflow[j++] = mem[i++];
    ovrflow[j] = mem[i];
    return (ovrflow);
}

char *get_next_line(int fd)
{
    int size = 1, i = 0;
    memory_t *tmp = malloc(sizeof(*tmp));
    static char *mem = NULL;
    char buffer[READ_SIZE + 1];
    char *line = malloc(sizeof(char) * 2);

    if (buffer == NULL || READ_SIZE <= 0 || fd == -1 || !(line)) return (NULL);
    line[0] = '\0';
    if (mem != NULL) {
        line = str_cat(line, &i, tmp, mem);
        mem = tmp->overflow;
    }
    while (i == 0 && (size = read(fd, buffer, READ_SIZE)) > 0) {
        buffer[size] = '\0';
        line = str_cat(line, &i, tmp, buffer);
        mem = tmp->overflow;
    }
    if ((line[0] == '\0' && size == 0) || size < 0) return (NULL);
    free(tmp);
    return (line);
}