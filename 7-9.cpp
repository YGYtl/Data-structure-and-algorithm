#include<iostream>
using namespace std;
#define MAXSIZE 1003
#define INF 63350
int G[MAXSIZE][MAXSIZE][2];
int lowdistance[MAXSIZE], lowcost[MAXSIZE], nowk[MAXSIZE];
int nv, ne, v, d;
void Creat()
{
	cin >> nv >> ne >> v >> d;
	int a, b, l, w;
	for(int i=0; i<nv; i++)
	{
		for(int j=0; j<nv; j++)
		{
			G[i][j][0] = INF;
			G[i][j][1] = INF;
		}
	}
	for(int i=0; i<ne; i++)
	{
		cin >> a >> b >> l >> w;
		G[a][b][0] = l;
		G[a][b][1] = w;
		G[b][a][0] = l;
		G[b][a][1] = w;
	}
}
void Dijkstra();
int main()
{
	Creat();
	Dijkstra();
	if(lowdistance[d]<INF)
	{
		cout << lowdistance[d] << " " << lowcost[d] << endl;
	}
	return 0;
}

void Dijkstra()
{
	int min, cost=0, k;
	for(int i=0; i<nv; i++)
	{
		lowdistance[i] = G[v][i][0];
		lowcost[i] = G[v][i][1];
		nowk[i] = 0;
	}
	nowk[v] = 1;
	lowdistance[v] = 0;
	lowcost[v] = 0;
	
	for(int i=1; i<nv; i++)
	{
		min = INF;
		for(int j=0; j<nv; j++)
		{
			if(nowk[j]==0&&lowdistance[j]<min)
			{
				min = lowdistance[j];
				cost = lowcost[j];
				k = j;
			}
		}
		nowk[k] = 1;
		for(int j=0; j<nv; j++)
		{
			if(nowk[j]==0&&(min+G[k][j][0]<lowdistance[j]))
			{
				lowdistance[j] = min + G[k][j][0];
				lowcost[j] = cost + G[k][j][1];
			}
			else if(nowk[j]==0&&(min+G[k][j][0]==lowdistance[j])&&(cost+G[k][j][1]<lowcost[j]))
			{
				lowcost[j] = cost + G[k][j][1];
			}
		}
	}
}
