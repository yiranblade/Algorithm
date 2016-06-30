//动态规划0-1背包
#include<stdio.h>
#include<stdlib.h>

const int N=4;

void Knapsack(int v[],int w[],int c,int n,int m[][10]);
void Traceback(int m[][10],int w[],int c,int n,int x[]);
int min(int a,int b);
int max(int a,int b);
int main(void){
	int c=8;
	int v[]={0,2,1,4,3};
	int w[]={0,1,4,2,3};//下标从1开始
	int x[N+1];
	int m[10][10];

	printf("待装物品重量分别为:\n");
	for(int i=1;i<=N;i++){
		printf("%2d",w[i]);
	}
	printf("\n");
	printf("待装物品价值分别为:\n");
	for(int i=1;i<=N;i++){
		printf("%2d",v[i]);

	}
	printf("\n");
	Knapsack(v,w,c,N,m);
	printf("背包能装的最大价值为:%d",m[1][c]);
	Traceback(m,w,c,N,x);
	printf("背包装物品的编号为:");
	for(int i=1;i<=N;i++){
		if(x[i]==1){
			printf("%2d",i);
		}
	}
	printf("\n");
	return 0;

}
void Knapsack(int v[],int w[],int c,int n,int m[][10]){
   	int jMax = min(w[n]-1,c);//背包剩余容量上限 范围[0~w[n]-1]  
   	for(int j=0; j<=jMax;j++)  
   	{  
        	m[n][j]=0;  
   	}  
  
   	for(int j=w[n]; j<=c; j++)//限制范围[w[n]~c]  
   	{  
       		m[n][j] = v[n];  
    	}  
  
    	for(int i=n-1; i>1; i--)//从第n-1个物品开始构建最优解  
    	{  
        	jMax = min(w[i]-1,c);  
        	for(int j=0; j<=jMax; j++)//背包不同剩余容量j<=jMax<c  
        	{  
           		 m[i][j] = m[i+1][j];//没产生任何效益  
        	}  
  
        	for(int j=w[i]; j<=c; j++) //背包不同剩余容量j-wi >c  
        	{  
            		m[i][j] = max(m[i+1][j],m[i+1][j-w[i]]+v[i]);//效益值增长vi   
        	}  
    	}  
    	m[1][c] = m[2][c];  
    	if(c>=w[1])  
    	{  
        	m[1][c] = max(m[1][c],m[2][c-w[1]]+v[1]);  
    	}  
}  
void Traceback(int m[][10],int w[],int c,int n,int x[])  
{  
    for(int i=1; i<n; i++)  
    {  
        if(m[i][c] == m[i+1][c])  
        {  
            x[i]=0;  
        }  
        else  
        {  
            x[i]=1;  
            c-=w[i];  
        }  
    }  
    x[n]=(m[n][c])?1:0;  
}
int min(int a,int b){
	if(a>b)
		return b;	
	else
		return a;

}   

int max(int a,int b){
	if(a>b)
		return a;
	else  
		return b;
}
