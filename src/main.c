#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"
#include "compiler.h"
#include "runner.h"

int usage(const char *name)
{
    printf("Usage: %s <code or source file>\n", name);
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        return usage(argv[0]);
    }

    char *filename = argv[1];

    if (has_extension(filename, "ac"))
    {
        run(filename);
        return 0;
    }

    if (has_extension(filename, "as"))
    {
        compile(filename);
        return 0;
    }

    return usage(argv[0]);
}
