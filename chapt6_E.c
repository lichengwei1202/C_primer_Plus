/*第1题*/
int ch6_E1(void)
{
    char n[26];
    char i;
    int j;
    for(i='a',j=1;j<=26;i++,j++)
    {
        n[j] = i;
        printf("%c",n[j]);
    }

    return 0;
}

/*第2题*/
int ch6_E2(void)
{
    int i,j,n;
    for(i=1,j=1;i<=4;i++,j++)
    {
        for(n=1;n<=j;n++)
            printf("$");
        printf("\n");
    }
   return 0;
}

/*第3题*/
int ch6_E3(void)
{
    int i,j;
    char n;

    for(i=1;i<=6;i++)
    {
        for(n='F',j=1;j<=i;n--,j++)
        {
            printf("%c",n);
        }
        printf("\n");
    }

    return 0;
}

/*第4题*/
int ch6_E4(void)
{
    int i,j;
    char n = 'A';

    for(i=1;i<=6;i++)
    {
        for(j=1;j<=i;j++,n++)
        {
            printf("%c",n);
        }
        printf("\n");
    }

    return 0;

}

/*第5题*/
int ch6_E5(void)
{
    int i,j,k,y;
    char n,m,x;
    scanf("%c",&x);
    y = x-'A'+1;
    for(i=1;i<=y;i++)
    {
        for(j=1;j<=(5-i);j++)
        {
            printf(" ");
        }
        for(j=1,m='A';j<=i;j++,m++)
        {
            printf("%c",m);
        }

        for(k=1,n=(m-2);k<(j-1);k++,n--)
        {
            printf("%c",n);
        }
        printf("\n");
    }
    return 0;
}

/*第6题*/
int ch6_E6(void)
{
    int d,u,i,j;
    printf("please input the downside of the sheet:\n");
    scanf("%d",&d);
    printf("please input the upside of the sheet:\n");
    scanf("%d",&u);
    if(d<u)
    {
        for(i=d;i<=u;i++)
        {
            printf("%d %d %d\n",i,i*i,i*i*i);
        }

    }
    printf("Done");

    return 0;

}

/*第7题*/
int ch6_E7(void)
{
    char word[40];
    int i,length;
    printf("Please input a word:\n");
    scanf("%s",word);
    length = strlen(word);

    for(i=length-1;i>=0;i--)
    {
        printf("%c",word[i]);
    }
    printf("\n");

    return 0;
}

/*第8题*/
int ch6_E8(void)
{
    double i,j;
    printf("please input two numbers:");

    while(scanf("%lf %lf",&i,&j)==2)
    {
        printf("%lf\n",(i-j)/(i*j));

        printf("please input two numbers:");
    }

    printf("Done");
    return 0;
}

/*第9题*/

double calculator(double i,double j)
{
    double result;
    result = (i-j)/(i*j);

    return result;
}

int ch6_E9(void)
{
    double i,j,r;
    printf("please input two numbers:");
    while(scanf("%lf %lf",&i,&j)==2)
    {
        r = calculator(i,j);
        printf("%lf\n",r);

        printf("please input two numbers:");
    }

    printf("Done");

    return 0;

}


/*第10题*/
int ch6_E10(void)
{
    int lower,upper,i,sum;
    sum = 0;
    printf("Enter lower and upper integer limits:\n");

    while(scanf("%d %d",&lower,&upper)==2&&lower<upper )
    {
        for(i=lower;i<=upper;i++)
        {
            sum = sum + i*i;
        }
        printf("The sums of the squares from %d to %d is %d\n",lower,upper,sum);
        printf("Enter next set of limits:\n");
        scanf("%d %d",&lower,&upper);
    }
    printf("Done\n");

    return 0;
}

/*第11题*/
int ch6_E11(void)
{
    int number[8];
    int i;

    for(i=0;i<=7;i++)
    {
        printf("Please input number %d:",i+1);
        scanf("%d",&number[i]);
    }
    printf("\n");
    printf("the results show below:\n");
    for(i=7;i>=0;i--)
    {
        printf("%d,",number[i]);
    }
    printf("\n");

    return 0;

}

/*第12题*/
int ch6_E12(void)
{
    double sum1,sum2;
    int i,term;

    printf("Enter the number of terms:");
    while(scanf("%d",&term)==1&&term>0)
    {
        sum1=0.0;
        sum2=0.0;
        for(i=1;i<=term;i++)
        {
            sum1 = sum1+(1.0/i);
            sum2 = sum2 +pow(-1,(i+1))*1.0/i;
        }
        printf("The sum of formula_1 is: %lf\n ",sum1);
        printf("The sum of formula_2 is: %lf\n ",sum2); 
        printf("Enter the next number of terms:");
    }
    printf("Done\n");
    return 0;

}

/*第13题*/
int ch6_E13(void)
{
    int list[8];
    int i;
    for(i=0;i<=7;i++)
    {
        list[i]=pow(2,i+1);
    }

    i=0;
    do
    {
        printf("%d,",list[i++]);
    } while (i<=7);
    
    return 0;
}

/*第14题*/
int ch6_E14(void)
{
    double list1[8],list2[8];
    int i;
    printf("Please input list1 number %d:",1);
    scanf("%lf",&list1[0]);
    list2[0]=list1[0];

    for(i=1;i<=7;i++)
    {
        printf("Please input list1 number %d:",i+1);
        scanf("%lf",&list1[i]);
        list2[i] = list2[i-1]+list1[i];
    }
    
    printf("list_1:");
    for(i=0;i<=7;i++)
    {
        printf("%.2lf, ",list1[i]);
    }

    printf("\n");


    printf("list_2:");
    for(i=0;i<=7;i++)
    {
        printf("%.2lf, ",list2[i]);
    }

    return 0;
}

/*第15题*/
int ch6_E15(void)
{
    char list[255];
    int i=0;
    do
    {
        scanf("%c",&list[i]);
    }
    while(list[i]!='\n' && ++i);

    for(i=strlen(list)-1;i>=0;i--)
    {
        printf("%c",list[i]);
    }
    return 0;
}

/*第16题*/
int ch6_E16(void)
{
    double DA_total=100.0, DE_total=100.0;
    int i=1;

    do
    {
        DA_total = DA_total+(100*0.1);
        DE_total = DE_total*(1.05);
        i++;
    }
    while (DA_total>DE_total);

    printf("Deirdre's investment($%.2lf) will beyond Daphne's($%.2lf) in year %d.",DE_total,DA_total,i);
    
    return 0;
}

/*第17题*/
int ch6_E17(void)
{
    double total_m=100.0;
    int i=1;

    do
    {
        total_m = total_m*1.08-10;
    }
    while(total_m>=0&&i++);

    printf("Chuckie Lucky will take all his money in year %d",i);
    return 0;
}

/*第18题*/
int ch6_E18(void)
{
    const int Dunbar = 150;
    int number = 5;
    int i;

    do
    {
        number = (number-1)*2;
        printf("Rabnud will have %d friends in week %d\n",number,i);
    } while (number<=Dunbar&&i++);

    printf("Rabnud's friends will beyond Dunar's number in week %d\n",i);

    return 0;
     

}