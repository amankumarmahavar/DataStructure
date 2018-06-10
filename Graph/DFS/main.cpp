#include <iostream>

#define MAX_ROW 5
#define MAX_COL 5
using namespace std;

struct point{
	int row,col;
}stack[512];
int top = 0;

void push(struct point p){
	stack[top++] = p;
}

struct point pop(void){
	return stack[--top];
};

int IsEmpty(void){
	return top == 0;
}

int maze[MAX_ROW][MAX_COL] = {
	0,1,0,0,0,
	0,1,0,1,0,
	0,0,0,0,0,
	0,1,1,1,0,
	0,0,0,1,0,
};

void print_maze(void){
	int i,j;
	for(i=0; i<MAX_ROW; i++){
		for(j=0; j<MAX_COL; j++)
			cout<<maze[i][j]<<"  ";
		cout<<endl;
	}
	cout<<"*************"<<endl;
}

struct point predecessor[MAX_ROW][MAX_COL]{
	{{-1 , -1},  {-1 , -1},  {-1 , -1},  {-1 , -1},  {-1 , -1}},
	{{-1 , -1},  {-1 , -1},  {-1 , -1},  {-1 , -1},  {-1 , -1}},
	{{-1 , -1},  {-1 , -1},  {-1 , -1},  {-1 , -1},  {-1 , -1}},
	{{-1 , -1},  {-1 , -1},  {-1 , -1},  {-1 , -1},  {-1 , -1}},
	{{-1 , -1},  {-1 , -1},  {-1 , -1},  {-1 , -1},  {-1 , -1}},
};

void visit(int row, int col, struct point pre){
	struct point visit_point = {row, col};
	maze[row][col] = 2;
	predecessor[row][col] = pre;
	push(visit_point);
}
int main()
{
	struct point p ={ 0, 0 };

	maze[p.row][p.col] = 2;
	push(p);

	while(!IsEmpty()){
		p = pop();
		if(p.row == MAX_ROW - 1 && p.col == MAX_COL-1)
			break;
		if(p.col+1 < MAX_COL && maze[p.row][p.col+1] == 0) //right
			visit(p.row, p.col+1, p);
		if(p.row+1 <MAX_ROW && maze[p.row+1][p.col] == 0) //down
			visit(p.row+1, p.col, p);
		if(p.col-1 >=0 && maze[p.row][p.col-1] == 0 )  //left
			visit(p.row, p.col-1, p);
		if(p.row-1 >=0 && maze[p.row-1][p.col] == 0) //up
			visit(p.row-1, p.col, p);
		print_maze();
	}

	if(p.row == MAX_ROW -1 && p.col == MAX_COL -1){
		cout<<p.row<<","<<p.col<<endl;
		while(predecessor[p.row][p.col].row != -1){
            p = predecessor[p.row][p.col];
			cout<<p.row<<","<<p.col<<endl;
		}
	}
	else{
		cout<<"No Path";
	}

    return 0;
}
