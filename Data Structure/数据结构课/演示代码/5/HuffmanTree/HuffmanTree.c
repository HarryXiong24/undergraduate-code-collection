//代码5.27--------- 哈弗曼树的结构定义代码----------//
//文件名：HuffmanTree.c（第1部分，共5部分）
#include "stdio.h"
#define  N  8          // 假设已知n=8个数据权值
typedef  struct  HuffRec
{                     
    double  w;                 // 允许权重为实数
    int     Pr,  Lch,   Rch;
}HuffRec,  *HuffRecPtr; 
//本例定义了一个全局数组HT用于存放哈夫曼树的相关数据
//哈弗曼树有2n-1个结点。因为C数组从0开始编号，故HT的最后一个元素的下标为2n-2。
HuffRec  HT[2*N-1];
int Code[N][N], Start[N];     //这2个全局数组主要用于哈夫曼编码的获取和保存  

//代码5.28--------- 哈弗曼问题中特定的"求最小值位置"的子函数代码----------//
//文件名：HuffmanTree.c（第2部分，共5部分）
int  GetMinPos(int  m)
{   int  k,  s;
    double  Min;
    k= 0;
    Min= 9999.99;
    for(s=0;  s<=m;  s++){
        if (HT[s].Pr==0  &&  HT[s].w < Min) { //若有相同的最小值元素，则以先找到的那个为返回。
                                           // Pr属性不为0的元素不在比较范围内。
            k=s;
            Min= HT[s].w;
        }
    }
    return  k;
}

//代码5.29---------哈弗曼树的创建操作---------//
//文件名：HuffmanTree.c（第3部分，共5部分）
int  CreateHuffmanTree()  
{  int      i,  j,  m;
    double  wi;
    printf("请依次输入%d个权值的信息，用空格间隔：\n", N);
    for(i=0;  i<N;  i++){
        scanf("%lf",  &wi);
        HT[i].w= wi;
    }
    for(m= N;  m< 2*N- 1;  m++){
        i= GetMinPos(m-1);               //i为最小者
        HT[i].Pr=m;
        j= GetMinPos(m-1);               //j为次小者，因为经过了HT[i].Pr=m之后再次调用，i≠j
        HT[m].Lch= i;                    //本程序设定最小者作为左孩子
        HT[m].Rch= j;
        HT[m].w= HT[i].w + HT[j].w;
        HT[j].Pr= m;
    }
    return 0;
}


//代码5.30---------哈夫曼编码提取操作代码---------//
//文件名：HuffmanTree.c（第4部分，共5部分）
// 在本函数中，Code[][]数组和Start数组是预先定义的全局数组
int  GenerateCode()  
{ 
    int  i,  j,  m,  pr;
    for(i= 0;  i<N;  i++)
        for(j=0;  j<N;  j++){
            Code[i][j]=  0;
        }
    for (i= 0;  i<N;  i++)
        Start[i]=  0;
    for(i=0;  i<N;  i++){
        m=  N;
        j=  i;
        while(j < 2*N-2){
            pr= HT[j].Pr;
            m-- ; 
            if (j== HT[pr].Lch)
                Code[i][m]= 0;
            else
                Code[i][m]= 1;
            j= pr;
        }
        Start[i]= m;
    }
    return 0;
}

//代码5.31---------哈夫曼编码输出显示代码---------//
//文件名：HuffmanTree.c（第5部分，共5部分）
// 在本函数中，Code[][]数组和Start数组是预先定义的全局数组
int PrintfHuffmanCode() 
{
    int i, j;
    printf("%d个权值对应的哈夫曼编码如下：\n", N);
    for(i= 0; i<N; i++)
    {
        printf("权值%5.1lf的哈夫曼编码是：", HT[i].w);
        for(j= Start[i]; j<N; j++)
            printf("%d", Code[i][j]);
        printf("\n");
    }
    return 0;
}

int main()
{
	CreateHuffmanTree();
	GenerateCode();
	PrintfHuffmanCode();
	return 0;
}

/*
8个测试数据：
14 23 5 29 3 11 7 8 

*/