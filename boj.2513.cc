#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<pair<int,int>> left, right;
    int n, k, s;
    cin>>n>>k>>s;

    for(int location, students, i = 0; i<n; ++i)
    {
        cin>>location>>students;
        if(location<s)
        {
            left.push(make_pair(s-location, students));
        }
        else
        {
            right.push(make_pair(location-s, students));
        }
    }

    ll result = 0, bus = 0, maxLength = 0;
    while(!left.empty())
    {
        ll length = left.top().first, students = left.top().second;
        left.pop();
        maxLength = max(maxLength, length);
        if(k - bus < students)
        {
            left.push(make_pair(length, students - k + bus));
            bus = k;
        }
        else
        {
            bus += students;
        }

        if(bus == k)
        {
            result += maxLength*2, maxLength = 0, bus = 0;
        }
    }
    result += maxLength*2, bus = 0, maxLength = 0;

    int ii = 0; 
    while(!right.empty())
    {
        ll length = right.top().first, students = right.top().second;
        right.pop();
        maxLength = max(maxLength, length);
        if(k - bus < students)
        {
            right.push(make_pair(length, students - k + bus));
            bus = k;
        }
        else
        {
            bus += students;
        }

        if(bus == k)
        {
            result += maxLength*2, maxLength = 0, bus = 0;
        }
    }
    result += maxLength*2, bus = 0, maxLength = 0;


    cout<<result;

    return 0;
}