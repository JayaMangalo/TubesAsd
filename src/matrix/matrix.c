/* NIM: 13520009 */
/* Nama: Ahmad Romy Zahran */
/* Tanggal : 22 September 2021 */
/* Topik Praktikum : ADT Matrix */
/* File : matrix.c */
/* Berisi implementasi primitif matrix dengan elemen integer */
#include "matrix.h"
#include <stdio.h>
#include <math.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow, int nCol, Matrix *m) {
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
    /* Kamus Lokal */
    /* Algoritma */
    ROWS(*m) = nRow;
    COLS(*m) = nCol;
};

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValid(int i, int j) {
/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */
    /* Kamus Lokal */
    /* Algoritma */
    return (i>=0 && i<ROW_CAP) && (j>=0 && j<COL_CAP);
};

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow(Matrix m) {
/* Mengirimkan Index baris terbesar m */
    /* Kamus Lokal */
    /* Algoritma */
    return ROWS(m)-1;
};
Index getLastIdxCol(Matrix m) {
/* Mengirimkan Index kolom terbesar m */
    /* Kamus Lokal */
    /* Algoritma */
    return COLS(m) -1;
};
boolean isIdxEff(Matrix m, Index i, Index j) {
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
    /* Kamus Lokal */
    /* Algoritma */
    return (i>=0 && i<ROWS(m)) && (j>=0 && j<COLS(m));
};
ElType getElmtDiagonal(Matrix m, Index i) {
/* Mengirimkan elemen m(i,i) */
    return ELMT(m,i,i);
};

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes) {
/* Melakukan assignment MHsl  MIn */
    /* Kamus Lokal */
    int i,j;
    /* Algoritma */
    ROWS(*mRes) = ROWS(mIn);
    COLS(*mRes) = COLS(mIn);
    for(i=0;i<ROWS(mIn);i++) {
        for(j=0;j<COLS(mIn);j++) {
            ELMT(*mRes,i,j) = ELMT(mIn,i,j);
        }
    }
};

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol) {
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
    /* Kamus Lokal */
    int i,j;
    /* Algoritma */
    CreateMatrix(nRow,nCol,m);
    for(i=0;i<ROWS(*m);i++) {
        for(j=0;j<COLS(*m);j++) {
            scanf("%d", &ELMT(*m,i,j));
        }
    }
};
void displayMatrix(Matrix m) {
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
    /* Kamus Lokal */
    int i,j;
    /* Algoritma */
    for(i=0;i<ROWS(m);i++) {
        for(j=0;j<COLS(m);j++) {
            if(j==COLS(m)-1 && i!=ROWS(m)-1) {
                printf("%d\n", ELMT(m,i,j));
            } else if(j==COLS(m)-1 && i==ROWS(m)-1) {
                printf("%d", ELMT(m,i,j));
            } else {
                printf("%d ", ELMT(m,i,j));
            }
        }
    }
};

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2) {
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
    /* Kamus Lokal */
    Matrix m3;
    int i,j;
    /* Algoritma */
    CreateMatrix(ROWS(m1),COLS(m1),&m3);
    for(i=0;i<ROWS(m1);i++) {
        for(j=0;j<COLS(m1);j++) {
            ELMT(m3,i,j) = ELMT(m1,i,j) + ELMT(m2,i,j);
        }
    }
    return m3;
};
Matrix subtractMatrix(Matrix m1, Matrix m2) {
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
    /* Kamus Lokal */
    Matrix m3;
    int i,j;
    /* Algoritma */
    CreateMatrix(ROWS(m1),COLS(m1),&m3);
    for(i=0;i<ROWS(m1);i++) {
        for(j=0;j<COLS(m1);j++) {
            ELMT(m3,i,j) = ELMT(m1,i,j) - ELMT(m2,i,j);
        }
    }
    return m3;
};
Matrix multiplyMatrix(Matrix m1, Matrix m2) {
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
    /* Kamus Lokal */
    Matrix m3;
    int i,j,k;
    /* Algoritma */
    CreateMatrix(ROWS(m1),COLS(m2),&m3);
    for(i=0;i<ROWS(m1);i++) {
        for(j=0;j<COLS(m2);j++) {
            ELMT(m3,i,j)=0;
            for(k=0;k<COLS(m1);k++) {
                ELMT(m3,i,j) += ELMT(m1,i,k)*ELMT(m2,k,j);
            }
        }
    }
    return m3;
};
Matrix multiplyConst(Matrix m, ElType x) {
/* Mengirim hasil perkalian setiap elemen m dengan x */
    /* Kamus Lokal */
    Matrix mn;
    int i,j;
    /* Algoritma */
    CreateMatrix(ROWS(m),COLS(m),&mn);
    for(i=0;i<ROWS(m);i++) {
        for(j=0;j<COLS(m);j++) {
            ELMT(mn,i,j) = x*ELMT(m,i,j);
        }
    }
    return mn;
};
void pMultiplyConst(Matrix *m, ElType k) {
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
    /* Kamus Lokal */
    int i,j;
    /* Algoritma */
    for(i=0;i<ROWS(*m);i++) {
        for(j=0;j<COLS(*m);j++) {
            ELMT(*m,i,j) = k*ELMT(*m,i,j);
        }
    }
};

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqualMatrix(Matrix m1, Matrix m2) {
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getFirstIdxRow(m1) = getFirstIdxRow(m2) 
   dan getLastIdxCol(m1) = getLastIdxCol(m2) */
    /* Kamus Lokal */
    boolean Eq=true;
    int i,j;
    /* Algoritma */
    if(getLastIdxRow(m1)==getLastIdxRow(m2) && getLastIdxCol(m1)==getLastIdxCol(m2)) {
        for(i=0;i<ROWS(m1)&&Eq;i++) {
            for(j=0;j<COLS(m1)&&Eq;j++) {
                if(ELMT(m1,i,j)!=ELMT(m2,i,j)) Eq=false;
            }
        }
        return Eq;
    } else {
        return false;
    }
};
boolean isNotEqualMatrix(Matrix m1, Matrix m2) {
/* Mengirimkan true jika m1 tidak sama dengan m2 */
    /* Kamus Lokal */
    /* Algoritma */
    return !isEqualMatrix(m1,m2);
};
boolean isSizeEqualMatrix(Matrix m1, Matrix m2) {
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu getRowEff(m1) = getnRowEff (m2) dan getnColEff (m1) = getnColEff (m2) */
    /* Kamus Lokal */
    /* Algoritma */
    return (ROWS(m1)==ROWS(m2) && COLS(m1)==COLS(m2));
};

