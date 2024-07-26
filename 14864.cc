#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX_STUDENT = 1e5, MAX_CP = 1e6;
ll n, m, result[MAX_STUDENT] = {0}, degree[MAX_STUDENT] = {0};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i<n; ++i)
    {
        degree[i] = i;
    }
    for(int a, b, i = 0; i<m; ++i)
    {
        cin>>a>>b;
        --a, --b; // a->b ==> b->a
        --degree[b], ++degree[a];
    }

    bool isValid = true;
    for(int i = 0; i<n; ++i)
    {
        if(!result[degree[i]])
        {
            result[degree[i]] = 1;
        }
        else
        {
            isValid = false;
            cout<<-1<<"\n";
            break;
        }
    }

    for(int i = 0; isValid && i<n; ++i)
    {
        cout<<degree[i]+1<<" ";
    }
    cout<<"\n";

    return 0;
}