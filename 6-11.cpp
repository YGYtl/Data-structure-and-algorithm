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

BinTree CreatBinTree(); /* 实现细节忽略 */
void PreorderPrintLeaves( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("Leaf nodes are:");
    PreorderPrintLeaves(BT);
    printf("\n");

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

void PreorderPrintLeaves( BinTree BT )
{
	if(BT)
	{
		if(BT->Left==NULL&&BT->Right==NULL)
		{
			printf(" %c", BT->Data);
		}
		PreorderPrintLeaves(BT->Left);
		PreorderPrintLeaves(BT->Right);	
	}
}