#include <iostream>
#define N 8
using namespace std;

int count = 0;
int notdangder(int row,int j, int (*chess)[N]){
	int i, k, flag1=0, flag2=0, flag3=0, flag4=0,flag5=0;
	for(i = 0; i<N; i++){
		if(*(*(chess + i)+j) != 0){
			flag1 = 1;
			break;
		}
	}

	for(i=row, k=j; i>=0&&k>=0; i--,k--){
		if(*(*(chess+i)+k) !=0){
			flag2 = 1;
			break;
		}
	}

	for(i=row,k=j; i<N&&k<N; i++,k++){
        if(*(*(chess+i)+k)!=0){
			flag3 = 1;
			break;
        }
	}

	for(i=row,k=j; i>=0&&k<N; i--,k++){
		if(*(*(chess+i)+k)!=0){
            flag4 = 1;
            break;
		}
	}

	for(i=row,k=j; i<N&&k<N; i++,k--){
        if(*(*(chess+i)+k)!=0){
			flag5 = 1;
			break;
        }
	}
	if(flag1||flag2||flag3||flag4||flag5){
		return 0;
	}
	else{
		return 1;
	}
}

void NQueen(int row, int n, int (*chess)[N]){
	int chess2[N][N],i , j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++)
			chess2[i][j] = chess[i][j];
	}

	if(row == N){
		cout<<"第"<<count+1<<"种"<<endl;
		for(i=0; i<N; i++){
			for(j=0; j<N; j++){
				cout<<*(*(chess2+i)+j);
			}
			cout<<endl;
		}
		cout<<endl;
		count++;
	}
	else{
        for(j=0; j<n; j++){
			if(notdangder(row,j,chess)){
				for(i=0;i<N;i++){
					*(*(chess2+row)+i)=0;
				}
				*(*(chess2+row)+j) = 1;
				NQueen(row+1,n,chess2);
			}
        }
	}
}

int main()
{
	int chess[N][N], i ,j ;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			chess[i][j] = 0;
		}
	}
    NQueen(0, N, chess);
    cout<<count<<"方法"<<endl;
    return 0;
}
