#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX_NODE= 1e5;
int n, k, parents[MAX_NODE] = {-1, 0}, color[MAX_NODE] = {-1, 0};
int parent0[MAX_NODE], parent1[MAX_NODE], idx0, idx1, tgt0, tgt1;

void lca(int a, int b)
{
    idx0 = 0, idx1 = 0, tgt0 = a, tgt1 = b;
    while(tgt0 != -1)
    {
        parent0[idx0++] = tgt0, tgt0 = parents[tgt0];
    }

    while(tgt1 != -1)
    {
        parent1[idx1++] = tgt1, tgt1 = parents[tgt1];
    }

    do
    {
        --idx0, --idx1;
    }
    while(idx0 >=0 && idx1 >= 0 && parent0[idx0] == parent1[idx1]);
}

void paint(int a, int b, int c)
{
    lca(a, b);
    while(idx0>=0)
    {
        color[parent0[idx0--]] = c;
    }
    while(idx1>=0)
    {
        color[parent1[idx1--]] = c;
    }
}

void move(int a, int b)
{
    parents[a] = b;
}

int count(int a, int b)
{
    map<ll, bool> isExist;
    lca(a, b);
    while(idx0>=0)
    {
        isExist[color[parent0[idx0--]]] = true;;
    }
    while(idx1>=0)
    {
        isExist[color[parent1[idx1--]]] = true;;
    }
    return isExist.size();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;
    for(int r, a, b, c, i = 0; i<k; ++i)
    {
        cin>>r;
        switch(r)
        {
            case 1:
            cin>>a>>b>>c;
            paint(a, b, c);
            break;

            case 2:
            cin>>a>>b;
            move(a, b);
            break;

            case 3:
            cin>>a>>b;
            cout<<count(a,b)<<"\n";
            break;
        }
    }

    return 0;
}