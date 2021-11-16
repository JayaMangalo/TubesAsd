#include <stdio.h>
#include "time.h"

//Create empty time.
void CreateTime(Time *T){
    CurrentTime(*T) = 0;
    Weight(*T) = 0;
    SpeedBoost(*T) = 0;
}

//fungsi untuk menambahkan waktu ketika moving 
//(+1 jika normal, +0.5 jika speedboost +2,3,4 jika ada weight)
// Juga mengurangi speedboost setiap kali gerak
// Juga mengupdate time remaining on perishable items (Not implemented yet)
// Maybe update perishable item
void AddTimeByMove(List *td, Daftar *DaftarOrder, Time *T){          
    if (SpeedBoost(*T) > 0){
        CurrentTime(*T) = CurrentTime(*T) + 0.5;
        SpeedBoost(*T)--;
    }
    else{
        CurrentTime(*T) = CurrentTime(*T) + 1 + Weight(*T);
    }
    updToDo(td,DaftarOrder,T);
}

//fungsi menambahkan time melalui ability speedboost (constant +10 )
void AddSpeedBoost(Time *T){
    SpeedBoost(*T) = SpeedBoost(*T) +10;
}

//fungsi meremove time (jika pickup heavy item)
void RemoveSpeedBoost(Time *T){
    SpeedBoost(*T) = 0;
}

//fungsi sama seperti CurrentTime(T), tetapi hasilnya int dibulatkan kebawah, bukan float.
int GetCurrentTime(Time T){
    return (int)CurrentTime(T);
}

