//代码7.1---------折半查找算法的参考代码---------//
// data为数组名称，n为data数组的实际元素个数，K为要查找的元素值。本代码假设数组元素为int型
#include "stdio.h"
int main()
{
    int i, KK, pos, AA[20];
	int  Binary_Search(int  data[], int  n, int  K);
    printf("请以严格单调递增的顺序输入查找表的15个整数：\n");
    for(i= 0; i < 15; i++)
        scanf("%d", &AA[i]);
    printf("请输入要查找的整数：");
    scanf("%d", &KK);
    pos=Binary_Search(AA, 15, KK); 
    if (pos == -1)
        printf("查找失败，查找表中没有该元素！");
    else
        printf("查找成功！%d在查找表中的第%d号位置上。", KK, pos);
    return 0;
}

int  Binary_Search(int  data[], int  n, int  K)
{
    int  low,  high,  mid;
    low=  0;  high=  n-1;      //初始最低下标为0，初始最高下标为n-1
    while (low <= high) {         //大前提不能忘 ，这是循环结束条件
        mid= (low+high)/2;      //折半（注意，是下标位置的折半，不是数组元素值的折半）
        if (K < data[mid])
            high= mid - 1;
        else if (K > data[mid])
            low= mid + 1;
        else
            return  mid;
    }
    return -1;
}

/*
测试数据：
5 10 13 18 20 24 27 31 33 39 43 46 48 52 55


*/