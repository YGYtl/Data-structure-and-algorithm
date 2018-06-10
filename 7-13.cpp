#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n, k;
	int num[54]={'\0'};
	memset(num,0,sizeof(num));
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> k;
		num[k]++;
	}
	for(int i=0; i<=50; i++)
	{
		if(num[i]!=0)
		{
			cout << i << ":" << num[i] << endl;
		}
	}
	return 0;
}
