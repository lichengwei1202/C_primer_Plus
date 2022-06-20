/*第6题*/

int ch6_R6(void)
{
    int i,j;
    for (i=0;i<=3;i++)
    {
        for (j=0;j<=7;j++)
        {
            printf("$");
        }
        printf("\n");
    }
    return 0;
}

/*第8题*/
int ch6_R8(void)
{
    char ch;

    scanf("%c", &ch);
    while(ch != 'g')
    {
        printf("%c",ch);
        scanf("%c",&ch);
    }

    return 0;
}

/*第8题——测试*/

int ch6_R8_1(void)
{
    double ch[2];
    int i;
    for(i=0;i<2;i++)
    {
        scanf("%lf",&ch[i]);
        printf("%f",ch[i]);
    }


    return 0;
}

int ch6_R8_2(void)
{
    int i,j;
    char n,m;

    for(i=1,n='A';i<=4;i++,n++)
    {

        for(j=2,m=n;j<=i;j++,m--)
        {
            printf("%c",m);  
        }
        printf("\n");
    }
    return 0;
}