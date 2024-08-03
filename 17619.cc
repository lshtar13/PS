#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

uint n, q, parents[100000] = {0}, cords[100000][3] = {{0}};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>q;
    priority_queue<pair<uint, uint>> pq;
    for(int x1, x2, y, i = 0; i<n; ++i)
    {
        cin>>x1>>x2>>y;
        parents[i] = i, cords[i][0] = x1,  cords[i][1] = x2, cords[i][2] = y;
        pq.push(make_pair(-x1, i));
    }

    vector<pair<uint, uint>> state; //y_cord, idx
    while(!pq.empty())
    {
        uint idx = pq.top().second, x1 = cords[idx][0], x2 = cords[idx][1], y = cords[idx][2];
        pq.pop();

        for()
    }

    return 0;
}