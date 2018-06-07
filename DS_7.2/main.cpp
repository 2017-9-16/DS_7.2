//
//  main.cpp
//  DS_7.2
//
//  Created by Walter Mitty on 2018/6/7.
//  Copyright © 2018年 Walter Mitty. All rights reserved.
//

#include "stdlib.h"
#include "stdio.h"
#define vertexnum 9   //定义顶点数

int visited[vertexnum]; //用于标记结点是否已访问
bool isEdge(int G[8][8],int v,int w)//用于检查v w是否为g中的一条边
{
    return G[v][w]==1?true:false;
}
void dfs(int vertex,int G[8][8]){ //深度优先搜索法
    int queue[10],v,w;
    int front=0,rear=0;
    printf("[%d]->",vertex);//输出选择的第一个顶点
    visited[vertex-1]=1;//标记已经访问的第一个顶点
    queue[rear++]=vertex-1;//vertex入队列
    while (rear!=front) {//队列非空
        v=queue[front++];//弹出v
        for (w=0; w<8; w++) {//对图中的每个顶点W 若W是V的邻接点并且未访问过
            if (!visited[w]&&isEdge(G, v, w)) {
                printf("[%d]->",w+1);//访问顶点w
                visited[w]=1;
                queue[rear++]=w;//w入队列
        }
        }//while结束
    }
}
int main(){ //主程序
    int i;
    
    int node[20][2]={    {1,2},{2,1},{1,3},{3,1},
        {2,4},{4,2},{2,5},{5,2},
        {3,6},{6,3},{3,7},{7,3},
        {4,8},{8,4},{5,8},{8,5},
        {6,8},{8,6},{7,8},{8,7}        };
    
    int G[8][8];//graph
    int j,v1=0,v2=0;
    for (i=0; i<8; i++) {
        for (j=0; j<8; j++) {
            G[i][j]=0;
        }
    }
    for (i=0; i<20; i++) {
        v1=node[i][0];
        v2=node[i][1];
        G[v1-1][v2-1]=1;
    }
    for (i=0;i<vertexnum;i++)   //配置所有结点均未访问
        visited[i]=0;
    
    printf("graph\n");
    for (i=0;i<8;i++)
    {
        for (j=0;j<8;j++)
            printf("[%d] ",G[i][j]);  /*打印矩阵内容*/
        printf("\n");
    }
    int vertex;
    printf("\nPlease enter the start node:");
    scanf("%d",&vertex);
    printf("\nthe depth of the graph is (starting from node %d):\n",vertex);
    printf(" [开始]==>");
    dfs(vertex,G);
    printf(" [结束] \n\n");
}




