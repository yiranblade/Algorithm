//最大团问题
#include<stdio.h>
#include<stdlib.h>

const int N=5;

int **a,	//图G的邻接矩阵
    n,		//图G的顶点数
    *x,		//当前解
    *bestx,	//当前最优解
    cn,		//当前顶点数
    bestn; 	//当前最大顶点数

int MaxClique(int **a,int v[]);
void Backtrack(int i);
int main(void){
	int v[N+1];
	a=(int **)malloc(sizeof(int *)*(N+1));
	for(int i=1;i<=N;i++){
		a[i]=(int*)malloc(sizeof(int)*(N+1));
	}
	printf("图的邻接矩阵为:\n");
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			scanf("%d",&a[i][j]);

		}
	

	}
	printf("\n");
	

	printf("图G的最大团顶点个数为:");
	printf("图G的最大团解向量:\n");
	printf("%d\n",MaxClique(a,v));

	return 0;


}
void Backtrack(int i){
	if(i>n){//到达叶结点
		for(int j=1;j<=n;j++){
			bestx[j]=x[j];
			printf("%d ",x[j]);
		}
		printf("\n");
		bestn=cn;
		return ;
	}
	//检查顶点i与当前团的连接
	int ok=1;
	for(int j=1;j<i;j++)
		if(x[j]&&a[i][j]==0){
			ok=0;//i与j不相连
			break;
		}
	if(ok){
		x[i]=1;
		cn++;
		Backtrack(i+1);
		x[i]=0;
		cn--;
	}
	if(cn+n-i>=bestn){//进入右子树
		x[i]=0;
		Backtrack(i+1);
			
	}
	


	
	

}
int MaxClique(int **a,int v[]){
	x=(int *)malloc(sizeof(int)*(n+1));
	n=N;
	cn=0;
	bestn=0;
	bestx=v;
	

	Backtrack(1);
	
	return bestn;

}

