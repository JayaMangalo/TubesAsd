#include <stdio.h>
#include "commandcharmachine.h"

int main () {
    printf("MASUKKAN KARAKTER: ");
    startCommandChar();
    printf("KARAKTER PERTAMA: ");
    printf("%c", currentCommandChar);
}