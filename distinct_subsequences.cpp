#include<bits/stdc++.h>
using namespace std;
#define take_input freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
const ll mod = 1e9+7;
const ll n=7e2+3;
ll dp[n][n];
ll go(string &a,string &b,ll i,ll j)
{
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(j==b.length())
	{
		return 1;
	}
	if(i==a.length())
	{
		return 0;
	}
	if(a[i]!=b[j])
	{
		return dp[i][j]=go(a,b,i+1,j);
	}
	else
	{
		return dp[i][j]=go(a,b,i+1,j+1)+go(a,b,i+1,j);
	}
}
int main()
{
	take_input;
	fast;
	string a,b;
	cin>>a>>b;
	if(a==b)
	{
		cout<<"1"<<endl;
	}
	else
	{
		memset(dp,-1,sizeof(dp));
		cout<<go(a,b,0,0);
	}
	
}