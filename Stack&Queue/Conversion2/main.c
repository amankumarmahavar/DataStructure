#include <stdio.h>
#include <stdlib.h>
#include "../SequenceStack/SequenceStack.c"
void Conversion(int);

int main()
{
	int num;
    printf("Please Input the Decimal number you want to convert\n");
    scanf("%d", &num);
    Conversion(num);
    return 0;
}

void Conversion(int num){
	SqStack S;
	ElemType e;
	int sys;
    InitStack_Sq(&S);
    printf("\nPlease intput the number system you want to convert\n");
    scanf("%d", &sys);
    while(num){
        Push_Sq(&S, num%sys);
        num /= sys;
    }
    while(!StackEmpty_Sq(S)){
        Pop_Sq(&S, &e);
        if(e >9){
			e +=55;
			printf("%c", e);
        }
        else
			printf("%d", e);
    }
}
