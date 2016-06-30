#include<stdio.h>
#include<string.h>

#define N 3//作业数目
#define MAX 1000
int x[N+1]={0,1,2,3};
int m[3][N+1]={
	0,0,0,0,
	0,2,3,2,
	0,1,1,3
};
int bestx[N+1];//用于保存结果调度顺序
int f2[N+1];//第i阶段机器2完成处理的时间
int f1=0;//机器1完成处理时间
int f=0;//当前完成时间和
int bestf=MAX;
void swap(int *x,int *y);//交换两数值的函数
void Backtrace(int t);//回溯函数，搜索排列树
int main(void){
	Backtrace(1);
	printf("该作业调度的最优完成时间和为:%d\n调度顺序为:\n",bestf);
	for(int i=1;i<=N;i++){
		printf("%d",bestx[i]);

	}
	printf("\n");
	return 0;
}
void swap(int *x,int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;

}
void Backtrace(int t){
	if(t>N){
		bestf=f;
		for(int i=1;i<=N;i++){
			bestx[i]=x[i];
		}

	}else{
		for(int i=t;i<=N;i++){
			f1+=m[1][x[i]];
			f2[t]=(f2[t-1]>f1?f2[t-1]:f1)+m[2][x[i]];
			printf("第%d阶段机器2完成处理第%d个作业的时间%d\n",t,i,f2[t]);
			f+=f2[t];
			swap(&x[t],&x[i]);
			if(f<bestf){
				Backtrace(t+1);

			}
			swap(&x[t],&x[i]);
			f1-=m[1][x[i]];
			f-=f2[t];
	
		}

	}
}

