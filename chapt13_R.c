#include <stdio.h>
#include <math.h>
#include <string.h>
#include <float.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
/*13.1*/
#define LIM 40
#define BUSSIZE 4096
int main(int argc, char *argv[])
{
    char ch;
    FILE *fp;
    char line[LIM];
    if (argc!=3||strlen(argv[1])!=1)
    {
        printf("Please input the right format!\n");

        exit(EXIT_FAILURE);
    }

    if ((fp=fopen(argv[2],"r"))==NULL)
    {
        printf("cannot open the file\n");
        exit(EXIT_FAILURE);
    }

    ch=argv[1][0];
    while(fgets(line,LIM,fp)!=NULL)
    {
        char *p=line;
        while (*p!='\0')
        {
            if (*p++==ch)
            {
                printf("FOUND %c in LINE : %s", ch, line);
                break;
            }
            
        }
        
    }
    
    return 0;
}

/*练习4 请贴入主函数
    FILE *fp;
    double num=0;
    int count=0;
    double sum=0;
    double average;
    if (argc==1)
    {
        printf("You does not chose a file, please input the number directly(q to quit):\n");
        fp=stdin;
    }
    else if (argc==2)
    {
        if ((fp=fopen(argv[1],"r"))==NULL)
        {
            printf("Cannot open file %s",argv[1]);
            exit(EXIT_FAILURE);
        }

        
    }
    else
    {
        printf("too many variables.please input the number directly(q to quit):\n");
        fp=stdin;
    }

    while (!feof(fp)&&fscanf(fp,"%lf",&num)==1)
    {
        count++;
        sum += num;
    }
    fclose(fp);

    average = sum/count;

    fprintf(stdout,"the average is %.2lf\n",average);

    return 0;
    */