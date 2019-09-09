#include<bits/stdc++.h>
using namespace std;
struct node
{
	node* ch[2];
	int l,r;
	long long lazy,sum;
}Sg[1000010];
int v[100010];
int nn;
void newnode(node* &x){x=Sg+nn++;}
void pushdown(node* now)
{
	if(!now||!now->lazy) return;
	for(int i=0;i<2;i++)
		if(now->ch[i])
		{
			now->ch[i]->lazy+=now->lazy;
			now->ch[i]->sum+=now->lazy*(now->ch[i]->r-now->ch[i]->l+1);
		}
	now->lazy=0;
}
void update(node* now)
{
	if(!now) return;
	now->sum=0;
	for(int i=0;i<2;i++)
		if(now->ch[i])
			now->sum+=now->ch[i]->sum;
}
node* build(int ll,int rr)
{
	node* x;
	newnode(x);
	x->l=ll;
	x->r=rr;
	if(ll==rr)
	{
		x->sum=v[ll];
		return x;
	}
	int mid=ll+rr>>1;
	x->ch[0]=build(ll,mid);
	x->ch[1]=build(mid+1,rr);
	update(x);
	return x;
}
void add(node* now,int ll,int rr,int l,int r,int k)
{
	pushdown(now);
	if(ll>r||rr<l) return;
	if(ll>=l&&rr<=r)
	{
		now->lazy+=k;
		now->sum+=k*(rr-ll+1);
		return;
	}
	int mid=ll+rr>>1;
	add(now->ch[0],ll,mid,l,r,k);
	add(now->ch[1],mid+1,rr,l,r,k);
	update(now);
}
long long query(node* now,int ll,int rr,int l,int r)
{
	pushdown(now);
	if(ll>r||rr<l) return 0;
	if(ll>=l&&rr<=r)
		return now->sum;
	int mid=ll+rr>>1;
	long long ans=query(now->ch[0],ll,mid,l,r)+query(now->ch[1],mid+1,rr,l,r);
	return ans;
}
node* root;
int main()
{
	int N,M;
	cin>>N>>M;
	for(int i=1;i<=N;i++)
		cin>>v[i];
	root=build(1,N);
	for(int i=1;i<=M;i++)
	{
		int opt;
		cin>>opt;
		if(opt==1)
		{
			int x,y,k;
			cin>>x>>y>>k;
			add(root,1,N,x,y,k);
		}
		else
		{
			int x,y;
			cin>>x>>y;
			cout<<query(root,1,N,x,y)<<endl;
		}
	}
}
