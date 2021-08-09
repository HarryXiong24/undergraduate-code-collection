//代码5.4---------二叉树的顺序存储表示结构定义---------//
//文件名：SeqBiTree.c（第1部分，共10部分）
#include  "stdio.h"               //scanf函数和printf函数需要用到该头文件
#include  "malloc.h"              //如果代码中需要用到malloc函数，则需要该头文件
#include  "string.h"              //memset和strcpy函数需要该头文件

#define  MAX_TREE_SIZE  100       //限制本例表示的一棵二叉树最大结点数目不超过100个结点
typedef  struct  TelmType {       //假定在实际问题中，元素类型为结构体，其类型名为TelmType，
	char  name[20];               //且内含一个字符串成员name和一个整型成员number 
	int   number;
} TelmType; 
typedef  TelmType  SeqBiTree[MAX_TREE_SIZE];    // 定义一个数组类型，名为SeqBiTree。这种类
                                  //型要求内含MAX_TREE_SIZE 个元素，每个元素都属于
                                  //TelmType 类型。TelmType根据实际类型，在编码时替换
#include  "iSeqStack.c"

//代码5.16---------顺序存储结构下的二叉树创建和初始化操作---------//
//文件名：SeqBiTree.c（第2部分，共10部分）
//该程序要求在运行时以"二叉树位置编号 ,元素值"的形式接受每个结点的信息
int  CreateTree(SeqBiTree  mybt)
{
    TelmType tempNode;
    int  NodePos, i;

    if (mybt==NULL) return -1;                   //参数校验
    for (i=0; i<MAX_TREE_SIZE; i++)             //清空结构，准备接收数据
    {
        memset(mybt[i].name, 0, 20);
        mybt[i].number= 0;
    }
    scanf("%d", &NodePos);
    scanf("%s", tempNode.name);
    scanf("%d", &tempNode.number);
    while(NodePos!=0)             //约定NodePos为0，表示数据输入正常结束
    {
        if (NodePos<0 || NodePos> MAX_TREE_SIZE) return -2; //越界出错，提前结束
        if (NodePos==0) return 0; 
        strcpy(mybt[NodePos-1].name, tempNode.name);
        mybt[NodePos-1].number= tempNode.number;
        scanf("%d", &NodePos);
        scanf("%s", tempNode.name);
        scanf("%d", &tempNode.number);
    }
    return 0;
}
//代码5.17---------顺序存储结构下的二叉树"判断树是否为空"操作---------//
//文件名：SeqBiTree.c（第3部分，共10部分）
//判断在bt数组中以第iRootPos-1 个元素为根结点的树/子树是否为空树
int  TreeIsEmpty(SeqBiTree  bt, int  iRootPos )
{
    // 参数有效性检验。如果参数无效，则视其表达的树为空树。
    if (bt == NULL || iRootPos > MAX_TREE_SIZE || iRootPos <= 0) 
        return  1;
    // 若参数有效，但根结点位置的数组元素无值，则视该根结点为空，进而视该树/子树为空
    if (bt[iRootPos-1].name[0]=='\0'  &&  bt[iRootPos-1].number==0)   
        return  1;
    else
        // 若上述判断条件均不满足，则视该树/子树存在
        return  0;
}

//代码5.18---------顺序存储结构中的二叉树求左孩子地址操作---------//
//文件名：SeqBiTree.c（第4部分，共10部分）
//已知二叉树bt中某结点的位置编号cur_e，函数返回其左孩子的位置编号
//函数返回-1表示参数有误；返回0表示该结点没有左孩子
int  GetNodeLeftChild(SeqBiTree  bt, int  cur_e)
{
    int  iChildPos;
     //每个算法首先要做的第一步就是参数有效性验证
    if( bt == NULL || cur_e <=0 || cur_e>MAX_TREE_SIZE)
       return  -1;
    iChildPos= cur_e * 2;
    if (iChildPos > MAX_TREE_SIZE)      //如果给定的结点位于二叉树的最下面两层，其左孩子极
                                        //有可能超过原二叉树的结点范围，若读取会产生越界
        return  0;
    if (bt[iChildPos-1].name[0]=='\0' && bt[iChildPos-1].number== 0) //如果左孩子结点在数组表示范围
                                                         //内，但其结点不存在，则仍返回0
        return  0;
    return  iChildPos;
}
//求右孩子和求左孩子过程极为类似，不再注释
int  GetNodeRightChild(SeqBiTree  bt, int  cur_e)
{
    int  iChildPos;
    if( bt == NULL || cur_e <=0 || cur_e>MAX_TREE_SIZE)
       return  -1;
    iChildPos= cur_e * 2 + 1;
    if (iChildPos > MAX_TREE_SIZE) 
        return  0;
    if (bt[iChildPos-1].name[0]=='\0' && bt[iChildPos-1].number== 0)
        return  0;
    return  iChildPos;
}

