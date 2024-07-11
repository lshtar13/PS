#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(void)
{
    int n, tgt0, tgt1, parent[10001] = {0},
        parent0[10001] = {0}, parent1[10001] = {0},
        idx0 = 0, idx1 = 0;
    cin>>n;
    for(int i = 0, p, c; i<n-1; ++i)
    {
        cin>>p>>c;
        parent[c] = p;
    }

    cin>>tgt0>>tgt1;
    while(tgt0)
    {
        parent0[idx0++] = tgt0;
        tgt0 = parent[tgt0];
    }
    
    while(tgt1)
    {
        parent1[idx1++] = tgt1;
        tgt1 = parent[tgt1];
    }

    while(parent0[--idx0]==parent1[--idx1])
        ;
    
    cout<<parent0[++idx0]<<"\n";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}