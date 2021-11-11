#include <stdio.h>
#include "commandwordmachine.c"
#include "commandcharmachine.c"
int main(){
    startCommand();

    
    char ass[99] = "GAYGAYGAY";
    Command X;
    int length = 9;
    for (int i = 0; i < length; i++)
    {
        X.contents[i] = ass[i];
    }
    X.length = length;
    

    if(isEqualCommand(X,currentCommand)){
        printf("yes");
    }
    printf("no");
}