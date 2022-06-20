/*第1题*/
#define HOUR_MIN 60
int ch5_E1(void)
{
    int mins;
    int hours,min;
    printf("Input the time measured in minute\n");
    scanf("%d",&mins);
    while (mins>0)
    {
        hours = mins/60;
        min = mins-hours*60;
        printf("the time is %d hour %d mins\n",hours,min);
        printf("Input the time measured in minute\n");
        scanf("%d",&mins);
    }
    return 0;
}

/*第2题*/
int ch5_E2(void)
{
    int a, i=0;
    printf("Please iuput a number:\n");
    scanf("%d",&a);
    printf("10 numbers bigger than %d:\n",a);
    while(i++<11)
    {
        printf("%d\n",a++);
    }

    return 0;
}

/*第3题*/
int ch5_E3(void)
{
    int weeks, days, day;
    printf("Please input the number of days:\n");
    scanf("%d",&days);
    while(days>0)
    {
        weeks =days/7;
        day = days-weeks*7;
        printf("%d days are %d weeks, %d days\n",days, weeks, day);

        printf("Please input the number of days:\n");
        scanf("%d",&days);
    }
    printf("ERROR\n");
    return 0;
}

/*第4题*/
int ch5_E4(void)
{
    const double FEET_TO_CM=30.48;
    const double INCH_TO_CM=2.54;
    double h_cm,h_inch,h_inches;
    int h_feet;
    printf("Enter a height in centimeters:");
    scanf("%lf",&h_cm);
    h_feet = h_cm/FEET_TO_CM;
    h_inches = h_cm/INCH_TO_CM;
    h_inch =h_inches-h_feet*FEET_TO_CM/INCH_TO_CM;

    while(h_cm>0)
    {
        printf("%.1lf cm = %d feet, %.1lf inches\n",h_cm,h_feet,h_inch);
        printf("Enter a height in centimeters:");
        scanf("%lf",&h_cm);
        h_feet = h_cm/FEET_TO_CM;
        h_inches = h_cm/INCH_TO_CM;
        h_inch =h_inches-h_feet*FEET_TO_CM/INCH_TO_CM;
    }
    printf("bye\n");

    return 0;
}

/*第5题*/
int ch5_E5(void)
{
    int count=0,max,sum=0;
    printf("give a number, I can show you the sum from 1 to it.\n");
    scanf("%d",&max);
    while(count++<max)
    {
        sum = sum + count;
    }
    printf("the sum is %d",sum);
    return 0;
}

/*第6题*/
int ch5_E6(void)
{
    int count=0,sum=0;
    printf("give a number, I can show you the sum of square from 1 to it.\n");
    scanf("%d",&count);
    while(count>0)
    {
        sum = sum + count*count;
        count--;
    }
    printf("the sum is %d",sum);    

    return 0;
}

/*第7题*/
int fabric(int input)
{
    int a,b;
    a = input;
    b = a*a*a;
    printf("%d",b);

    return 0;
}

int ch5_E7(void)
{
    int number;
    scanf("%d",&number);

    fabric(number);

    return 0;
}

/*第8题*/
int ch5_E8(void)
{
    int operand_1, operand_2, moduli;
    printf("This program computes moduli.\n");
    printf("Enter an integer to serve as the second operand:");
    scanf("%d",&operand_2);

    printf("Enter an integer to serve as the first operand:");
    scanf("%d",&operand_1);

    while (operand_1>0)
    {
        moduli = operand_1-(operand_1/operand_2)*operand_2;
        printf("%d %% %d is %d\n",operand_1,operand_2,moduli);
        printf("Enter an integer to serve as the first operand（<=0 to quit）:");
        scanf("%d",&operand_1);
    }
    printf("Done");

    return 0;
    
}

/*第9题*/

int Temperatures(double F_scale);

int ch5_E9(void)
{
    double F_scale;
    printf("Give me a temperature in F-scale:\n");
    while(scanf("%lf",&F_scale) == 1)
    {
        Temperatures(F_scale);
        printf("Give me a temperature in F-scale(q to quit):\n");  
    }
    printf("Done.\n");
    return 0;
}
const double ABSOLUTE_ZERO = -273.16;
int Temperatures(double F_scale)
{
    double C_scale, K_scale;
    C_scale = 5.0/9.0*(F_scale-32.0);
    K_scale = C_scale-ABSOLUTE_ZERO;
    printf("%.1lf F = %.1lf C = %.1lf K\n",F_scale,C_scale,K_scale);
    
    return 0;
}
