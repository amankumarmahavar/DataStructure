#include <stdio.h>
#include <stdlib.h>
#include "./Conversion.c"

int main()
{

	int option;
    while(1){

		printf("\n\nÑ¡Ôñ½øÖÆ£º\n");
		printf("1.2 to 16 \n");
		printf("2.2 to 8 \n");
		printf("3.2 to 10 \n");
		scanf("%d",&option);
		switch(option){
		case 1:
			Bin2Hex();
			break;
		case 2:
			Bin2Oct();
			break;
		case 3:
			Bin2Dec();
			break;
		default:
			break;
        }
    }

    return 0;
}
