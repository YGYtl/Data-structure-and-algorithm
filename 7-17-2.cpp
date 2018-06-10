#include<iostream>
using namespace std;
void han(int n, char a, char b, char c)
{
	if(n==1) cout << a << " -> " << c << endl;
	else{
		han(n-1,a,c,b);
		cout << a << " -> " << c << endl;
		han(n-1,b,a,c);
	}
}
int main()
{
	int n;
	cin >> n;
	han(n,'a','b','c');
	return 0;
}
