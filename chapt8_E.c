

/*第1题*/
int ch8_E1(void)
{
    int ch;
    int count=0;
    while((ch=getchar())!=EOF)
    {

        count++;
    }
    printf("%d",count);
    return 0;
}

/*第2题*/
int ch8_E2(void)
{
    char ch,i;
    do
    {
        for(i=1;i<=10;i++)
        {
            if((ch=getchar()) <32)
            {
                if (ch=='\n')
                {
                    printf("'\\n\'-%d,",ch);
                }
                else if (ch=='\t')
                {
                    printf("'\\t\'-%d,",ch);
                }
                else
                {
                    printf("^%c-%d,",(int)ch+64,ch);
                }
            }
            else
            {
                printf("%c-%d,",ch,ch);
            }         
        }
        printf("\n");
    }
    while (ch!=EOF);
    
    
    return 0;
}

/*第3题*/
int ch8_E3(void)
{
    char ch;
    int Capital_number=0,lowercase_number=0;
    while ((ch=getchar())!=EOF)
    {
        if(ch>'A'&&ch<'Z')
        {
            Capital_number++;
        }

        if(ch>'a'&& ch<'z')
        {
            lowercase_number++;
        }
    }
    printf("Capital number:%d\nlowercase number:%d",Capital_number,lowercase_number);
    return 0;
    
}

/*第4题*/
int ch8_E4(void)
{
    int alpha_count=0,word_count=0;
    char ch;

    while ((ch=getchar())!=EOF)
    {
        if(ispunct(ch)==0)
        {
            alpha_count++;
        }

        if(ispunct(ch)!=0||ch==' ')
        {
            word_count++;
        }
    }

    printf("average number of alphabet of a word are: %.2f",(float)alpha_count/word_count);
    
    return 0;
}

/*第5题*/
int ch8_E5(void)
{
    int guess=50;
    char ch;
    printf("*********************************************\n");
    printf("Pick an integer from 1 to 100. I'll guess it.\n");
    printf("*********************************************\n");
    printf("is it %d?\n",guess);
    printf("*********************************************\n");
    printf("   S) too Small           B)to Big\n");
    printf("   Y) Yes\n");
    printf("*********************************************\n");
    while ((ch=getchar())!='Y')
    {
        if(ch=='B')
        {
            guess= guess/2;
        }
        else if (ch=='S')
        {
            guess=(guess+100)/2;
        }
        else
        {
            printf("Error, please type again!\n");
        }
        printf("is it %d?\n",guess);
        printf("*********************************************\n");
        printf("   S) too Small           B)to Big\n");
        printf("   Y) Yes\n");
        printf("*********************************************\n");

    }

return 0;
}

/*第6题*/
char print(void);

int ch8_E6(void)
{
    char ch;
    ch = print();
    printf("%c",ch);
    return 0;
}

char print(void)
{
    char ch;

    while((ch=getchar())==' '||ch=='\n')
    {
        
    }
    return ch;
}

/*第7题*/
int ch8_E7(void)
{
    double time,sum,income;
    int judge=0;
    char ch;
    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("a) $8.75/hr                            b) $9.33/hr\n");
    printf("c) $10.00/hr                           d) $11.20/hr\n");
    printf("q)quit\n");
    printf("*****************************************************************\n");
    ch=getchar();
    while (getchar()!='\n')  /*当输入多余一个字符时，只取第一个*/
    {
        continue;
    }
    
    while(judge==0)
    {
        switch (ch)
        {
        case 'a':
            income =8.75;
            judge = 1;
            break;
        case 'b':
            income =9.33;
            judge = 1;
            break;
        case 'c':
            income =10.00;
            judge = 1;
            break;
        case 'd':
            income =11.20;
            judge = 1;
            break;
        case 'q':
            income = -1;
            judge = 1;
            break;
        default:
            printf("Please input the right number!");
            ch=getchar();
            break;
        }
    }

    if(income>0)
    {
        printf("Enter the number corresponding to the desired pay rate or action:\n");
        printf("Please input your total work time this week:");
        scanf("%lf",&time);

        if(time>OT_START)
        {
            sum = income *OT_START;
            sum += (time-OT_START)*1.5*income;
        }
        else
        {
            sum = income*time;
        }

        if(sum<FIRST_STEP)
        {
            sum = sum*(1-TAX_300);
        }
        else if (sum<SECOND_STEP)
        {
            sum = FIRST_STEP*(1-TAX_300)+(sum-FIRST_STEP)*TAX_450;
        }
        else
        {
            sum = FIRST_STEP*(1-TAX_300)+TAX_450*(SECOND_STEP-FIRST_STEP)+TAX_MORE*(sum-SECOND_STEP);
        }

        printf("totoal income(After tax):%.2lf\n",sum);
    }
    else
    {
        printf("quit\n");
    }

    return 0;
}

/*第8题*/
int screen2(void);
int ch8_E8(void)
{
    char ch;
    double num1, num2, result;
    screen2();
    while((ch = getchar())!='q')
    {
        while(getchar()!='\n')
        {
            continue;
        }
        printf("Enter first number:\n");
        while(scanf("%lf",&num1)!=1)
        {
            printf("Please enter a number, such as 2.5, -1.78E8, or 3:\n");
        }
        printf("Enter second number:\n");
        while(scanf("%lf",&num2)!=1)
        {
            printf("Please enter a number, such as 2.5, -1.78E8, or 3:\n");
        }
        switch (ch)
        {
            case 'a':
                result = num1+num2;
                printf("%.1lf+%.1lf=%.1lf\n",num1,num2,result);
                break;
            case 's':
                result = num1-num2;
                printf("%.1lf-%.1lf=%.1lf\n",num1,num2,result);
                break;          
            case 'm':
                result = num1*num2;
                printf("%.1lf*%.1lf=%.1lf\n",num1,num2,result);
                break;
            case 'd':
                while(num2==0)
                {
                    printf("Enter a number other than 0:\n");
                    scanf("%lf",&num2);                    
                }
                result = num1/num2;
                printf("%.1lf/%.1lf=%.1lf\n",num1,num2,result);
                break;
            case 'q':
                break;                       
            default:
                printf("Please input the right choice.\n");
            break;
        }
    while(getchar()!='\n');      
    screen2();   
    }
    printf("Bye!\n");
    return 0;
}

int screen2(void)
{
    printf("Enter the operation of your choice:\n");
    printf("   a. add           s. subtract    \n");
    printf("   m. multiply      d. divide    \n");
    printf("   q. quit\n");

    return 0;
}