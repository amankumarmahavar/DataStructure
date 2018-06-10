#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100
#define INFINITY 65535
typedef struct{
	char vexs[MAXVEX];					//�����
	int arc[MAXVEX][MAXVEX];       //�ڽӾ���
	int numVertexes, numEdges;    //�������ͱ���
}MGraph;

MGraph CreateMGraph(MGraph G){
	int i, j, k, w;
	printf("�����붨������\n");
	scanf("%d",&G.numVertexes);
	printf("����������� \n");
	scanf("%d",&G.numEdges);
	printf("�����붥�����ƣ�\n");
	for(i=0 ;i<G.numVertexes; i++){
        scanf("%c",&G.vexs[i]);
        getchar();
        printf("�����붥������:\n");
	}

	for(i=0;i<G.numVertexes;i++){
		for(j=0;j<G.numVertexes;j++){
			G.arc[i][j] = INFINITY;
		}
	}

	for(k=0; k<G.numVertexes; k++){
		printf("������ߣ�Vi,Vj���ϵ��±�i,�±�j�Ͷ�Ӧ��Ȩw��\n");
		scanf("%d",&i);
		scanf("%d",&j);
		scanf("%d",&w);
		G.arc[i][j] = w;
		G.arc[j][i] = G.arc[i][j];
	}
	return G;
}

void MiniSpanTree_Prim(MGraph G){
	int min, i, j, k;
	int adjvex[MAXVEX];
	int lowcost[MAXVEX];
	lowcost[0] = 0;
	adjvex[0] = 0;
	for(i = 1; i<G.numVertexes ;i++){
		lowcost[i] = G.arc[0][i];
		adjvex[i] = 0;
	}

	for(i = 1; i<G.numVertexes; i++){
		min = INFINITY;
		j = 1;
		k = 0;
		while(j<G.numVertexes){
			if(lowcost[j]!=0 && lowcost[j]<min){
				min = lowcost[j];
				k = j;
			}
			j++;
		}
		printf("��%d,%d��",adjvex[k],k);
		lowcost[k] = 0;
		for(j=0; j<G.numVertexes ;j++){
			if(lowcost[j]!=0 && G.arc[k][j]<lowcost[j]){
				lowcost[j] = G.arc[k][j];
				adjvex[j] = k;
			}
		}
	}
}
int main()
{
	MGraph G;
	MiniSpanTree_Prim(CreateMGraph(G));
    return 0;
}
