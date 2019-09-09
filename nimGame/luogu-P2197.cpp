#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		int ans=0;
		while(N--)
		{
			int x;
			cin>>x;
			ans^=x;
		}
		if(ans) puts("Yes");
		else puts("No");
	}
}
