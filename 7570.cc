#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const ll N_MAX = 1e6;
ll n, arr[N_MAX+1] = {0};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    ll gap = 0;
    cin>>n;
    for(ll num, _num, i = 0; i<n; ++i)
    {
        cin>>num;
        arr[num] = arr[num-1] ? arr[num-1] : num;
        gap = max(gap, num - arr[num]);
    }

    cout<<n - gap - 1<<"\n";
    
    return 0;
}