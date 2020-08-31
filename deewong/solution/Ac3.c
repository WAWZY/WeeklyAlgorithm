#include <stdio.h>
#include <string.h>

int main()
{
    int count, maxn;
    FILE *fin = stdin;
    fscanf(fin, "%d", &count);

    for (int kase = 0; kase < count; kase ++)
    {
        int n, k;
        fscanf(fin, "%d%d", &n, &k);
        if (n > 200 || n < 1) return 0;
        maxn += n;
        if (maxn > 200) return 0;
        int bed[n], water[k];
        memset(bed, 0, sizeof(bed));
        for (int i = 0; i < k; i ++)
        {
            int tmp;
            fscanf(fin, "%d", &tmp);
            water[i] = --tmp; // xi - i
        }

        int j = 0;
        int watered = 0;
        int loop = 0;
        while (watered != n)
        {
            j ++;
            // water start work
            for (int i = 0; i < k; i ++)
            {
                watered += 2;
                int current = water[i];
                int left = current - (j - 1);
                int right = current + (j - 1);

                if (left == right) {
                    bed[left] = 1;
                    watered --;
                    continue;
                }

                if (left >= 0 && left < right)
                {
                    if (bed[left]) {
                        watered --;
                    }
                    else
                    {
                        bed[left] = 1;
                    }
                }
                else 
                {
                    watered --;
                }

                if (right < n && right > left)
                {
                    if (bed[right]) {
                        watered --;
                    }
                    else
                    {
                        bed[right] = 1;
                    }
                }
                else
                {
                    watered --;
                }
            }
        }

        printf("%d\n", j);
    }

    fclose(fin);
    return 0;
}
