#include <stdio.h>
#include <string.h>
struct color {
    char type[15];
    int amount;
};
int main()
{
    int find = 0, state = 1;
    do {
        struct color count[1000];
        struct color *p = count;
        int number;
        char data[15];
        scanf("%d", &number);
        if(number == 0) break;
        for(int n = 0; n < number; n++){
            scanf("%s", data);
            for (find = 0 ; &count[find] != p; find++)
            {
                if(!strcmp(count[find].type, data)) {
                    count[find].amount++;
                    state = 0;
                    break;
                }
            }
            if (state) {
                strcpy(p->type,data);
                p->amount = 1;
                p++;
            }
            state = 1;
        }
        int max = count[0].amount, position = 0;
        for (int n = 1; &count[n] != p; n++)
        {
            if (max < count[n].amount) {
                max = count[n].amount;
                position = n;
            }
        }
        printf("%s\n",count[position].type);
        p = count;
    }while(1);
    return 0;
}
