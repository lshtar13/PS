#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, q, cords[200000] = {0};

int minFatigue(int left, int right)
{
    int fatigue = 0,
        l = lower_bound(cords, cords+n, left) - cords,
        r = upper_bound(cords, cords+n, right) - cords,
        nCord = r - l, costs[200000] = {0};

    for(int h = l+1; h<r; ++h)
    {
        costs[0] += abs(cords[l] - cords[h]);
    }

    for(int dif, prev = cords[l], conf = l+1; conf<r; ++conf)
    {
        dif = cords[conf]  - prev;
        costs[conf-l] = costs[conf-l-1] + dif*(conf - l) - dif*(r-conf);
        prev = cords[conf];
    }
    if(nCord>0)
    {
        sort(costs, costs+nCord);
    }

    for(int i = 1; i<nCord; ++i)
    {
        fatigue += abs(costs[i] - costs[i-1]);
    }

    return fatigue;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>q;
    for(int i = 0; i<n; ++i)
    {
        cin>>cords[i];
    }

    for(int l, r, i = 0; i<q; ++i)
    {
        cin>>l>>r;
        cout<<minFatigue(l, r)<<"\n";
    }

    return 0;
}