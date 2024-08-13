#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX_N = 1e6;
int n, k, memo[MAX_N+1][11] = {{0}};

int search(int num, int _k)
{
    // cout<<num<<" "<<_k<<"\n";
    if(memo[num][_k])
    {
        return memo[num][_k];
    }

    if(_k == 0)
    {
        return memo[num][_k] = num;
    }

    for(int i = 1; i<n; i*=10)
    {
        for(int j = i*10; j<=n; j*=10)
        {
            int num_i = (num/i)%10, num_j = (num/j)%10,
                _num = num - num_i*i + num_i*j - num_j*j + num_j*i;
            if(num/(j*10) != 0 || num_i != 0)
            {
                memo[num][_k] = max(memo[num][_k], search(_num, _k-1));
            }
        }
    }

    return memo[num][_k];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>k;    
    search(n, k);
    if(memo[n][k])
    cout<<memo[n][k]<<"\n";
    else
    cout<<-1<<"\n";

    return 0;
}