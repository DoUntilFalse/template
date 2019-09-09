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
bool in[100010];
queue<int> Q;
void spfa(int s,int N)
{
	for(int i=1;i<=N;i++)
		dis[i]=2147483647;
	dis[s]=0;
	Q.push(s);
	while(Q.size()!=0)
	{
		int now=Q.front();
		Q.pop();
		in[now]=false;
		for(int k=head[now];k;k=Fu[k].next)
			if(dis[Fu[k].to]>dis[now]+Fu[k].len)
			{
				dis[Fu[k].to]=dis[now]+Fu[k].len;
				if(!in[Fu[k].to])
				{
					in[Fu[k].to]=true;
					Q.push(Fu[k].to);
				}
			}
	}
}
int main()
{
	int N,M,S;
	scanf("%d%d%d",&N,&M,&S);
	for(int i=1;i<=M;i++)
	{
		int f,t,l;
		cin>>f>>t>>l;
		addedge(f,t,l);
	}
	spfa(S,N);
	for(int i=1;i<=N;i++)
		printf("%d%c",(int)dis[i],i==N?'\n':' ');
}

