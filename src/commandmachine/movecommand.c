#include "commandwordmachine.h"
#include <stdio.h>
int main() {
    
    startCommand();
    printf("%s",currentCommand.contents);

    startCommand();
    printf("%s", currentCommand.contents);
}