#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

Position BinarySearch( List L, ElementType X )
{
	int l=0, r=L->Last;
	if(L)
	{
		int mid;
		while(l <= r)
		{
			int mid = (l+r)/2;
			if(L->Data[mid] == X) return mid;
			else if(L->Data[mid] < X) l = mid + 1;
			else r = mid - 1;
		}
		return NotFound;
	}
	return NotFound;
}
List ReadInput()
{
	int n, k, o;
	List l = (List)malloc(sizeof(struct LNode));
	l->Last = 0;
	scanf("%d", &n);
	if(n <= MAXSIZE) o = n;
	else o = n - MAXSIZE;
	while(n--)
	{
		scanf("%d", &k);
		if(o)
		{
			l->Data[++l->Last] = k;
		}
		o--;
	}
	return l;
}