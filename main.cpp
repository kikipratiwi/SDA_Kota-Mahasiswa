/*=========================================================================*/
/* File 			: main.cpp 											   */
/* Deskripsi 		: Contoh Kasus Single Linked List (Kota dan Mahasiswa) */
/* 					  Implementasi alokasi memori statis dan dinamis	   */
/* Dibuat oleh 		: Kiki Pratiwi(46) & Mufida Nuha S(50)				   */
/* Tanggal Dibuat 	: 27-03-2018 s/d 01-04-2018							   */
/* InfoType 		: string 											   */
/*=========================================================================*/

#include "kota_mhs.h"

int main() 
{
	//Deklarasi variabel pada 'Main/menu utama'
	address  PNew;
	infotype nm_mhs, search_kt, mhs_del;
	int 	 i, no_kt, no_mhs, jum_mhs, jum_kota; 
	bool 	 ulangi		 = false, semua = true,
		 	 input_again = false, tampilkan_data;
	char 	 pil_menu;
	
	//Input jumlah kota
    printf("Berapa banyak kota yang diinputkan? : ");
    fflush(stdin);
	scanf ("%d", &jum_kota);
	system("cls");
	while (jum_kota<=0)
	{
		printf("\t[ Jumlah Kota Minimal Satu ]");
		printf("\nInputkan no kota : ");
		fflush(stdin);
		scanf ("%d", &jum_kota);
	}
	dt_kota A[jum_kota];
	
	//Input nama-nama kota
	printf("Inputkan  nama kota : \n");
	for(i=0; i<jum_kota; i++)
	{
		fflush(stdin);
		A[i].kt = (char *) malloc(20 * sizeof(char)+1);
	    printf("[%d] ", i+1);
	    scanf ("%[^\n]s", A[i].kt);
	    A[i].next = Nil;
	}
	tampil_data(A, 0);
	//Proses yang dilakukan
	do
	{
		system("cls");
		pil_menu = pilih_menu();
		
		switch(pil_menu)
		{
			//Input nama mahasiswa,
			case '1':
				
				tampil_daftar_kota(A, jum_kota);
				no_kt = input_no_kota(jum_kota);
				
				do
				{
					fflush(stdin);
					printf("\n\t> Masukkan nama mahasiswa : ");
					nm_mhs = (char *) malloc(20 * sizeof(char)+1);
					scanf("%[^\n]s", nm_mhs);
				
					Create_Node (&PNew);
					Isi_Node	(&PNew, nm_mhs);
					Ins_Akhir	(&A[no_kt].next, PNew);
					
					printf("\nInput mahasiswa lagi? 1 / 0 : ");
					fflush(stdin);
					scanf ("%d", &input_again);
				}while(input_again);
				
				system("cls");
				tampil_data(A, no_kt);
			break;
			case '2':
				//Pencarian(search) terdapat opsi menampilkan data yang telah dicari
				system("cls");
				printf("Inputkan nama kota : ");
				fflush(stdin);
				search_kt = (char *) malloc(20 * sizeof(char)+1);
				fflush(stdin);
				scanf ("%[^\n]s", search_kt);
				no_kt = search_kota(A, search_kt);
				
				if(no_kt >= 0)
					tampil_data(A, no_kt);
				else
					printf("[ Kota %s Tidak Ditemukan ]\n", search_kt);
			break;
			case '3':
				system("cls");
				tampil_daftar_kota	   	(A, jum_kota);
				no_kt   = input_no_kota	(jum_kota);
				jum_mhs = NbElmt		(A[no_kt].next);
				
				system("cls");
				tampil_data(A, no_kt);
				
				if(!isEmpty(A[no_kt].next))
				{
					printf("Inputkan nomor absen mahasiswa yang datanya akan dihapus : ");
					fflush(stdin);
					scanf ("%d", &no_mhs);
					
					while(no_mhs<=0 || no_mhs>jum_mhs)
					{
						printf("\nNomor yang anda inputkan tidak tersedia");
						printf("\nInputkan nomor absen mahasiswa yang datanya akan dihapus : ");
						fflush(stdin);
						scanf ("%d", &no_mhs);
					}
					
					del_data_mhs(&A[no_kt].next, no_mhs, &mhs_del);
					
					system("cls");
					printf		("Data Mahasiswa bernama %s telah hapus\n", mhs_del);
					tampil_data (A, no_kt);
				}
			break;
			case '4':
				system("cls");
//				printf("\nIngin menampilkan semua data? 1 / 0 : ");
//				fflush(stdin);
//              scanf ("%d", &semua);
//				if(semua)
//				{
//					system("cls");
					for(i=0; i<jum_kota; i++)
						tampil_data(A, i);
//				}
//				else
//				{
//					system("cls");
//					tampil_daftar_kota(A, jum_kota);
//					no_kt = input_no_kota(jum_kota);
//					system("cls");
//					tampil_data(A, no_kt);				
//				}
			break;			
		}
		
		printf("\nKembali ke Menu Utama? 1 / 0 : ");
		fflush(stdin);
		scanf("%d", &ulangi);
		
	}while(ulangi);
	return 0;
}
