#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int r, c, iceberg[1501*1501] = {0} parent[1501*1501] = {0};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>r>>c;
    for(int i = 1; i<=r; ++i)
    {
        for(int l = 1; l<c; ++l)
        {
            char ice;
            cin>>ice;
            switch(ice)
            {
                case '.':
                
                break;
                case 'X':
                break;
                case 'L':
                break;
            }
        }
    }

    return 0;
}