#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> cord;
typedef pair<int, pair<cord, pair<cord, cord>>> edge;

int find(vector<int> &parents, int v)
{
    return parents[v] = parents[v] == v ? v : find(parents, parents[v]);
}

bool merge(vector<int> &parents, int v0, int v1)
{
    int root0 = find(parents, v0), root1 = find(parents, v1);
    if(root0==root1)
    {
        return false;
    }
    else
    {
        parents[root0] = root1;
        return true;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, mat[100][100];
    cin>>n>>m;

    for(int i = 0; i<n; ++i)
    {
        for(int l = 0; l<m; ++l)
        {
            cin>>mat[i][l];
        }
    }

    vector<vector<cord>> isls;
    for(int i = 0; i<n; ++i)
    {
        for(int l = 0; l<m; ++l)
        {
            if(mat[i][l]==1)
            {
                isls.push_back(vector<cord>());
                vector<cord> &isl = isls.back();
                queue<cord> q;
                q.push(make_pair(i, l));
                mat[i][l] = -1;
                isl.push_back(make_pair(i, l));

                while(!q.empty())
                {
                    cord land = q.front();
                    q.pop();
                    // cout<<land.first<<" "<<land.second<<"\n";
                    int a, b;
                    
                    b = land.second;
                    if((a=land.first-1) >= 0 && mat[a][b] == 1)
                    {
                        q.push(make_pair(a, b));
                        mat[a][b] = -1;
                        isl.push_back(make_pair(a, b));
                    }
                    
                    b = land.second;
                    if((a=land.first+1) <n && mat[a][b] == 1)
                    {
                        b = land.second;
                        q.push(make_pair(a, b));
                        mat[a][b] = -1;
                        isl.push_back(make_pair(a, b));
                    }
                    
                    a = land.first;
                    if((b=land.second+1) <m && mat[a][b] == 1)
                    {
                        q.push(make_pair(a, b));
                        mat[a][b] = -1;
                        isl.push_back(make_pair(a, b));
                    }
                    
                    a = land.first;
                    if((b=land.second-1) >=0 && mat[a][b] == 1)
                    {
                        q.push(make_pair(a, b));
                        mat[a][b] = -1;
                        isl.push_back(make_pair(a, b));
                    }
                }
            }
        }
    }

    // cout<<"\n";
    
    // for(int i = 0; i<n; ++i)
    // {
    //     for(int l = 0; l<m; ++l)
    //     {
    //         cout<<mat[i][l]<<" ";
    //     }
    //     cout<<"\n";
    // }

    int nisl = isls.size();
    priority_queue<edge, vector<edge>, greater<edge>> edges;
    for(int i = nisl - 1; i>=0; --i)
    {
        vector<cord> &isl0 = isls[i];
        int size0 = isl0.size();
        for(int l = 0; l<i; ++l)
        {
            vector<cord> &isl1 = isls[l];
            int size1 = isl1.size(), mindis = 11;
            pair<cord, cord> mincord;

            for(int j = 0; j<size0; ++j)
            {
                for(int k = 0; k<size1; ++k)
                {
                    int dis;
                    cord cord0 = isl0[j], cord1 = isl1[k];
                    if(cord0.first == cord1.first
                        && (dis = abs(cord0.second - cord1.second) - 1)<mindis
                        && dis >= 2)
                    {
                        bool valid = true;
                        int s0 = min(cord0.second, cord1.second),
                            s1 = max(cord0.second, cord1.second);
                        for(s0 = s0+1; s0<s1; ++s0)
                        {
                            if(mat[cord0.first][s0] == -1)
                            {
                                valid = false;
                                break;
                            }
                        }
                        if(valid)
                        {
                            mindis = dis, mincord = make_pair(cord0, cord1);
                        }
                    }
                    if(cord0.second== cord1.second
                        && (dis = abs(cord0.first- cord1.first) - 1)<mindis
                        && dis>= 2)
                    {
                        bool valid = true;
                        int f0 = min(cord0.first, cord1.first),
                            f1 = max(cord0.first, cord1.first);
                        for(f0 = f0+1; f0<f1; ++f0)
                        {
                            if(mat[f0][cord0.second]== -1)
                            {
                                valid = false;
                                break;
                            }
                        }
                        if(valid)
                        {
                            mindis = dis, mincord = make_pair(cord0, cord1);
                        }
                    }
                }
            }

            if(mindis < 11)
            {
                edges.push(make_pair(mindis, 
                    make_pair(make_pair(i, l), mincord)));
            }
        }
    }
    
    vector<int> parents(nisl);
    for(int i = 0; i<nisl; ++i)
    {
        parents[i] = i;
    }

    // cout<<"\n";
    int result = 0;
    while(!edges.empty())
    {
        edge b = edges.top(); // bridge
        edges.pop();

        pair<cord, pair<cord, cord>> bi = b.second; //bridge info.
        int isl0 = bi.first.first, isl1 = bi.first.second;
        if(merge(parents, isl0, isl1))
        {
            // cord p0 = bi.second.first, p1 = bi.second.second;
            // cout<<"dis : "<<b.first<<" "<<""<<isl0<<" "<<isl1<<" : ";
            // cout<<"("<<p0.first<<","<<p0.second<<")"<<" ";
            // cout<<"("<<p1.first<<","<<p1.second<<")"<<"\n";
            // if(p0.first == p1.first)
            // {
            //     for(int i = p0.second < p1.second ? p0.second+1:p1.second+1,
            //          to = p0.second + p1.second - i + 1; i < to; ++i)
            //     {
            //         mat[p0.first][i] = 2;
            //     }
            // }

            // if(p0.second== p1.second)
            // {
            //     for(int i = p0.first< p1.first? p0.first+1:p1.first+1,
            //         to = p0.first+ p1.first- i + 1; i < to; ++i)
            //     {
            //         mat[i][p0.second] = 2;
            //     }
            // }

            result += b.first;
        }
        
    }

    // cout<<"\n";
    // for(int i = 0; i<n; ++i)
    // {
    //     for(int l = 0; l<m; ++l)
    //     {
    //         cout<<mat[i][l]<<" ";
    //     }
    //     cout<<"\n";
    // }

    // cout<<"\n";
    int root = find(parents, 0);
    for(auto p: parents)
    {
        // cout<<p<<" ";
        if(root != find(parents, p))
        {
            cout<<-1;
            return 0;
        }
    }

    cout<<result;

    return 0;
}