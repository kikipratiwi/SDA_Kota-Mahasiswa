/*==========================================================================*/
/* File 			: kota_mhs.h											*/
/* Deskripsi 		: header yang berisi prototipe modul yang dibutuhkan 	*/
/* 					  dalam program kota - mahasiswa						*/
/* Dibuat oleh 		: Kiki Pratiwi(46) & Mufida Nuha S(50)				    */
/* Tanggal Dibuat 	: 27-03-2018 s/d 01-04-2018							    */
/*==========================================================================*/

#ifndef KOTA_MHS_H_INCLUDED
#define KOTA_MHS_H_INCLUDED

#include "ADT_SLL.h"

extern int jum_kota;

char pilih_menu();
int  search_kota(dt_kota daftar_kt[], infotype cr_kt);
int  input_no_kota(int jum_kt);
void tampil_data(dt_kota daftar_kt[], int no_kt);
void tampil_daftar_kota(dt_kota daftar_kt[], int jum_kt);
void del_data_mhs(address * p, int idx, infotype * X);

#endif
