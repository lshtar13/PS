#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int INF = 1e7;

int solve(int n)
{
    int cost[125][125] = {{0}}, mat[125][125] = {{0}};

    for(int i = 0; i<n; ++i)
    {
        for(int l = 0; l<n; ++l)
        {
            cin>>mat[i][l];
            cost[i][l] = INF;
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    cost[0][0] = mat[0][0];
    pq.push(make_pair(cost[0][0], 0));

    while(!pq.empty())
    {
        int c = pq.top().first, i = pq.top().second/125, l = pq.top().second%125, _i, _l;
        pq.pop();

        // cout<<i<<" "<<l<<"\n";

        if(c > cost[i][l])
        {
            continue;
        }
        
        if(i-1>=0)
        {
           _i = i-1, _l = l;
           if(cost[i][l] + mat[_i][_l] < cost[_i][_l])
           {
                pq.push(make_pair(cost[_i][_l] = cost[i][l] + mat[_i][_l], _i*125+_l));
           }
        }

        if(i+1<n)
        {
           _i = i+1, _l = l; 
           if(cost[i][l] + mat[_i][_l] < cost[_i][_l])
           {
                pq.push(make_pair(cost[_i][_l] = cost[i][l] + mat[_i][_l], _i*125+_l));
           }
        }

        if(l-1>=0)
        {
           _i = i, _l = l-1; 
           if(cost[i][l] + mat[_i][_l] < cost[_i][_l])
           {
                pq.push(make_pair(cost[_i][_l] = cost[i][l] + mat[_i][_l], _i*125+_l));
           }
        }

        if(l+1<n)
        {
           _i = i, _l = l+1; 
           if(cost[i][l] + mat[_i][_l] < cost[_i][_l])
           {
                pq.push(make_pair(cost[_i][_l] = cost[i][l] + mat[_i][_l], _i*125+_l));
           }
        }
    }

    return cost[n-1][n-1];
}

int main(void)
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    for(int n, r, i = 1; cin>>n && n; ++i)
    {
        r = solve(n);
        cout<<"Problem "<<i<<": "<<r<<"\n";
    }

    return 0;
}