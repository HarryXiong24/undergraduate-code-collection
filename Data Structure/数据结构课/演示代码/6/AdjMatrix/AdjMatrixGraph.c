//代码6.1 ---------图的邻接矩阵基本结构定义代码---------//
//文件名：AdjMatrixGraph.c（第1部分，共6部分）
#include "stdio.h"
#include "malloc.h"
typedef char VertexType[20];         //假定顶点元素的类型为char[20]
typedef float  EdgeType;
#define MAXVEX 100              //假定图中最多只有100个顶点
#define MAXEDGE 2000            //假定图中最多只有2000条边或弧
#define INFINITY 65535
typedef struct
{
    VertexType vexs[MAXVEX];
    EdgeType   arcs[MAXVEX][MAXVEX];
    int iCurVexCount;
    int iCurEdgeCount;
}AdjMatrix;

//代码6.2 ---------图的邻接矩阵"创建"操作代码---------//
//文件名：AdjMatrixGraph.c（第2部分，共6部分）
//输入指向图G结构体的二重指针ppG，在函数内进行数据的录入
int CreateAdjMatrix(AdjMatrix **ppG)
{
    int i,j,k;
    float weight;
    //第一步：申请新图所需要的结构体空间
    *ppG= (AdjMatrix *)malloc(sizeof(AdjMatrix));
    if (*ppG==NULL) return -1;
    //第二步：输入顶点和边/弧的数目
    printf("请输入顶点数目和边/弧数目，用空格隔开:\n");
    scanf("%d%d",&(*ppG)->iCurVexCount, &(*ppG)->iCurEdgeCount);
    //第三步：输入各个顶点
    printf("请按编号顺序依次输入各个顶点的值，用空格隔开:\n");
    for(i=0; i < (*ppG)->iCurVexCount; i++)
        scanf("%s", (*ppG)->vexs[i]);
    //第四步：边/弧数组初始化
    for(i=0; i < (*ppG)->iCurVexCount; i++)
        for(j=0; j < (*ppG)->iCurVexCount; j++)
            (*ppG)->arcs[i][j]= INFINITY;
    //第五步：输入各条边/弧
    printf("请输入弧的起始点编号、终止点编号和弧的权值：\n");
    for(k=0; k < (*ppG)->iCurEdgeCount; k++)
    {
        scanf("%d%d%f",&i,&j,&weight);
        (*ppG)->arcs[i][j]=weight;
        (*ppG)->arcs[j][i]=weight;
    }
    return 0;
}

//代码6.5 ---------递归的图的邻接矩阵结构下的深度优先搜索遍历算法代码----------//
//文件名：AdjMatrixGraph.c（第3部分，共6部分）
int visited[MAXVEX];              //增加辅助的一维整型数组visited[]
int DFS(AdjMatrix *pG, int cur)
{
    int i;
    if (pG==NULL)  return -1;
    visited[cur]= 1;
    printf("%s ", pG->vexs[cur]);     //访问顶点的操作，此处可更换为其他操作
    for (i= 0; i < pG->iCurEdgeCount ; i++)
    {
        if (pG->arcs[cur][i]==1 && visited[i]==0)  //邻接且未访问，注意邻接方向
            DFS(pG, i);                            //递归调用
    }
    return 0;
}
int DFSTraverse(AdjMatrix *pG)
{
    int i;
    if (pG== NULL) return -1;
    for(i=0; i < pG->iCurVexCount; i++)      //做好辅助结构的准备工作
        visited[i]= 0;
    for(i=0; i < pG->iCurVexCount; i++)
    {
        //对尚未访问过的顶点调用DFS函数。如果是连通图，则此处只会执行1次
        if (visited[i]==0)
            DFS(pG, i);
    }
    return 0;
}

