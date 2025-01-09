#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAX_NUMS = 1e6;
ll nums[MAX_NUMS] = {0}, tree[10*MAX_NUMS] = {0};

ll fill(ll s, ll e, ll node)
{
    if(s==e)
    {
        return tree[node] = nums[s];
    }
    else
    {
        ll mid = (s+e)/2;
        return tree[node] = fill(s,mid,node*2) 
                            + fill(mid+1,e,node*2+1);
    }
}

ll sum(ll s, ll e, ll node, ll l, ll r)
{
    if(s>r || e<l)
    {
        return 0;
    }

    if(l<=s && e<=r)
    {
        return tree[node];
    }

    ll mid = (s+e)/2;
    return sum(s, mid, node*2, l, r) + sum(mid+1,e,node*2+1,l,r);
}

void modify(ll s, ll e, ll node, ll idx, ll d)
{
    if(s>idx || e<idx)
    {
        return ;
    }

    tree[node] += d;
    if(s < e)
    {
        ll mid = (s+e)/2;
        modify(s,mid,node*2,idx,d);
        modify(mid+1,e,node*2+1,idx,d);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m, k;
    cin>>n>>m>>k;

    for(ll i = 0; i<n; ++i)
    {
        cin>>nums[i];
    }
    fill(0, n-1, 1);

    for(ll a, b, c, d, i = 0; i<(m+k); ++i)
    {
        cin>>a>>b>>c;
        --b;
        if(a == 1)
        {
            d = c - nums[b];
            nums[b] = c;
            modify(0, n-1, 1, b, d);
        }
        else
        {
            --c;
            cout<<sum(0, n-1, 1, b, c)<<"\n";
        }
    }

    return 0;
}