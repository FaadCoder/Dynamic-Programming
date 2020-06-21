#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod=1e9+7;
#define take_input freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
unordered_map<string,bool> mp;

bool go(string str,string pat,ll s=0,ll p=0)
{
	string temp=to_string(s)+"|"+to_string(p);
	if(mp.count(temp))
		return mp[temp];
	if(p==pat.length())
	{
		return mp[temp]=(s==str.length());
	}
	if(s==str.length())
	{
		for(ll i=p;i<pat.length();i++)
			if(pat[i]!='*')
				return (mp[temp]=false);
		return (mp[temp]=true);
	}

	if(pat[p]=='?' or pat[p]==str[s])
		return mp[temp]=go(str,pat,s+1,p+1);
	if(pat[p]=='*')
		return mp[temp]=go(str,pat,s+1,p) or go(str,pat,s,p+1);
	return mp[temp]=false;
}
int main()
{
	take_input;
	fast;
	string str,pat;
	cin>>str>>pat;
	cout<<go(str,pat)<<endl;
	
}