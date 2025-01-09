#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const ll INF = 1e8;
ll n, m;
char mat[101][101] = {{0}};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i<n; ++i)
    {
        cin.getline(mat[i], 101);
        for(int l = 0; l<m; ++l)
        {
            mat[i][l] -= '0';
        }
    }

    vector<vector<int>> cost(n, vector<int>(m, INF));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    cost[0][0] = 0;
    pq.push(make_pair(0, 0));

    while(!pq.empty())
    {
        int c = pq.top().first, i = pq.top().second/100, l = pq.top().second%100, _i, _l;
        pq.pop();

        if(i-1>=0)
        {
            _i = i-1, _l = l;
            if(cost[i][l] + mat[_i][_l] < cost[_i][_l])
            {
                pq.push(make_pair(cost[_i][_l] = cost[i][l] + mat[_i][_l], _i*100+_l));
            }
        }

        if(i+1<n)
        {
            _i = i+1, _l = l;
            if(cost[i][l] + mat[_i][_l] < cost[_i][_l])
            {
                pq.push(make_pair(cost[_i][_l] = cost[i][l] + mat[_i][_l], _i*100+_l));
            }

        }

        if(l-1>=0)
        {
            _i = i, _l = l-1;
            if(cost[i][l] + mat[_i][_l] < cost[_i][_l])
            {
                pq.push(make_pair(cost[_i][_l] = cost[i][l] + mat[_i][_l], _i*100+_l));
            }

        }

        if(l+1<m)
        {
            _i = i, _l = l+1;
            if(cost[i][l] + mat[_i][_l] < cost[_i][_l])
            {
                pq.push(make_pair(cost[_i][_l] = cost[i][l] + mat[_i][_l], _i*100+_l));
            }

        }
    }

    cout<<cost[--n][--m]<<"\n";


    return 0;
}