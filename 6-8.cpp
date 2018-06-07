#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* 实现细节忽略 */
int GetHeight( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}

BinTree CreatBinTree()
{
	ElementType data;
	scanf("%c", &data);
	BinTree BT;
	if(data == '#')
	{
		BT = NULL;
	}
	else{
		BT = (BinTree)malloc(sizeof(BinTree));
		BT->Data = data;
		BT->Left = CreatBinTree();
		BT->Right = CreatBinTree();
	}
	return BT;
}

int GetHeight( BinTree BT )
{
	int Ld, Rd;
	if(BT == NULL)
	{
		return 0;
	}
	else
	{
		Ld = GetHeight(BT->Left);
		Rd = GetHeight(BT->Right);
		return (Ld>Rd?Ld:Rd)+1;
	}
}