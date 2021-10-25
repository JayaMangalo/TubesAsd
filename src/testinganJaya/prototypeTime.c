#include <stdio.h>

//NOTE: ini masi prototype, kalo perlu bakal diganti.

typedef struct { 
	float CurrentTime;    //Waktu sekarang
    int Weight;         //Banyak barang. Kalo gaada -> 0 
	float SpeedBoost;   //Banyak speedboost yang remaining. Kalo gaada -> 0
} Time;

#define CurrentTime(P) (P).CurrentTime
#define Weight(P) (P).Weight
#define SpeedBoost(P) (P).SpeedBoost

//fungsi untuk menambahkan waktu ketika moving 
//(+1 jika normal, +0.5 jika speedboost +2,3,4 jika ada weight)
// Juga mengurangi speedboost setiap kali gerak
// Juga mengupdate time remaining on perishable items (Not implemented yet)
void CreateTime(Time *T){
    Time *T = {0,0,0};
}

void AddTimeByMove(Time *T){          
    if (SpeedBoost(*T) > 0){
        CurrentTime(*T) = CurrentTime(*T) + 0.5;
        SpeedBoost(*T)--;
    }
    else{
        CurrentTime(*T) = CurrentTime(*T) + 1 + Weight(*T);
    }
    //TODO : change the number of time remaining on perishable items.
}

//untuk testing.
int main(){
    Time x = {0,3,0};
    printf("%.1f\n", x.CurrentTime);
    AddTimeByMove(&x);
    printf("%.1f\n", x.CurrentTime);
    AddTimeByMove(&x);
    printf("%.1f\n", x.CurrentTime);
    AddTimeByMove(&x);
    printf("%.1f\n", x.CurrentTime);
    AddTimeByMove(&x);
    printf("%.1f\n", x.CurrentTime);
    AddTimeByMove(&x);
    printf("%.1f\n", x.CurrentTime);
    AddTimeByMove(&x);
    printf("%.1f\n", x.CurrentTime);
    AddTimeByMove(&x);
    printf("%.1f\n", x.CurrentTime);
    AddTimeByMove(&x);
    printf("%.1f\n", x.CurrentTime);
    AddTimeByMove(&x);
    printf("%.1f\n", x.CurrentTime);
    AddTimeByMove(&x);
    printf("%.1f\n", x.CurrentTime);
    AddTimeByMove(&x);
    printf("%.1f\n", x.CurrentTime);
    AddTimeByMove(&x);
    printf("%.1f\n", x.CurrentTime);
}