//代码5.19---------顺序存储结构中的二叉树求右兄弟地址操作---------//
//文件名：SeqBiTree.c（第5部分，共10部分）
//已知二叉树bt中某结点的位置编号cur_e，函数返回其右兄弟的位置编号
//函数返回-1表示参数有误；返回0表示该结点没有右兄弟
int  GetNodeRightSibling(SeqBiTree  bt, int  cur_e)
{
    int  iSibPos;
    //若参数非有效，则立即返回-1
    if( bt == NULL || cur_e <=0 || cur_e>MAX_TREE_SIZE)
        return  -1;
    if (cur_e%2==1)                     // 如果当前结点是奇数号位置，则没有右兄弟，返回0
        return 0; 
    else
    {
        iSibPos= cur_e  + 1;
        //若当前结点是最后一个结点，且恰为偶数，则也没有右兄弟，返回0
        if (iSibPos > MAX_TREE_SIZE)  return  0;
        if (bt[iSibPos-1].name[0]=='\0' && bt[iSibPos-1].number== 0)  //如果右孩子结点在数组表示范围
                                                             //内，但其结点不存在，则仍返回0
            return  0;
        return  iSibPos;
    }
}

//代码5.20---------递归的顺序存储结构下二叉树的先序遍历代码---------//
//文件名：SeqBiTree.c（第6部分，共10部分）
// bt：二叉树数组变量名  iRootPos：子树根结点的编号值（注意，原树根结点从1开始编号）
int  PreOrderTravSeqBiTree( SeqBiTree  bt,  int  iRootPos)   //注意函数头部与代码5.9有所不同
{
    if (TreeIsEmpty( bt, iRootPos))    // 递归函数首先应处理特殊情况，该情况下必定不需要再递归。
         return  1;
    else 
    {
         printf("%s  ",  bt[iRootPos -1].name);        //"访问"该树/子树的根节点
         printf("%d\n",  bt[iRootPos -1].number);
         PreOrderTravSeqBiTree (bt,  iRootPos *2);       //先序遍历该树/子树的左子树
         PreOrderTravSeqBiTree (bt,  iRootPos *2+1);     //先序遍历该树/子树的右子树
         return 1;
    }
}

//代码5.21-------顺序存储结构下的先序遍历二叉树算法代码------------------//
//文件名：SeqBiTree.c（第7部分，共10部分）
// bt：二叉树数组变量名  iRootPos：子树根结点的编号值（注意，原树根结点从1开始编号）
// 正常遍历结束返回0， 非正常遍历结束返回 -1
int  N_PreOrderTravSeqTree( SeqBiTree  bt,  int  iRootPos)
{
    SqStack S;
    int PosInTree;
    if (bt == NULL || iRootPos > MAX_TREE_SIZE || iRootPos <= 0) 
        return -1;
    InitStack(&S);
    PosInTree= iRootPos;
    while(1)
    {
        if (PosInTree!=0)
        {
            printf("%s  ",  bt[PosInTree-1].name);
            printf("%d\n",  bt[PosInTree-1].number);
            Push(&S, PosInTree);
            PosInTree= GetNodeLeftChild( bt, PosInTree);
        }
        else
        {
            if (StackIsEmpty(&S))
                return 0;
            Pop(&S, &PosInTree);
            PosInTree= GetNodeRightChild( bt, PosInTree);
        }
    }
}
//代码5.22---------递归的顺序存储结构下二叉树的中序遍历代码---------//
//文件名：SeqBiTree.c（第8部分，共10部分）
// bt：二叉树数组变量名  iRootPos：子树根结点的编号值（注意，原树根结点从1开始编号）
int  InOrderTravSeqBiTree( SeqBiTree  bt,  int  iRootPos)   //注意函数头格式，与二叉链表下的有所不同
{
    if (TreeIsEmpty( bt,  iRootPos))        // 递归函数首先应处理特殊情况，该情况下必定不需要再递归。
         return  1;
    else 
    {
         InOrderTravSeqBiTree (bt,  iRootPos *2);       //中序遍历左子树
         printf("%s  ",  bt[iRootPos -1].name);        //"访问"根节点
         printf("%d\n",  bt[iRootPos -1].number);
         InOrderTravSeqBiTree (bt,  iRootPos *2+1);     //中序遍历右子树
         return 1;
    }
}

