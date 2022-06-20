#include <string.h>
#define SLEN 32

struct names_st
{
    char first[SLEN];
    char last[SLEN];
};

void show_names(const struct names_st *);
