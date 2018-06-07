#include <stdio.h>
#include <stdlib.h>
#define ERROR -1
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read();

ElementType FindKth( List L, int K );

int main()
{
    int N, K;
    ElementType X;
    List L = Read();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if ( X!= ERROR )
            printf("%d ", X);
        else
            printf("NA ");
    }
    return 0;
}

ElementType FindKth( List L, int K )
{
	if(L==NULL) return ERROR;
	while(--K)
	{
		if(L->Next == NULL) return ERROR;
		else L=L->Next;
	}
	return L->Data;
}
