#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct d * list;
struct d{
	int data;
	list next;
};
list creatlist(list l);
list Blist(list l1, list l2);
void print(list l);
int main()
{
	list l1 = NULL;
	list l2 = NULL;
	list l;
	l1 = creatlist(l1);
	l2 = creatlist(l2);
	l = Blist(l1,l2);
	print(l);
	return 0;
}

list creatlist(list l)
{
	list p, head;
	if(l == NULL)
	{
		l = (list)malloc(sizeof(struct d));
		l->data = -1;
		l->next = NULL;
	}
	head = l;
	while(1)
	{
		int k;
		cin >> k;
		if(k == -1) break;
		p = (list)malloc(sizeof(struct d));
		p->data = k;
		p->next = l->next;
		l->next = p;
		l = p;
	}
	return head;
}

list Blist(list l1, list l2)
{
	list head, q;
	list l = (list)malloc(sizeof(struct d));
	l->data = -1;
	l->next = NULL;
	head = l;
	while(l1->next!=NULL&&l2->next!=NULL)
	{
		if(l1->next->data < l2->next->data)
		{
			q = (list)malloc(sizeof(struct d));
			q->data = l1->next->data;
			q->next = NULL;
			l->next = q;
			l = q;
			l1 = l1->next;
		}
		else if(l1->next->data > l2->next->data)
		{
			q = (list)malloc(sizeof(struct d));
			q->data = l2->next->data;
			q->next = NULL;
			l->next = q;
			l = q;
			l2 = l2->next;
		}
		else{
			q = (list)malloc(sizeof(struct d));
			q->data = l1->next->data;
			q->next = NULL;
			l->next = q;
			l = q;
			q = (list)malloc(sizeof(struct d));
			q->data = l2->next->data;
			q->next = NULL;
			l->next = q;
			l = q;
			l1 = l1->next;
			l2 = l2->next;
		}
	}
	if(l1->next!=NULL)
	{
		l->next = l1->next;
	}
	if(l2->next!=NULL)
	{
		l->next = l2->next;
	}
	return head;
}
void print(list l)
{
	int c = 0;
	while(l->next!=NULL)
	{
		if(c!=0) cout << " ";
		cout << l->next->data;
		l = l->next;
		c++;
	}
	if(c == 0)
	{
		cout << "NULL" << endl;
	}
	else{
		cout << endl;
	}
}