//代码6.8---------基于邻接矩阵的Prim算法代码---------//
//文件名：AdjMatrixGraph.c（第4部分，共6部分）
int Prim_AdjMatrix(AdjMatrix *pG)
{
    int i, j, k, StartPos;
    float min;
    //记录从顶点集U到I-U的代价最小的边的辅助数组定义
    int adjvex[MAXVEX];                //
    float lowcost[MAXVEX];             //
    if (pG==NULL) return -1;
    StartPos= 0;
    for (i=0; i < pG->iCurVexCount; i++)
    {
        lowcost[i]= pG->arcs[StartPos][i];
        adjvex[i]= StartPos;
    }
    //在本例中，我们从顶点E（编号4）出发，所以U={4}。集合U中的所有点，其lowcost值都是0
    lowcost[StartPos]= 0;
    adjvex[StartPos]=0;
    //循环变量i只起控制循环次数的作用，内部代码要求循环n-1次，每次找出一条边
    for(i=0; i<pG->iCurVexCount-1; i++)
    {
        //一段比较独立的代码，找出lowcost数组中非0元素的最小值，并得到其下标k
        //这个lowcost[k]就表示顶点集U到I-U的所有边中权值最小的那条边的权值，
        min= INFINITY;
        j= 0;
        k= StartPos;
        while (j < pG->iCurVexCount)
        {
            if (lowcost[j]>1e-6 && lowcost[j]<min)
            {
                min= lowcost[j];
                k=j;
            }
            j++;
        }
        //而k就是属于集合I-U，但是马上即将要被吸收到集合U中的顶点编号
        //adjvex[k]是这条边的另外一个端点的顶点编号，它属于顶点集U中
        printf("(%d,%d)", adjvex[k], k);      //输出这一轮选中的边，是最小生成树的一部分
        //=0表示顶点集U的所有点到编号为k的顶点的距离是0，这标志着顶点k被加入集合U。
        lowcost[k]=0; 
        //将lowcost数组所有元素都校对一遍
        for(j= 0; j<pG->iCurVexCount; j++)
        {
            //顶点集U加入了顶点k后，更新lowcost数组中"属于顶点集I-U的并且到顶点集U的距离
            //小于原有lowcost值"的元素，即把顶点k到其他顶点Vj的距离与lowcost[j]比较并刷新。
            if (lowcost[j]!=0 && pG->arcs[k][j] < lowcost[j])
            {
                lowcost[j]= pG->arcs[k][j];
                adjvex[j]=k;
            }
        }
    }
    return 0;
}


//代码6.9 ---------基于邻接矩阵的图的Kruskal算法代码(begin)---------//
//文件名：AdjMatrixGraph.c（第5部分，共6部分）
// 本算法包括GetEdges(), SortEdges(), GetBoss()和Kruskal_AdjMatrix()四个函数构成
typedef struct EdgeData    // 边的结构体，Kruskal算法的专用数据结构之1
{
    char  startNo;           // 边的起点编号
    char  endNo;             // 边的终点编号
    float weight;            // 边的权重
}EdgeData;
// 将邻接矩阵中的所有边的信息提取到一维数组中，为按权值排序做准备
int GetEdges(AdjMatrix *pG, EdgeData **ppED)
{
    int i,j;
    int index=0;
    if (pG==NULL) return -1;
    *ppED = (EdgeData *) malloc( pG->iCurEdgeCount * sizeof(EdgeData) );
    if (*ppED == NULL) return -2;
    for (i=0; i < pG->iCurVexCount; i++)
    {
        for (j=i+1; j < pG->iCurVexCount; j++)
        {
            if ( pG->arcs[i][j]!=INFINITY )
            {
                (*ppED)[index].startNo  = i;
                (*ppED)[index].endNo    = j;
                (*ppED)[index].weight   = pG->arcs[i][j];
                index++;
            }
        }
    }
    return 0;
}

//对pEdges指向的数组中的前len个元素按照边的权值大小进行排序(由小到大)
int SortEdges(EdgeData* pEdges, int len)
{
    int i,j;
    EdgeData tmp;
    if (pEdges== NULL) return -1;
    if (len <= 0 ) return -2;
    for (i=0; i<len; i++)
    {
        for (j=i+1; j<len; j++)
        {
            if (pEdges[i].weight > pEdges[j].weight)
            {
                // 交换"第i条边"和"第j条边"的值
                tmp = pEdges[i];
                pEdges[i] = pEdges[j];
                pEdges[j] = tmp;
            }
        }
    }
    return 0;
}

// 获取i的连通最大顶点编号
int GetBoss(int Boss[], int i)
{
    while (Boss[i] != 0)
        i = Boss[i];
    return i;
}

