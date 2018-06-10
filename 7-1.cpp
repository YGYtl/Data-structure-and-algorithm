#include<iostream>
using namespace std;
int main()
{
	int n, k, l, o = 0;
	int max = 0, m = 0;
	cin >> n;
	l = n;
	while(l--)
	{
		cin >> k;
		if(o == 0 && k > 0)
		{
			m = k;
			o = 1;
			continue;
		}
		m += k;
		if(m < 0)
		{
			o = 0;
			m = 0;
		}
		if(m > max)
		{
			max = m;
		}
	}
	cout << max << endl;
	return 0;
}
