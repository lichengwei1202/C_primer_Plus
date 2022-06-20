#include "pe12-2a.h"
/*第1题*/
void critic(int *units);
int ch12_E1(void)
{
    int units=0;
    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while (units!=56)
    {
        critic(&units);
    }

    printf("You must have looked it up!\n");
}

void critic(int *units)
{
    printf("No luck, my friend. Try again!\n");
    scanf("%d",units);
}

/*第2题--要求提供pe12-2a.h头文件和pe12-2a.c源文件，详情见两个文件*/
int ch12_E2(void)
{
    int mode;

    printf("Enter 0 for metric mode, 1 for US mode:");
    scanf("%d",&mode);

    while (mode>=0)
    {
        printf("mode=%d\n",mode);
        set_mode(mode);
        get_info();
        show_info();

        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" Enter -1 to quit:");
        scanf("%d", &mode);
    }

    printf("Done\n");

    return 0;
}

void set_mode(int mode_input)
{
    if (mode_input==0||mode_input==1)
    {
        ch12_mode =mode_input;
    }
    else
    {
        if (ch12_mode==0)
        {
            printf("Invalid mode specified. Mode %d(metric) used.",ch12_mode);
        }
        else if(ch12_mode==1)
        {
            printf("Invalid mode specified. Mode %d(US) used.",ch12_mode);
        }        
        
    }
    printf("ch12_mode=%d\n",ch12_mode);
}

void get_info()
{
    if (ch12_mode==0)
    {
        printf("Enter distance traveled in KMs:");
        scanf("%lf",&ch12_length);
        printf("Enter fuel consumed in liters:");
        scanf("%lf",&ch12_oil_consum);
    }
    else if (ch12_mode==1)
    {
        printf("Enter distance traveled in miles:");
        scanf("%lf",&ch12_length);
        printf("Enter fuel consumed in gallons:");
        scanf("%lf",&ch12_oil_consum);        
    }
    
    
}

void show_info()
{
    if (ch12_mode==0)
    {
        printf("Fuel consumption is %.1lf liters per 100KMs\n",ch12_oil_consum*100/ch12_length);
    }
    else if (ch12_mode==1)
    {
        printf("Fuel consumption is %.1lf miles per gallon\n",ch12_length/ch12_oil_consum); 
    }
}

/*第3题*/
int ch12_E3(void)
{
    int mode=0;
    int mode_last=mode;
    double length=0;
    double oil_consume=0;
    printf("Enter 0 for metric mode, 1 for US mode:\n");
    scanf("%d",&mode);

    while (mode>=0)
    {
        set_mode_E3(mode,mode_last);
        get_info_E3(mode, &length, &oil_consume);
        show_info_E3(mode, &length, &oil_consume);

        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" Enter -1 to quit:\n");
        mode_last=mode;
        scanf("%d", &mode);
    }

    printf("Done\n");

    return 0;
}

void set_mode_E3(int mode_input, int mode_last)
{
    if (mode_input==0||mode_input==1)
    {
        printf("mode=%d\n",mode_input);   
    }
    else
    {
        if (mode_last==0)
        {
            printf("Invalid mode specified. Mode %d(metric) used.\n",mode_last);
        }
        else if(mode_last==1)
        {
            printf("Invalid mode specified. Mode %d(US) used.\n",mode_last);
        }        
        
    } 
}

void get_info_E3(int mode, double *length, double *oil_consum)
{
    if (mode==0)
    {
        printf("Enter distance traveled in KMs:\n");
        scanf("%lf",length);
        printf("Enter fuel consumed in liters:\n");
        scanf("%lf",oil_consum);
    }
    else if (mode==1)
    {
        printf("Enter distance traveled in miles:\n");
        scanf("%lf",length);
        printf("Enter fuel consumed in gallons:\n");
        scanf("%lf",oil_consum);        
    }
    
    
}

void show_info_E3(int mode, double *length, double *oil_consum)
{
    if (mode==0)
    {
        printf("Fuel consumption is %.1lf liters per 100KMs\n",(*oil_consum)*100/(*length));
    }
    else if (mode==1)
    {
        printf("Fuel consumption is %.1lf miles per gallon\n",(*length)/(*oil_consum)); 
    }
}

/*第4题*/
int ch12_E4(void)
{
    int total;
    int call;
    printf("How many times you want to call:\n");
    scanf("%d",&total);
    for (int i = 0; i < total; i++)
    {
        call=ch12_E4_call_count();
        printf("%d time\n",call);
    }

    printf("Done\n");
    

}

int ch12_E4_call_count()
{
    static int count=0;
    count++;
    return count;
}

