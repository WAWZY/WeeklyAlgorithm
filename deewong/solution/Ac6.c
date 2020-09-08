#include <stdio.h>
#include <string.h>
#include <time.h>

#define size 1000000

int n, m;
int ask;

int main()
{
    // freopen("Ac6.in", "r", stdin);
    // freopen("Ac6.out", "w", stdout);

    int visit[size]; // record whether a girl has visited or not, index represent girls_number

    // 读取n m
    scanf("%d%d", &n, &m);
    int output[n + 1];
    if (n >= 1 && n <= 1e5 && m >= 1 && m <= 1e5)
    {
        int girls[n + 1]; // index represent days
        memset(girls, 0, sizeof(girls));
        // 读取n天内女孩编号
        for (int i = 1; i <= n; i++)
        {
            int girl_number;
            scanf("%d", &girl_number);
            girls[i] = girl_number;
        }

        int count = 0;
        memset(visit, 0, sizeof(visit));
        for (int i = n; i >= 1; i--)
        {
            for (int j = i; j <= n; j++)
            {
                int girl_number = girls[i];
                if (visit[girl_number] == 0)
                {
                    count++;
                    visit[girl_number] += 1;
                }
            }
            output[i] = count;
        }

        // 询问m次
        while (m--)
        {
            scanf("%d", &ask);
            if (ask < 1 || ask > n)
                continue;
            printf("%d\n", output[ask]);
        }
    }

    return 0;
}