// 利用Kruskal算法输出最小生成树的边，该函数会调用GetEdges(), SortEdges(), GetBoss()函数
int Kruskal_AdjMatrix(AdjMatrix *pG)
{
    int i,m,n;
    int index = 0;            // 用于记录生成树的边数，以便提前结束程序
    int Boss[MAXVEX]={0};     // 用于保存每个顶点在该最小生成树中的连通最大顶点编号
    EdgeData *edges;
    GetEdges(pG, &edges);    // 获取"图中所有的边"
    SortEdges(edges, pG->iCurEdgeCount);           // 将边按照"权"的大小进行排序(从小到大)
    for (i=0; i<pG->iCurEdgeCount; i++)
    {
        m = GetBoss(Boss, edges[i].startNo); //获取第i条边的"起点"在当前生成树中的连通最大顶点编号
        n = GetBoss(Boss, edges[i].endNo);   //获取第i条边的"终点"在当前生成树中的连通最大顶点编号
        if (m != n)        // 如果m!=n，意味着"边i"与"已经添加到最小生成树中的顶点"没有形成环路
        {
            if (m<n)
            {
                Boss[m] = n;                       // 设置m的连通最大顶点编号为n
            }
            else if (m > n)
            {
                Boss[n] = m;                       // 设置n的连通最大顶点编号为m
            }
            printf("(%2d,%2d)权值为%4f \n", edges[i].startNo, edges[i].endNo, edges[i].weight);
            index++;
            if (index== pG->iCurVexCount-1) break;       //凑够n-1条边则可以结束程序了
        }
    }
    free(edges);
    return 0;
}


//代码6.11 ---------基于邻接矩阵的图的Dijkstra算法代码(begin)---------//
//文件名：AdjMatrixGraph.c（第6部分，共6部分）
#include "stdlib.h"                            // 为了使用itoa()函数
#include "string.h"                            //为了使用strlen()函数
#include "math.h"                            //为了使用fabs()函数/
typedef char *PathVexes[MAXVEX];            //用于存储最短路径下标的数组
typedef float ShortPath[MAXVEX];             //用户存储源点到各点最短路径的权值和
//字符串拼接函数，Dijkstra算法专用，只在Dijkstra()函数中被调用
//不改变原有的s1和s2两个字符串，且生成的新字符串中s1串和s2串的值用ch字符间隔
char *strconnect(const char *s1, char ch, const char *s2)
{
    int i,j; 
    char *res;
    res= (char *)malloc(strlen(s1) + strlen(s2) + 2);     //新空间多一个间隔符，一个结束符
    if (res==NULL) return res;
    i=j=0;
    while (s1[j]!='\0')
        res[i++]= s1[j++];
    res[i]= ch;  i++;              //拼入间隔符

    j=0;
    while (s2[j]!='\0')
        res[i++]= s2[j++];
    res[i]= '\0';             //写入结束符
    return res;               //返回值是局部malloc申请的指针变量，需在主调函数调用结束后free掉 
}

//Dijkstra算法，求有向图G的StartVexPos顶点到其他顶点v的最短路径P[v]及路径长度值D[v]
int Dijkstra(AdjMatrix *pG, int StartVexPos, PathVexes P, ShortPath D)
{
    int i, j, MinPos;
    float min;
    char ch1[6], ch2[6];
    int VexIsinS[MAXVEX];
    char *tmp1, *tmp2;
    if (pG== NULL) return -1;
    //初始化D数组和P数组的值
    for(i=0; i < pG->iCurVexCount; i++)
    {
        VexIsinS[i]=0;
        D[i]= pG->arcs[StartVexPos][i];
        P[i]= NULL;
        if (D[i]!= INFINITY)
        {
            itoa(StartVexPos, ch1, 10);
            itoa(i, ch2, 10);
            P[i]=strconnect(ch1, '-', ch2);
        }
    }
    D[StartVexPos]= 0;            //出发点自己到自己的路径为0
    VexIsinS[StartVexPos]= 1;     //将源点置于集合S中，或标灰
    for(i=0; i < pG->iCurVexCount - 1; i++)
    {
        //找出I-S集合中D值最小的顶点编号MinPos及最小值min
        min= INFINITY;
        MinPos= -1;
        for(j= 0; j < pG->iCurVexCount; j++)
        {
            if (VexIsinS[j]==0 && D[j] < min )
            {
                MinPos= j;
                min= D[j];
            }
        }
        VexIsinS[MinPos]=1;       //将该顶点吸收到S集合中
        for(j=0; j < pG->iCurVexCount; j++)    //n次循环，搜遍所有顶点
        {
            if (VexIsinS[j]==0 && (D[MinPos] + pG->arcs[MinPos][j] < D[j]))  //需要修正相关数据
            {
                D[j]= D[MinPos] + pG->arcs[MinPos][j];
                itoa(j, ch2, 10);
                if (P[j]!=NULL)                   //先释放原有的路径字符串
                    free(P[j]);
                P[j]= strconnect(P[MinPos], '-', ch2);  //生成新的路径字符串
            }
            //如果存在多条最短路径
            else if (VexIsinS[j]==0 && fabs(D[MinPos] + pG->arcs[MinPos][j] - D[j]) < 1e-6 )
            {
                itoa(j, ch2, 10);
                tmp1= P[j];                                //原路径
                tmp2= strconnect(P[MinPos], '-', ch2);     //第二条路径
                P[j]= strconnect(tmp1, '|', tmp2); //将两条路径用"|"拼接，生成新的字符串，并用P[j]指向。
                free(tmp1);                                //释放原有的两条路径的字符串空间
                free(tmp2);
            }
        }
    }
    return 0;
}



