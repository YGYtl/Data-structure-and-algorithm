#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
typedef int ElementType;
typedef struct TNode * BinTree;
struct TNode{
	ElementType data;
	BinTree left;
	BinTree right;
};
BinTree Insert(BinTree BT, ElementType X);
bool Judge(BinTree bt, BinTree btp);
void FreeTree(BinTree bt);
int main()
{
	int n, m, k, c;
	scanf("%d", &n);
	while(n)
	{
		if(n==0) break;
		BinTree bt = NULL;
		scanf("%d", &m);
		c = n;
		while(c--)
		{
			scanf("%d", &k);
			bt = Insert(bt,k);
		}
		while(m--)
		{
			c = n;
			BinTree btp = NULL;
			while(c--)
			{
				scanf("%d", &k);
				btp = Insert(btp,k);
			}
			if(Judge(bt,btp)) printf("Yes\n");
			else printf("No\n");
			FreeTree(btp);//把Tree给free了.
		}
		scanf("%d", &n);
		FreeTree(bt);
	}
	return 0;
}
bool Judge(BinTree bt, BinTree btp)
{
	if(bt==NULL&&btp==NULL) return true;
	else if((bt==NULL&&btp!=NULL)||(bt!=NULL)&&(btp==NULL)) return false;
	else if(bt!=NULL&&btp!=NULL&&bt->data!=btp->data) return false;
	else return (Judge(bt->left,btp->left)&&Judge(bt->right,btp->right));
	//用递归判断两棵树是否相同，递归注重结果，不注重过程。 
}

BinTree Insert(BinTree BT, ElementType X)
{
	if(BT == NULL)
	{
		BT = (BinTree)malloc(sizeof(struct TNode));
		BT->data = X;
		BT->left = NULL;
		BT->right = NULL;
	}
	else if(X > BT->data)
	{
		BT->right = Insert(BT->right,X);
	}
	else if(X < BT->data){
		BT->left = Insert(BT->left,X);
	}
	return BT;
}

void FreeTree(BinTree bt)
{
	if(bt->left) FreeTree(bt->left);
	if(bt->right) FreeTree(bt->right);
	free(bt);
};//下面开始向上删除. 

