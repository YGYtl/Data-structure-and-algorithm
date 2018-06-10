#include<iostream>
#include<cstring>
#define MAXSIZE 10
using namespace std;
bool visited[MAXSIZE];
int arc[MAXSIZE][MAXSIZE];

void DFS(int i,int n)//�ݹ飬�ҵ��ڽӵ�ͽ�����һ���ݹ飬
{					//�����û�����ӵ�ʱ�����ص��ϲ�ݹ���ɽ��������жϡ� 
	visited[i] = true;
	printf("% d", i);
	for(int j=0; j<n; j++)
	{
		if(!visited[j]&&arc[i][j])
		{
			DFS(j,n);
		}
	}
}

void BFS(int i,int n)
{
	int front=-1, back=-1;//��û�д�ֵ����ָ��ͬһ���ط���-1 
	int q[MAXSIZE];
	visited[i] = true;
	q[++back] = i;
	while(front < back)
	{
		int v = q[++front];
		printf(" %d", v);
		for(int j=0; j<n; j++)
		{
			if(!visited[j]&&arc[v][j])//���ﲻ����i����v������ 
			{
				visited[j] = true;
				q[++back] = j;
			}
		}
	}
}


int main()
{
	memset(visited,false,sizeof(visited));
	int n, v, k;
	int a, b;
	cin >> n >> v;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i == j) arc[i][j] = 0;
		}
	}
	int c = v;
	while(c--)
	{
		cin >> a >> b;
		arc[a][b] = 1;
		arc[b][a] = 1;
	}
	for(int i=0; i<n; i++)//DFS
	{
		if(visited[i]==false)
		{
			printf("{");
			DFS(i,n);
			printf(" }\n");
		}
	}
	memset(visited,false,sizeof(visited));
	for(int i=0; i<n; i++)//BFS
	{
		if(visited[i]==false)
		{
			printf("{");
			BFS(i,n);
			printf(" }\n");
		}
	}
	return 0;
}
