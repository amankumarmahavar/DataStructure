#ifndef STATUS_H_INCLUDED
#define STATUS_H_INCLUDED

#define OK 1
#define FALSE 0
#define TRUE 1
#define ERROR 0
#define OVERFLOW -1

typedef int Status;


#define PressEnter\
 {\
	fflush(stdin);\
	cout<<endl<<"Press Enter..."<<endl;\
	getchar();\
	fflush(sdin);\
 }
#endif // STATUS_H_INCLUDED
