#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const char BLANK = '.', MINERAL = 'x';
int r, c, n;
char cave[100][100] = {{0}};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>r>>c;
    for(int i = 0; i<r; ++i)
    {
        for(int l = 0; l<c; ++l)
        {
            cin>>cave[i][l];
        }
    }

    for(int stick = 0, l, i; stick<n; ++stick)
    {
        cin>>i;
        i = r - i;
        if(stick%2)
        {
            for(l = 0; cave[i][l] != MINERAL && l<c; ++l)    
            {}
        }
        else
        {
            for(l = c-1; cave[i][l] != MINERAL && l>=0; --l)    
            {}
        }

        if(l==c || l==-1)
        {
            continue;
        }

        cave[i][l] = BLANK;
        //herer
    }

    return 0;
}