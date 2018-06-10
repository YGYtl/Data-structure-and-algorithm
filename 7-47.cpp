#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
	map<int, vector<string> > v;
	int n, c, k, m;
	string s;
	cin >> n >> c;
	while(n--)
	{
		cin >> s >> m;
		while(m--)
		{
			cin >> k;
			v[k].push_back(s);
		}
	}
	for(int i=1; i<=c; i++)
	{
		cout << i << " " << v[i].size() << endl;
		sort(v[i].begin(),v[i].end());
		for(int j=0; j<v[i].size(); j++)
		{
			cout << v[i][j] << endl;
		}
	}
	return 0;
}
