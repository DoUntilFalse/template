#include<bits/stdc++.h>
using namespace std;
int cnt[10010];
struct JackSlowFuck
{
	int from,to,len,next;
}Fu[10010];
int nn;
int head[10010];
void addedge(int f,int t,int l)
{
	++nn;
	Fu[nn].next=head[f];
	Fu[nn].from=f;
	Fu[nn].len=l;
	Fu[nn].to=t;
	head[f]=nn;
}
int N,M;
long long dis[10010];
bool in[10010];
queue<int> Q;
bool spfa()
{
	memset(in,0,sizeof in);
	memset(dis,0x3f,sizeof dis);
	dis[1]=0;
	while(Q.size()) Q.pop();
	Q.push(1);
	in[1]=true;
	while(Q.size())
	{
		int now=Q.front();
		Q.pop();
		cnt[now]++;
		if(cnt[now]>N) return true;
		in[now]=false;
		for(int k=head[now];k;k=Fu[k].next)
			if(dis[Fu[k].to]>dis[now]+Fu[k].len)
			{
				dis[Fu[k].to]=dis[now]+Fu[k].len;
				if(!in[Fu[k].to])
				{
					Q.push(Fu[k].to);
					in[Fu[k].to]=true;
				}
			}
	}
	return false;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>N>>M;
		memset(cnt,0,sizeof cnt);
		memset(head,0,sizeof head);
		nn=0;
		while(M--)
		{
			int f,t,l;
			cin>>f>>t>>l;
			addedge(f,t,l);
			if(l>=0)
				addedge(t,f,l);
		}
		if(spfa())
			puts("YE5");
		else
			puts("N0");
	}
}
