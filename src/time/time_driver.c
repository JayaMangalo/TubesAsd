#include <stdio.h>
#include "time.h"


int main(){
    Time x = {0,0,0};
    AddSpeedBoost(&x);
    AddTimeByMove(&x);
    printf("%.1f\n", x.CurrentTime);
    AddTimeByMove(&x);
    printf("%.1f\n", x.CurrentTime);
    AddTimeByMove(&x);
    printf("%.1f\n", x.CurrentTime);

    printf("%d\n",(int)x.CurrentTime);
    printf("%d\n",GetCurrentTime(x));
    
}