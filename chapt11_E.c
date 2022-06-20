/*第1题*/
char *ch11_E1()
{
    char list[30];
    int i=0;
    printf("please input some chars:");
    list[0]=getchar();
    putchar(list[0]);
    while(list[i]!=EOF)
    {
        i++;
        list[i]=getchar();
        putchar(list[i]);
    }

    return list;
}

/*第2题*/
char *ch11_E2(int n)
{
    char list[n];
    int i;
    printf("please input some chars:");
    list[0]=getchar();
    putchar(list[0]);
    while(list[i]!=EOF&&i++<n)
    {
        list[i]=getchar();
        if(list[i]==' '||list[i]=='\n'||list[i]=='\t')
            break;
        putchar(list[i]);
    }
    list[i]='\0';
    return list;
}

/*第3题*/
void ch11_E3(char *out,char *new_list,int num_nl)
{
    int i=0;
    while(*++out==' ')
    continue;

    do
    {
        *(new_list+i)= *out++; 
    } while (*out!=' '&& *out!='\n'&& *out!='\t'&& ++i<num_nl);

    new_list[i+1]='\0';
    
}

/*第4题同上*/

/*第5题*/
char *match(char *string, char c);
int ch11_E5()
{
    char string[30];
    char *temp;
    char *result;
    char c=' ';
    
    temp = string;
    printf("Please input the string we based on:\n");
    fgets(string,30,stdin);

    while(c!=EOF)
    {
        printf("Please input the char we need to search for:\n");
        while((c=getchar())=='\n')
        continue;

        result = match(string,c);
        if(result==NULL)
        {
            printf("there is no %c in the string, please try again\n",c);        
        }

        else
        {
            printf("the first %c is at the %ld number of the string with location at %p\n",c, result-temp+1,result);        
        }

    }


    return 0;
}

char *match(char *string, char c)
{
    while(c!=*string)
    {
        if(*string=='\0')
        return NULL;
        string++;
    }

    return string;
}

/*第6题*/
int is_within(char c, char *string);
int ch11_E6(void)
{
    char c=' ';
    char *string[30];
    int result;
    printf("please input the string you based on:\n"); 
    fgets(string,30,stdin);
    while(c!=EOF)
    {
        printf("please input the char you want to search:\n"); 
        while ((c=getchar())=='\n')
        continue;

        result=is_within(c,string);

        printf("the return is %d\n",result);
        
    }

    return 0;
}

int is_within(char c, char *string)
{
    while(*string++!='\0')
    {
        if (c==*string)
        {
            return 1;
        }
        
    }
    return 0;

}

/*第7题*/

char *mystrncpy(char *string, const char *string2, int n);
int ch11_E7()
{
    char string[5];
    char test[3];

    fgets(string,5,stdin);
    mystrncpy(test, string,3);
    fputs(test,stdout);
    return 0;
}

char *mystrncpy(char *string, const char *string2, int n)
{
    int count=0;
    while(count<n)
    {
        if(*(string2+count)=='\0')
        {
            *(string+count)='\0';
            break;
        }

        *(string+count)= *(string2+count);
        count++;
    }

    return string;
}

/*第8题*/
char *string_in(char *string, char *string2);
int ch11_E8()
{
    char string[30];
    char string2[5];
    char *result;
    printf("please input the string you based on:\n"); 
    s_gets(string,10);
    while(*string2!=EOF)
    {
        printf("please input the string you want to search:\n"); 
        s_gets(string2,5);

        result=string_in(string,string2);
        if (result==NULL)
        {
            printf("string2 is not included %lu\n",strlen(string));
        }
        else
        {
            printf("string2 is included and is located at %p\n",result);
        }
        
    }

    return 0;
}

char *string_in(char *string, char *string2)
{
    int count=0;
    int length = strlen(string2);
    char *copy;
    copy = string;
    while (*copy!='\0')
    {
        while (*(copy+count)==*(string2+count)&&*(copy+count)!='\0')
        {
            count++;
        }
        if (count==length)
        {
            break;
        }
        else
        {
            count=0;
        }
        copy++;
    }
    if (*copy=='\0')
    {
        return NULL;
    }
    else
    {
        return copy;
    }
    
}

/*第9题*/
void convert(char *string);
int ch11_E9()
{
    char string[30];
    while(*string!=EOF)
    {
        printf("please input the string:\n"); 
        s_gets(string,10);
        convert(string);
        fputs(string,stdout);
        printf("\n");
    }
    return 0;
}

void convert(char *string)
{
    int n=strlen(string);
    char temp[n+1];
    int i=0;
    do
    {
        temp[i]=*string;
        i++;
    } while (*++string!='\0');

    for ( i = 0; i < n; i++)
    {
        *--string=temp[i];
    }
}

/*第10题*/
void delete_space(char *string);
char *delete_space2(char *string);
int ch11_E10()
{
    char string[30];
    while (*string!=EOF)
    {
        char *ptr;
        printf("Please input the string:\n");
        fgets(string,10,stdin);
        ptr=delete_space2(string);
        fputs(string,stdout);
    }
    
    return 0;
}

void delete_space(char *string)
{
    int n=strlen(string);
    int m;
    char temp[n];
    int i=0,k=0;
    while (*(string+i)!='\0')
    {
        if(*(string+i)!=' ')
        {
            temp[k]=*(string+i);
            k++;            
        }
        i++;
    }
    while (k<n)
    {
        temp[k]='\0';
        k++;
    }
    
    i=0;
    while(*(temp+i)!='\0')
    {
        *(string+i)=temp[i];
        i++;
    }
    while(i < n)
    {
        *(string+i)='\0';
        i++;
    }
    
}

