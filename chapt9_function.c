#include <stdio.h>
#include "chapt9.h"

/*第1题*/
double min_test(double i, double j)
{
    if(i<=j)
    {
        return i;
    }
    else
    {
        return j;
    }
}