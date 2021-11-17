#include <stdio.h>
#include "commandwordmachine.h"

int main () {
    printf("ENTER COMMAND: ");
    startCommand();
    printf("CURRENT COMMAND: ");
    for(int i = 0; i < currentCommand.length; i++) {
        printf("%c",currentCommand.contents[i]);
    }
    printf("\n");    
}