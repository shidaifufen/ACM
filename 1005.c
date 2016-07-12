#include <stdio.h>
int main()
{
    int a, b, n;
    int save[200];
    save[1] = save[2] = 1;
    while(scanf("%d%d%d",&a,&b,&n),a || b || n )
    {
    	int count;
        for(count = 3; count < 200; count++)
        	{
        		save[count] = (a * save[count-1] + b * save[count-2]) % 7;
                printf("%d\n",save[count]);
        		if (save[count] ==save[2] && save[count-1] == save[1]) break;
        	}
        	int m = n % (count-2);
        	if (m == 0) m = count - 2;
        	printf("%d\n", save[m]);
    }
    return 0;
}
