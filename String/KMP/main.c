#include <stdio.h>
#include <stdlib.h>

typedef char* String;

void get_next(String T, int *next){
	int j = 0, i = 1;
	next[1] = 0;
	while(i<T[0]){
		if(j == 0 || T[i] == T[j]){
			++i;
			++j;
			next[i] = j;
			}
		else{
				j = next[j];

			}
	}

}


void get_nextval(String T, int *next){
	int j = 0, i = 1;
	next[1] = 0;
	while(i<T[0]){
		if(j == 0 || T[i] == T[j]){
			++i;
			++j;
			if(T[i]!=T[j])
				next[i] = j;
			else
				next[i] = next[j];
			}
		else{
				j = next[j];
			}
	}

}

int Index_KMP(String S, String T, int pos){
	int i = pos, j = 1;
	int next[225];
	get_next(T,next);
	while(i <= S[0] && j < T[0]){
			if(j == 0 || S[i] == T[j]){
				++j; ++i;
			}
			else
				j = next[j];
	}
	if(j > T[0])
		return i - T[0];
	else{
		return 0;
	}
}

int main()
{
    char T[255]=" ababaaaba";
    char S[255]=" aabaabababaaababab";
    int next[255];
    int i = 1;
    T[0] = 9;
    S[0] = 18;
    get_next(T,next);
    for(i=1;i<9;i++)
    {
        printf("%d  ",next[i]);
    }
    printf("\n%d",Index_KMP(S,T,1));
    return 1;
}
