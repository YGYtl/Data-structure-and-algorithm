#include<iostream>
#include<map>
using namespace std;
int main()
{
	string s1, s2, s;
	map<string, int> m;
	int n, max=0, c=0;
	cin >> n;
	while(n--)
	{
		cin >> s1 >> s2;
		m[s1]++;
		m[s2]++;
	}
	map<string, int>::iterator tmp;
	for(tmp=m.begin(); tmp!=m.end(); tmp++)
	{
		if(max == 0)
		{
			s = tmp->first;
			max = tmp->second;
			continue;
		}
		if(max < tmp->second)
		{
			s = tmp->first;
			max = tmp->second;
		}
	}
	for(tmp=m.begin(); tmp!=m.end(); tmp++)
	{
		if(tmp->second == max) c++;
	}
	cout << s << " " << max;
	if(c > 1) cout << " " << c << endl;
	else cout << endl;
	return 0;
}
