List Reverse( List L )
{
	List p, q;
	p = L;
	L = NULL;
	while(p!=NULL)
	{
		q = L;
		L = p;
		p = p->Next;
		L->Next = q;
	}
	return L;
}
