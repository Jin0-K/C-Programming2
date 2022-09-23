#include <stdio.h>

int main(void)
{
        long int a,b;
        int c = 0;
        long int fb[4];
        fb[0] = 1;
        fb[1] = 2;
        scanf("%ld %ld", &a, &b);

        while(1){

                if(fb[0] >= b){
                        printf("\n%d\n",c);
                        break;
                }

                else if(fb[0] >= a){
                        printf("%.0li ", fb[0]);
                        c++;
                }

                fb[2] = fb[0] + fb[1];
                fb[3] = fb[1];
                fb[1] = fb[2];
                fb[0] = fb[3];

        }

}
