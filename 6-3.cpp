#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read();

int Length( List L );

int main()
{
    List L = Read();
    printf("%d\n", Length(L));
    return 0;
}
int Length( List L )
{
	List p = L;
	int length = 0;
	while(p!=NULL)
	{
		length++;
		p = p->Next;
	}
	return length;
}
