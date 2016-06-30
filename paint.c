//图的m着色问题
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
const int N=5;	//图的顶点数
const int M=3;	//色彩数

int n,		//图的顶点数
    m,		//可用的颜色数
    **a,	//图的邻接矩阵
    *x;		//当前解
int sum;	//当前已找到的可m着色方案数

int mColoring(int n,int m);
void Backtrack(int t);
bool ok(int k);
int main(void){
	a=(int **)malloc(sizeof(int *)*(N+1));
	for(int i=1;i<=N;i++){
		a[i]=(int *)malloc(sizeof(int)*(N+1));

	}
	printf("图G的邻接矩阵为:\n");
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			scanf("%d",&a[i][j]);
		}
		
	}
	printf("图G的着色方案如下:");
	printf("当m=%d时图G的可行着色方案数目为:",M);
	printf("%d\n",mColoring(N,M));
}
void Backtrack(int t){
	
	if(t>n){
		sum++;
		for(int i=1;i<=n;i++)
			printf("%d ",x[i]);
	}
	else
	{
		for(int i=1;i<=m;i++){
			x[t]=i;
			if(ok(t))Backtrack(t+1);

		}

	}

}
bool ok(int k){//检查颜色可用性
	for(int j=1;j<=n;j++){
		if((a[k][j]==1)&&(x[j]==x[k]))//相邻且颜色相同
		{
			return false;

			}

	}
	return true;

}
int mColoring(int n1,int m1){
	n=n1;
	m=m1;

	sum=0;
	int *p;
	p=(int *)malloc(sizeof(int)*(n+1));
	for(int i=0;i<=n;i++){
		p[i]=0;
	}
	x=p;
	Backtrack(1);
	return sum;

}
