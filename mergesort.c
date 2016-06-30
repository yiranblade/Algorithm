//归并排序，时间复杂度nlogn
#include<stdio.h>
#include<stdlib.h>
void mergersort(int *A,int p,int l);
void merge(int *A,int p,int m,int l);
void mergersort(int* A,int p,int l){
	if(p<l){
		int m=(l+p)/2;
		mergersort(A,p,m);
		mergersort(A,m+1,l);
		merge(A,p,m,l);

	}

}
void merge(int *A,int p,int m,int l){
	int lf=m-p+1;
	int ri=l-m;
	int i,j,k;
	int la[lf+1];
	int ra[ri+1];
	for(i=0;i<lf;i++){
		la[i]=A[p+i];

	}
	for(i=0;i<ri;i++){
		ra[i]=A[m+i+1];
	}
	la[lf]=33768;
	ra[ri]=33768;
	i=0;
	j=0;
	for(k=p;k<=l;k++){
		if(la[i]<ra[j]){
			A[k]=la[i];
			i++;
		}
		else{
			A[k]=ra[j];
			j++;

		}
	}

}
int main(void){
	int n;
	int *A;
	int i;
	printf("Please input the array's length:");
	scanf("%d",&n);
	A=(int *)malloc(sizeof(int)*n);
	printf("Please input the number:\n");
	for(i=0;i<n;i++){
		
		scanf("%d",&A[i]);

	}
	mergersort(A,0,n-1);
	for(i=0;i<n;i++){
		printf("%2d",A[i]);
	}
	printf("\n");
	return 0;
	


}


