#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    ll t;
    scanf("%lld", &t);
    while(t--)
    {
        ll l, x0, y0, x1, y1;
        scanf("%lld %lld %lld %lld %lld", &l, &x0, &y0, &x1, &y1);

        vector<ll> mat(l*l, 0);
        queue<ll> q;
        q.push(l*x0 + y0);
        mat[l*x0 + y0] = 1;
        while(q.size())
        {
            ll top = q.front(), x = top/l, y = top%l, next;
            q.pop();
            
            if(x-2 >= 0 && y-1 >= 0 && !mat[(next = (x-2)*l + y-1)])
            {
                mat[next] = mat[top] + 1;
                q.push(next);
            }
            if(x-1 >= 0 && y-2 >= 0 && !mat[(next = (x-1)*l + y-2)])
            {
                mat[next] = mat[top] + 1;
                q.push(next);
            }
            if(x+2 < l && y+1 < l && !mat[(next = (x+2)*l + y+1)])
            {
                mat[next] = mat[top] + 1;
                q.push(next);
            }
            if(x+1 < l && y+2 < l && !mat[(next = (x+1)*l + y+2)])
            {
                mat[next] = mat[top] + 1;
                q.push(next);
            }

            if(x-1 >= 0 && y+2 < l && !mat[(next = (x-1)*l + y+2)])
            {
                mat[next] = mat[top] + 1;
                q.push(next);
            }
            if(x-2 >=0 && y+1 <l && !mat[(next = (x-2)*l + y+1)])
            {
                mat[next] = mat[top] + 1;
                q.push(next);
            }
            if(x+1 < l && y-2 >= 0 && !mat[(next = (x+1)*l + y-2)])
            {
                mat[next] = mat[top] + 1;
                q.push(next);
            }
            if(x+2 < l && y-1 >= 0 && !mat[(next = (x+2)*l + y-1)])
            {
                mat[next] = mat[top] + 1;
                q.push(next);
            }
        }

        printf("%lld\n", mat[x1*l + y1] - 1);
    }
    return 0;
}