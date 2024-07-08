#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX_SIZE = 1e9;

void solve()
{
    int k, files[500], dpCost[500][500] = {{0}}, dpSize[500][500] = {{0}};
    // dp[i][j] => minimum sum from i to j
    cin>>k;
    for(int i = 0; i<k; ++i)
    {
        cin>>files[i];
    }

    for(int i = 0; i<k; ++i)
    {
        dpSize[i][i] = files[i];
    }

    for(int size = 2; size<=k; ++size)
    {
        for(int start = 0, end = start + size - 1;
            end < k; end = ++start + size - 1)
        {
            // cout<<start<<" "<<end<<"\n";
            dpCost[start][end] = MAX_SIZE;
            for(int mid = start; mid<end; ++mid)
            {
                dpCost[start][end] = min(dpCost[start][end], 
                                dpCost[start][mid] + dpCost[mid+1][end]
                                + dpSize[start][mid] + dpSize[mid+1][end]);
            }
            dpSize[start][end] = dpSize[start][start] + dpSize[start+1][end];
        }
    }

    cout<<dpCost[0][k-1]<<"\n";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;

    while(t--)
    {
        solve();
    }
    return 0;
}