#include<stdio.h>
//最优装载问题，贪心算法
void sortBox(int *box,int n);
void loading(int *box,int *r,int w,int n);
void outputResult(int *r,int len);

void loading(int *box,int *r,int w,int n){
	r[0]=1;
	w-=box[0];
	for(int i=1;i<n;i++){
		if(w-box[i]>=0){
			w-=box[i];
			r[i]=1;

		}

	}

}
void sortBox(int *box,int n){
	for(int i=n-1;i>0;i--){
		for(int j=0;j<i;j++){
			int temp=box[j];
			box[j]=box[j+1];
			box[j+1]=temp;

		}

	}
}
void outputResult(int *r,int len){
	printf("结果");
	for(int i=0;i<len;i++){
		printf("%d\t",r[i]);

	}
	printf("\n");
}
int main(void){
	int w=100;
	int box[6]={100,20,25,25,20,20};
	sortBox(box,6);
	int result[6]={0};
	loading(box,result,w,6);
	outputResult(result,6);
	return 0;
}