//代码5.23-------非递归的顺序存储结构下的二叉树的中序遍历操作代码------------//
//文件名：SeqBiTree.c（第9部分，共10部分）
// bt：二叉树数组变量名  iRootPos：子树根结点的编号值（注意，原树根结点从1开始编号）
//正常遍历结束返回0， 非正常遍历结束返回-1
int  N_InOrderTravSeqTree( SeqBiTree  bt,  int  iRootPos)
{
    SqStack S;
    int PosInTree;
    if (bt == NULL || iRootPos > MAX_TREE_SIZE || iRootPos <= 0) 
        return -1;
    InitStack(&S);
    PosInTree= iRootPos;
    while(1)
    {
        if (PosInTree!=0){
            Push(&S, PosInTree);
            PosInTree= GetNodeLeftChild( bt, PosInTree);
        }
        else{
            if (StackIsEmpty(&S))
                return 0;
            Pop(&S, &PosInTree);
            printf("%s  ",  bt[PosInTree-1].name);
            printf("%d\n",  bt[PosInTree-1].number);
            PosInTree= GetNodeRightChild( bt, PosInTree);
        }
    }
}


//代码5.24-------非递归的顺序存储结构下的二叉树的后序遍历操作代码------------//
//文件名：SeqBiTree.c（第10部分，共10部分）
// bt：二叉树数组变量名  iRootPos：子树根结点的编号值（注意，原树根结点从1开始编号）  //
//正常遍历结束返回0， 非正常遍历结束返回-1
int  N_PostOrderTravSeqTree ( SeqBiTree  bt,  int  iRootPos)
{
    SqStack S;    
    int PosInTree;
    if (bt == NULL || iRootPos > MAX_TREE_SIZE || iRootPos <= 0) 
        return -1;
    InitStack(&S);

    PosInTree= iRootPos;
    while(1) {
        if (PosInTree!=0) {
            Push(&S, PosInTree);
            PosInTree= GetNodeLeftChild( bt, PosInTree);
        }
        else {
            GetTop(S, &PosInTree);
            if (GetNodeRightChild(bt, PosInTree)!=0) {
                PosInTree= GetNodeRightChild(bt, PosInTree);
            }
            else {
                do {
                    if (StackIsEmpty(&S))
                        return 0;
                    Pop(&S,  &PosInTree);
                    printf("%s  ",  bt[PosInTree-1].name);
                    printf("%d\n",  bt[PosInTree-1].number);
                    PosInTree= GetNodeRightSibling( bt, PosInTree);
                }while(PosInTree==0);
            }
        }
    }
}


  ///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
int main()
{
    SeqBiTree  bt;
    printf("请输入二叉树的结点编号、结点值（以空格分隔）:\n");
    CreateTree(bt);
    printf("递归下的先序遍历结果:\n");
    PreOrderTravSeqBiTree(bt, 1);
    printf("非递归下的先序遍历结果:\n");
    N_PreOrderTravSeqTree(bt, 1);
    printf("非递归下的中序遍历结果:\n");
    N_InOrderTravSeqTree(bt, 1);
    printf("非递归下的后序遍历结果:\n");
    N_PostOrderTravSeqTree(bt, 1);
    return 0;
}

/*
1 点1 10
3 点3 30
6 点6 60
7 点7 70
0 任意值 12345

*/