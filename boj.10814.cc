#include <bits/stdc++.h>

using namespace std;
typedef pair<int, string> mem;
typedef vector<mem> mems;

mem swp;
void mergesort(mems &memlist, int start, int end)
{
    if (start == end)
        return;

    if (start + 1 == end)
    {
        if (memlist[start].first > memlist[end].first)
            swp = memlist[start], memlist[start] = memlist[end], memlist[end] = swp;
        return;
    }

    mems sorted(memlist.size());
    int mid = (start + end) / 2;
    mergesort(memlist, start, mid);
    mergesort(memlist, mid + 1, end);

    for (int i = start, l = mid + 1, pos = start; i <= mid || l <= end; ++pos)
    {
        if (i > mid)
            sorted[pos] = memlist[l++];
        else if (l > end)
            sorted[pos] = memlist[i++];
        else if (memlist[i].first <= memlist[l].first)
            sorted[pos] = memlist[i++];
        else
            sorted[pos] = memlist[l++];
    }

    move(sorted.begin() + start, sorted.begin() + end + 1, memlist.begin() + start);
}

bool comp(mem m0, mem m1) { return m0.first < m1.first; }

int main(void)
{
    int n;
    scanf("%d", &n);

    mems memlist(n);
    for (auto &x : memlist)
    {
        char name[101];
        scanf("%d %s", &x.first, name);
        x.second = name;
    }

    // mergesort(memlist, 0, n - 1);
    stable_sort(memlist.begin(), memlist.end(), comp);

    for (auto &x : memlist)
        printf("%d %s\n", x.first, x.second.c_str());

    return 0;
}