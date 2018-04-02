/*==========================================================================*/
/* File 			: ADT_SLL.cpp											*/
/* Deskripsi 		: ADT linked list dengan representasi fisik pointer 	*/
/* 					  Representasi address dengan pointer 				    */
/* Dibuat oleh 		: Kiki Pratiwi(46) & Mufida Nuha S(50)				    */
/* Tanggal Dibuat 	: 27-03-2018 s/d 01-04-2018							    */
/* InfoType 		: string 											    */
/*==========================================================================*/

#include "ADT_SLL.h"

/********** BODY SUB PROGRAM ***********/

boolean isEmpty(address p)
// Tujuan : memeriksa apakah linked masih kosong
// Linked list kosong , jika Head == NULL
{
	return (p == Nil);
}

void Create_Node (address *p)
// Tujuan : memesan memory dengan alokasi dinamis
// Jika berhasil mengirimkan address, dan jika gagal mengirimkan NULL
// Parameter : P (parameter Output)
{
	*p = (address) malloc(sizeof (tElmtListMhs));
	if (!isEmpty(*p))
	{
//		printf("\nBerhasil Alokasi Memori\n");
	}
	else
		printf("\nGagal Alokasi Memori\n");	
}

void Isi_Node (address *p , infotype nilai)
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan
// Periksa keberadaan P, Nilai diisi jika P tidak NULL
// *p.next diisi NULL
// Parameter : P (parameter Input-Output); Nilai (parameter Input)
{
	if (*p != Nil)
	{
		info(*p) = nilai;
		next(*p) = Nil;
	}
}

void Tampil_List (address p)
// Tujuan : Menampilkan seluruh isi Linked List
// Parameter : p (parameter input)
{
	int i=1;
	while (p != Nil)
	{
		printf("\t[%d] %s\n", i, info(p));
		p = next(p);
		i++;
	}
}

void Ins_Akhir (address *p, address PNew)
/* Tujuan : menambahkan elemen list (PNew) di akhir LinkedList */
/* IS : p mungkin Kosong */
/* FS : menyambungkan elemen baru (PNew) di akhir Linked List */
{
	if(isEmpty(*p)){
//		printf("Pertama\n");
		next(PNew) = Nil;        
   		*p = PNew;
	}
	else {
		address temp;
		temp = *p;
		while(!isEmpty(next(temp))){
			temp=next(temp);
		}
		next(temp) = PNew;	
	}	
}

address Search (address p, infotype nilai)
/* Mencari apakah ada elemen list dengan Info(P) = nilai */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype boolean */
{
	bool found;
	found = false;
	while (p != Nil and not found)
	{
		if (info(p) == nilai)
			found = true;
		else
			p = next(p);
	}
	
	return(p);
}

void Del_Awal (address * p, infotype * X)
/* IS : P TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* dan alamat elemen pertama di dealokasi */
{
	address PDel;
	
	PDel = *p;
	*X = info(*p);
	
	*p = next(*p);
	next(PDel) = Nil;
	
	DeAlokasi(&PDel);
}

void Del_Akhir (address * p, infotype * X)
/* IS : P TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* dan alamat elemen terakhir di dealokasi */
{
	address PDel, PPrev;
	
	PPrev = Nil;
	PDel = *p;
	
	while (next(PDel) != Nil)
	{
		PPrev = PDel;
		PDel = next(PDel);
	}
	
	*X = info(PDel);
	
	if (PPrev == Nil)
		 *p = Nil;
	else
	{
		next(PPrev) = Nil;
		DeAlokasi(&PDel);
	}	
}

void DeAlokasi (address * p)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
{
	if (*p != Nil)
		free (*p);
}

int NbElmt (address p)
/* Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong */
// Recursif Mode
{
	if (p != Nil)
		return 1 + NbElmt(next(p));
	else
		return 0;
}

