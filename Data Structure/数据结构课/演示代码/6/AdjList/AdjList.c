//代码6.3 ---------图的邻接表表示法基本结构定义代码---------//
//文件名：AdjList.c（第1部分，共5部分）
#include "stdio.h"
#include "malloc.h"
#define MAXVEX 100              //假定图中最多只有100个顶点
typedef char VertexType[20];         //假定顶点元素的类型为char[20]
typedef float EdgeType;             //假定弧的权值类型为float
typedef struct LinkListNode          //弧表结点
{
    int adjVex;        //邻接点域，存储该弧对应的弧头顶点的下标(邻接表)/弧尾顶点的下标(逆邻接表)
    EdgeType weight;  //权值域，存储该弧对应的权值
    struct LinkListNode *next;
}LinkListNode;
typedef struct VertexNode        //顶点表结点
{
    int InDegree;              //在拓扑排序算法中专门增设的域，如果没学拓扑排序，可忽略此成员
    VertexType data;           //顶点域，存储图中所有顶点的基本信息
    LinkListNode *first;       //弧表的表头指针，指向第一个弧表结点
}VertexNode;
typedef struct                 //封装，加入图的一些相关辅助信息
{
    VertexNode AdjList[MAXVEX];
    int iVertexCount;
    int iEdgeCount;
    int visited[MAXVEX];
}ADJLIST;                   //邻接表新类型产生，取名ADJLIST
#include "LinkStack.h"          //深度遍历需要使用链栈
#include "LinkQueue.h"         //广度遍历需要使用链队列

//代码6.4 ---------图的邻接表"创建"操作代码---------//
//文件名：AdjList.c（第2部分，共5部分）
//若图中边弧有权值，则应启用标有(*)行的代码
int CreateAdjList(ADJLIST **ppG)
{
    int i, j, k;
   // float weight;                           // (*)
    LinkListNode *p;
    //创建并初始化图的邻接表结构
    *ppG= (ADJLIST *)malloc(sizeof(ADJLIST));
    if (*ppG==NULL) return -1;
    printf("请先输入顶点总数和弧的总数：\n");
    scanf("%d%d", &(*ppG)->iVertexCount, &(*ppG)->iEdgeCount);  //输入顶点总数和弧的总数
    printf("请输入顶点的值（以空格键间隔）：\n");
    for (i=0; i < (*ppG)->iVertexCount; i++)
    {
        scanf("%s", (*ppG)->AdjList[i].data);    //按编号依次输入顶点的值
        (*ppG)->AdjList[i].first= NULL;        //将弧表初始置为空
         (*ppG)->AdjList[i].InDegree= 0;       //如果没学拓扑排序，可不看此行代码
        (*ppG)->visited[i]= 0;
    }
    printf("请随意输入所有弧的顶点编号组合。\n例如从3号点到5号点有一条弧，则输入3,5\n");
    for(k= 0; k < (*ppG)->iEdgeCount; k++)
    {
        scanf("%d,%d", &i, &j);               //输入弧(vi, vj)的顶点序号
        //scanf("%d,%d,%f", &i, &j, &weight);   //若启用本行，则删除上一行代码    (*)
        p= (LinkListNode *)malloc(sizeof(LinkListNode));
        if (p==NULL)
            return -1;
        p->adjVex= j;
        p->next= (*ppG)->AdjList[i].first;
        //p->weight= weight;                 // (*)
        (*ppG)->AdjList[i].first = p;
        (*ppG)->AdjList[j].InDegree++;        //如果没学拓扑排序，可不看此行代码
    }
    return 0;
}

//代码6.6 ---------非递归的图的邻接表“深度优先遍历”操作代码---------//
//文件名：AdjList.c（第3部分，共5部分）
//N_DFS函数只适用于单个连通图的情况，是N_DFSTraverse的子函数。
int N_DFS(ADJLIST *pG, int StartVex)
{
    int j, cur;
    LinkStack *pS;
    LinkListNode *p;        //负责指向邻接表中的单链表结点
    if (pG==NULL) return -1;

    InitStack(&pS);
    cur= StartVex;
    p= pG->AdjList[cur].first;
    pG->visited[cur]= 1;
    printf("%s ", pG->AdjList[cur].data);
    Push(pS, cur, p);
    while( !StackIsEmpty(pS) )    //每个元素都要进栈出栈一次，以栈空来控制程序结束
    {
        //让p定位到该链表中第一个未被访问过的结点
        while (p!= NULL && pG->visited[p->adjVex]==1 )
        {
            p= p->next;
        }
        if (p==NULL)                //如果该顶点的所有邻接点都已经被访问
        {
            Pop(pS, &cur, &p);      //不再前进，退而选择路径中上一个顶点
        }
        else                        //如果该顶点还有未被访问的顶点，则访问，标记，压栈，前行
        {
            j= p->adjVex;      
            pG->visited[j]= 1;                    //标记
            printf("%s ", pG->AdjList[j].data);   //访问
            p= pG->AdjList[j].first;              //前行
            Push(pS, j, p);                       //压栈
        }
    }
    printf("\n");
    return 0;
}
//深度优先遍历的完整函数
int N_DFSTraverse(ADJLIST *pG)
{
    int i;
    if (pG== NULL) return -1;
    for(i=0; i < pG->iVertexCount; i++)      //做好辅助结构的准备工作
        pG->visited[i]= 0;
    for(i=0; i < pG->iVertexCount; i++)
    {
        //对尚未访问过的顶点调用DFS函数。如果是连通图，则此处只会执行1次
        if (pG->visited[i]==0)
            N_DFS(pG, i);
    }
    return 0;
}

