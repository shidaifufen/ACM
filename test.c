#include <stdio.h>
#include <string.h>
struct data {
	int sum[1500];
	char number1[1000];
	char number2[1000];
	int mark;
};
int main(int argc, char const *argv[])
{
	int line;
	struct data test[20];
	scanf("%d",&line);
	for (int i = 0; i < line; i++)
	{
		int l1, l2, l, other;
		int next = 0, count = 0;
		for (int init = 0; init < 1500; ++init)
			test[i].sum[init] = -1;

		scanf("%s%s", test[i].number1, test[i].number2);
		
		l1 = strlen(test[i].number1);
		l2= strlen(test[i].number2);
		l = l1 > l2?l2:l1;
		for (;l > 0; l--)
		{
			int s = (int)test[i].number1[--l1] + (int)test[i].number2[--l2] - 2 * (int)'0';
			test[i].sum[count] = (s + next) % 10;
			if (s < 10) 
			{
				if (s + next >= 10)
					next  = 1;
				else 
					next = 0;	
			}  
			else
				next = 1;
			count++;
		}
		other = l1 > l2? l1 - l2: l2 - l1;
		for (; other > 0; other--) 
		{
			int n;
			if (l1 > l2) 
				n = (int)test[i].number1[other-1] - (int)'0' + next;
			else
				n = (int)test[i].number2[other-1] - (int)'0' + next;
			if (n >= 10) 
			{
				n = n % 10;
				next = 1;
			} 
			else 
				next = 0;
			test[i].sum[count] = n;
			count++;
		}
		if (next > 0)
		{
			test[i].sum[count] = next;
			count++;
		}
		count--;
		test[i].mark = count;
	}
	for (int out = 1; out <= line; out++) 
	{
		printf("Case %d:\n%s + %s = ",out,test[out-1].number1,test[out-1].number2);
		for(int n = test[out-1].mark; n >=0; n--)
			printf("%d",test[out-1].sum[n]);
		if (out != line) 
			printf("\n\n");
	}
	putchar('\n');
	return 0;
}