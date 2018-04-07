#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    int n,a[105][105];
    while(~scanf("%d", &n))
    {
        for(int i = 0; i <= n; ++i)
            a[i][0] = a[0][i] = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                {
                    scanf("%d", &a[i][j]);
                    a[i][j] += a[i-1][j];
                }
        int Max = 0;
        for(int i1 = 0; i1 < n; ++i1)
            for(int i2 = i1+1; i2 <= n; ++i2)
            {
                int sum = 0;
                for(int j = 1; j <= n; ++j)
                {
                    if(sum >= 0)
                        sum += a[i2][j] - a[i1][j];
                    else sum = a[i2][j] - a[i1][j];
                    Max = max(Max, sum);
                }
            }
        printf("%d\n", Max);
    }
    return 0;
}
