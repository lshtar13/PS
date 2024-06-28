#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF 987654321

inline int c2d(int n){return (2*n)%10000;}
inline int c2s(int n){return n?n-1:9999;}
inline int c2l(int n){return (n%1000)*10 + n/1000;}
inline int c2r(int n){return (n%10) * 1000 + n/10;}

bool push(vector<int> &mat, 
    int n, int b, char c, queue<pair<int, string>> &q)
{
    int idx = q.front().first;
    string str = q.front().second;
    if(!mat[n])
    {
        mat[n] = 1;
        q.push(make_pair(n, str+c));
        if(b == n)
        {
            printf("%s\n", (str+c).c_str());
            return false;
        }
    }

    return true;
}

void solve()
{
    int a, b;
    vector<int> mat(10000, 0); 
    // 0 Cost, 1 Pre, 2 Op. Type, 3 Visited
    scanf("%d %d", &a, &b);

    queue<pair<int,string>> q;
    mat[a] = 1;
    q.push(make_pair(a, ""));

    while(!q.empty())
    {
        int idx = q.front().first;
        int d = c2d(idx), s = c2s(idx), l = c2l(idx), r = c2r(idx);

        if(!push(mat,  d, b, 'D', q)
            || !push(mat, s, b, 'S', q)
            || !push(mat, l, b, 'L', q)
            || !push(mat, r, b, 'R', q))
        {
            break;
        }

        q.pop();
    }
}

int main(void)
{
    int t;
    scanf("%d", &t);
    vector<string> result(t);
    for(int i = 0; i<t; ++i)
    {
        solve();
    }

    return 0;
}