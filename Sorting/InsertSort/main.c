#include <stdio.h>
#include <stdlib.h>

void InsertSort(int *k , int n){
	int i, j, temp;
	for (i = 1; i < n; i++ ){
        if(k[i] < k[i-1]){
			temp = k[i];
			for(j = i-1; k[j] > temp; j--)
				k[j+1] = k[j];
			k[j+1] = temp;
        }
	}
}

int main()
{
	int i ,b[10]={3,1,2,5,9,8,6,7,4,0};
	InsertSort(b, 10);
	printf("The result of sorting:");
	for(i = 0; i<10 ;i++){
		printf("%d ",b[i]);
	}
	printf("\n\n");
	return 0;
}
