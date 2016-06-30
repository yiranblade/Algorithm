//快速排序
#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y);
int findbasic(int n1,int n2);
void fastsort(int *A,int f,int e);
void printArray(int *A,int n);
void printArray(int *A,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%3d",A[i]);
	}
	printf("\n");

}
void swap(int *x,int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
int findbasic(int n1,int n2){
	return (n1+n2)/2;

}
void fastsort(int* A,int f,int e){
	int key,i,j,k;
	if(f<e){
		k=findbasic(f,e);
		swap(&A[f],&A[k]);
		key=A[f];
		i=f+1;
		j=e;
		while(i<=j){
			while((i<=e)&&(A[i]<=key))
				i++;
			while((j>f)&&(A[j]>key))
				j--;
			
			if(i<j){
				swap(&A[j],&A[i]);
			}
		}
		
		swap(&A[f],&A[j]);
		fastsort(A,f,j-1);
		fastsort(A,j+1,e);
	}

}
int main(void){
	int *A;
	int n;
	int i;
	printf("Please input your array's length:\n");
	scanf("%d",&n);
	A=(int *)malloc(sizeof(int)*n);
	printf("PLease input the number:\n");
	for(i=0;i<n;i++){
		printf("the %d: \n",i+1);
		scanf("%d",&A[i]);
	}
	fastsort(A,0,n-1);
	printArray(A,n);
}


