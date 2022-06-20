/*第1题*/

int ch7_E1(void)
{
    char list;
    int i=0;
    int n_number=0,b_number=0,o_number=0;
    printf("Please input a string:\n");
    
while((list=getchar())!='#')
{
    if(list ==' ')
    {
        b_number++;
    }
    else if (list == '\n')
    {
        n_number++;
    }
    else
    {
        o_number++;
    }
    
}


    printf("the string has %d blank space, %d enter, %d other chars.", b_number,n_number,o_number);

    return 0;

}

/*第2题*/
int ch7_E2(void)
{
    char ch;
    int i=0;
    printf("Please input a string:\n");
    while((ch=getchar())!='#')
    {
        if(i++%8==0)
        {
            printf("\n");
        }
        if(ch=='\n')
        {
            printf("'\\n'-%d,",ch);
        }
        else if (ch=='\t')
        {
            printf("'\\t'-%d,",ch);
        }
        else
        {
            printf("%c-%d,",ch,ch);
        }
        
    }
    printf("\nDone\n");
    return 0;
}

/*第3题*/
int ch7_E3(void)
{
    int number=0,count_odd=0,count_even=0;
    int sum_odd=0,sum_even=0;

    printf("Please input a number:");
    scanf("%d",&number);
    while(scanf("%d",&number))
    {
        if(number == 0) break;
        if(number%2==0)
        {
            sum_even = sum_even+number;
            count_even++;
        }
        else
        {
            sum_odd = sum_odd +number;
            count_odd++;
        }
    }

    printf("have %d odds, the average of odd numbers is %g\n",count_odd,1.0*sum_odd/count_odd);
    printf("have %d evens, the average of even numbers is %g\n",count_even,1.0*sum_even/count_even);

    return 0;
}

/*第4题*/
int ch7_E4(void)
{
    char ch;
    int count=0;

    while((ch=getchar())!='#')
    {
        if(ch=='.')
        {
            ch='!';
            count++;
        }
        else if (ch=='!')
        {
            putchar('!');
            count++;
        }
        putchar(ch);    
    }
    printf("\n%d replacement",count);
    return 0;
}

/*第5题*/
int ch7_E5(void)
{
    char ch;
    int count=0;

    while((ch=getchar())!='#')
    {
        switch (ch)
        {
        case '.':
            ch ='!';
            putchar(ch);
            count++;
            break;
        case '!':
            putchar(ch);
            putchar('!');
            count++;
            break;
        
        default:
            putchar(ch);
            break;
        }
    }
    printf("\n%d replacement",count);
    return 0;
}

/*第6题*/
int ch7_E6(void)
{
    char ch;
    int count=0;
    while ((ch=getchar())!='#')
    {
        if((ch=='e'&&(ch=getchar())=='i'))
        {
            count++;
        }
    }
    printf("the string has %d ei",count);

    return 0;
    
}

/*第6题,参考答案方法*/
int ch7_E6_1(void)
{
    char ch;
    int count=0;
    int halfpair=0;
    while ((ch=getchar())!='#')
    {
        switch (ch)
        {
        case 'e':
            halfpair=1;
            break;

        case 'i':
            if(halfpair==1)
                halfpair=0;
                count++;
            break;
        
        default:
            break;
        }
    }
    printf("the string has %d ei",count);

    return 0;
}

/*第7题*/
#define BASIC_INCOME_HOUR 10.00
#define OT_START 40
#define OT_HOUR 1.5
#define FIRST_STEP 300
#define SECOND_STEP 450
#define TAX_300 0.15
#define TAX_450 0.20
#define TAX_MORE 0.25

