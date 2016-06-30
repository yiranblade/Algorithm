//多机调度问题
//利用贪心可以设计出解多机调度问题的较好的近似解法
//最长时间作业优先的贪心选择策略
#include<stdio.h>

#define N 7//作业数
#define M 3//机器数

int s[M]={0,0,0};//每台机器当前已分配的作业总耗时

int setwork1(int t[],int n);//机器数大于待分配作业数

int setwork2(int t[],int n);//机器数小于待分配作业数

int min(int m);//求出目前处理作业的时间和 最小的机器号

int max(int sp[],int num);

int setwork1(int t[],int n){
	int i;
	for(i=0;i<n;i++){
		s[i]=t[i];

	}
	int ma=max(s,N);
	return ma;
}
int setwork2(int t[],int n){
	int i;
	int mi=0;
	for(i=0;i<n;i++){
		mi=min(M);
		printf("%d,时间和最小的机器号为:%d.时间和为:%d:\n",i,mi,s[mi]);
		s[mi]=s[mi]+t[i];
	}
	int ma=max(s,M);
	return ma;

}
int min(int m){
	int min=0;
	int i;
	for(i=1;i<m;i++){
		if(s[min]>s[i]){
			min=i;
		}

	}
	return min;
}
int max(int s[],int num){
	int max=s[0];
	int i;
	for(i=1;i<num;i++){
		if(max<s[i]){
			max=s[i];
		}
	}
	return max;
}
int main(void){
	int time[N]={16,14,6,5,4,3,2};
	int maxtime=0;
	int i;
	if(M>=N){
		maxtime=setwork1(time,N);
	}else{
		maxtime=setwork2(time,N);
	}
	printf("最多耗费时间%d\n",maxtime);
	printf("三台机器分别处理作业的时间和:\n");
	for(i=0;i<3;i++){
		printf("%3d",s[i]);
	}
	printf("\n");
	return 0;
}


