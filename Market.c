#include<stdio.h>
#include<string.h>
#define arr_boyut 100
#define str_boyut 20

void space(int);
void space2(int);
void space3(int);
void tablo();
int stok(int,int);
int basamak_sayisi(int);
void urun_adi_belirleme();
void fiyat_belirleme(int,int,int[]);
void stok_belirleme(int,int,int[]);
void maliyet_belirleme(int,int, int[]);
double kar(int,int);
int giren(int,int);
int cikan(int,int);
void stok_uyari(int);

// Varsayilan stok miktarlari 
int adet[100] = {32, 34, 21, 2, 72, 23, 19, 56, 29, 40};

// Varsayilan fiyatlar 
int fiyat[100] = {78, 150, 1000, 5000, 1500, 3700, 1100, 1300, 550, 20};

// Varsayilan maliyetler 
int maliyet[100] = {60, 80, 800, 4000, 1200, 2800, 900, 1060, 420, 10};

// Varsayilan urunler 
char urunler[arr_boyut][str_boyut] = {"Mouse", "Klavye", "Monitor", "Ekran_Karti", "Anakart", "Islemci", "RAM", "SSD", "Harddisk", "USB"};

// Urun sayisi
int a = 10;	
	
int main(void){
	
	int cvp, j, urun_adeti, kod, flag2, cvp2;
	char cvp3;
	int islem_sayisi = 0, cvpk = 0, ind = 1, flag1 = 0, flag3 = 0, satis = 0, maliyet = 0, islem = 0, flag4 = 1;
	int alinan_urun_sayisi[20];
	int urun_kodlari[20];
		

	tablo();
	printf("\n\n Stok Sayisi Belirleme      : 1\n Satis Fiyati Belirleme     : 2\n Maliyet Belirleme\t    : 3\n Alisveris Islemi\t    : 4\n Stoktaki Urunleri Yenileme : 5\n");
	printf("\n Hangi Islemi Yapmak Istersiniz ?\n ");
	scanf("%d", &cvp);
		
	while(islem == 0){
			
		if(cvp == 1){
				
			stok_belirleme(1, kod, urun_kodlari);
							
			printf("\n\n\n Satis Fiyati Belirleme     : 1\n Maliyet Belirleme\t    : 2\n Alisveris Islemi\t    : 3\n Stoktaki Urunleri Yenileme : 4\n");
			printf("\n Hangi Islemi Yapmak Istersiniz ?\n ");
			scanf("%d", &cvp2);
				
			if(cvp2 == 1)
			{
				cvp = 2;
				islem = 0;
			}
				
			else if(cvp2 == 2)
			{
				cvp = 3;
				islem = 0;
			}
				
			else if(cvp2 == 3)
			{
				cvp = 4;
				islem = 0;
			}
			
			else if(cvp2 == 4)
			{
				cvp = 5;
				islem = 0;
			}
				
			else
			{
				printf(" Lutfen Gecerli Bir Cevap Verin.\n");
				islem = 0;
			}
		}
	
	
		if(cvp == 2){
				
			fiyat_belirleme(1, kod, urun_kodlari);
						
			printf("\n\n\n Stok Sayisi Belirleme\t    : 1\n Maliyet Belirleme\t    : 2\n Alisveris Islemi\t    : 3\n Stoktaki Urunleri Yenileme : 4\n");
			printf("\n Hangi Islemi Yapmak Istersiniz ?\n ");
			scanf("%d",&cvp2);
			
			if(cvp2 == 1)
			{
				cvp = 1;
				islem = 0;
			}
				
			else if(cvp2 == 2)
			{
				cvp = 3;
				islem = 0;
			}
				
			else if(cvp2 == 3)
			{
				cvp = 4;
				islem = 0;
			}
				
			else if(cvp2 == 4)
			{
				cvp = 5;
				islem = 0;
			}
				
			else
			{
				printf(" Lutfen Gecerli Bir Cevap Verin.\n");
				islem = 0;
			}
		}
			
			
		if(cvp == 3){
				
			maliyet_belirleme(1, kod, urun_kodlari);
						
			printf("\n\n\n Stok Sayisi Belirleme\t    : 1\n Satis Fiyati Belirleme     : 2\n Alisveris Islemi\t    : 3\n Stoktaki Urunleri Yenileme : 4\n");
			printf("\n Hangi Islemi Yapmak Istersiniz ?\n ");
			scanf("%d",&cvp2);
				
			if(cvp2 == 1)
			{
				cvp = 1;
				islem = 0;
			}
				
			else if(cvp2 == 2)
			{
				cvp = 2;
				islem = 0;
			}
				
			else if(cvp2 == 3)
			{
				cvp = 4;
				islem = 0;
			}
				
			else if(cvp2 == 4)
			{
				cvp = 5;
				islem = 0;
			}
				
			else
			{
				printf(" Lutfen Gecerli Bir Cevap Verin.\n");
				islem = 0;
			}
		}
			
			
								
		if(cvp == 4){
			
			while(flag1 == 0){
					
				urun_adeti = 0;
				tablo();
					
				printf("\n\n Istenilen %d. Urunun Kodunu Girin : ", ind);
				scanf("%d", &kod);		
				urun_kodlari[ind - 1] = kod;
			
				if(stok(urun_adeti, kod) != 0)
				{
					printf("\n\n Lutfen Kac Adet %s Alinacagini Belirtin : ", urunler[kod - 1]);
					scanf("%d", &urun_adeti);
					printf("\n");
					alinan_urun_sayisi[ind - 1] = urun_adeti;
					flag3 = 1;
				}		
				
			
				if(stok(urun_adeti, kod) == 0)
				{	
					if(adet[kod - 1] != 0)
						printf("\n\n Talep ettiginiz sayida %s yoktur.(Stokta %d adet vardir)\n\n",urunler[kod - 1], adet[kod - 1]);	
											
					else
						printf("\n\n Stokta hic %s kalmamistir.\n\n",urunler[kod - 1]);													
				}
				
			
				else
				{
					adet[kod - 1] -= urun_adeti;
					maliyet += cikan(urun_adeti, kod);
					satis += giren(urun_adeti, kod);
					stok_uyari(kod);
					ind++;
					islem_sayisi++;
				}
									
				flag2 = 0;
			
				while(flag2 == 0){
					
					printf("\n Islem Yapilmaya Devam Edilsin Mi ? (Evet : e | Hayir : h)\n ");
					scanf(" %c", &cvp3);
				
					if(cvp3 == 'e' || cvp3 == 'E')
					{
						islem = 0;
						flag1 = 0;
						flag2 = 1;
						fflush(stdin);
					}
	
	
					else if(cvp3 == 'h' || cvp3 == 'H')
					{
						islem = 1;
						flag1 = 1;
						flag2 = 1;
						flag3 = 1;
						flag4 = 0;
					}
				
				
					else
					{
						printf("\n\nLutfen Gecerli Bir Cevap Verin");
						flag1 = 0;
						flag2 = 0;
					}
						
				}
			}
		}
		
		
		if(cvp == 5){
				
			urun_adi_belirleme();
				
			printf("\n\n Stok Sayisi Belirleyin.\n\n");
			stok_belirleme(3, kod, urun_kodlari);
				
			printf("\n Satis Fiyati Belirleyin.\n\n");
			fiyat_belirleme(3, kod, urun_kodlari);
				
			printf("\n Maliyet Belirleyin.\n\n");
			maliyet_belirleme(3,kod,urun_kodlari);
			
			cvp = 4;
			islem = 0;
				
		}
			
			
		if(cvp>5){
			printf(" Lutfen Gecerli Bir Islem Numarasi Girin.");
			islem = 1;
		}
	}
	
	
	
	
	if(flag3 == 1){
		
		printf("\n\n------------------------------------");
		printf("\n\t     Sepet\n\n");
				
		for(j = 0 ; j < islem_sayisi ; j++)
			printf("\t %d  Adet  %s\n", alinan_urun_sayisi[j], urunler[urun_kodlari[j] - 1]);
			
		printf("\n\n Urunlerin Toplam Maliyeti    : %d", maliyet);
		printf("\n\n Urunlerin Toplam S. Fiyati   : %d", satis);
		printf("\n\n Kasaya Girecek Miktar        : %d", satis - maliyet);
		printf("\n\n Elde Edilen Yuzde Kar        :");
		printf(" %% ");
		printf("%.2lf",kar(maliyet,satis));
	}
	
		
	
	return 0;
}



