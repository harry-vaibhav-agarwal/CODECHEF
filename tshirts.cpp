#include <bits/stdc++.h>
using namespace std;
#define sd(n) scanf("%lld",&n)
#define pf(n) printf("%lld\n",n)
#define pb push_back
#define ll long long
const ll m=1e9+7;
ll n;
vector<ll>tshirt[103];
ll dp[102][1<<12];
void reset()
{
    for(ll i=0;i<103;i++)
        tshirt[i].clear();
}

ll assign(ll tsid,ll mask)
{
    if(mask+1==(1<<n))
        return dp[tsid][mask]=1;
        
    if(tsid==101)
        return 0;
        
    if(dp[tsid][mask]!=-1)
        return dp[tsid][mask];
        
        
    dp[tsid][mask]=assign(tsid+1,mask);
        
    for(auto i:tshirt[tsid])
        if((mask & (1<<(i-1)))==0)
            dp[tsid][mask]=(dp[tsid][mask]+assign(tsid+1,mask|(1<<(i-1))))%m;
        
    
    
    return dp[tsid][mask];
        
}
ll solve()
{
    ll a;
    sd(n);
    cin.get();
    string str;
    reset();
    for(ll i=1;i<=n;i++)
    {
        getline(cin,str);
        
        stringstream ss(str);
        while(ss>>a)
            tshirt[a].pb(i);  //ith person has a tshirt in his wardrobe
        
    }
    memset(&dp,-1,sizeof(dp));
   return assign(1,0);
   
   
    
}

int main() {
	
	ll t;
	sd(t);
	while(t--)
	    pf(solve());
	return 0;
}