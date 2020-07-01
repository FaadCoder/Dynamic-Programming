#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define take_input freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define ll long long int
const ll mod=1e9+7;
ll dp[1002][1002];
ll go(string s1,string s2,ll i=0,ll j=0)
{

	if(dp[i][j]!=-1)
		return dp[i][j];
	ll cost=0;
	if(i==s1.length() and j==s2.length())
	{
		cost=0;
	}
	else if(i==s1.length())
	{
		cost+=go(s1,s2,i,j+1)+s2[j];
	}
	else if(j==s2.length())
	{
		cost+=go(s1,s2,i+1,j)+s1[i];
	}
	else if(s1[i]==s2[j])
	{
		cost+=go(s1,s2,i+1,j+1);
	}
	else
	{
		cost+=min(go(s1,s2,i+1,j)+s1[i],go(s1,s2,i,j+1)+s2[j]);
	}
	return dp[i][j]=cost;
}
int main()
{
	fast;
	take_input;
	string s1,s2;
	cin>>s1>>s2;
	memset(dp,-1,sizeof(dp));
	cout<<go(s1,s2);
	return 0;
}