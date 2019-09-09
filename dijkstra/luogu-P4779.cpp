#include<bits/stdc++.h>
using namespace std;
struct JackSlowFuck
{
	int from,to,next;
	long long len;
}Fu[1000010];
int head[100010],nn;
void addedge(int f,int t,int l)
{
	++nn;
	Fu[nn].next=head[f];
	Fu[nn].from=f;
	Fu[nn].len=l;
	Fu[nn].to=t;
	head[f]=nn;
}
long long dis[100010];
priority_queue<pair<long long,int> > Q;
void dijkstra(int s,int N)
{
	for(int i=1;i<=N;i++)
		dis[i]=2147483647;
	dis[s]=0;
	Q.push(pair<long long,int>(-dis[s],s));
	while(Q.size()!=0)
	{
		int now=Q.top().second;
		long long d=-Q.top().first;
		Q.pop();
		if(d!=dis[now]) continue;
		for(int k=head[now];k;k=Fu[k].next)
			if(dis[Fu[k].to]>dis[now]+Fu[k].len)
			{
				dis[Fu[k].to]=dis[now]+Fu[k].len;
				Q.push(pair<long long,int>(-dis[Fu[k].to],Fu[k].to));
			}
	}
}
int main()
{
	int N,M,S;
	cin>>N>>M>>S;
	for(int i=1;i<=M;i++)
	{
		int f,t,l;
		cin>>f>>t>>l;
		addedge(f,t,l);
	}
	dijkstra(S,N);
	for(int i=1;i<=N;i++)
		cout<<(int)dis[i]<<(i==N?'\n':' ');

}

