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

ll mat[5][5] = {{}};

ll search(ll i, ll l, ll y, ll s, cll _i, cll _l, ll current[][5])
{
    if(y+s == 7 && s>y)
    {
        return 1;
    }
    
    ll result = 0, _y, _s;
    if(i+1<5 && !current[i+1][l])
    {
        current[i+1][l] = 1;
        result += search(i+1, l, y + !mat[i+1][l], s + mat[i+1][l], _i, _l, current);
        current[i+1][l] = 0;
    }
    
    if(i-1>=0 && !current[i-1][l])
    {
        current[i-1][l] = 1;
        result += search(i-1, l, y + !mat[i-1][l], s + mat[i-1][l], _i, _l, current);
        current[i-1][l] = 0;
    }
    
    if(l+1<5 && !current[i][l+1])
    {
        current[i+1][l] = 1;
        result += search(i+1, l, y + !mat[i+1][l], s + mat[i+1][l], _i, _l, current);
        current[i+1][l] = 0;
    }
    
    if(l-1>=0 && !current[i][l-1])
    {
        current[i+1][l] = 1;
        result += search(i+1, l, y + !mat[i+1][l], s + mat[i+1][l], _i, _l, current);
        current[i+1][l] = 0;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(ll i = 0; i<5; ++i)
    {
        string input;
        getline(cin, input);
        for(ll l = 0; l<5; ++l)
        {
            mat[i][l] = input[l] == 'Y' ? 0 : 1;
        }
    }

    ll result = 0;
    for(ll k = 0; k<25; ++k)
    {
        ll i = k/5, l = k%5, current[5][5] = {{}};
        result += search(i, l, 0, 0, i, l, current);
    }

    cout<<result;

    return 0;
}