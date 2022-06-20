#define ch14_R1_LEN 40

struct ch14_R1_S
{
    char *first;
    char *last;
};

int ch14_R1(void)
{
    struct ch14_R1_S accountant = {"Mike", "Ross"};
    printf("%s %s",accountant.first, accountant.last);
    
    return 0;
}

/*R2*/
#define LIM_ch14_R3 40
struct Month
{
    char month_name[LIM_ch14_R3];
    char title[LIM_ch14_R3];
    int date_num;
    int month_No;
};

int ch14_R2(void)
{
    struct Month Year_2022[12]=
    {
        {"January","JAN",31,1},
        {"Febuary","FEB",28,2},
        {"March","MAR",31,3},
        {"April","APRI",30,4},
        {"May","MAY",31,5},
        {"June","JUN",30,6},
        {"July","JUL",31,7},
        {"Augest","AUG",30,8},
        {"September","SEPT",31,9},
        {"October","OCT",30,10},
        {"November","NOV",31,11},
        {"December","DEC",30,12}
    };
    int i=0;
    int month_chose;
    int date_result=0;
    printf("give me a month,I'll show you how many days pased tile this month:");
    
    while (scanf("%d",&month_chose)!=1||month_chose>12||month_chose<1) continue;
    
    date_result = Year_2022[0].date_num;
    do
    {
        i++;
        date_result+=Year_2022[i].date_num;
    } while (Year_2022[i].month_No!=month_chose);
    
    printf("%d days in total",date_result);
    return 0;
}

/*R3*/
struct chapt14_R3_name
{
    char first[40];
    char last[40];
};

struct chapt14_R3_bem
{
    int limbs;
    struct chapt14_R3_name title;
    char type[30];
};
int ch14_R3_print(struct chapt14_R3_bem *input);
int ch14_R3(void)
{
    struct chapt14_R3_bem deb=
    {
        6,
        {"Berbnazel","Gwolkapwolk"},
        "Arcturan"
    };
    printf("now print\n");
    scanf("%d",&(&deb)->limbs);
    ch14_R3_print(&deb);
    return 0;
}
int ch14_R3_print(struct chapt14_R3_bem *input)
{
    printf("%s %s is a %d-limbed %s",input->title.first, input->title.last, input->limbs, input->type);

    return 0;
}

/*R4
struct chapt14_R4_gas
{
    float distance;
    float gals;
    float mpg;
};

int ch14_R4(void)
{
    void *pf(struct chapt14_R4_gas *);
    char ps[40]="ch14_R4_mpg_cal";
    pf=ps;
    return 0;
}

void ch14_R4_mpg_cal(struct chapt14_R4_gas *input)
{
    input->mpg=input->distance/input->gals;
}
*/