int main()
{
    AdjMatrix *pG;
    CreateAdjMatrix(&pG);
    DFSTraverse(pG);
    return 0;
}

/*
CreateAdjMatrix函数测试数据
4 5
北 上 广 成
3 0 1700
0 1 1178
0 2 1950
3 1 2351
2 1 1308


DFSTraverse函数测试数据
15 70
A B C D E F G H I J L M N O P
0 1 1
0 5 1
0 6 1

1 0 1
1 2 1
1 5 1
1 6 1
1 7 1

2 1 1
2 3 1
2 6 1
2 7 1
2 8 1

3 2 1
3 4 1
3 8 1
3 9 1

4 3 1
4 8 1
4 9 1

5 0 1
5 1 1
5 6 1
5 10 1
5 11 1

6 0 1
6 1 1
6 2 1
6 5 1
6 7 1
6 10 1
6 11 1
6 12 1

7 1 1
7 2 1
7 6 1
7 8 1
7 11 1
7 12 1

8 2 1
8 3 1
8 4 1
8 7 1
8 9 1
8 12 1
8 13 1
8 14 1

9 3 1
9 4 1
9 8 1
9 13 1

10 5 1
10 6 1
10 11 1

11 5 1
11 6 1
11 7 1
11 10 1
11 12 1
 
12 6 1
12 7 1
12 8 1
12 11 1
12 13 1

13 8 1
13 9 1
13 12 1
13 14 1

14 8 1
14 13 1

Prim算法，Kruskal算法测试数据
16 84
A B C D E F G H I J K L M N O P

0 1 20
0 4 5
0 5 10
1 0 20
1 4 15
1 5 5
1 6 2
1 2 3
2 1 3
2 5 7
2 6 15
2 7 8
2 3 15
3 2 15
3 6 12
3 7 35
4 8 40
4 9 3
4 5 9
4 1 15
4 0 5
5 4 9
5 8 5
5 9 21
5 10 15
5 6 35
5 2 7
5 1 5
5 0 10
6 5 35
6 9 4
6 10 12
6 11 8
6 7 6
6 3 12
6 2 15
6 1 2
7 6 6
7 10 14
7 11 20
7 3 35
7 2 8
8 12 10
8 13 30
8 9 50
8 5 5
8 4 40
9 8 50
9 12 50
9 13 8
9 14 11
9 10 6
9 6 4
9 5 21
9 4 3
10 9 6
10 13 4
10 14 50
10 15 10
10 11 35
10 7 14
10 6 12
10 5 15
11 10 35
11 14 12
11 15 13
11 7 20
11 6 8
12 13 6
12 9 50
12 8 10
13 12 6
13 14 30
13 10 4
13 9 8
13 8 30
14 13 30
14 15 8
14 11 12
14 10 50
14 9 11
15 14 8
15 11 13
15 10 10
 
最后的输出为：
(4,9)(9,6)(6,1)(1,2)(4,0)(1,5)(5,8)(6,7)(9,10)(10,13)(13,12)
(6,11)(10,15)(15,14)(6,3)



*/