//代码6.7 ---------非递归的图的邻接表“广度优先遍历”操作代码---------//
//文件名：AdjList.c（第4部分，共5部分）
//N_BFS函数只适用于单个连通图的情况，是N_BFSTraverse的子函数。
int N_BFS(ADJLIST *pG, int StartVex)
{
    int j, cur;
    LinkQueue *pQ;
    LinkListNode *p;           //负责指向邻接表中的单链表结点
    if (pG==NULL) return -1;

    InitQueue(&pQ);
    cur= StartVex;
    p= pG->AdjList[cur].first;
    pG->visited[cur]= 1;
    printf("%s ", pG->AdjList[cur].data);
    EnQueue(pQ, cur);
    while( !QueueIsEmpty(pQ) )    //每个元素都要进队出队一次，以队空来控制程序结束
    {
        //将p所在链表中所有未被访问过的点依次标记、访问和入队。已访问过的点自动飘过
        while (p!= NULL) 
        {
            if (pG->visited[p->adjVex]==0)
            {
                j= p->adjVex;      
                pG->visited[j]= 1;                     //标记
                printf("%s ", pG->AdjList[j].data);      //访问
                EnQueue(pQ, j);                      //入队
            }
            p= p->next;
        }

        if (p==NULL)                    //如果该顶点的所有邻接点都已经被访问
        {
            DeQueue(pQ, &cur);           //从队列中另取一个元素，以便访问其未被访问的所有邻接点
            p= pG->AdjList[cur].first;                 //前行
        }
    }
    printf("\n");
    return 0;
}
//广度优先遍历的完整函数
int N_BFSTraverse(ADJLIST *pG)
{
    int i;
    if (pG== NULL) return -1;
    for(i=0; i < pG->iVertexCount; i++)      //做好辅助结构的准备工作
        pG->visited[i]= 0;
    for(i=0; i < pG->iVertexCount; i++)
    {
        //对尚未访问过的顶点调用DFS函数。如果是连通图，则此处只会执行1次
        if (pG->visited[i]==0)
            N_BFS(pG, i);
    }
    return 0;
}

//代码6.10 --------- 基于邻接表的图的拓扑排序算法代码 --------- //
//文件名：AdjList.c（第5部分，共5部分）
int TopoSortByAdjList(ADJLIST *pG)
{
    LinkListNode *p;
    int i, k, gettop;
    int count= 0;  //用于计算输出点的个数，进而判断拓扑排序是否查出回路
    int *stack;    //定义一个简易的int栈，用于存放待输出的入度为0的顶点编号
    int top=0;     //stack栈专用的栈顶指示器 
    if (pG==NULL) return -1;
    stack= (int *)malloc(pG->iVertexCount * sizeof(int));
    //第一步：先将邻接表中所有入度为0的顶点编号压栈
    for(i=0; i < pG->iVertexCount; i++)
        if (pG->AdjList[i].InDegree==0)
        {
            top= top +1;
            stack[top]= i;
        }
    //第二步：对所有入栈的顶点做以下操作：
    while(top!=0)
    {
        //从栈中取出一个入度为0的顶点编号，输出
        gettop= stack[top];
        top= top - 1;
        printf("%s ", pG->AdjList[gettop].data);
        count++;
        //将以该顶点为弧尾的所有弧头点的InDegree值减1，以表示删除了1条弧
        p= pG->AdjList[gettop].first;
        while(p!= NULL)
        {
            k= p->adjVex;
            pG->AdjList[k].InDegree--;
            if (pG->AdjList[k].InDegree == 0)   //对删除弧之后入度变为0的顶点压栈，以备随后输出
            {
                top++;
                stack[top]= k;
            }
            p= p->next;
        }
    }
    if (count < pG->iVertexCount)    //如果输出点的个数少于总顶点个数，说明存在回路
        return -2;
    else
        return 0;
}


int main()
{
    ADJLIST *pG;
    CreateAdjList(&pG);
	printf("非递归的基于邻接表的深度遍历结果如下：\n");
    N_DFSTraverse(pG);
    return 0;
}

/*
测试CreateAdjList函数数据
4 5
赵 王 李 张
1,3
3,0
1,0
3,2
1,2

N_DFSTraverse函数测试数据
15 70
A B C D E F G H I J L M N O P
0,1
0,5
0,6
1,0
1,2
1,5
1,6
1,7
2,1
2,3
2,6
2,7
2,8
3,2
3,4
3,8
3,9
4,3
4,8
4,9
5,0
5,1
5,6
5,10
5,11
6,0
6,1
6,2
6,5
6,7
6,10
6,11
6,12
7,1
7,2
7,6
7,8
7,11
7,12
8,2
8,3
8,4
8,7
8,9
8,12
8,13
8,14
9,3
9,4
9,8
9,13
10,5
10,6
10,11
11,5
11,6
11,7
11,10
11,12
12,6
12,7
12,8
12,11
12,13
13,8
13,9
13,12
13,14
14,8
14,13

拓扑排序的测试数据如下：
11 20
A B T D R K G H P M S
0,1
0,5
1,2
2,3
2,7
4,0
4,5
4,9
5,1
5,2
5,6
5,10
6,2
6,9
7,3
7,10
8,4
8,5
8,9
9,10




输入7 11，然后输入ABCDEFG7个点
0,1
0,2
0,3
1,5
3,6
5,6
4,5
2,1
2,4
1,3
4,3

*/