#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef const ll cll;
typedef queue<ll> qll;
typedef queue<pll> qpll;
typedef priority_queue<ll> pqll;
typedef priority_queue<pll> pqpll;
typedef vector<ll> vll;

ll l, k, c, spot[10001] = {};

struct Compare {
    bool operator()(const pll& p1, const pll& p2) {
        if (p1.first == p2.first) {
            return p1.second > p2.second; // first가 같으면 second가 작은 것이 우선
        }
        return p1.first < p2.first; // first가 큰 것이 우선
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>l>>k>>c;
    for(ll i = 0; i<k; ++i)
    {
        cin>>spot[i];
    }
    sort(spot, spot+k);
    priority_queue<pll, vector<pll>, Compare> pq;
    pq.push(make_pair(l, 0));
    ll genCut = l + 1;
    while(c-- > 0)
    {
        ll st = pq.top().second, en = st + pq.top().first, mid = (st + en)/2, 
            *_cut = lower_bound(spot, spot+k, mid), cut = *_cut;

        if(cut >= en)
        {
            cut = *(_cut-1);
        }
        cout<<st<<" "<<en<<" "<<cut<<" "<<mid<<"\n";
        pq.pop();
        genCut = min(genCut, cut);
        pq.push(make_pair(cut - st, st));
        pq.push(make_pair(en - cut, cut));
    }

    cout<<pq.top().first<<" "<<genCut<<"\n";

    return 0;
}