#include<iostream>
#include<algorithm>
using namespace std;
int v[1000005];
int main()
{
	int n, k;
	cin >> n;
	for(int i=0; i<2*n; i++)
	{
		cin >> k;
		v[i] = k;
	}
	sort(v, v+2*n);
	cout << v[n-1] << endl;
	return 0;
}