int stok(int urun_adeti, int kod){
	
	int stok_urun_a = adet[kod - 1];
	
	if(urun_adeti > stok_urun_a)	
		return 0;
	else
		return 1;		
}



void urun_adi_belirleme(){
	
	int i = 1, cvp;
	char yeni_urun[20];
	
	printf("\n Girilecek Urun Sayisini Girin : ");
	scanf("%d",&a);
	
	int tmp = a;
	
	while(tmp > 0){
		
		printf("\n %d. Urunun Adini Girin : ", i);
		scanf(" %[^\n]s", yeni_urun);
		
		strcpy(urunler[i - 1], yeni_urun);
		i++;
		tmp--;
	}
}



void stok_uyari(int kod){
	
	if(adet[kod - 1] < 6){
		
		if(adet[kod - 1] == 0)
			printf("\n %s Stogunuz Tukendi\n\n", urunler[kod - 1]);
		else
			printf("\n %s Stogunuz Tukenmek uzere!\n ( Stokta Kalan %d )\n", urunler[kod - 1], adet[kod - 1]);	
	}
	
}



void stok_belirleme(int x, int kod, int urun_kodlari[]){
	
	int islem,yeni_stok,i,flag=1;
	char cvp;
	
	if(x==3){
		for(i = 0 ; i < a ; i++){					
			printf("\n Stoga Girecek %s Sayisi : ", urunler[i]);
			scanf("%d", &yeni_stok);
		
			printf("\n");
			adet[i] = yeni_stok;
		}
		islem = 0;
	}
	
	else{
		printf("\n Butun Urunlerin Stogunu Degistirmek   : 1\n Belirli Urunlerin Stogunu Degistirmek : 2\n ");
		scanf("%d",&islem);
	}
	
	
	if(islem == 1){

		if(x == 1)
		{
			for(i = 0 ; i < a ; i++){
				printf("\n Stoktaki Eski %s Sayisi : %d", urunler[i], adet[i]);
		
				printf("\n Yeni %s Sayisini Girin : ", urunler[i]);
				scanf("%d", &yeni_stok);
		
				printf("\n");
				adet[i] = yeni_stok;
			}	
		}
		
	}
	
	
	if(islem == 2){
		
		while(flag)
		{
			tablo();
			
			printf("\n Lutfen Stogu Degistirilecek Urunun Kodunu Girin : ");
			scanf("%d",&kod);
			
			printf("\n Stoktaki Eski %s Sayisi : %d", urunler[kod-1], adet[kod-1]);
			
			printf("\n Yeni %s Sayisini Girin : ", urunler[kod-1]);
			scanf("%d", &yeni_stok);
			
			printf("\n");
			adet[kod-1] = yeni_stok;
			
			while(1)
			{
				printf(" Islemi Sonlandirmak Ister Misiniz? (Evet : e | Hayir : h)\n ");
				scanf(" %c",&cvp);
				
				if(cvp == 'e' || cvp == 'E'){
					flag = 0;
					break;
				}
				
				else if(cvp=='h' || cvp=='H'){
					flag=1;
					break;
				}
				
				else{
					printf(" Lutfen Gecerli Bir Cevap Verin.\n");
				}
					
			}
		}		
	}
	
}



