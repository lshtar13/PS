#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int l, kmp[1000000] = {-1,};
    cin>>l;
    
    string led;
    cin>>led;
    
    int i = 0, j = 0;
    while(i<l)
    {
        if(led[i]==led[j])
        {
            ++j, ++i;
        }
        else
        {
            i = j == 0 ? i+1:i;
            j = 0;
        }
    }

    cout<<i<<" "<<j;

    return 0;
}