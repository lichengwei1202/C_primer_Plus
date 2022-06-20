/*第1题*/

#define MONTH 12
#define YEAR 5
int ch10_E1()
{
    const float rain[YEAR][MONTH]=
    {
        {4.3, 4,3, 4,3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
        {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
        {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
        {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
        {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
    };

    const float (*ptc)[MONTH]=rain;

    int month, year;
    double subtotal,total,month_total;

    printf("Year  RAINFALL(inches)\n");
    for(year=0,subtotal=0; year<YEAR;year++)
    {
        for(month=0; month<MONTH; month++)
        {
            subtotal = *(*(ptc+year)+month);
        }
        printf("%5d %15.1f\n",2010+year,subtotal);
        total += subtotal; 
    }

    printf("The yearly average is %.1f inches\n",total/YEAR);

    printf("MONTHLY AVERAGES:\n");
    printf("Jan Feb Mar Apr May Jun Jul Aug Sept Oct Nov Dec\n");

    for(month=0; month<MONTH; month++)
    {
        for(year=0; year<YEAR; year++)
        {
            month_total = *(*(ptc+year)+month);
        }
        printf(" %.1f",month_total);
    }
    printf("\n");



    return 0;
}

/*第2题*/
int copy_arr(double target1[], double source[],int num);
int copy_ptr(double *t, double *s,int num);
int copy_ptrs(double *t_3, double *s,double *e);
int ch10_E2()
{
    double source[5]={1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    int i;

    copy_arr(target1,source,5);
    printf("*********target 1************\n");    
    printf("Index     num\n");
    for(i=0;i<5;i++)
    {
        printf("%5d %10.1f\n",i, target1[i]);
    }

    copy_ptr(target2,source,5);
    printf("*********target 2************\n");
    printf("Index     num\n");
    for(i=0;i<5;i++)
    {
        printf("%5d %10.1f\n",i, target2[i]);
    }

    copy_ptrs(target3,source,source+5);
    printf("*********target 3************\n");
    printf("Index     num\n");
    for(i=0;i<5;i++)
    {
        printf("%5d %10.1f\n",i, target3[i]);
    }
    return 0;
}

int copy_arr(double target1[], double source[],int num)
{
    int i;
    for(i=0;i<num;i++)
    {
        target1[i]=source[i];
    }

    return 0;
}

int copy_ptr(double *t, double *s,int num)
{
    int i;
    for(i=0;i<num;i++)
    {
        *(t+i)= *(s+i);
    }

    return 0;
}

int copy_ptrs(double *t_3, double *s,double *e)
{
    while (*s!=*e)
    {
        *t_3=*s;
        *s++;
        *t_3++;
    }

    return 0;
}

/*第3题*/
int max(int *list, int num);
int max2(int list[], int num);
int ch10_E3()
{
    int list[4]={1,2,3,4};
    int result;

    result = max(list,4);

    printf("the largest number of the list is %d",result);

    return 0;

}

int max(int *list, int num)
{
    int max;
    int i,j=0;
    for(i=0;i<num;i++)
    {
        if(*(list+i)>*(list+j))
        {
            j=i;
        }
    }

    return list[j];
}

int max2(int list[], int num)
{
    int max;
    int i,j=0;
    for(i=0;i<num;i++)
    {
        if(list[i]>list[j])
        {
            j=i;
        }
    }

    return list[j];
}


/*第4题*/
int max_E4(double *l, int num);
int ch10_E4()
{
    double list[5]={1.1,23.32,13.32,56.3,32.4};
    printf("the subscript %d of the list is the largest", max_E4(list,5));

}

int max_E4(double *l, int num)
{
    int i,j;
    for(i=0;i<num;i++)
    {
        if(*(l+i)>*(l+j))
        {
            j=i;
        }
        
    }

    return j;
}

/*第5题*/

double min_to_max(double *l, int num);
int ch10_E5(void)
{
    double list[5]={1.1,23.32,13.32,50.3,32.4};
    double mtm;
    mtm = min_to_max(list,5);

    printf("the gap between the largest to smallest of the list is %f\n",mtm);

    return 0;
}

double min_to_max(double *l, int num)
{
    int i,j=0,k=0;
    double mtm;

    for(i=0;i<num;i++)
    {
        if(*(l+i)>*(l+j))
        {
            j=i;
        }
        else if (*(l+i)<*(l+k))
        {
            k=i;
        }
    }

    mtm = l[j];

    return mtm;
}

/*第6题*/
int sort_E6(double *l,int num);
int ch10_E6(void)
{
    double list[4]={4.0,3.0,1.0,2.0};
    int i;
    sort_E6(list,4);

    printf("Index     num\n");
    for(i=0;i<4;i++)
    {
        printf("%2d %10.1f\n",i,list[i]);
    }

    return 0;
}

int sort_E6(double *l,int num)
{
    int i,j;
    double temp;

    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            if(*(l+j)<*(l+i))
            {
                temp = *(l+j);
                *(l+j)=*(l+i);
                *(l+i)=temp;
            }
        }
    }

    return 0;
}

/*第7题*/
#define COLS 5
#define ROWS 2
void copy_2d_array(double (*l)[ROWS],double (*s)[ROWS],int cols);
int ch10_E7(void)
{
    double list[COLS][ROWS]={{2,3},{4,3},{5,6},{7,2},{10,1}};
    double target[COLS][ROWS];
    int i,j;
    copy_2d_array(target,list,5);
    printf("Index      num\n");
    for(i=0;i<5;i++)
    {

        printf("%d %10.1f %.1f\n",i,target[i][0],target[i][1]);
    }

    return 0;
}

void copy_2d_array(double (*l)[ROWS],double (*s)[ROWS],int cols)
{
    int i;
    for(i=0;i<cols;i++)
    {
        copy_arr(l[i],s[i],ROWS);
    }
}

/*第8题*/
void copy_part(double *l,double *s,int start, int length);
int ch10_E8(void)
{
    double source[7] = {1,2,3,4,5,6,7};
    double target[3];
    int i;
    copy_part(target,source,3,5);
    printf("Index      num\n");
    for(i=0;i<3;i++)
    {

        printf("%d %10.1f\n",i,target[i]);
    }

    return 0;


}

void copy_part(double *l,double *s,int start, int length)
{
    for(int i=start-1;i<start+length;i++)
    {
        *(l+i-start+1)=*(s+i);
    }
}

/*第9题*/
void copy_9(int cols, int rows, int t[cols][rows], int s[cols][rows]);
int ch10_E9(void)
{
    int list[3][5]={{1,2,3,4,5},{12,23,13,45,32},{123,342,453,765,645}};
    int target[3][5];
    copy_9(3,5,target,list);

    printf("Index      num\n");
    for(int i=0;i<3;i++)
    {

        printf("%d     ",i);
        for(int j=0;j<5;j++)
        {
            printf("%d ",target[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void copy_9(int cols, int rows, int t[cols][rows],int s[cols][rows])
{
    for(int i=0;i<cols;i++)
    {
        for(int j=0;j<rows;j++)
            {
                t[i][j]=s[i][j];
            }        
    }

}

/*第10题*/
void add_together(double *l,double *s,double *r, int num);
int ch10_E10(void)
{
    double first[5]={1,2,3,4,5};
    double second[5]={5,4,3,2,1};
    double result[5];
    add_together(first,second,result,5);

    printf("Index     num\n");
    for(int i=0;i<5;i++)
    {
        printf("%2d %10.1f\n",i,result[i]);
    }

    return 0;
}

void add_together(double *l,double *s,double *r, int num)
{
    for(int i=0; i<num;i++)
    {
        *(r+i)=*(l+i)+*(s+i);
    }   
}

/*第11题*/

void show_list_11(int cols,int rows,int list[cols][rows]);
void double_list(int cols,int rows,int list[cols][rows]);

int ch10_E11(void)
{
    int list[3][5]={{1,2,3,4,5},
                    {3,4,5,6,7},
                    {9,1,4,3,5},};
    
    show_list_11(3,5,list);
    double_list(3,5,list);
    show_list_11(3,5,list);
    
    return 0;
}

void show_list_11(int cols,int rows,int list[cols][rows])
{
    for(int i=0;i<cols;i++)
    {
        for(int j=0;j<rows;j++)
        {
            printf("%d,",list[i][j]);
        }      
        printf("\n");  
    }
    printf("**************finished*****************\n");  
}

void double_list(int cols,int rows,int list[cols][rows])
{
    for(int i=0;i<cols;i++)
    {
        for(int j=0;j<rows;j++)
        {
            list[i][j]=list[i][j]*2;
        }
    }
}

/*第12题*/
void annual_precipitation(double (*ra)[MONTH],double *re,int year);
double yearly_average(double *re, int year);
void monthly_average(double (*ra)[MONTH], double *re, int year);
int ch10_E12(void)
{
    const double rain[5][MONTH]=
    {
        {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
        {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
        {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
        {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
        {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
    };
    double result_y[5];
    double result_m[MONTH];
    double average;
    annual_precipitation(rain, result_y,5);

    average=yearly_average(result_y,5);
    printf("The yearly average is %.1f inches\n",average);

    monthly_average(rain,result_m,5);


}

void annual_precipitation(double (*ra)[MONTH],double *re,int year) /*rain.c中计算年降雨量函数*/
{
    for(int i=0;i<year;i++)
    {
        for(int j=0;j<MONTH;j++)
        {
            *(re+i) += *(*(ra+i)+j);
        }
    }

    printf("Index     rainfall(inches)\n");
    for(int k=0;k<year;k++)
    {
        printf("%2d %10.1f\n",k,*(re+k));
    }
}


double yearly_average(double *re, int year)
{
    double sum=0.0,average;
    for(int i=0;i<year;i++)
    {
        sum += *(re+i);
    }
    average = sum/year;
    return average;
}

void monthly_average(double (*ra)[MONTH], double *re, int year)
{
    for(int i=0;i<MONTH;i++)
    {
        for(int j=0;j<year;j++)
        {
            *(re+i) += *(*(ra+j)+i);
        }
    }

    printf("Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sept  Oct  Nov  Dec\n");
    for(int k=0;k<MONTH;k++)
    {
        printf("%4.1f ",*(re+k)/year);
    }
}

/*第13题*/
void function_a(int num,double a[],double b[],double c[],double result[3][num]);
int ch10_E13(void)
{
    double a[5],b[5],c[5];
    double result[3][5];
    printf("Please input 3 list of numbers\n");
    printf("Please input the first list:\n");
    scanf("%lf %lf %lf %lf %lf", a,a+1,a+2,a+3,a+4);
    printf("Please input the second list:\n");
    scanf("%lf %lf %lf %lf %lf", b,b+1,b+2,b+3,b+4);
    printf("Please input the third list:\n");
    scanf("%lf %lf %lf %lf %lf", c,c+1,c+2,c+3,c+4);

    function_a(5,a,b,c,result);
    printf("Index     num\n");
    for(int k=0;k<3;k++)
    {
        printf("%2d  ",k);
        for(int i=0;i<5;i++)
        {
            printf("%.1f ",*(*(result+k)+i));
        }
        printf("\n");
    }
    return 0;
}

void function_a(int num,double a[],double b[],double c[],double result[3][num])
{
    for(int j=0;j<num;j++)
    {
        result[0][j]=a[j];
        result[1][j]=b[j];
        result[2][j]=c[j];
    }
}

double function_b(double a[],int num)
{
    double sum=0, average;
    for(int i=0;i<num;i++)
    {
        sum += a[i];
    }
    average = sum/num;

    return average;
}

double function_c(int num, double a[3][num])
{
    int sum=0, average;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<num;j++)
        {
            sum += a[i][j];
        }
    }

    average = sum/(num*3);

    return average;
}

double function_d(int num, double a[3][num])
{
    double result=a[0][0];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<num;j++)
        {
            if(result<a[i][j])
            {
                result = a[i][j];
            }
        }
    }
    return result;
}

int test(int *a,int num)
{

}