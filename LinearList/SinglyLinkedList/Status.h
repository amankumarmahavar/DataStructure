#ifndef STATUS_H_INCLUDED
#define STATUS_H_INCLUDED

#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OVERFLOW 0


typedef int Status;

#endif // STATUS_H_INCLUDED


#define PressEnter\
 {\
	fflush(stdin);\
	printf("\nPress Enter...");\
	getchar();\
	fflush(stdin);\
 }


