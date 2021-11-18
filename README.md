# Tugas Besar Algoritma dan Struktur Data - MOBILITA DELIVERY SERVICE
> Game mengantar pesanan dengan memanfaatkan berbagai macam ADT menggunakan bahasa C
 
## Setup
### Instalasi Awal
Karena Program menggunakan bahasa pemograman C maka diperlukan untuk mengunduh toolset C yang sesuai, biasanya yaitu gcc. Untuk panduan pengunduhan toolset tersebut bisa dilihat dari video berikut https://www.youtube.com/watch?v=0HD0pqVtsmw&t=3s
Setelah mengikuti instruksi pada video tersebut repository ini dapat di clone dengan command 'git clone https://github.com/JayaMangalo/TubesAsd.git' pada git BASH di folder tujuan anda
### Cara Menjalankan Program
1. Buka cmd lalu change directory hingga ke folder src pada repository ini
2. Jalankan command berikut 
```
gcc gameplay.c  charmachine//charmachine.c commandmachine//commandcharmachine.c commandmachine//commandwordmachine.c gadget//gadget.c gamecommand//gamecommand.c list_linked//list_linked.c listdin//listdin.c listpos//listpos.c map//map.c matrix//matrix.c node//node.c order//order.c pcolor//pcolor.c point//point.c queue//prioqueue.c setup//setup.c stack//stack.c time//time.c wordmachine//wordmachine.c -o  gameplay
```
3. Jalankan command berikut 
```
./gameplay
```
4. Ketik command 'NEW GAME" lalu masukan nama file konfigurasi yang ada di folder src, jika berhasil maka akan ada tulisan 'GAME INITIALIZED SUCCESFULLY' dan game sudah bisa dimainkan ![image](https://user-images.githubusercontent.com/88297362/142243033-9bb253de-5532-4578-b5bd-a6fc8dfa062c.png)
5. Ketik command HELP untuk list command yang dapat dilakukan ![image](https://user-images.githubusercontent.com/88297362/142243271-2d651c8c-21c0-4d8c-8bae-f3d453532fba.png)

## Fitur
| Fitur | Status |
|------|--------|
| Main Menu | Selesai |
| Mekanisme Waktu | Selesai |
| Daftar Pesanan | Selesai |
| To Do List | Selesai |
| In Progress List | Selesai |
| Tas | Selesai |
| Jenis Item | Selesai |
| Ability | Selesai |
| Gadget | Selesai |
| Inventory Gadget | Selesai |
| Peta | Selesai |
| Lokasi dan Command | Selesai |

## Buatan Kelompok 4 Kelas 01
* 13520009	Ahmad Romy Zahran 
* 13520013	Ilham Prasetyo Wibowo 
* 13520015	Jaya Mangalo Soegeng Rahardjo 
* 13520025	Fransiskus Davin Anwari 
* 13520047	Hana Fathiyah 
* 13520051	Flavia Beatrix Leoni A. S. 

## Pembagian Tugas
| NIM | Nama | Tugas |
|------|--------|--------|
| 13520009 | Ahmad Romy Zahran | Command, To Do List, Jenis Item |
| 13520013 | Ilham Prasetyo Wibowo | Command, Gadget |
| 13520015 | Jaya Mangalo Soegeng Rahardjo | Command, Mekanisme Waktu, Tas, Ability |
| 13520025 | Fransiskus Davin Anwari | Command, Daftar Pesanan, In Progress List, Inventory Gadget |
| 13520047 | Hana Fathiyah | Command, Main Menu |
| 13520051 | Flavia Beatrix Leoni A. S. | Command, Map, Gadget |

