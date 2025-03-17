#include "util.h"

#include <string.h>

const char *get_file_extension(const char *filename)
{
    const char *dot = strrchr(filename, '.');
    if (!dot || dot == filename)
        return NULL;
    return dot + 1;
}

const char *get_extension(const char *filename)
{
    const char *dot = strrchr(filename, '.');
    if (!dot || dot == filename)
        return NULL;
    return dot + 1;
}

int has_extension(const char *filename, const char *ext)
{
    const char *file_ext = get_file_extension(filename);
    return (file_ext && strcmp(file_ext, ext) == 0);
}

void get_ac_filename(const char *input, char *output)
{
    strcpy(output, input);
    char *dot = strrchr(output, '.');

    if (!dot || dot == input || strcmp(dot, ".as") != 0)
    {
        return;
    }

    strcpy(dot, ".ac");
}