/*第5题--随机数加随机种子*/
int ch12_E5()
{
    int input;
    int count;
    int random_num[100];
    printf("Please input a seed:\n");
    while (scanf("%d",&input)!=1)
    {
        printf("Please input a integer,try again:\n");
    }
    printf("How many randoms you want to produce:\n");
    while (scanf("%d",&count)!=1)
    {
        printf("Please input a integer,try again:\n");
    }
    myseed(input);
    for (int i = 0; i < count; i++)
    {
        random_num[i]=myrand();
    }

    ch12_E5_mysort(random_num, count);

    for (int k = 0; k < count; k++)
    {
        printf("%d\n",random_num[k]);
    }
    
}

int myrand()
{
    static unsigned int i=0;
    i=(i+1)*35;
    next = next*i+3;
    next = next%10;
    return next;
}

int myseed(int input)
{
    next = input;
}

int ch12_E5_mysort(int *st, int n)
{
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (st[i]<st[j])
            {
                temp = st[j];
                st[j] = st[i];
                st[i] = temp;
            }
            
        }
        
    }
    
}

/*第6题*/
int ch12_E6()
{
    int input;
    int count=100;
    int count_2=0;
    int count_3=0;
    int random_num[1000];
    int sort_count=0;

    while (count_3!=10)
    {
        printf("Please input a seed:\n");
        while (scanf("%d",&input)!=1)
        {
            printf("Please input a integer,try again:\n");
        }        
        myseed(input);   
    
        for (int i = 0; i < count; i++)
        {
            random_num[count_3*count+i]=myrand();
        }
        count_3++;
    }

    ch12_E5_mysort(random_num, 1000);

    for (int k = 1; k < 1000; k++)
    {
        sort_count++;
        if (random_num[k]!=random_num[k-1])
        {
            printf("%d--%d\n",random_num[k-1],sort_count);
            sort_count=0;
        }
        
    }
    
}

/*第7题*/
int ch12_E7(void)
{
    int sets;
    int sides;
    int dice;
    int result;

    printf("Enter the number of sets; enter q to stop:\n");
    while ((scanf("%d",&sets)==1))
    {
        printf("How many sides and how many dice?\n");
        while((scanf("%d %d",&sides,&dice))!=2&&sides>1&&dice>1)
        {
            printf("Please input two positive integers!\nHow many sides and how many dice?\n");
        }

        int list[sets];
        srand((unsigned int) time(NULL));
        for (int i = 0; i < sets; i++)
        {
            result=0;
            for (int j = 0; j < dice; j++)
            {
                result += ch12_E7_roll_dice(sides);
            }
            list[i]=result;

        }
        
        printf("Here are %d sets of %d %d-sided throws\n",sets,dice,sides);
        for (int k = 0; k < sets; k++)
        {
            printf("%d  ",list[k]);
        }
        printf("\nEnter the number of sets; enter q to stop:\n");
    }
    


    return 0;
}

int ch12_E7_roll_dice(int side)
{
    int roll = rand()%side+1;

    return roll;
}

/*第8题：主函数已经给了，需要完善两个被调函数*/
int ch12_E8(void)
{
    int *pa;
    int size;
    int value;

    printf("Enter the number of elements:\n");
    while ((scanf("%d", &size))==1&&size>0)
    {
        printf("Enter the initialization value: ");
        scanf("%d", &value);
        pa = make_array(size, value);
        if(pa)
        {
            show_array(pa,size);
            free(pa);
        }
        printf("Enter the number of elements (<1 to quit):");
    }
    printf("Done.\n");
    return 0;
    
}

int *make_array(int elem, int val)
{
    int *st;
    if (elem<1)
    {
        return NULL;
    }
    
    st = (int *)malloc(elem*sizeof(int));

    for (int i = 0; i < elem; i++)
    {
        *(st+i) = val;
    }
    
    return st;

}

void show_array(const int ar[],int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",ar[i]);
        if (i%8==7)
        {
            printf("\n");
        }
        
    }
    printf("\n");
}

/*第9题*/
int ch12_E9(void)
{
    int num;
    char *temp;
    char **st=(char **)malloc(ch12_E9_ARR*sizeof(char*));

    printf("How many words you want to enter?");
    scanf("%d", &num);
    printf("Enter %d words now:\n",num);
    for (int i = 0; i < num; i++)
    {
        char temp[ch12_E9_ARR];
        scanf("%s",temp);
        int length = strlen(temp);
        char *ptr = (char *)malloc(length*sizeof(char));
        strcpy(ptr,temp);
        st[i]=ptr;
    }
    printf("Here are your %d words\n",num);
    for (int j = 0; j < num; j++)
    {
        printf("%s\n",st[j]);
    }

    free(st);
    

    printf("Done\n");
    return 0;

}

