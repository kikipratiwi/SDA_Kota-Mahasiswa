/*==========================================================================*/
/* File 			: kota_mhs.cpp											*/
/* Deskripsi 		: berisi modul yang dibutuhkan dalam program			*/
/* 					  kota - mahasiswa									    */
/* Dibuat oleh 		: Kiki Pratiwi(46) & Mufida Nuha S(50)				    */
/* Tanggal Dibuat 	: 27-03-2018 s/d 01-04-2018							    */
/*==========================================================================*/

#include "kota_mhs.h"

char pilih_menu()
{
	char pil_menu;

	printf("====================  M E N U  ====================");
	printf("\n 1. Entry Data Mahasiswa\n 2. Cari Data Kota\n 3. Hapus Data Mahasiswa dari Kota\n 4. Tampilkan Semua Data\n");
	
	printf("\n> ");
	fflush(stdin);
	scanf ("%c", &pil_menu);
	
	return pil_menu;
}

int search_kota(dt_kota daftar_kt[], infotype cr_kt)
{
	int i 		= 0;
	size_t n 	= sizeof(daftar_kt); 
	bool found	= false;
	while(i<n && !found)
	{
		if(strcmp(daftar_kt[i].kt, cr_kt) == Nil)
			found = true;
		else
			i++;
	}
	
	return (found)?i:-1;
}

void tampil_data(dt_kota daftar_kt[], int no_kt)
{
	int jum_mhs = 0;
	printf	("\nKota %s\n",daftar_kt[no_kt].kt);
	if (!isEmpty(daftar_kt[no_kt].next))
	{
		Tampil_List(daftar_kt[no_kt].next);
		jum_mhs = NbElmt(daftar_kt[no_kt].next);
	}
	printf("\n------------------------------------------ Total %d Mahasiswa\n", jum_mhs);
}

void tampil_daftar_kota(dt_kota daftar_kt[], int jum_kt)
{
	int i;
	for(i=0; i<jum_kt; i++)
		printf("\n\t[%d] %s", i+1, daftar_kt[i].kt);
}

int input_no_kota(int jum_kt)
{
	int no_kt;
	printf("\nInputkan nomor kota: ");
	fflush(stdin);
	scanf ("%d", &no_kt);
	
	while(no_kt<=0 || no_kt>jum_kt)
	{

		printf("\t[ Maaf nomor kota yang anda input tidak tersedia ]");
		printf("\nInputkan nomor kota : ");
		fflush(stdin);
		scanf ("%d\n", &no_kt);
	}
	return no_kt-1;
}

void del_data_mhs(address * p, int idx, infotype * X)
{
	address PDel, PPrev;
	PPrev = Nil;
	PDel  = *p;
	
	int i = 1;
	int jum_data = NbElmt(*p);
	
	if (idx >= i && idx <= jum_data){
		if(idx == 1) 
			Del_Awal(p,X);
		else if(idx == jum_data)
			Del_Akhir(p,X);
	}
	else {
		while(!isEmpty(next(PDel)) && i != idx)
		{
			PPrev = PDel;
			PDel = next(PDel);
			i++;
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
}
