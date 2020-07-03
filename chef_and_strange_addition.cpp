#include <bits/stdc++.h>
using namespace std;
#define sd(n) scanf("%lld",&n)
#define pf(n) printf("%lld\n",n)
#define pb push_back
#define ll long long
#define debug4(a,b,c,d) printf("%s\t%lld\t%s\t%lld\t%s\t%lld\t%s\t%lld\n",#a,a,#b,b,#c,c,#d,d)
#define debug3(a,b,c) printf("%s\t%lld\t%s\t%lld\t%s\t%lld\n",#a,a,#b,b,#c,c)
#define debug2(a,b) printf("%s\t%d\t%s\t%d\n",#a,a,#b,b)
#define debug(a) printf("%s\t%lld\n",#a,a)

const ll m=1e9+7;
ll c;

ll dp[34][2][34][34];
ll cnt(ll num)
{
    ll ans=0;
    while(num)
    {
        num=(num &(num-1));
        ans++;
    }
    return ans;
}


void reset()
{
    for(ll i=0;i<34;i++)
        for(ll j=0;j<2;j++)
            for(ll k=0;k<34;k++)
                for(ll l=0;l<34;l++)
                    dp[i][j][k][l]=-1;
                    
}


ll no_of_ways(ll bit,ll cf,ll cnta,ll cntb)
{
    
    if(cnta<0 || cntb<0)
        return 0;
        
    if(bit==32)
        return (cnta==cntb && cnta==0 && cf==0);
    
    
    
    ll bitset=(c & (1<<bit));
    if(bitset)
        bitset=1;
    
    
    ll ans=0;
    
    if(dp[bit][cf][cnta][cntb]!=-1)
        return dp[bit][cf][cnta][cntb];
        
    if(cf!=bitset)
        ans+=no_of_ways(bit+1,cf,cnta-1,cntb)+no_of_ways(bit+1,cf,cnta,cntb-1);
    
    else
        ans+=no_of_ways(bit+1,0,cnta,cntb)+no_of_ways(bit+1,1,cnta-1,cntb-1);

    return dp[bit][cf][cnta][cntb]=ans;
}

ll solve()
{
    ll a,b;
    sd(a);
    sd(b);
    sd(c);
    reset();
    return no_of_ways(0,0,cnt(a),cnt(b));
}

int main()
{
    ll t;
    sd(t);
    while(t--)
        pf(solve());
}