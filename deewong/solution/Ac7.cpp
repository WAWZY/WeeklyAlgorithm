#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<int> output;
set<int> used_color;

int c = 0;

int color(int range)
{
    c = (c + 1) % (range + 1);
    if (c == 0)
    {
        c++;
    }
    return c;
}

int main()
{
    int n, k, flag = 0;
    scanf("%d%d", &n, &k);

    set<int> a[n + 1];

    for (int i = 1; i <= n; i++)
    {
        pair<set<int>::iterator, bool> p;
        int w;
        scanf("%d", &w);

        while (!p.second)
        {
            c = color(k);
            p = a[w].insert(c);
        }

        used_color.insert(c);

        if (used_color.size() == k)
        {
            flag = 1;
        }

        if (used_color.size() > k)
        {
            flag = 0;
        }

        output.push_back(c);
    }

    if (flag)
    {
        puts("YES");
        // output...
        for (vector<int>::iterator it = output.begin(); it != output.end(); it++)
        {
            printf("%d%c", *it, (it == output.end() - 1) ? '\n' : ' ');
        }
    }
    else
    {
        puts("NO");
    }

    return 0;
}