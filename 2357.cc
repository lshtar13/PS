#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MID(a,b) ((a+b)/2)

const ll MAX_N = 1e5;
ll nums[MAX_N] = {0}, maxTree[10*MAX_N] = {0}, minTree[10*MAX_N] = {0};

ll fill_max(ll s, ll e, ll node)
{
    if(s == e)
    {
        return maxTree[node] = nums[s];
    }
    else
    {
        return maxTree[node] =
            max(fill_max(s,MID(s,e),node*2),
                fill_max(MID(s,e)+1,e,node*2+1));
    }
}

ll fill_min(ll s, ll e, ll node)
{
    if(s == e)
    {
        return minTree[node] = nums[s];
    }
    else
    {
        return minTree[node] =
            min(fill_min(s,MID(s,e),node*2),
                fill_min(MID(s,e)+1,e,node*2+1));
    }
}

ll find_max(ll s, ll e, ll node, ll l, ll r)
{
    if(s>r || e<l)
    {
        return 0;
    }

    if(l<=s && e<=r)
    {
        return maxTree[node];
    }

    return max(find_max(s,MID(s,e),node*2,l,r),
                find_max(MID(s,e)+1,e,node*2+1,l,r));
}

ll find_min(ll s, ll e, ll node, ll l, ll r)
{
    if(s>r || e<l)
    {
        return 1e9+1;
    }

    if(l<=s && e<=r)
    {
        return minTree[node];
    }

    return min(find_min(s,MID(s,e),node*2,l,r),
                find_min(MID(s,e)+1,e,node*2+1,l,r));
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m;
    cin>>n>>m;
    for(int i = 0; i<n; ++i)
    {
        cin>>nums[i];
    }
    fill_max(0, n-1, 1);
    fill_min(0, n-1, 1);

    for(int a, b, i = 0; i<m; ++i)
    {
        cin>>a>>b;
        --a, --b;
        cout<<find_min(0, n-1, 1, a, b)<<" "
            <<find_max(0, n-1, 1, a, b)<<"\n";
    }

    return 0;
}