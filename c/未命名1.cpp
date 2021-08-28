 #include<bits/stdc++.h>

using namespace std;

const int N = 410, M = 100010, INF = 1e8;

int n, m, S, T;
int h[N], e[M], w[M], ne[M], idx;
int q[N], d[N], cur[N];

char s[25][25];
int num[25][25];
int G[N][N];
int cnt;

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
	e[idx] = a, w[idx] = 0, ne[idx] = h[b], h[b] = idx ++ ;
}

bool bfs()
{
	int hh = 0, tt = 0;
	memset(d, -1, sizeof d);
	q[0] = S, d[S] = 0, cur[S] = h[S];
	while (hh <= tt)
	{
		int t = q[hh ++ ];
		for (int i = h[t]; ~i; i = ne[i])
		{
			int ver = e[i];
			if (d[ver] == -1 && w[i])
			{
				d[ver] = d[t] + 1;
				cur[ver] = h[ver];
				if (ver == T)  return true;
				q[ ++ tt] = ver;
			}
		}
	}
	return false;
}

int find(int u, int limit)
{
	if (u == T) return limit;
	int flow = 0;
	for (int i = cur[u]; ~i && flow < limit; i = ne[i])
	{
		cur[u] = i;  // 当前弧优化
		int ver = e[i];
		if (d[ver] == d[u] + 1 && w[i])
		{
			int t = find(ver, min(w[i], limit - flow));
			if (!t) d[ver] = -1;
			w[i] -= t, w[i ^ 1] += t, flow += t;
		}
	}
	return flow;
}

int dinic()
{
	int r = 0, flow;
	while (bfs()) while (flow = find(S, INF)) r += flow;
	return r;
}
void flody()
{
	for(int k=1; k<=cnt; k++)
		for(int i=1; i<=cnt; i ++)
			for(int j=1; j<=cnt; j++)
				if(G[i][k] && G[k][j])
					G[i][j]=true;
}
int main()
{
	memset(h, -1, sizeof h);
	idx=0;
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++)
		cin>>s[i]+1;
	S = N - 2, T = N - 1;
	cnt=0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(s[i][j]=='1')
				num[i][j]=++cnt;

	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(num[i][j])
			{
				int a=num[i][j];
				add(S,a,1);
				add(cnt+a,T,1);
				int b=num[i+1][j];
				if(b)
					G[a][b]=true;
				b=num[i][j+1];
				if(b)
					G[a][b]=true;
			}

	flody();

	for(int i=1; i<=cnt; i ++)
		for(int j=1; j<=cnt; j ++)
			if(G[i][j])
				add(i,cnt+j,1);

	printf("%d\n",cnt-dinic());
	return 0;
}
