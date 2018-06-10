#include<iostream>
#include<queue>
using namespace std;
int main()
{
	queue<int> v1, v2, v;
	int o = 0;
	while(1)
	{
		int k;
		cin >> k;
		if(k==-1) break;
		v1.push(k);
	}
	while(1)
	{
		int k;
		cin >> k;
		if(k==-1) break;
		v2.push(k);
	}
	while(!v1.empty()&&!v2.empty())
	{
		if(v1.front() < v2.front())
		{
			v.push(v1.front());
			v1.pop();
		}
		else if(v1.front() > v2.front())
		{
			v.push(v2.front());
			v2.pop();
		}
		else{
			v.push(v1.front());
			v.push(v1.front());
			v1.pop();
			v2.pop();
		}
	}
	while(!v1.empty())
	{
		v.push(v1.front());
		v1.pop();
	}
	while(!v2.empty())
	{
		v.push(v2.front());
		v2.pop();
	}
	while(!v.empty())
	{
		if(o != 0) cout << " ";
		cout << v.front();
		v.pop();
		o = 1;
	}
	if(o!=0) cout << endl;
	else cout << "NULL" << endl;
	return 0;
}
