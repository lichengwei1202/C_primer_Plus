#include "pe12-2a.h"
#include <stdio.h>
#include <string.h>
#include <float.h>
#include <ctype.h>
#include <stdlib.h>
void set_mode(int mode_input)
{
    if (mode_input==0||mode_input==1)
    {
        int mode =mode_input;
    }
    else
    {
        if (mode==0)
        {
            printf("Invalid mode specified. Mode %d(metric) used.",mode);
        }
        else if(mode==1)
        {
            printf("Invalid mode specified. Mode %d(US) used.",mode);
        }        
        
    }
    
}

void get_info()
{
    if (mode==0)
    {
        printf("Enter distance traveled in KMs:");
        scanf("%lf",&length);
        printf("Enter fuel consumed in liters:");
        scanf("%lf",&oil_consum);
    }
    else if (mode==1)
    {
        printf("Enter distance traveled in miles:");
        scanf("%lf",&length);
        printf("Enter fuel consumed in gallons:");
        scanf("%lf",&oil_consum);        
    }
    
    
}

void show_info()
{
    if (mode==0)
    {
        printf("Fuel consumption is %.1lf liters per KMs",oil_consum/length);
    }
    else if (mode==1)
    {
        printf("Fuel consumption is %.1lf miles per gallon",length/oil_consum); 
    }
}

