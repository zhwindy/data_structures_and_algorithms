#include "stdio.h"

#define MATRIX_SIZE 10
#define WEIGHT 0

// 图的存储->邻接矩阵
typedef struct graph{
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    int vexSize;   // 图的定点个数
    int edgeSize;   // 图的边个数
} Graph;


// 创建无向网(边带权值的无向图)邻接矩阵
void CreateGraph(Graph* G){
    int i, j, k, w;

    printf("请输入图的顶点个数:");
    scanf("%d", &k);
    G->vexSize = k;

    printf("请输入图的边的个数:");
    scanf("%d", &w);
    G->edgeSize = w;

    for(i=0; i<G->vexSize; i++)
    {
        for(j=0; j<G->vexSize; j++)
        {
            G->matrix[i][j] = WEIGHT;    // 初始化矩阵,所有值为-1
        }
    }

    for(k=0; k<G->edgeSize; k++)
    {
        printf("请输入i,j和权值w:");
        scanf("%d %d %d", &i, &j, &w);
        G->matrix[i][j] = w;
        G->matrix[j][i] = G->matrix[i][j];   // 无向图的邻接矩阵是对称矩阵,所以这一步是必须的
    }
}

// 创建有向网(边带权值的有向图)邻接矩阵
void CreateDirectGraph(Graph* G){
    int i, j, k, w;

    printf("请输入图的顶点个数:");
    scanf("%d", &k);
    G->vexSize = k;

    printf("请输入图的边的个数:");
    scanf("%d", &w);
    G->edgeSize = w;

    for(i=0; i<G->vexSize; i++)
    {
        for(j=0; j<G->vexSize; j++)
        {
            G->matrix[i][j] = WEIGHT;    // 初始化矩阵,所有值为-1
        }
    }

    for(k=0; k<G->edgeSize; k++)
    {
        printf("请输入i,j和权值w:");
        scanf("%d %d %d", &i, &j, &w);
        G->matrix[i][j] = w;
    }
}

// 打印邻接矩阵
void PrintMatrix(Graph G)
{
    printf("生成的邻接矩阵为:\n");
    int i,j;
    for(i=0;i<G.vexSize; i++)
    {
        for(j=0;j<G.vexSize; j++)
        {
            printf("%d ", G.matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    Graph G;
    CreateGraph(&G);
    PrintMatrix(G);
}