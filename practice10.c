#include <stdio.h>

/*这个例子说明了2个内容：
    1. 数组的名称是数组第一个元素的地址
    2. 指针的加减运表示的是该类数据类型的前/后一个元素的第一个字节的地址*/
int main(void)
{
    const int size=4;

    int index;
    short dates[size];
    long bills[size];
    int *pdt;
    long *pbt;

    pdt = dates;
    pbt = bills;

    printf("%23s %15%s\n","short","long");

    for(index=0;index<=size;index++)
    {
        printf("index %d: %5p %10p\n",index,pdt+index,pbt+index);
    }

    return 0;
}

/*