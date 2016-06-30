#include<stdio.h>
#include<stdlib.h>
int n,		//集装箱数目
    *x,		//当前解
    *bestx;	//当前最优解
int *w,		//集装箱重量数组
    c,		//第一艘轮船的载重量
    cw,		//当前载重量
    bestw,	//当前最优载重量
    r;		//剩余集装箱重量
void Backtrack(int i);//搜索第i层结点
int MaxLoading(int w[],int c,int n,int bestx[]);//返回最优载重量
void Backtrack(int i){//搜索第i层节点
	if(i>n){
		if(cw>bestw){
			for(int j=1;j<=n;j++){
				bestx[j]=x[j];//更新最优解
				bestw=cw;
			}
		}
		return ;
	}
	r-=w[i];
	if(cw+w[i]<=c){//搜索左子树
		x[i]=1;
		cw+=w[i];
		Backtrack(i+1);
		cw-=w[i];
	}
	if(cw+r>bestw){
		x[i]=0;//搜索右子树
		Backtrack(i+1);
	}
	r+=w[i];
	
}
int MaxLoading(int w[],int c,int n,int bestx[])//返回最优载重量
{
	x=(int *)malloc(sizeof(int)*(n+1));
	w=w;
	c=c;
	n=n;
	bestx=bestx;
	bestw=0;
	cw=0;
	r=0;
	
	for(int i=1;i<=n;i++){
		r+=w[i];
	}
	Backtrack(1);
	
	return bestw;


}
int main(void){
	int n=3,m;
	int c=50,c2=50;
	
	int w[4]={0,10,40,40};
	int bestx[4];

	m=MaxLoading(w,c,n,bestx);
	
	printf("轮船的载重量分别为:\n");
	printf("%d  %d",c,c2);
	
	printf("待装集装箱重量分别为:");
	for(int i=1;i<=n;i++){
		printf("%d",w[i]);
	}
	printf("\n");
	printf("回溯选择结果为:\n");
	printf("m(1):%d\n",m);
	printf("x[i]:\n");
	
	for(int i=1;i<=n;i++){
		printf("%3d",bestx[i]);

	}
	printf("\n");
	int m2=0;
	for(int j=1;j<=n;j++){
		m2=m2+w[j]*(1-bestx[j]);
	}
	printf("m(2)=%d\n",m2);
	if(m2>c2){
		printf("因为m(2)大于c(2),所以原问题无解!");
	}
	return 0;
}
