#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    long n, m;
    set<long> s;
    ios::sync_with_stdio(false);

    cin >> n >> m;
    long input[n], output[n];
    for (long i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    for (long i = n - 1; i >= 0; i--)
    {
        s.insert(input[i]);
        output[i] = s.size();
    }

    long x;
    for (long i = 0; i < m; i++)
    {
        cin >> x;
        x--;
        cout << output[x] << endl;
    }
    return 0;
}