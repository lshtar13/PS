#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int m, n, mat[700][700] = {{0}};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>m>>n;
    for(int d0, d1, d2, i = 0; i<n; ++i)
    {
        cin>>d0>>d1>>d2;
        for(int a, b, l = 0; l<2*m-1; ++l)
        {
            if(n >= l+1)
            {
                a = n-l-1, b = 0;
            }
            else
            {
                a = 0, b = l - (n-1);
            }

            if(l<d0)
            {
                mat[a][b] += 0;
            }
            else if(l<(d0+d1))
            {
                mat[a][b] += 1;
            }
            else
            {
                mat[a][b] += 2;
            }
        }
    }

    return 0;
}