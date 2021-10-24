#include <stdio.h>
#include "pcolor.c"

int main(){
    int N = 10;
    int M = 10;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if( i==0 || i==N-1 || j == 0 || j==M-1){
                printf("*");
            }
            else if(i==3||j==4){
                print_red('R');
            }
            else if(i==7||j==2){
                print_blue('B');
            }
            else if(i==5||j==7){
                print_green('G');
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    
}