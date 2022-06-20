#include <stdio.h>

/*第一题*/

#define FIRSTNAME "chengwei"
#define LASTNAME "Li"

void E1(void)
{
    printf("%s %s\n", FIRSTNAME, LASTNAME);
    printf("%s\n%s\n", FIRSTNAME, LASTNAME);
    printf("%s", FIRSTNAME);
    printf("%s\n", LASTNAME);
}

/*第二题*/
#define ADDRESS "shanghai"
#define NAME "CHENGWEI"

int E2(void)
{
    printf("Address: %s\n Name: %s\n",ADDRESS,NAME);
    return 0;
}

/*第三题*/
#define AGE 27
int E3(void)
{
    printf("My age is %d (days:%d)\n",AGE,AGE*365);
    return 0;
}

/*第四题*/
int jolly(void)
{
    int i;
    for(i=0;i<=2;i++)
    {
        printf("For he's a jolly good fellow!\n");
    }
    return 0;
}

int deny(void)
{
    printf("Which nobody can deny!\n");
    return 0;
}

int E4(void)
{
    jolly();
    deny();
    return 0;
}
/*第五题*/
int br(void)
{
    printf("Brazil, Russia");
    return 0;
}

int ic(void)
{
    printf("India, China");
    return 0;
}

int E5(void)
{
    br();
    printf(", ");
    ic();
    printf("\n");
    ic();
    printf("\n");
    br();
    printf("\n");
    return 0;

}

/*第六题*/
int E6(void)
{
    int toes = 10;
    printf("%d %d %d\n", toes, toes*2, toes*toes);
    return 0;
}

/*第七题*/
int smile(void)
{
    printf("smile!");
    return 0;
}
int E7(void)
{
    smile();smile();smile();
    printf("\n");
    smile();smile();
    printf("\n");
    smile();
    printf("\n");
    return 0;
}

/*第八题*/
int two(void)
{
    printf("two\n");
    return 0;
}
int one_three(void)
{
    printf("one\n");
    two();
    printf("three\n");
    return 0;
}

int E8(void)
{
    printf("starting now:\n");
    one_three();
    return 0;
}