int ch7_E7(void)
{
    double time;
    double sum;
    printf("Please input your total work time this week:");
    scanf("%lf",&time);
    if(time>OT_START)
    {
        sum = BASIC_INCOME_HOUR *OT_START;
        sum += (time-OT_START)*1.5*BASIC_INCOME_HOUR;
    }
    else
    {
        sum = BASIC_INCOME_HOUR*time;
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

    return 0;
    
}


/*第8题*/
int ch7_E8(void)
{
    double time,sum,income;
    int choice,judge=0;
    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $8.75/hr                            2) $9.33/hr\n");
    printf("3) $10.00/hr                           4) $11.20/hr\n");
    printf("5)quit\n");
    printf("*****************************************************************\n");
    scanf("%d",&choice);
    while(judge==0)
    {
        switch (choice)
        {
        case 1:
            income =8.75;
            judge = 1;
            break;
        case 2:
            income =9.33;
            judge = 1;
            break;
        case 3:
            income =10.00;
            judge = 1;
            break;
        case 4:
            income =11.20;
            judge = 1;
            break;
        case 5:
            income = -1;
            judge = 1;
            break;
        default:
            printf("Please input the right number!");
            scanf("%d",&choice);
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

/*第9题*/
int ch7_E9(void)
{
    int number;
    int i,j;
    printf("Please input a number(>0):");
    do
    {
        scanf("%d",&number);
    }
    while(number<0 && printf("Please input a number(>0):"));

    printf("the prime numbers smaller than(include %d) %d are:\n",number,number);

    for(i=2;i<=number;i++)
    {
        for(j=2;j<i;j++)
        {
            if(i%j ==0)
                break;

        }

        if(j==i)
        {
            printf("%d,",i);
        }

    }

    printf("\n");

    return 0;
}

/*第10题*/

int Tax_caculator(int group, double income);
int input(void);

int ch7_E10(void)
{
    int group,i,j;
    double income;
    printf("start\n");

    do
    {
    input();
    i=scanf("%d",&group);
    printf("Enter your income:");
    j=scanf("%lf",&income);
    Tax_caculator(group,income);
    
    } 
    while (i==1 && j==1);

    printf("Bye!\n");
    
    return 0;
}

int input(void)
{
    printf("*****************************************************************\n");
    printf("Enter the number of your identity:\n");
    printf("1) single                            2) household\n");
    printf("3) married                           4) divorced\n");
    printf("q)quit\n");
    printf("*****************************************************************\n");    
}

#define TAX1 0.15
#define TAX2 0.28
#define SINGLE_INCOME 17850
#define HOUSEHOLDER__INCOME 23900
#define MARRIED_INCOME 29750
#define DIVORCED__INCOME 14875

int Tax_caculator(int group, double income)
{
    double tax;
    switch (group)
    {
    case 1:
        if(income>SINGLE_INCOME)
        {
            tax = SINGLE_INCOME*TAX1+(income-SINGLE_INCOME)*TAX2;
        }
        else
        {
            tax = income*TAX1;
        }

        printf("you are single and your income is $%lf, you need to pay $%lf this month.\n", income, tax);
        break;

    case 2:
        if(income>HOUSEHOLDER__INCOME)
        {
            tax = HOUSEHOLDER__INCOME*TAX1+(income-HOUSEHOLDER__INCOME)*TAX2;
        }
        else
        {
            tax = income*TAX1;
        }

        printf("you are householder and your income is $%lf, you need to pay $%lf this month.\n", income, tax);
        break;

    case 3:
        if(income>MARRIED_INCOME)
        {
            tax = MARRIED_INCOME*TAX1+(income-MARRIED_INCOME)*TAX2;
        }
        else
        {
            tax = income*TAX1;
        }

        printf("you are married and your income is $%lf, you need to pay $%lf this month.\n", income, tax);
        break;        

    case 4:
        if(income>DIVORCED__INCOME)
        {
            tax = DIVORCED__INCOME*TAX1+(income-DIVORCED__INCOME)*TAX2;
        }
        else
        {
            tax = income*TAX1;
        }

        printf("you are divorced and your income is $%lf, you need to pay $%lf this month.\n", income, tax);
        break;        
        
    default:
        printf("error, please input the right number!\n");
        break;
    }

    return 0;
}

/*第11题*/
#define P_price 2.05
#define B_price 1.15
#define C_price 1.09
double tran_fee_calculator(double total_weight);
double order_caculator(double weight_A,double weight_B,double weight_C);
double discount_calculator(double total_weight);
int screen(void);

int ch7_E11(void)
{
    int group,j;
    double weight_A=0.0,weight_B=0.0,weight_C=0.0,total_weight=0.0;
    double weight_A_input=0.0,weight_B_input=0.0,weight_C_input=0.0;
    double tran_fee, order_fee,total_fee;
    double discount;

    screen();
    scanf("%d",&group);
    do
    {
        printf("Enter the weight:");
        switch (group)
        {
            case 1:
                j=scanf("%lf",&weight_A_input);
                weight_A += weight_A_input;
                break;
            case 2:
                j=scanf("%lf",&weight_B_input);
                weight_B += weight_B_input;
                break;
            case 3:
                j=scanf("%lf",&weight_C_input);
                weight_C += weight_C_input;
                break;

            default:
                break;
        }
        screen();
    }
    while (scanf("%d",&group) && j==1);

    printf("finish order.\n");
    /*计算数量*/
    total_weight = weight_A+weight_B+weight_C;

    /*计算折扣、运费*/
    discount = discount_calculator(total_weight);
    tran_fee = tran_fee_calculator(total_weight);

    /*计算订购费*/
    order_fee = order_caculator(weight_A,weight_B,weight_C);

    /*计算总费用*/
    total_fee = order_fee+tran_fee-discount;

    printf("you ordered %.2lf Bounds of potatos\n",weight_A);
    printf("you ordered %.2lf Bounds of beets\n",weight_B);
    printf("you ordered %.2lf Bounds of carrots\n",weight_C);
    printf("******************************Fees list********************************\n");
    printf("your orders fee in total is%.2lf \n",order_fee);
    printf("your trans and package fee is %.2lf in total\n",tran_fee);
    printf("your discount is $%.2lf\n",discount);
    printf("totally you need to pay %.2lf in total\n",total_fee);
    
    return 0;

}

int screen(void)
{
    printf("*****************************************************************\n");
    printf("Enter the vegetable you want to order:\n");
    printf("1) potato  $2.05/Bound               2) Beet  $1.15/Bound\n");
    printf("3) carrot  $1.09/Bound               q) quit\n");
    printf("*****************************************************************\n");    
    return 0;    
}

double tran_fee_calculator(double total_weight)
{
    double discount=0;
    int total_weight_int;
    double tran_fee;
    if(total_weight<=5.0)
    {
        tran_fee = 6.5;
    }
    else if (total_weight<=20)
    {
        tran_fee = 14.0;
    }
    else if (total_weight<100)
    {
        tran_fee = 14.0 + (total_weight-20)*0.5;
    }
    else
    {
        total_weight_int = total_weight;
        discount = ((total_weight_int-(total_weight_int%100))/100)*5;
        tran_fee = (14.0 + (total_weight-20)*0.5)-discount;
    }

    
    return tran_fee;
}

double discount_calculator(double total_weight)
{
    double discount=0;
    int total_weight_int;
    if(total_weight>=100)
    {
        total_weight_int = total_weight;
        discount = ((total_weight_int-(total_weight_int%100))/100)*5;
    }
    else
    {
        discount = 0;
    }

    return discount;
}

double order_caculator(double weight_A,double weight_B,double weight_C)
{
    double order_fee;
    order_fee = (weight_A*P_price)+(weight_B*B_price)+(weight_C*C_price);

    return order_fee;

}