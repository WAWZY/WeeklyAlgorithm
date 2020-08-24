#include <stdio.h>
#include <string.h>

int main()
{
    int count;
    char file[] = __FILE__;
    char *filename = strtok(file, ".");
    strcat(filename, ".in");
    FILE *fin = fopen(filename, "rb");
    fin = stdin;
    fscanf(fin, "%d", &count);

    for (int kase = 0; kase < count; kase ++)
    {
        int n, k;
        fscanf(fin, "%d%d", &n, &k);
        int bed[n], water[k];
        memset(bed, 0, sizeof(bed));
        for (int i = 0; i < k; i ++)
        {
            int tmp;
            fscanf(fin, "%d", &tmp);
            water[i] = --tmp; // xi - i
        }

        int j = 0;
        while (1)
        {
            j ++;
            // water start work
            for (int i = 0; i < k; i ++)
            {
                int current = water[i];
                int left = current - (j - 1);
                int right = current + (j - 1);

                if (left >= 0 && left <= right)
                {
                    bed[left] = 1;
                }

                if (right < n && right >= left)
                {
                    bed[right] = 1;
                }
            }

            int finished = 1;
            for (int i = 0; i < n; i ++)
            {
                if (bed[i] == 0)
                { // bed is not watered
                    finished = 0;
                    break;
                }
            }

            if (finished == 1)
            {
                break;
            }
        }

        printf("%d\n", j);
    }

    fclose(fin);
    return 0;
}
