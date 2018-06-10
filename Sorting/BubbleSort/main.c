#include <stdio.h>
#include <stdlib.h>

void BubbleSort_1(int *k ,int n){
    int i, j, temp, count1 = 0,count2 = 0;
    for(i = 0; i < n-1; i++){
		for(j = i+1; j < n; j++){
			count1++;
			if(k[i]>k[j]){
				count2++;
				temp = k[j];
				k[j] = k[i];
				k[i] = temp;
			}
		}
    }
    printf("%d Times Comparison£¬%d Times Exchange\n", count1, count2);
}

void BubbleSort_2(int *k, int n){
    int i, j, temp, count1 = 0,count2 = 0;
    for(i = 0; i < n-1; i++){
		for(j = n-1; j >i; j--){
			count1++;
			if(k[j-1]>k[j]){
				count2++;
				temp = k[j-1];
				k[j-1] = k[j];
				k[j] = temp;
			}
		}
    }
   printf("%d Times Comparison£¬%d Times Exchange\n", count1, count2);
}

void BubbleSort_3(int *k, int n){
    int i, j, temp, count1 = 0,count2 = 0, flag=1; //Add a sign of the sequence already sorted
    for(i = 0; i < n-1 && flag; i++){
		for(j = n-1; j >i; j--){
			count1++;
			flag = 0;
			if(k[j-1]>k[j]){
				count2++;
				temp = k[j-1];
				k[j-1] = k[j];
				k[j] = temp;
				flag = 1;
			}
		}
    }
   printf("%d Times Comparison£¬%d Times Exchange\n", count1, count2);
}

int main()
{
    int i, a[10] ={1,0,2,3,4,5,6,7,9,8},b[10] ={1,0,2,3,4,5,6,7,9,8},c[10] ={1,0,2,3,4,5,6,7,9,8};

	printf("Method 1:\n");
    {
		BubbleSort_1(a, 10);
		printf("The result of sorting:");
		for(i = 0 ;i<10 ;i++){
			printf("%d ",a[i]);
		}
		printf("\n\n");
    }

	printf("Method 2:\n");
	{
		BubbleSort_2(b, 10);
		printf("The result of sorting:");
		for(i = 0; i<10 ;i++){
			printf("%d ",b[i]);
		}
		printf("\n\n");
	}

	printf("Method 3:\n");
	{
		BubbleSort_3(c, 10);
		printf("The result of sorting:");
		for(i = 0; i<10 ;i++){
			printf("%d ",c[i]);
		}
		printf("\n\n");
	}
    return 0;
}
