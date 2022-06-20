#include <stdio.h>
#include <string.h>
/*添加一个类似put的函数，但是不会自动打印换行符,并会返回打印字符串地址*/

const char *put1(const char *string)
{
    while (*string!='\0')
    {
        putchar(*string++);    
    }
    
    return string;
}

/*添加一个类似put的函数，会给出待打印字符个数*/

int put2(const *string)
{
    int count=0;
    while(*string)
    {
        putchar(*string++);
        count++;
    }
    putchar('\n');
    return count;
}

#define ROW_test1 50
#define LIM_SIZE 20

char *s_gets(char *string, int n);
void sort_test(char *string[],int num);
int test1(void)
{
    char list[LIM_SIZE][ROW_test1];
    char *input[LIM_SIZE];
    int i=0;

    while(i<LIM_SIZE && s_gets(list[i],ROW_test1)!=NULL && list[i][0]!='\0')
    {
        input[i]=list[i];
        i++;
    }

    sort_test(input,i);

    for(int k=0;k<i;k++)
    {
        puts(input[k]);
    }
    return 0;
}

void sort_test(char *string[],int num)
{
    char *temp;
    for(int i=0;i<num-1;i++)
    {
        for(int j=i+1;j<num;j++)
        {
            if(strcmp(string[i],string[j])>0)
            {
                temp = string[i];
                string[i]=string[j];
                string[j]=temp;
            }            
        }        
    }
}
char *s_gets(char *string, int n)
{
    char *rel_val;
    int i=0;
    rel_val=fgets(string,n,stdin);
    if(rel_val)
    {
        while(rel_val[i]!='\n'&&rel_val[i]!='\0')
        {
            i++;
        }

        if(rel_val[i]=='\n')
            rel_val[i]='\0';
        else
            while(getchar()!='\n')
                continue;
               
    }
    return rel_val; 
}

/*第10题*/
int length(char *string)
{
    int count=0;
    while(*string++)
    {
        count++;        
    }
    return count;
}


/*第12题*/
char *blank(char *string)
{
    while(*string++)
    {
        if(*string==' ')
        {
            return string;
        }
    }

    return NULL;
}