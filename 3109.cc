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

cll MAX_R = 1e4, MAX_C = 500;
ll r, c, mat[MAX_R][MAX_C] = {};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>r>>c;
    cin.ignore();
    string input;
    for(ll i = 0; i<r; ++i)
    {
        input.clear();
        getline(cin, input);
        for(ll l = 0; l<c; ++l)
        {
            mat[i][l] = input[l] == '.' ? 1 : 0;
        }
    }
    
    return 0;
}