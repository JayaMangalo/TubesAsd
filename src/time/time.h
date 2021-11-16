#ifndef time_H
#define time_H

#include <stdio.h>
typedef struct { 
	float CurrentTime;    //Waktu sekarang
    int Weight;         //Banyak barang. Kalo gaada -> 0 
	float SpeedBoost;   //Banyak speedboost yang remaining. Kalo gaada -> 0
} Time;

#define CurrentTime(P) (P).CurrentTime
#define Weight(P) (P).Weight
#define SpeedBoost(P) (P).SpeedBoost

void CreateTime(Time *T);

//fungsi untuk menambahkan waktu ketika moving 
//(+1 jika normal, +0.5 jika speedboost +2,3,4 jika ada weight)
// Juga mengurangi speedboost setiap kali gerak
// Juga mengupdate time remaining on perishable items (Not implemented yet)
// Maybe update perishable item
void AddTimeByMove(Time *T);

//fungsi menambahkan time melalui ability speedboost (constant +10 )
void AddSpeedBoost(Time *T);

//fungsi meremove time (jika pickup heavy item)
void RemoveSpeedBoost(Time *T);

//fungsi sama seperti CurrentTime(T), tetapi hasilnya int dibulatkan kebawah, bukan float.
int GetCurrentTime(Time T);

#endif