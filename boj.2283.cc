#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const ll MAX_PNTS = 1e6;
ll n, k, sum = 0, st_pnts[MAX_PNTS+1] = {0}, en_pnts[MAX_PNTS+1] = {0};

int main(void)
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    
    cin>>n>>k;
    for(int a, b, i = 0; i<n; ++i)
    {
        cin>>a>>b;
        ++st_pnts[a], ++en_pnts[b];
        sum += b-a;
    }

    ll st = 0, en = 0, po = st_pnts[0], ne = st_pnts[0], _k = 0;
    while(_k != k && en <= MAX_PNTS)
    {
        if(_k < k)
        {
            _k += po;
            po += st_pnts[++en], po -= en_pnts[en];
        }
        else
        {
            _k -= ne;
            ne += st_pnts[++st] , ne -= en_pnts[st];
        }
    }

    if(_k == k)
    {
        cout<<st<<" "<<en<<"\n";
    }
    else
    {
        cout<<0<<" "<<0<<"\n";
    }

    return 0;
}