#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve()
{
    int n, m;
    cin>>n>>m;

    for(int i = m, a, b; m && cin>>a>>b; --m)
        ;
    cout<<n-1<<"\n";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}