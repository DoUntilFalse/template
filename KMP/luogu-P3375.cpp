#include<bits/stdc++.h>
using namespace std;
int sl,wl;
char s[1000010],w[1000010];
int nxt[1000010];
void build()
{
	nxt[1]=0;
	int j=nxt[1];
	for(int i=2;i<=wl;i++)
	{
		while(j>0&&w[j+1]!=w[i]) j=nxt[j];
		if(w[j+1]==w[i]) j++;
		nxt[i]=j;
	}
}
void compare()
{
	int j=nxt[1];
	for(int i=1;i<=sl;i++)
	{
		while(j>0&&w[j+1]!=s[i]) j=nxt[j];
		if(w[j+1]==s[i]) j++;
		if(j==wl)
		{
			cout<<i-wl+1<<endl;
			j=nxt[j];
		}
	}
}
int main()
{
	scanf("%s%s",s+1,w+1);
	sl=strlen(s+1);
	wl=strlen(w+1);
	build();
	compare();
	for(int i=1;i<=wl;i++)
		cout<<nxt[i]<<" ";
	
}
