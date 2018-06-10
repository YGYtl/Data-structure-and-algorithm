#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct d * list;
struct d{
	int date;
	list next;
};
list creatlist(list head);
void find(list l1, list l2);
int main()
{
	list l1=NULL, l2=NULL;
	l1 = creatlist(l1);
	l2 = creatlist(l2);
	find(l1,l2);
	return 0;
}
list creatlist(list head)
{
	list p, l;
	int k;
	if(head==NULL)
	{
		head = (list)malloc(sizeof(struct d));
		head->date = -1;
		head->next = NULL;
	}
	l = head;
	while(1)
	{
		cin >> k;
		if(k == -1) break;
		p = (list)malloc(sizeof(struct d));
		p->date = k;
		p->next = l->next;
		l->next = p;
		l = p;
	}
	return head;
}
void find(list l1, list l2)
{
	list p = l2;
	int c = 0;
	while(l1->next!=NULL)
	{
		while(p->next!=NULL)
		{
			if(l1->next->date == p->next->date)
			{
				if(c != 0) cout << " ";
				cout << l1->next->date;
				c++;
				p = p->next;
				break;
			}
			else if(l1->next->date > p->next->date)
			{
				p = p->next;
			}
			else{
				break;
			}
		}
		l1 = l1->next;
	}
	if(c == 0) cout << "NULL";
	cout << endl;
}
