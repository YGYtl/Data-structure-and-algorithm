#include<iostream>
#include<algorithm>
using namespace std;
struct data{
	string s;
	int sum;
}a[100001];
bool cmp(data a, data b)
{
	return a.sum > b.sum;
}
int main()
{
	int n, k, num, o=0, c=0;
	cin >> n >> k;
	string s;
	while(n--)
	{
		cin >> s >> num;
		o = 0;
		for(int i=0; i<c; i++)
		{
			if(a[i].s == s)
			{
				o = 1;
				if(num <= 500)
				{
					a[i].sum += 500;
				}
				else{
					a[i].sum += num;
				}
			}
		}
		if(o == 0)
		{
			a[c].s = s;
			if(num <= 500)
			{
				a[c++].sum += 500;
			}
			else{
				a[c++].sum += num;
			}
		}
	}
	sort(a,a+c,cmp);
	cin >> n;
	while(n--)
	{
		cin >> s;
		o = 0;
		for(int i=0; i<c; i++)
		{
			if(a[i].s == s)
			{
				o = 1;
				cout << a[i].sum << endl;
				break;
			}
		}
		if(o == 0) cout << "No Info" << endl;
	}
	return 0;
}
