#ifndef STATUS_H_INCLUDED
#define STATUS_H_INCLUDED

#define OK 1
#define FALSE 0
#define ERROR 0
#define OVERFLOW -1
#define TRUE 1

typedef int Status;


#define PressEnter\
  {\
	fflush(stdin);\
	printf("Press Enter...");\
	getchar();\
	fflush(stdin);\
  }
#endif // STATUS_H_INCLUDED
