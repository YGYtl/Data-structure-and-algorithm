#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a, int b)
{
	return a < b;
}
int main()
{
	int n, k;
	cin >> n;
	vector<int> v;
	while(n--)
	{
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(),v.end(), cmp);
	for(int i=0; i<v.size(); i++)
	{
		if(i!=0) cout << " ";
		cout << v[i];
	}
	return 0;
}
