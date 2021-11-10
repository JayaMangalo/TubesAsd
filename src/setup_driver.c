// #include "wordmachine/wordmachine.h"
// #include "charmachine/charmachine.h"
// #include "listdin/listdin.h"
// #include "point/point.h"
// #include "matrix/matrix.h"
// #include "order/order.h"
#include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>
#include "setup/setup.h"

int main(){
    Command NEW_GAMES;
    NEW_GAMES.contents[0] = 'N';
    NEW_GAMES.contents[1] = 'E';
    NEW_GAMES.contents[2] = 'W';
    NEW_GAMES.contents[3] = ' ';
    NEW_GAMES.contents[4] = 'G';
    NEW_GAMES.contents[5] = 'A';
    NEW_GAMES.contents[6] = 'M';
    NEW_GAMES.contents[7] = 'E';
    NEW_GAMES.contents[8] = 'S';
    NEW_GAMES.length = 10;
    printf("MAIN MENU\n");
    printf("ENTER FILE NAMES: ");
    startCommand();
    setup();
    return 0;
}