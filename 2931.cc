#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int r, c, m_i, m_l;
char mat[25][25] = {{0}};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>r>>c;
    for(int i = 0; i<r; ++i)
    {
        cin.getline(mat[i], 25);
    }

    m_i = -1, m_l = -1;
    for(int i = 0; m_i == -1 && i<r; ++i)
    {
        for(int l = 0; m_l == -1 && l<c; ++l)
        {
            if(mat[i][l] == 'M')
            {
                m_i = i, m_l = l;
            }
        }
    }

    while(true)
    {
        char c = mat[m_i][m_l];
        if(c == 'M')
        {
            
        }
        else if(c == '|')
        {

        }
        else if(c == '-')
    }

    return 0;
}