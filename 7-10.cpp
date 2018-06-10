#include<iostream>
using namespace std;
#define MAXSIZE 1003
#define INF 65535
int G[MAXSIZE][MAXSIZE];
int nv, ne;
void Creat();
int Prime();
int main()
{
	int f;
	scanf("%d %d", &nv, &ne);
	Creat();
	f = Prime();
	cout << f << endl;
	return 0;
}
void Creat()
{
	int a, b, w;
	for(int i=1; i<=nv; i++)
	{
		for(int j=1; j<=nv; j++)
		{
			G[i][j] = INF;
		}
	}
	for(int i=0; i<ne; i++)
	{
		cin >> a >> b >> w;
		G[a][b] = w;
		G[b][a] = w;
	}
}

int Prime()
{
	int lowcost[MAXSIZE];
	lowcost[1] = 0;
	for(int i=2; i<=nv; i++)
	{
		lowcost[i] = G[1][i];
	}
	int min = 0, j, cost=0;
	for(int i=2; i<=nv; i++)
	{
		int k = 0;
		min = INF;
		for(int i=1; i<=nv; i++)
		{
			cout << " " << lowcost[i];
		}
		cout << endl;
		for(j=1; j<=nv; j++)
		{
			if(lowcost[j]!=0&&lowcost[j]<min)
			{
				min = lowcost[j];
				k = j;
			}
		}
		if(k==0) return -1;
		cost += min;
		lowcost[k] = 0;
		for(j=2; j<=nv; j++)
		{
			if(lowcost[j]!=0&&G[k][j]<lowcost[j])
			{
				lowcost[j] = G[k][j];
			}
		}
	}
	return cost;
}
