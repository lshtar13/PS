#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n, m, l, r, nCmp = 0, cmps[1000] = {0};
pair<ll, ll> student[1000001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i<n; ++i)
    {
        for(int num, l = 0; l<m; ++l)
        {
            cin>>num;
            student[i*m+l] = make_pair(num, i);
        }
    }
    sort(student, student+n*m);

    ll l = 0, r = 0, result = 1e9+1;
    while(r<n*m)
    {
        if(nCmp < n)
        {
            nCmp = cmps[student[r++].second]++ == 0 ? nCmp + 1 : nCmp;
        }
        else
        {
            result = min(result, student[r-1].first - student[l].first);
            nCmp = --cmps[student[l++].second] == 0 ? nCmp - 1 : nCmp;
        }
    }

    cout<<result<<"\n";

    return 0;
}