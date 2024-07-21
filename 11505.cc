#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAX_NUMS = 1e6, MOD = 1e9 + 7;
ll nums[MAX_NUMS] = {0}, tree[10*MAX_NUMS] = {0};

ll fill(ll s, ll e, ll node)
{
    if(s == e)
    {
        return tree[node] = nums[s]%MOD;
    }
    else
    {
        ll mid = (s+e)/2;
        return tree[node] = 
            (fill(s, mid, node*2) * fill(mid+1, e, node*2 + 1))%MOD;
    }
}

void modify(ll s, ll e, ll node, ll idx, ll num)
{
    if(s>idx || e<idx)
    {
        return;
    }

    ll mid = (s+e)/2;
    tree[node] = tree[node] * num;
    tree[node] /= nums[idx];
    if(s<e)
    {
        modify(s, mid, node*2, idx, num);
        modify(mid+1, e, node*2 + 1, idx, num);
    }
}

ll mult(ll s, ll e, ll node, ll l, ll r)
{
    if(s>r || e<l)
    {
        return 1;
    }
    else if(s<=l && r<=e)
    {
        return tree[node];
    }
    else
    {
        ll mid = (s+e)/2;
        return (mult(s, mid, node*2, l, r) 
            * mult(mid+1, e, node*2+1, l, r))%MOD;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m, k;
    cin>>n>>m>>k;
    for(int i = 0; i<n; ++i)
    {
        cin>>nums[i];
        nums[i] = !nums[i] ? -1 : nums[i];
    }
    fill(0, n-1, 1);

    for(int a, b, c, i = 0; i<(m+k); ++i)
    {
        cin>>a>>b>>c;
        --b;
        if(a == 1)
        {
            modify(0, n-1, 1, b, c);
            nums[b] = c;
        }
        else
        {
            cout<<mult(0, n-1, 1, b, --c)<<"\n";
        }
    }

    return 0;
}