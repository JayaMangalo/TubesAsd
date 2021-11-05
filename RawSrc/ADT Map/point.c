/* File: point.c */
/* Tanggal: 2 September 2021 */
/* Body ADT POINT */

#include "point.h"
#include<math.h>
#include<stdio.h>
        
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y) {
/* Membentuk sebuah POINT dari komponen-komponennya */
    /* Kamus Lokal */
    POINT P;
    /* Algoritma */
    Absis(P)=X;
    Ordinat(P)=Y;
    return P;
};

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P) {
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
    /* Kamus Lokal */
    float X,Y;
    /* Algoritma */
    scanf("%f %f", &X, &Y);
    *P = MakePOINT(X,Y);
};

void TulisPOINT (POINT P) {
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
    /* Kamus Lokal */
    /* Algoritma */
    printf("(%d,%d)", Absis(P), Ordinat(P));
};

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2) {
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    /* Kamus Lokal */
    /* Algoritma */
    return (Absis(P1)==Absis(P2)) && (Ordinat(P1)==Ordinat(P2));
};

boolean NEQ (POINT P1, POINT P2) {
/* Mengirimkan true jika P1 tidak sama dengan P2 */
    /* Kamus Lokal */
    /* Algoritma */    
    return (Absis(P1)!=Absis(P2)) || (Ordinat(P1)!=Ordinat(P2));
};

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P) {
/* Menghasilkan true jika P adalah titik origin */
    /* Kamus Lokal */
    /* Algoritma */    
    return (Absis(P)==0) && (Ordinat(P)==0);
};

boolean IsOnSbX (POINT P) {
/* Menghasilkan true jika P terletak Pada sumbu X */
    /* Kamus Lokal */
    /* Algoritma */   
    return (Ordinat(P)==0);
};

boolean IsOnSbY (POINT P) {
/* Menghasilkan true jika P terletak pada sumbu Y */
    /* Kamus Lokal */
    /* Algoritma */    
    return (Absis(P)==0);
};

int Kuadran (POINT P) {
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
    /* Kamus Lokal */
    /* Algoritma */
    if(Absis(P)>0 && Ordinat(P)>0) {
        return 1;
    } else if(Absis(P)<0 && Ordinat(P)>0) {
        return 2;
    } else if(Absis(P)<0 && Ordinat(P)<0) {
        return 3;
    } else if(Absis(P)>0 && Ordinat(P)<0) {
        return 4;
    }
};

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P) {
/* Mengirim salinan P dengan absis ditambah satu */
    /* Kamus Lokal */
    /* Algoritma */
    return MakePOINT(Absis(P)+1,Ordinat(P));
};           

POINT NextY (POINT P) {
/* Mengirim salinan P dengan ordinat ditambah satu */
    /* Kamus Lokal */
    /* Algoritma */
    return MakePOINT(Absis(P),Ordinat(P)+1);
};

POINT PlusDelta (POINT P, int deltaX, int deltaY) {
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
    /* Kamus Lokal */
    /* Algoritma */
    return MakePOINT(Absis(P)+deltaX,Ordinat(P)+deltaY);
};

POINT MirrorOf (POINT P, boolean SbX) {
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
    /* Kamus Lokal */
    /* Algoritma */    
    if(SbX) {
        return MakePOINT(Absis(P),Ordinat(P)*(-1));
    } else {
        return MakePOINT(Absis(P)*(-1),Ordinat(P));
    }
};

float Jarak0 (POINT P) {
/* Menghitung jarak P ke (0,0) */
    /* Kamus Lokal */
    /* Algoritma */
    return sqrtf(Absis(P)*Absis(P)+Ordinat(P)*Ordinat(P));
};

float Panjang (POINT P1, POINT P2) {
/* Menghitung jarak antara titik P1 dan P2 */
    /* Kamus Lokal */
    /* Algoritma */
    return sqrtf((Absis(P1)-Absis(P2))*(Absis(P1)-Absis(P2))+(Ordinat(P1)-Ordinat(P2))*(Ordinat(P1)-Ordinat(P2)));
};

void Geser (POINT *P, int deltaX, int deltaY) {
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
    /* Kamus Lokal */
    /* Algoritma */
    *P = PlusDelta(*P,deltaX,deltaY);
};

void GeserKeSbX (POINT *P) {
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
    /* Kamus Lokal */
    /* Algoritma */    
    *P = MakePOINT(Absis(*P),0);
};

void GeserKeSbY (POINT *P) {
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
    /* Kamus Lokal */
    /* Algoritma */    
    *P = MakePOINT(0,Ordinat(*P));
};

void Mirror (POINT *P, boolean SbX) {
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
    /* Kamus Lokal */
    /* Algoritma */    
    if(SbX) {
        *P = MakePOINT(Absis(*P),Ordinat(*P)*(-1));
    } else {
        *P = MakePOINT(Absis(*P)*(-1),Ordinat(*P));
    }
};

void Putar (POINT *P, float Sudut) {
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat searah jarum jam dengan sumbu titik (0,0) */
    /* Kamus Lokal */
    /* Algoritma */
    *P = MakePOINT(Absis(*P)*cosf(Sudut*M_PI/180.0)+Ordinat(*P)*sinf(Sudut*M_PI/180.0),Ordinat(*P)*cosf(Sudut*M_PI/180.0)-Absis(*P)*sinf(Sudut*M_PI/180.0));
};