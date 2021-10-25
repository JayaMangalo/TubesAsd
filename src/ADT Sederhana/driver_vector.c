#include<stdio.h>
#include "vector.h"

int main() {
    VECTOR v1, v2;
    v1 =MakeVector(2.0,7.0); v2=MakeVector(3.0,5.0);
    TulisVector(v1); printf("\n");

    printf("Magnitude: %.2f\n", Magnitude(v1));
    TulisVector(Add(v1,v2)); printf("\n");
    TulisVector(Substract(v1,v2)); printf("\n");
    printf("dot: %.2f\n", Dot(v1,v2));
    TulisVector(Multiply(v1,2.0)); printf("\n");
}