#include "./Conversion.h"
#include "math.h"

Status InitStack(SqStack *S){
	S->base = (ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!S->base)
		exit(OVERFLOW);

	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}

Status StackEmpty(SqStack S){
	return (S.top=S.base) ? TRUE :FALSE;
}
Status Push(SqStack *S, ElemType e){
	if(S->top - S->base >= S->stacksize){
		S->base = (ElemType *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(ElemType));
		if(!S->base)
			exit(ERROR);
		S->top = S->base+S->stacksize;
		S->stacksize +=STACKINCREMENT;
	}
    *S->top= e;
    S->top++;
    return OK;
}

Status Pop(SqStack *S, ElemType *e){
	if(S->base == S->top)
		return FALSE;
	*e = *(--S->top);
	return OK;
}

int StackLength(SqStack S){
	return S.top - S.base ;
}


void Bin2Hex(){
	ElemType c, ch, chi;
	SqStack S,O;
	InitStack(&S);
	InitStack(&O);
	int i, j, k, length1,length2,sum;
	sum = 0;

	printf("请输入二进制数：输入#符号表示结束\n");
    scanf("%c",&c);
    while(c != '#'){
		Push(&S, c);
		scanf("%c",&c);
    }
    //getchar();

	length1 = StackLength(S);
	for(i=0; i<length1;i=i+4){
		for(j=0; j<4; j++){
            Pop(&S,&c);
            sum += (c-48)*pow(2,j);
            if(S.base == S.top)
				break;
		}
		chi = sum + '0';
		switch(sum){
            case 10:
                chi='A';
                break;
            case 11:
                chi='B';
                break;
            case 12:
                chi='C';
                break;
            case 13:
                chi='D';
                break;
            case 14:
                chi='E';
                break;
            case 15:
                chi='F';
                break;
		}
		Push(&O,chi);
		sum=0;
	}
	length2 = StackLength(O);
    printf("转换后十六进制数是:");
    for(k=0;k<length2;k++)
    {
        Pop(&O,&ch);
        printf("%c\n",ch);
    }
}

void Bin2Oct(){
	ElemType c, ch, chi;
	SqStack S,O;
	InitStack(&S);
	InitStack(&O);
	int i, j, k, length1,length2,sum;
	sum = 0;

	printf("请输入二进制数：输入#符号表示结束\n");
    scanf("%c",&c);
    while(c != '#'){
		Push(&S, c);
		scanf("%c",&c);
    }
    getchar();

	length1 = StackLength(S);
	for(i=0; i<length1; i=i+3){
		for(j=0; j<3; j++){
            Pop(&S,&c);
            sum += (c-48)*pow(2,j); //计算2的j次方
            if(S.base == S.top)
				break;
		}
		chi = sum + '0'; //重新转换为字符串格式
		Push(&O,chi);
		sum = 0;
	}

	length2 = StackLength(O);
	printf("转换后的八进制数为:");
	for(k=0;k<length2;k++){
		Pop(&O,&ch);
		printf("%c\n",ch);
	}
}

void Bin2Dec(){
	ElemType c;
	SqStack S;
	InitStack(&S);
	int i, length1,sum;
	i =0;
	sum = 0;

	printf("请输入二进制数：输入#符号表示结束\n");

    scanf("%c",&c);
    while(c!='#')
    {
        Push(&S,c);
        scanf("%c",&c);
    }
    getchar();
    length1=StackLength(S);
    printf("栈的当前容量是：%d\n",length1);
    for(i=0;i<length1-1;i++)
    {
        Pop(&S,&c);
        printf("%c\n",c);
        sum+=(c-48)*pow(2,i);
    }
    printf("转换后十进制数是： %d\n",sum);
}


