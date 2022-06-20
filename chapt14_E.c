/*第1题*/
struct chpt14_E1_Month
{
    char month_name[LIM_ch14_R3];
    char title[LIM_ch14_R3];
    int date_num;
    int month_No;
};

int chpt14_E1(void)
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

    char month_input[40];
    int i=0;
    int date=Year_2022[i].date_num;
    printf("which month do you chose:\n");
    scanf("%s",month_input);

    do
    {
        i++;
        date += Year_2022[i].date_num;
    } while (strcmp(month_input,Year_2022[i].month_name)!=0||i==12);

    printf("%d days have left tile %s",date,month_input);
    
    return 0;
}

/*第2题,引用第1题的struct*/

int ch14_E2(void)
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

    
}