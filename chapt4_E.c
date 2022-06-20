/*第1题*/
int ch4_E1(void)
{
    char first_name[40];
    char last_name[40];

    printf("first name:");
    scanf("%s",first_name);
    printf("last name:");
    scanf("%s",last_name);
    printf("last name:%s\nfirst name:%s\n",last_name,first_name);

    return 0;
}

/***第2题*/
int ch4_E2(void)
{
    char name[40];
    int width = strlen(name);
    printf("please input your name:");
    scanf("%s",name);
    printf("%s\n",name);
    printf("\"%s\"\n",name);
    printf("\"%20s\"\n",name);
    printf("\"%-20s\"\n",name);
    printf("\"%*s\"\n",width+3,name);

    return 0;
}

/*第3题*/
int ch4_E3(void)
{
    float number;
    printf("please input a float:");
    scanf("%f",&number);

    printf("the input is %.1for%.1e",number,number);
    printf("the input is %+.3for%.3e",number,number);
     return 0;

}

/*第4题*/
int ch4_E4(void)
{
    char name[40];
    float height;
    printf("please input your name:\n");
    scanf("%s",name);
    printf("please input your height:\n");
    scanf("%f",&height);

    printf("%s, you are %.3f feet tall\n",name, height);

    return 0;

}


/*第5题*/
int ch4_E5(void)
{
    float rate,size;
    printf("Please input the download rateof your computer(Mb/s):\n");
    scanf("%f",&rate);
    printf("Please input the size of your file(Mb):\n");
    scanf("%f",&size);

    printf("At %.2f megabits per second, a file of %.2f megabytes downloads in %.2f seconds",rate, size, size*8/rate);

    return 0;

}

/*第6题*/
int ch4_E6(void)
{
    char name[40];
    char surname[40];

    int name_length,surname_length;

    printf("What's your name?\n");
    scanf("%s",name);
    printf("What's your surname\n");
    scanf("%s",surname);

    name_length=strlen(name);
    surname_length=strlen(surname);

    printf("%s %s\n",name,surname);
    printf("%*d %*d\n",name_length,name_length,surname_length,surname_length);

    printf("%s %s\n",name,surname);
    printf("%-*d %-*d\n",name_length,name_length,surname_length,surname_length);


    return 0;


}

/*第7题*/
int ch4_E7(void)
{
    double a=1.0/3.0;
    float b=1.0/3.0;

    printf("%.6f,%.6f\n",a,b);
    printf("%.12f,%.12f\n",a,b);
    printf("%.16f,%.16f\n",a,b);
    printf("%d,%d\n",FLT_DIG,DBL_DIG);

    return 0;
}

/*第8题*/

#define T_RATE 3.785/1.609
int ch4_E8(void)
{
    float miles;
    float gasoline;
    float rate;
    printf("How long did you travel?\n");
    scanf("%f",&miles);
    printf("How much gasoline did you cost?\n");
    scanf("%f",&gasoline);

    rate = miles/gasoline;
    
    printf("Your oil wear is %.1f Miles/Gallon(US),whcih is %.1f litres/Km(UK).\n",rate, T_RATE*rate);

    return 0;


}