void fiyat_belirleme(int x, int kod, int urun_kodlari[]){
	
	int islem, yeni_fiyat, i, flag=1;
	char cvp;
	
	
	if(x == 3){
		for(i = 0 ; i < a ; i++){
											
			printf("\n %s Satis Fiyatini Girin : ", urunler[i]);
			scanf("%d", &yeni_fiyat);

			printf("\n\n");
			fiyat[i] = yeni_fiyat;
		}	
		islem = 0;
	}
	else{
		printf("\n Butun Urunlerin Fiyatini Degistirmek   : 1\n Belirli Urunlerin Fiyatini Degistirmek : 2\n ");
		scanf("%d", &islem);
	}
	
	
	if(islem == 1){	
		if(x == 1){
			for(i = 0 ; i < a ; i++){
					
				printf("\n Eski %s Fiyati : %d", urunler[i], fiyat[i]);
				
				printf("\n Yeni %s Fiyatini Girin : ", urunler[i]);
				scanf("%d", &yeni_fiyat);
			
				printf("\n\n");
				fiyat[i] = yeni_fiyat;
			}
		}
	
	}
	
	
	if(islem == 2){
		
		while(flag)
		{
			tablo();
			
			printf("\n Lutfen Fiyati Degistirilecek Urunun Kodunu Girin : ");
			scanf("%d", &kod);
			
			printf("\n Eski %s Fiyati : %d", urunler[kod - 1], fiyat[kod - 1]);
			
			printf("\n Yeni %s Fiyatini Girin : ", urunler[kod - 1]);
			scanf("%d", &yeni_fiyat);
			
			printf("\n");
			fiyat[kod - 1] = yeni_fiyat;
			
			while(1)
			{
				printf(" Islemi Sonlandirmak Ister Misiniz? (Evet : e | Hayir : h)\n ");
				scanf(" %c", &cvp);
				
				if(cvp == 'e' || cvp == 'E'){
					flag = 0;
					break;
				}
				
				else if(cvp == 'h' || cvp == 'H'){
					flag = 1;
					break;
				}
				
				else
					printf(" Lutfen Gecerli Bir Cevap Verin.\n");
							
			}
		}		
	}
}



