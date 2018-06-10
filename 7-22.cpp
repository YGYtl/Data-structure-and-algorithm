#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int main()
{
	int n1, n2, t;
	char ch;
	stack<int> s1, s2;
	scanf("%d %d", &n1, &n2);
	if(n1 > n2)
	{
		n1 = n2;
	}
	while(1)
	{
		getchar();
		scanf("%c", &ch);
		if(ch == 'T') break;
		else if(ch == 'A')
		{
			scanf("%d", &t);
			if(s1.size()==n1&&s2.size()!=0)
			{
				cout << "ERROR:Full" << endl;
				continue;
			}
			if(s1.size()!=n1) s1.push(t);
			else{
				while(!s1.empty())
				{
					s2.push(s1.top());
					s1.pop();
				}
				s1.push(t);
			}
		}
		else{
			if(s1.size()==0&&s2.size()==0)
			{
				cout << "ERROR:Empty" << endl;
				continue;
			}
			if(s2.size()==0)
			{
				while(!s1.empty())
				{
					s2.push(s1.top());
					s1.pop();
				}
			}
			cout << s2.top() << endl;
			s2.pop();
		}
	}
	return 0;
}
