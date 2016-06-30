//最大子段和
#include<stdio.h>
#include<stdlib.h>
int max_sum(int n,int *a){
	int sum=0;
	int b=0;
	int i;
	
	for(i=0;i<n;i++){
		if(b>0)b+=a[i];
		else b=a[i];
		if(b>sum)sum=b;

	}
	return sum;

}
int main(void){
	int a[]={-2,1,-4,13,-5,-2,-10,20,100};
	int length=sizeof(a)/sizeof(int);
	printf("%d\n",length);
	int sum=-1;
	

	sum=max_sum(length,a);
	printf("%d",sum);
	printf("\n");
	return 0;

}
