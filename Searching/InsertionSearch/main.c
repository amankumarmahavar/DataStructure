#include <stdio.h>
#include <stdlib.h>
int InsertionSearch(int *str, int n, int key){
	int low,high,mid;
	low = 0;
	high = n-1;
	while(low<=high){
		mid = low + (key - str[low])/(str[high]-str[low]) * (high-low);
		if(str[mid] == key)
			return mid;
		if(str[mid] < key)
			low = mid +1;
		if(str[mid]>key)
			low = mid - 1;
		}
	return -1;
}


int main()
{
    int i,j;
    int a[11]={1,1,2,3,5,8,13,21,34,55,89};
    printf("Input the number you wanna search£º");
    scanf("%d",&i);
    j = InsertionSearch(a, 11, i);
    printf("The position of %d is at %d\n",i,j );
    return 0;
}
