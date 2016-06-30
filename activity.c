//活动安排问题，贪心算法
#include<stdio.h>
#include<stdbool.h>
#define N 11
void GreedySelector(int n,int s[],int f[],bool A[]);
void GreedySelector(int n,int s[],int f[],bool A[]){
	A[1]=true;
	int j=1;//记录最近一次加入A中的活动
	
	for(int i=2;i<=n;i++){
		if(s[i]>=f[j]){
			A[i]=true;
			j=i;

		}else
		{
			A[i]=false;

		}

	}


}
int main(void){
	int s[]={0,1,3,0,5,3,5,6,8,8,2,12};
	int f[]={0,4,5,6,7,8,9,10,11,12,13,14};

	bool A[N+1];
	int i;
	int n=sizeof(s)/sizeof(int)-1;
	int c=sizeof(f)/sizeof(int)-1;
	
	printf("活动的开始时间和结束时间");
	for(i=1;i<=n;i++){
		printf("%2d %2d",s[i],f[i]);
		printf("\n");

	}
	printf("\n");
	GreedySelector(n,s,f,A);
	printf("第");
	for(i=1;i<=n;i++){
		if(A[i]){
			printf("%2d",i);
		}

	}
	printf("个活动被安排");
	printf("\n");
	return 0;
}

