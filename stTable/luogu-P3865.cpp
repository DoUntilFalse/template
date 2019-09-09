#include<bits/stdc++.h>
using namespace std;
int N,M;
int a[100010];
int l[100010][20];
int r[100010][20];
int xx[100010];
int x[20];
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
		scanf("%d",&a[i]);
	xx[1]=0;
	for(int i=2;i<=N;i<<=1)
		xx[i]=xx[i>>1]+1;
	for(int i=1;i<=N;i++)
		if(xx[i]==0)
			xx[i]=xx[i-1];
	x[0]=1;
	for(int i=1;i<=xx[N];i++)
		x[i]=x[i-1]*2;
	for(int i=1;i<=N;i++)
		l[i][0]=r[i][0]=a[i];
	for(int k=1;k<=xx[N];k++)
		for(int i=1;i<=N;i++)
		{
			l[i][k]=max(l[i][k-1],(i+x[k-1]>N)?0:l[i+x[k-1]][k-1]);
			r[i][k]=max(r[i][k-1],(i-x[k-1]<1)?0:r[i-x[k-1]][k-1]);
		}
	while(M--)
	{
		int ll,rr;
		scanf("%d%d",&ll,&rr);
		printf("%d\n",max(l[ll][xx[rr-ll+1]],r[rr][xx[rr-ll+1]]));
	}
}
