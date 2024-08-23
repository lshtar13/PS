#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef const ll cll;
typedef priority_queue<ll> pqll;
typedef priority_queue<pll> pqpll;

ll n, npos[2] = {0}, chess[10][10] = {}, pos[2][100][2] = {}, dxdy[4][2] = {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

ll search(ll k)
{
    ll result = 0;
    for(ll idx = 0, i = pos[k][idx][0], l = pos[k][idx][1]; 
        idx<npos[k]; ++idx, i = pos[k][idx][0], l = pos[k][idx][1])
    {
        if(!chess[i][l])
        {
            continue;
        }

        vector<pll> modified;
        chess[i][l] = 0;
        modified.push_back(make_pair(i, l));
        for(ll d = 0; d<4; ++d)
        {
            for(ll a = i, b = l; a<n && b<n && a>=0 && b>=0; a += dxdy[d][0], b += dxdy[d][1])
            {
                if(chess[a][b])
                {
                    chess[a][b] = 0;
                    modified.push_back(make_pair(a, b));
                }
            }
        }
        result = max(result, search(k)+1);
        for(auto &p: modified)
        {
            chess[p.first][p.second] = 1;
        }

        chess[i][l] = 1;
    }

    return result;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(chess, -1, sizeof(chess));
    cin>>n;
    for(ll i = 0; i<n; ++i)
    {
        for(ll l = 0; l<n; ++l)
        {
            cin>>chess[i][l];
            if(chess[i] && (i+l)%2)
            { 
                pos[1][npos[1]][0] = i, pos[1][npos[1]++][1] = l;
            }
            else if(chess[i] && (i+l)%2 == 0)
            { 
                pos[0][npos[0]][0] = i, pos[0][npos[0]++][1] = l;
            }
        }
    }

    cout<<search(0) + search(1)<<"\n";

    return 0;
}