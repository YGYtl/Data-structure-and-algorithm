#include<iostream>
#include<stack>
using namespace std;
struct node{
	int a, b, c, n;
	node(int m, int x, int y, int z):n(m),a(x),b(y),c(z){}
};
int main()
{
	int n;
	cin >> n;
	stack<node> s;
	s.push(node(n,'a','b','c'));
	while(!s.empty())
	{
		node t = s.top();
		s.pop();
		if(t.n==1) printf("%c -> %c\n", t.a, t.c);
		else{
			s.push(node(t.n-1,t.b,t.a,t.c));
			s.push(node(1,t.a,t.b,t.c));
			s.push(node(t.n-1,t.a,t.c,t.b));
		}
	}
	return 0;
}