/* ********** Operasi lain ********** */
int count(Matrix m) {
/* Mengirimkan banyaknya elemen m */
    /* Kamus Lokal */
    /* Algoritma */
    return ROWS(m)*COLS(m);
};

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m) {
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
    /* Kamus Lokal */
    /* Algoritma */
    return ROWS(m)==COLS(m);
};
boolean isSymmetric(Matrix m) {
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
    /* Kamus Lokal */
    boolean sym=true;
    int i,j;
    /* Algoritma */
    if(isSquare(m)) {
        for(i=0;i<ROWS(m)&&sym;i++) {
            for(j=i+1;j<COLS(m)&&sym;j++) {
                if(ELMT(m,i,j)!=ELMT(m,j,i)) sym=false;
            }
        }
        return sym;
    } else {
        return false;
    }
};
boolean isIdentity(Matrix m) {
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
    /* Kamus Lokal */
    boolean I=true;
    int i,j;
    /* Algoritma */
    if(isSquare(m)) {
        for(i=0;i<ROWS(m)&&I;i++) {
            if(getElmtDiagonal(m,i)!=1) I=false;
        }
        for(i=0;i<ROWS(m)&&I;i++) {
            for(j=i+1;j<COLS(m)&&I;j++) {
                if(ELMT(m,i,j)!=0 || ELMT(m,j,i)!=0) I=false;
            }
        }
        return I;
    } else {
        return false;
    }
};
boolean isSparse(Matrix m) {
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
    /* Kamus Lokal */
    boolean sparse=true;
    int ct=0;
    int size=count(m);
    int i,j;
    /* Algoritma */
    for(i=0;i<ROWS(m)&&sparse;i++) {
        for(j=0;j<COLS(m)&&sparse;j++) {
            if(ELMT(m,i,j)!=0) ct++;
            if(20*ct>size) {
                sparse=false;
            }
        }
    }
    return sparse;
};
Matrix inverse1(Matrix m) {
/* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
    /* Kamus Lokal */
    /* Algoritma */
    return multiplyConst(m,-1);
};
void pInverse1(Matrix *m) {
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
    /* Kamus Lokal */
    /* Algoritma */
    pMultiplyConst(m,-1);
};
float determinant(Matrix m) {
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
    /* Kamus Lokal */
    float det=1.0f, EPS=1e-6f, maxA, absA;
    int i,j,k, imax;
    float A[ROWS(m)][COLS(m)], temp;
    int P[ROWS(m)+1];
    /* Algoritma */
    for(i=0;i<=ROWS(m);i++) P[i]=i;
    for(i=0;i<ROWS(m);i++) {
        for(j=0;j<COLS(m);j++) {
            A[i][j] = (float)ELMT(m,i,j);
        }
    }
    for(i=0;i<ROWS(m);i++) {
        maxA = 0.0f;
        imax =i;
        for(k=i;k<ROWS(m);k++) {
            if((absA= fabsf(A[k][i]))> maxA) {
                maxA = absA;
                imax =k;
            }
        }
        if(maxA<EPS) return 0.0f;
        if(imax!=i) {
            j = P[i];
            P[i] = P[imax];
            P[imax] = j;

            // ptr = A[i];
            // A[i] = A[imax];
            // A[imax] = ptr;
            for(j=0;j<COLS(m);j++) {
                temp = A[i][j];
                A[i][j] = A[imax][j];
                A[imax][j] = temp;
            }
            P[ROWS(m)]++;
        }
        for(j=i+1;j<ROWS(m);j++) {
            A[j][i] /= A[i][i];
            for(k=i+1;k<ROWS(m);k++) {
                A[j][k] -= A[j][i]*A[i][k];
            }
        }
    }
    for(i=0;i<ROWS(m);i++) {
        det *= A[i][i];
    }
    return (P[ROWS(m)]-ROWS(m))%2==0? det : -det;
};
void transpose(Matrix *m) {
/* I.S. m terdefinisi dan isSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    /* Kamus Lokal */
    int i,j;
    ElType temp;
    /* Algoritma */
    for(i=0;i<ROWS(*m);i++) {
        for(j=i+1;j<COLS(*m);j++) {
            temp = ELMT(*m,i,j);
            ELMT(*m,i,j) = ELMT(*m,j,i);
            ELMT(*m,j,i) = temp;
        }
    }
};