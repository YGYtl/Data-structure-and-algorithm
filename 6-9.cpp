#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); 
void InorderTraversal( BinTree BT );
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
    return 0;
}
BinTree CreatBinTree()
{
	BinTree BT;
	char c;
	scanf("%c", &c);
	if(c == '#')
	{
		BT = NULL;
	}
	else{
		BT = (BinTree)malloc(sizeof(struct TNode));
		BT->Data = c;
		BT->Left = CreatBinTree();
		BT->Right = CreatBinTree();
	}
	return BT;
}

void InorderTraversal( BinTree BT )
{
	if(BT)
	{
		InorderTraversal(BT->Left);
		printf("%c", BT->Data);
		InorderTraversal(BT->Right);
	}
}

void PreorderTraversal( BinTree BT )
{
	if(BT)
	{
		printf("%c", BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
}

void PostorderTraversal( BinTree BT )
{
	if(BT)
	{
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		printf("%c", BT->Data);
	}
}

void LevelorderTraversal( BinTree BT )
{
	if(BT == NULL)
	{
		return ;
	}
	BinTree Tree[1000];
	int head=0, last=0;
	Tree[last++] = BT;
	while(head < last)
	{
		BinTree temp = Tree[head++];
		printf("%c", temp->Data);
		if(temp->Left)
		{
			Tree[last++] = temp->Left;
		}
		if(temp->Right)
		{
			Tree[last++] = temp->Right; 
		}
	}
}