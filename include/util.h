#ifndef ARIA_UTIL_H
#define ARIA_UTIL_H

const char *get_file_extension(const char *filename);
const char *get_extension(const char *filename);
int has_extension(const char *filename, const char *ext);
void get_ac_filename(const char *input, char *output);

#endif // ARIA_UTIL_H