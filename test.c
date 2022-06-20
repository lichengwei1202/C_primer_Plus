#include <stdio.h>
#include "names_st.h"

void show_names(const struct names_st *pn)
{
    printf("%s %s",pn->first,pn->last);
}