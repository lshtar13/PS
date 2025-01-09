#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int r, c, parent[1500*1501] = {0}, swans[2] = {0}, s = 0;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>r>>c;
    
    char ice;
    for(int i = 0; i<=r; ++i)
    {
        for(int l = 1; l<c; ++l)
        {
            int idx = i*1501 + l; 
            cin>>ice;
            if(ice == '.')
            {
                
            }
            else if(ice == 'X')
            {

            }
            else
            {

            }
        }
    }

    

    return 0;
}