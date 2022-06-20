#include <stdio.h>
/*第1题*/
int ch3_E1(void)
{
    int a=2147483647;
    float b=-10.0/3;
    printf("int a=2^16-1---------output of int a=%d\n",a);
    printf("int a=2^16---------output of int a=%d(overflow)\n",a+1);
    printf("float b=10.0/3------output of float b=%f\n",b);
    return 0;
}

/*第2题*/
int ch3_E2(void)
{
    unsigned char a;
    printf("enter a number:");
    scanf("%d",&a);
    printf("ASCII:%c\n",a);
    return 0;
}

/*第3题*/
int ch3_E3(void)
{
    char a='\a';
    printf("%c",a);
    printf("Startled by the sudden sound, Sally shouted,\n 'By the Great Pumpkin, what was that!'\n");

    return 0;
}

/*第4题*/
int ch3_E4(void)
{
    float a;
    printf("Enter a floating-point value:\n");
    scanf("%f",&a);
    printf("fixed-point notation: %f\n",a);
    printf("exponential notation: %e\n",a);
    printf("p notation:%x\n",a);
    return 0;
}

/*第5题*/
#define ONE_YEAR 3.156E7
int ch3_E5(void)
{
    int year;
    float seconds;
    printf("Please input your name, I'll transfer into seconds\n");
    scanf("%d",&year);
    seconds = year*ONE_YEAR;
    printf("You are %d years old, which is %e seconds.", year, seconds);

    return 0;
}

/*第6题*/

#define ONE_molecule 3.0E-23
#define ONE_QUART 950
int ch3_E6(void)
{
    double quarts;
    printf("Please input the number of quarts:\n");
    scanf("%lf",&quarts);
    printf("%f quarts of water have %e water molecules.\n",quarts,quarts*ONE_QUART/ONE_molecule);

    return 0;

}

/*第7题*/

/*第8题*/
#define ONE_PINT_TO_CUP 2
#define ONE_CUP_TO_OUNCE 8
#define ONE_OUNCE_TO_SOUP 2
#define ONE_SOUP_TO_TEASPOON 3

int ch3_E8(void)
{
    float cup;
    printf("input the number of cups:\n");
    scanf("%f",&cup);

    printf("%f cups equal to %f pints\n",cup,cup/2);
    printf("%f cups equal to %f ounces\n",cup,8*cup);
    printf("%f cups equal to %f soup spoons\n",cup,8*2*cup);
    printf("%f cups equal to %f teaspoons\n",cup,8*2*3*cup);

    return 0;
}