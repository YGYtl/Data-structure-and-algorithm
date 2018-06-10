#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
//ÄÚ´æ³¬ÏÞ queue 
using namespace std;
int main()
{
	map<string, vector<int> > m;
	int n, c;
	int num, ms;
	string s;
	cin >> n >> c;
	while(c--)
	{
		cin >> num >> ms;
		while(ms--)
		{
			cin >> s;
			m[s].push_back(num);
		}
	}
	while(n--)
	{
		cin >> s;
		cout << s << " " << m[s].size();
		sort(m[s].begin(), m[s].end());
		for(int i=0; i<m[s].size(); i++)
		{
			cout << " " << m[s][i];
		}
		cout << endl;
	}
	return 0;
}