char *delete_space2(char *string)
{
    char *ptr;
    ptr = string;
    int i=0;
    while (*string!='\0')
    {
        if (*string==' ')
        {
            string++;
            i++;
        }
        else
        {
            *ptr++=*string++;
        }
        
    }

    while(i--)
    {
        *ptr++='\0';
    }
    
    
    return ptr;
}

/*第11题*/
#define LIM 5
#define SIZE 81

void screen_ch11_E11(void);
void rank_b(char *ptstr[]);
void rank_c(char *ptstr[]);
void rank_d(char *ptstr[]);
void print_E11(char *ptstr[]);
int ch11_E11()
{
    char *string[LIM][SIZE];
    char *ptstr[LIM];
    int count=0;
    int input=' ';
    printf("Please input the string:\n");

    while (count<LIM&&fgets(string[count],SIZE,stdin)!=NULL&&string[count][0]!=EOF)
    {
        ptstr[count] = string[count];
        count++;
    }

    while (input!='q')
    {
        screen_ch11_E11();
        while((input=getchar())=='\n')
        continue;
        printf("%c\n",input);
        switch (input)
        {
        case 'a':
            print_E11(ptstr);
            
            break;
        case 'b':
            rank_b(ptstr);
            print_E11(ptstr);
            break;
        case 'c':
            rank_c(ptstr);
            print_E11(ptstr);
            break;
        case 'd':
            rank_d(ptstr);
            print_E11(ptstr);
            break;

        default:
            break;
        }

        getchar();
        count=0;
        input=' ';
        printf("Please input the string:\n");

        while (count<LIM&&fgets(string[count],SIZE,stdin)!=NULL&&string[count][0]!=EOF)
        {
            ptstr[count] = string[count];
            count++;
        }
    }

    printf("Bye\n");
    return 0;
}

void screen_ch11_E11(void)
{
    printf("Enter the operation of your choice:\n");
    printf("   a. print the string                       b. print the string ranked by ASCII\n");
    printf("   c. print the string ranked by length      d. print the string ranked by the length of the first word\n");
    printf("   q. quit\n");
}

void print_E11(char *ptstr[])
{
    for ( int i = 0; i < LIM; i++)
    {
        fputs(ptstr[i],stdout);
    }
}

void rank_b(char *ptstr[])
{
    char *temp;
    for (int i = 0; i < LIM-1; i++)
    {
        for (int j = i+1; j < LIM; j++)
        {
            if (strcmp(ptstr[i],ptstr[j])>0)
            {
                temp = ptstr[i];
                ptstr[i] = ptstr[j];
                ptstr[j] = temp;
            }
            
        }
        
    }
    
}

void rank_c(char *ptstr[])
{
    char *temp;
    int temp2;
    int length[LIM];
    for (int k = 0; k < LIM; k++)
    {
        length[k]=strlen(ptstr[k]);
    }
    
    for (int i = 0; i < LIM-1; i++)
    {
        for (int j = i+1; j < LIM; j++)
        {
            if (length[i]>length[j])
            {
                temp = ptstr[i];
                ptstr[i] = ptstr[j];
                ptstr[j] = temp;

                temp2 = length[i];
                length[i] = length[j];
                length[j] = temp2;
            }
            
        }
        
    }
}

void rank_d(char *ptstr[])
{
    char *temp;
    int temp2;
    int length[LIM];
    int s;
    for (int k = 0; k < LIM; k++)
    {
        s=0;
        while(isalpha(ptstr[k][s])!=0)
        {
            s++;
        }


        length[k]=s;
        printf("%d %c\n",length[k],ptstr[k][0]);
    }
    
    for (int i = 0; i < LIM-1; i++)
    {
        for (int j = i+1; j < LIM; j++)
        {
            if (length[i]>length[j])
            {
                temp = ptstr[i];
                ptstr[i] = ptstr[j];
                ptstr[j] = temp;

                temp2 = length[i];
                length[i] = length[j];
                length[j] = temp2;
            }
            
        }
        
    }
}

/*第12题*/

/*第13题

修改命令行
int main(int argc, char *argv[])
{
    for (int i = argc-1; i > 0; i--)
    {
        printf("%s ",argv[i]);
    }
    return 0;
}
*/

/*第14题*/

/*修改命令行

int main(int argc, char *argv[])
{
    int base = atoi(argv[1]);
    int count =atoi(argv[2]);
    int result=1;
    for (int i = 0; i < count; i++)
    {
        result = result*base;
    }
    printf("the result is %d",result);
    return 0;
}
*/

/*第15题*/

int myatoi(char *st)
{
    int length = strlen(st);
    int number;
    int result;
    int transfer=1;
    int base=10;
    for (int i=length;i>0;i--)
    {
        if(isdigit(*(st+i-1)==0))
        {
            printf("error");
            return 0;
        }

        result = (*(st+i-1)-'0')*transfer;

        transfer *= base;        
    }
    
    return result;
    
}

/*第16题*/
void function_p(char *st)
{
    printf("%s",st);
}

void function_u(char *st)
{
    while (*st!=EOF&&*st!='\0')
    {
        if (*st=='\n')
        {
            putchar('\n');
            st++;
        }
        else
        {
            putchar(toupper(*st++));            
        }

        
    }
}

void function_l(char *st)
{
    while (*st!=EOF&&*st!='\0')
    {
        if (*st=='\n')
        {
            putchar('\n');
            st++;
        }
        else
        {
            putchar(tolower(*st++));            
        }
    }
}