#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const ll MAX_STND = 1e5, MAX_ANML = 1e5;
ll m, n, l, stands[MAX_STND];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>m>>n>>l;
    for(int i = 0; i<m; ++i)
    {
        cin>>stands[i];
    }
    sort(stands, stands+m);

    int result = 0;
    for(int x, y, _l, leftX, rightX, left, right, i = 0;
        i<n; ++i)
    {
        cin>>x>>y;
        if((_l = l - y)<0)
        {
            continue;
        }

        leftX = x - _l, rightX = x + _l;
        left = upper_bound(stands, stands+m, leftX-1) - stands,
        right = upper_bound(stands, stands+m, rightX) - stands;
        if(left<right)
        {
            ++result;
        }
    }

    cout<<result<<"\n";

    return 0;
}