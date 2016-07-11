#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int n_case;
    scanf("%d", &n_case);
    for (int i = 0; i < n_case; i++)
    {
        int count = 0;
        int l, r, max = -99999999, save = 0,m_l,m_r;
        int *number;
        scanf("%d", &count);
        number = (int *) calloc (count,sizeof(int));
        for (int i = 0; i < count; ++i){
            scanf("%d", &number[i]);
        }
        for(int mark = 0, sum=0, l = 1; mark < count; mark++) {
            sum += number[mark];
            if(sum > max) {
                max = sum;
                m_l = l;
                m_r = mark+1;
            }
            if (sum < 0) {
                sum = 0;
                l=mark+2;
            }
        }
        printf("Case %d:\n%d %d %d\n",i+1,max, m_l, m_r );
        if (i != n_case-1)
        {
            printf("\n");
        }
    }
return 0;
}
