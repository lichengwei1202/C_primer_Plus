#include <stdio.h>
#include <math.h>
#include <string.h>
#include <float.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include "chapt2_E.c"
#include "chapt3_E.c"
#include "chapt4_E.c"
#include "chapt5_E.c"
#include "chapt6_R.c"
#include "chapt6_E.c"
#include "chapt7_E.c"
#include "chapt8_R.c"
#include "chapt8_E.c"
#include "chapt9_E.c"
#include "chapt10_E.c"
#include "chapt11_Test.c"
#include "chapt11_E.c"
#include "chapt12_E.c"
#include "chapt13_E.c"
#include "chapt14_R.c"
#include "chapt14_E.c"
#include "names_st.h"
int main(int argc, char *argv[])
{
    struct names_st candidate=
    {
        "MIke",
        "Ross"
    };

    show_names(&candidate);

    return 0;
    
}