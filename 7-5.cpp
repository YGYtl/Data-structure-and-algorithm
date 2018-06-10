#include<iostream>
using namespace std;
int H[1001], size;
void Creat();
void Insert(int k);
int main()
{
	int n, m, k;
	cin >> n >> m;
	Creat();
	while(n--)
	{
		cin >> k;
		Insert(k);
	}
	while(m--)
	{
		cin >> k;
		cout << H[k];
		while(k > 1)
		{
			k /= 2;
			cout << " " << H[k];
		}
		cout << endl;
	}
	return 0;
}
void Creat()
{
	size = 0;
	H[0] = -10000;
}

void Insert(int k)
{
	int i;
	if(size==1000) return;
	size++;
	for(i=size; H[i/2] > k; i/=2)
	{
		H[i] = H[i/2];
	}
	H[i] = k;
}
