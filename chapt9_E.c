/*第1题*/
double min_test(double i, double j);
int ch9_E1(void)
{
    double i,j,min_number;
    printf("Enter two numbers.\n");
    scanf("%lf %lf",&i,&j);

    min_number=min_test(i,j);

    printf("%.2lf",min_number);

    return 0;

}

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

/*第2题*/

void chline(char ch, int x, int y);
int ch9_E2(void)
{
    char ch;
    int x,y;
    printf("Please input the char you want to print:");
    ch = getchar();
    printf("Please input the columns and rows:\n");
    scanf("%d %d",&x,&y);
    chline(ch,x,y);

    return 0;
}

void chline(char ch, int x, int y)
{
    int i,j;
    for(i=1;i<=x;i++)
    {
        for(j=1;j<=y;j++)
        {
            printf("%c",ch);
        }
        printf("\n");
    } 
}

/*第3题 略*/
/*第4题 略*/

/*第5题*/
void large_of(double *x, double *y);
int ch9_E5(void)
{
    double x,y;
    printf("Please input two numbers:\n");
    scanf("%lf %lf",&x, &y);
    large_of(&x,&y);
    printf("%.2lf %.2lf",x,y);

    return 0;
}
void large_of(double *x, double *y)
{
    if(*x>*y)
    {
        *y = *x;
    }
    else
    {
        *x = *y;
    }

}

/*第6题*/
void sort_basic(double *x, double *y);
void sort_number(double *x, double *y, double *z);

int ch9_E6(void)
{
    double a,b,c;
    printf("Please give three numbers:\n");
    scanf("%lf %lf %lf",&a,&b,&c);
    sort_number(&a,&b,&c);

    printf("the sorted list is %.2lf %.2lf %.2lf",a,b,c);
    return 0;
}

void sort_number(double *x, double *y, double *z)
{
    sort_basic(x,y);
    sort_basic(x,z);
    sort_basic(y,z);
}

void sort_basic(double *x, double *y)
{
    double temp;
    if(*x>*y)
    {
        temp = *y;
        *y = *x;
        *x = temp;
    }
}

/*第7题*/
int alpha_location(char ch);
int ch9_E7(void)
{
    char ch;
    int location;

    while((ch=getchar())!=EOF)
    {
        if(isalpha(ch)==1)
        {
            location=alpha_location(ch);
            printf("%c-%d\n",ch,location);            
        }
        else
        {
            printf("%c-not_alphabet\n",ch);
        }
    }
    
    return 0;
}

int alpha_location(char ch)
{
    int location;
    if(isupper(ch)==1)
    {
        location = (int)ch-64;
    }
    else if(islower(ch)==1)
    {
        location = (int)ch-96;
    }

    return location;
}

/*第8题*/
double power(double base, int pow);
int ch9_E8(void)
{
    int pow;
    double base;

    printf("Please input the base and the power:");
    scanf("%lf %d",&base,&pow);

    printf("the result is %.2lf",power(base,pow));


    return 0;
}

double power(double base, int pow)
{
    int i;
    double result=1;

    if(pow>0)
    {
        for(i=1;i<=pow;i++)
        {
            result *= base;            
        }
    }
    else if(pow<0)
    {
        for(i=1;i<=(-pow);i++)
        {
            result *= (1/base);            
        }
    }
    else
    {
        if(base==0)
        {
            printf("0's 0 power is not defined! we set it 1.\n");
        }
        result = 1;
    }

    return result;
}

/*第9题*/
double power_2(double base, int pow);
int ch9_E9(void)
{
    int pow;
    double base;

    printf("Please input the base and the power:");
    scanf("%lf %d",&base,&pow);

    printf("the result is %.2lf",power_2(base,pow));


    return 0;
}

double power_2(double base, int pow)
{
    int i;
    double result=1;
    double base2 = 1/base;

    if(pow>0)
    {
        result = base*power_2(base,pow-1);            
    }
    else if (pow<0)
    {
        result = base2*power_2(base2,abs(pow)-1);
    }
    else
    {
        if(base==0)
        {
        printf("0's 0 power is not defined! we set it 1.\n");                
        }
        result = 1;
    }    

    return result;
}

/*第10题*/

void to_base_n(unsigned long number, unsigned short base);
int ch9_E10(void)
{
    int number,base;
    scanf("%d %d",&number,&base);
    to_base_n(number,base);

    return 0;
}

void to_base_n(unsigned long number, unsigned short base)
{
    int r;
    r = number%base;
    if(number>=base)
    {
        to_base_n(number/base,base);
    }
    printf("%d",r);
}

/*第11题*/

int Fibonacci(unsigned long num);
int Fibonacci_2(unsigned long num);
int ch9_E11(void)
{
    int num,result;
    scanf("%d",&num);
    result = Fibonacci_2(num);
    printf("the %dth Fibonacci number is %d\n",num,result);

    return 0;
}

/*递归方式*/
int Fibonacci(unsigned long num)
{
    if(num<=2)
    {
        return 1;
    }

    return Fibonacci(num-1)+Fibonacci(num-2);
}

/*循环方式*/
int Fibonacci_2(unsigned long num)
{
    int i;
    int result=1, result_1=1, result_2=1;
    if(num<=2)
    {
        return 1;
    }

    for(i=3;i<=num;i++)
    {
        result_2 = result_1;
        result_1 = result;
        result = result_1 + result_2; 
    }

    return result;
}