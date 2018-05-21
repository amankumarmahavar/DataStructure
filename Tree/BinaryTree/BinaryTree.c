
#include "./BinaryTree.h"
#define MAX_TREE_SIZE 100

Status InitBiTree(BiTree *T){
	*T = NULL;
	return OK;
}

Status BiTreeEmpty(BiTree T){
	return (!T)? TRUE:FALSE;
}

/*
Status CreateBiTree_i(BiTree *T){
	if(*T){
		if((*T)->lchild)
			CreateBiTree(&((*T)->lchild));
		if((*T)->rchild)
			CreateBiTree(&((*T)->rchild));

		free(*T);
		*T = NULL;
	}
	return OK;
}
*/
/*
Status CreateBiTree_i(BiTree *T){
	char ch;

	scanf("%c",&ch);

	if(ch == '^')
		*T = NULL;
	else{
        *T = (BiTree)malloc(sizeof(BiTNode));
        if(!(*T))
			exit(OVERFLOW);
		(*T)->data = ch;
		CreateBiTree_i(&(*T)->lchild);
		CreateBiTree_i(&(*T)->rchild);
		}
		return OK;
}
*/
Status CreateBiTree(FILE *fp, BiTree *T){
	char ch;

	Scanf(fp, "%c", &ch);

	if(ch == '^')
		*T = NULL;
	else{
        *T = (BiTree)malloc(sizeof(BiTNode));
        if(!(*T))
			exit(OVERFLOW);
		(*T)->data = ch;
		CreateBiTree(fp, &(*T)->lchild);
		CreateBiTree(fp, &(*T)->rchild);
		}
		return OK;
	}

int BiTreeDepth(BiTree T){
	int LD, RD;
	if(T == NULL)
		return 0;
	else{
        LD = BiTreeDepth(T->lchild);
        RD = BiTreeDepth(T->rchild);

        return (LD>=RD ? LD : RD) +1;
	}
}


int BiTreeLength(BiTree T){
	Node node[100];
	int i, len;

	i = len = 0;

	if(T){
        node[i].left = T->lchild;
        node[i].right = T->rchild;
        node[i].n = 1;
        if(node[i].n > len)
			len = node[i].n;

		while(i>=0){
            while(node[i].left){
				node[i+1].left = node[i].left ->lchild;
				node[i+1].right = node[i].left ->rchild;
				node[i+1].n = 2*node[i].n;
				node[i+1].left = NULL;
				++i;
				if(node[i].n > len)
					len = node[i].n;
            }

            while(node[i].right){
                node[i+1].left = node[i].right ->lchild;
                node[i+1].right = node[i].right ->rchild;
                node[i+1].n = 2*node[i].n+1;
                node[i].right = NULL;
                ++i;
                if(node[i].n>len)
					len = node[i].n;
            }

            if(node[i].left == NULL && node[i].right == NULL)
				--i;
		}
	}

	return len;
}


void LevelOrderTraverse(BiTree T, void(Visit)(TElemType)){
	int i, j;
	BiTree p[100];

	i = j = 0;
	if(T)
		p[j++] = T;

	while(i<j){
		Visit(p[j]->data);
		if(p[i]->lchild)
			p[j++] = p[i] ->lchild;
		if(p[i]->rchild)
			p[j++] = p[i] ->rchild;
		i++;
	}

}

void PreOrderTraverse_1(BiTree T,void(Visit)(TElemType)){
	if(T)
	{
		Visit(T->data);
		PreOrderTraverse_1(T->lchild,Visit);
		PreOrderTraverse_1(T->rchild,Visit);
	}
}

Status PreOrderTraverse_2(BiTree T,Status(Visit)(TElemType)){
	if(T){
		if(Visit(T->data)){
			PreOrderTraverse_2(T->lchild, Visit);
			PreOrderTraverse_2(T->rchild, Visit);
		}
		return OK;
	}
	else{
		return ERROR;
	}
}

void  InOrderTraverse_1(BiTree T, void(Visit)(TElemType)){
	if(T){
		InOrderTraverse_1(T->lchild, Visit);
		Visit(T->data);
		InOrderTraverse_1(T->rchild, Visit);
	}
}

void PostOrderTraverse(BiTree T, void(Visit)(TElemType)){
	if(T){
		InOrderTraverse_1(T->lchild, Visit);
		InOrderTraverse_1(T->rchild, Visit);
				Visit(T->data);
	}
}
