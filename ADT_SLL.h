/*=========================================================================*/
/* File 			: ADT_SLL.h 										   */
/* Deskripsi 		: ADT linked list dengan representasi fisik pointer	   */
/* 			   		  Representasi address dengan pointer 				   */
/* Dibuat oleh 		: Kiki Pratiwi(46) & Mufida Nuha S(50)				   */
/* Tanggal Dibuat 	: 27-03-2018 s/d 01-04-2018							   */
/* InfoType 		: string 											   */
/*=========================================================================*/

#ifndef ADT_SLL_H
#define ADT_SLL_H

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <windows.h>
#include "boolean.h"

#define Nil NULL
#define info(P) (P)->nm
#define next(P) (P)->next

typedef char* infotype;
typedef struct tElmtListMhs *address;
typedef struct tElmtListMhs {
	infotype nm;
	address next;
} dt_mhs;

typedef struct{
	infotype kt;
	address next;
} dt_kota;

boolean isEmpty(address p);
// Tujuan : memeriksa apakah linked masih kosong
// Linked list kosong , jika Head == NULL

void Create_Node (address *p);
// Tujuan : memesan memory dengan alokasi dinamis
// Jika berhasil mengirimkan address, dan jika gagal mengirimkan NULL
// Parameter : P (parameter Output)

void Isi_Node (address *p , infotype nilai);
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan
// Periksa keberadaan P, Nilai diisi jika P tidak NULL
// *p.next diisi NULL
// Parameter : P (parameter Input-Output); Nilai (parameter Input)

void Ins_Akhir (address *p, address PNew);
/* Tujuan : menambahkan elemen list (PNew) di akhir LinkedList */
/* IS : p mungkin Kosong */
/* FS : menyambungkan elemen baru (PNew) di akhir Linked List */

void Tampil_List (address p);
// Tujuan : Menampilkan seluruh isi Linked List
// Parameter : p (parameter input)

void Del_Akhir (address * p, infotype * X);
/* IS : P TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* dan alamat elemen terakhir di dealokasi */

void DeAlokasi (address * p);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */

int NbElmt (address p);
/* Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong */
// Recursif Mode

address Search (address p, infotype nilai);
/* Mencari apakah ada elemen list dengan Info(P) = nilai */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype boolean */

void Del_Awal (address * p, infotype * X);
/* IS : P TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* dan alamat elemen pertama di dealokasi */

#endif