void maliyet_belirleme(int x, int kod, int urun_kodlari[]){
	
	int yeni_maliyet, i, islem, flag=1;
	char cvp;
	
	if(x==3){
		for(i = 0 ; i < a ; i++){
											
			printf("\n %s Maliyetini Girin : ", urunler[i]);
			scanf("%d", &yeni_maliyet);

			printf("\n\n");
			maliyet[i] = yeni_maliyet;
		}	
		islem = 0;
	}
	
	else{
		printf("\n Butun Urunlerin Maliyetini Degistirmek   : 1\n Belirli Urunlerin Maliyetini Degistirmek : 2\n ");
		scanf("%d", &islem);
	}
	
	
	if(islem == 1){
		for(i = 0 ; i < a ; i++){			
			printf("\n %s Maliyeti Girin : ", urunler[i]);
			scanf("%d", &yeni_maliyet);
			
			printf("\n\n");
			maliyet[i] = yeni_maliyet;
		}
	}
	
	
	if(islem == 2){
		while(flag)
		{			
			tablo();
			
			printf("\n Lutfen Maliyeti Degistirilecek Urunun Kodunu Girin : ");
			scanf("%d",&kod);
			
			printf("\n Eski %s Maliyeti : %d", urunler[kod - 1], maliyet[kod - 1]);
			
			printf("\n Yeni %s Maliyetini Girin : ", urunler[kod - 1]);
			scanf("%d", &yeni_maliyet);
			
			printf("\n");
			maliyet[kod - 1] = yeni_maliyet;
			
			while(1)
			{	
				printf(" Islemi Sonlandirmak Ister Misiniz? (Evet : e | Hayir : h)\n ");
				scanf(" %c",&cvp);
				
				if(cvp == 'e' || cvp == 'E'){
					flag = 0;
					break;
				}
				
				else if(cvp == 'h' || cvp == 'H'){
					flag = 1;
					break;
				}
				
				else{
					printf(" Lutfen Gecerli Bir Cevap Verin.\n");
				}
					
			}
		}		
	}
	
	
}



int basamak_sayisi(int sayi){
	
	int b_s = 0, x;
	
	while(sayi != 0){
		
   		x = sayi % 10;
		sayi -= x;
		sayi /= 10;
   		b_s++;
   		
	}
	
	return b_s;
}



void space(int i){
	
	int spc;
    spc = 27 - strlen(urunler[i]);
    
  	while(spc > 0){
		printf(" ");
		spc--;	
	}
}



void space2(int i){
	
	int spc = 24 - basamak_sayisi(adet[i]);

	if(adet[i] == 0){
		while(spc > 2)
		{
			printf(" ");
			spc--;	
		}
	}
	
    else if(adet[i] - 10 < 0){
		while(spc > 1)
		{
			printf(" ");
			spc--;	
		}
	}
	
	else{
		while(spc > 0)
		{
			printf(" ");
			spc--;	
		}
	}
	
}


void space3(int i){
	
	int spc = 23 - basamak_sayisi(fiyat[i]);
    
    if(fiyat[i] == 0){
    	while(spc > 2)
		{
			printf(" ");
			spc--;	
		}
	}
	
	else{
		while(spc > 0)
		{
			printf(" ");
			spc--;	
		}
	}
}


void tablo(){
	
	int i = 0;
	printf("\n\n\t\tURUN ADI\t\tURUN ADETI\t\t URUN FIYATI\t\t   URUN KODU\n");
	
	while(i < a)
	{
		
		printf("\n\t\t ");
		
		printf("%s", urunler[i]);
			
		space(i); 
		
		if(adet[i] - 10 < 0)	
			printf("0%d", adet[i]);
		else
			printf("%d", adet[i]);
			
		space2(i); 
			
		printf("%d TL", fiyat[i]);
			
		space3(i);
		
		printf(" %d\n", i + 1);
			
		i++;		
	}
}


int giren(int urun_adeti, int kod){
	
	int urun_fiyat = fiyat[kod - 1];
	int satis_fiyat = urun_fiyat * urun_adeti;
	return satis_fiyat;
}


int cikan(int urun_adeti,int kod){
	
	int urun_maliyet = maliyet[kod - 1];
	int maliyet_fiyat = urun_maliyet * urun_adeti;
	return maliyet_fiyat;
}


double kar(int maliyet, int satis){	
	double kar = ( ( (double)satis * 100.00) / (double)maliyet) - 100.00;
	return kar ;
}
