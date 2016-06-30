#include<stdio.h>
#include<stdlib.h>
void test(int **a){
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			a[i][j]=1;
		}
	}
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%2d",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}
int main(void){
	int **a;
	int i;
	int j;
	a=(int **)malloc(sizeof(int *)*5);
	for(i=0;i<5;i++){
		a[i]=(int *)malloc(sizeof(int)*5);
	}

	test(a);
	return 0;

}
