#include <stdio.h> 
//dosya giri�-��k�� i�lemleri i�in stdio.h k�t�phanesindeki fonksiyonlar de�i�kenler ve sabitler kullan�l�r
//bu k�t�phaneyi kullanarak bilgisayardaki klavye, ekran, disk s�r�c� veya port'lara eri�im sa�layarak i�lem yapabiliriz
//fclose fopenf fprintf fscanf prinft scanf remove rename FILE(veri) EOF(sbt) NULL(sbt)

#include<stdlib.h>
//stdlib.h k�t�phanesinde, dinamik bellek y�netimi, rasgele say� �retimi, �evre ile ileti�im, tamsay� aritmeti�i, arama, s�ralama ve d�n��t�rme gibi �e�itli genel ama�l� fonksiyonlar tan�mlanm��t�r
//exit ve system 

#include<ctype.h> 
//karakterlerle ilgili fonksiyonlar i�in kullan�l�r
//b�y�k-k���k harf 

#include<conio.h> 
//program ��kt�s�n� alabilmek i�in
//getche() ve getch()

#include<string.h> 
//string.h k�t�phanesinde karakter dizileri ile ilgili fonksiyon, veri t�r� i�erir
//strcmp, strlen 

#include<time.h> 
//time.h k�t�phanesinde tarih ve saat i�lemleri i�in fonskiyon ve de�i�ken tan�mlamalar� yer al�r
//time, ctime

#include<locale.h> 
//T�rk�e karakterleri kullanabilmek i�in yerel fonk ve verileri i�erir
//setlocale

#include<stdbool.h> 
//bool verileri i�in, ikili sayi sistem ver, t�r� dep�erleri ile ilgili tan�mlamalar 
//bool, true, false

FILE *fo, *fg; //file tipinde pointerleri tan�mlad�k, ��aret�ilerin di�er de�i�kenlerden tek fark� ba�ka bir de�i�kenin bellek adresini i�eriyor olmas�d�r.

//E�er bir fonksiyonun ad�n�n ba��nda veri t�r� tan�mlanmazsa, fonksiyon int bir de�er geri verir. 
// olu�turulan fonksiyonnlar, main() fonksiyonundan sonra yer al�yorsa, mutlaka main() fonksiyonunda �nce fonksiyon bildirimi(fonksiyon prototipi y�ntemiyle bildirimi) yap�lmal�d�r.
void sifrekullanici(); //bilgisayara fonksiyonlar tan�mland�
void kayit_ekleme();
void kayit_listeleme();
void kayit_silme();
void kayit_guncelleme();
void kayit_noara();
void kayit_adara();

//Yap�, farkl� veri t�rlerini bir grup alt�nda toplayan kullan�c� tan�ml� bir veri t�r�d�r. 
//�ki veya daha fazla elemandan olu�ur. Bir yap� i�indeki b�t�n veri tipleri ayn� olabilece�i gibi, her veri t�r� birbirinden farkl� da olabilir.
struct hasta {  //struct yap�s� tan�mland� 
	int durum;
	int yas;
	int no;
	char ad[20];
	char soyad[20];
	char konum[30];
	char adres[100];
	char tarih[15];
	char saat[10];
	char medeni[10];
	char kan[10];
	char sosyalg[20];
	 
};

struct hasta hast,gec; //gecici ve hasta dosylar�nda kullan�lacak iki de�i�ken tan�mlad�k
//yukar�da tan�mlad���m�z de�i�kenleri 2 farkl� de�i�ken olarak kullanabilece�iz 

int main() 
{
	system("cls"); //clearing the screen
	//Bilgisayar ortam�n�n komut i�lemcisini command parametre de�eri ile �a��rarak, sistemin bu komutu uygulamas�n� sa�lar.
	
	setlocale(LC_ALL, "Turkish"); // t�rk�e karakterler i�in kullan�lan fonksiyon, yerel verileri okuyan veya ayarlayan fonk
	
	time_t t; //zaman bilgisini g�stermeye yarar
    time(&t);
    
    int secenek;
	char x='E';
	
	//printf("\n\n\n\n\t\t\t\t\t%s", ctime(&t));  //ctime Timer parametresi ile g�sterilen time_t de�erini yerel zamana �evirdikten sonra y�l, ay, g�n ve saat bilgilerini i�eren karakter dizisini geri d�nd�r�r.
    
    printf("\n\n\n\n\t\t\t\t************************************");
    printf("\n\t\t\t\t********** EMEK HASTANESI **********");
    printf("\n\t\t\t\t************************************\n");

	sifrekullanici();
    	
    while(x=='E'){
		
    	printf("\n");
    	printf("\t\tANA MENU ");
    	printf("\n\n\t[1]\tYENI KAYIT EKLE");
    	printf("\n\t[2]\tKAYIT LISTELE");
    	printf("\n\t[3]\tKAYIT SILME");
    	printf("\n\t[4]\tKAYIT GUNCELLE");
    	printf("\n\t[5]\tKIMLIK NUMARASINA GORE ARAMA");
    	printf("\n\t[6]\tADA GORE ARAMA");
    	printf("\n\t[7]\tCIKIS");
        
    	printf("\n\n\tGITMEK ISTEDIGINIZ SECENEK:");
    	scanf(" %d", &secenek);
    	
    	printf("\n");
    	
    	if(secenek==1 || secenek==2 || secenek==3 || secenek==4 || secenek==5 || secenek==6 || secenek==7){
    		switch(secenek) 
    		{
    			case 1 :
    				kayit_ekleme();
    			break;
    			
				case 2:
    				kayit_listeleme();
    			break;
    			
				case 3:
    				kayit_silme();
    			break;
    			
				case 4:
    				kayit_guncelleme();
    			break;
    			
				case 5:
    				kayit_noara();
    			break;
    		
				case 6:
    				kayit_adara();
    			break;
				
				case 7:
                	printf("\n\n\tSAGLIKLI GUNLER DILERIZ... ");
                    getch(); //?
                    exit(0); //Kaynaklar� tamamen temizleyerek program� normal bir �ekilde sonland�r�r.
                    
                break;
        	}        
         
		 	x='H';
         	printf("Ana menuye donmek icin E, cikis yapmak icin H:");
       	 	scanf(" %c", &x); 
         
       	 	system("cls");    // daha once ekrana yazd�r�lm�� ��kt�lar� ekrandan temizler.
	    }
            
        else{
            system("cls"); 
			printf("\nYanlis bir secim yaptiniz.\n");
            x='E';	
        }
    
    }
  return 0;
	
}

void sifrekullanici() 
{
	
	int e=0	;
	char kullaniciadi[15];
	char sifre[15];
	char dogru_kullaniciadi[25]="aysukaymak";
	char dogru_sifre[15]="123456789";
	
	do 
    { 
		printf("\n\n\n\n\t\t\t\tKullan�c� Ad� ve �ifrenizi Giriniz :)");
		printf("\n\n\n\t\t\t\t\tKullan�c� Ad�:");
		scanf(" %s", kullaniciadi);
	
		printf("\n\n\t\t\t\t\t�ifre:");
		scanf(" %s", sifre);
	
		if (strcmp(kullaniciadi, dogru_kullaniciadi)==0 && strcmp(sifre, dogru_sifre)==0)
		{
			printf("\n\n\n\t\t\t\t...Ba�ar�yla Giri� Yap�ld�...");
	 	
			getch();
			//main();
			break;
		}
		else
		{
			printf("\n\t\t\tYanl�� Giri� Yapt�n�z. Yeniden Deneyin:");
			e++;
			getch();
		}
	}
    while(e<=2);
   
	if(e>2)
	{
		printf("Deneme hakk�n�z dolmu�tur. Giri� yapamazs�n�z. :( :(");
		getch();
   	    exit(0);
	}
 
system("cls");

}

void kayit_ekleme()
{
	system("cls");
	
    int no;
	
	printf("\n");
	
	fo=fopen("Hasta.txt","r");	// arg�man olarak dosya ad� ve dosyan�n hangi modla ac�lac��� girilir, r modunda okuma i�in bir metin dosyas� a��l�r, dosya mevcut olmal�d�r.
	
	printf("Hastanin kimlik numarasini girin : ");
	scanf(" %d", &hast.no);
	
	while(fscanf(fo,"%d %s %s %d %s %s %s %s %s %s %s %d", &gec.no,gec.ad,gec.soyad, &gec.yas, gec.medeni,gec.kan,gec.sosyalg, gec.konum, gec.adres, gec.tarih, gec.saat, &gec.durum)!=EOF)
	{
	
		if(hast.no==gec.no && gec.durum==1) 
		{
			printf("Girdi�iniz kimlik numaras�na sahip hastan�n kayd� yap�lm��, ba�ka bir kimlik numaras� giriniz:\n");
			fclose(fo);
			return;
			
			//return ifadesi bir fonksiyondan ��k�� yapmak ve program i�inde fonksiyon �a�r�s�n�n yap�ld��� i�lem sat�r�ndan bir sonraki i�lem sat�r�na ge�i� yapmak i�in kullan�l�r.	
		}
	}
	
	fclose(fo); //ac�lan dosyay�  kapat�r.
	
	fo=fopen("Hasta.txt","r+"); //r+ Okuma ve yazma i�in bir metin dosyas� a�ar. Dosya mevcut olmal�d�r.
	fg=fopen("Gecici.txt","w+"); //w+	Okuma ve yazma i�in bir metin dosyas� olu�turur.
	
	printf("Hastan�n ad�: ");
	scanf("%s", hast.ad);
	printf("Hastan�n soyad�: ");
	scanf("%s", hast.soyad);
	printf("Hastan�n ya��: ");
	scanf("%d", &hast.yas);
	printf("Hastan�n medeni hali: ");
	scanf("%s", hast.medeni);
	printf("Hastan�n kan grubu: ");
	scanf("%s", hast.kan);
	printf("Hastan�n sosyal g�vence durumu: ");
	scanf("%s", hast.sosyalg);
	printf("Hastan�n ikamet etti�i il/il�e: ");
	scanf("%s", hast.konum);	
	printf("Hastan�n adresi: ");
	scanf("%s", hast.adres);
	printf("Kay�t edilen tarih(gg/aa/yyyy): ");
	scanf("%s", hast.tarih);
	printf("Kay�t edilen saat(ss:dd): ");
	scanf("%s", hast.saat);
	
	//fprintf, printf ile benzerdir ama ekrana de�il dosyaya yazar.
	//fscanf, scanf ile benzerdir ama klavyeden de�il dosyadan veri okur.
	//strcmp, karakter dizilerini kar��la�t�r�r. E�er her iki karakter dizisindeki t�m karakterler ayn� ise s�f�r de�eri, aksi takdirde s�f�rdan farkl� bir de�er geri d�nd�r�r.
	//<0 ise str1 bellek i�eri�i str2 bellek i�eri�inden k���kt�r.
	//>0 ise str2 bellek i�eri�i str1 bellek i�eri�inden k���kt�r.
	//=0 ise str1 bellek i�eri�i str2 bellek i�eri�ine e�ittir.
	
	
	int yazildi=0;
	
	while(fscanf(fo,"%d %s %s %d %s %s %s %s %s %s %s %d", &gec.no, gec.ad, gec.soyad, &gec.yas, gec.medeni, gec.kan, gec.sosyalg, gec.konum, gec.adres, gec.tarih, gec.saat, &gec.durum) != EOF)
	{ 
		
		if(strcmp(hast.ad, gec.ad)<0 && yazildi==0)
		{ //alfabetik s�ralama i�in 
			fprintf(fg,"%d %s %s %d %s %s %s %s %s %s %s 1\n", hast.no, hast.ad, hast.soyad, hast.yas, hast.medeni, hast.kan, hast.sosyalg, hast.konum, hast.adres, hast.tarih, hast.saat);
			yazildi=1;
		}	
		fprintf(fg,"%d %s %s %d %s %s %s %s %s %s %s %d\n", gec.no, gec.ad, gec.soyad, gec.yas, gec.medeni, gec.kan, gec.sosyalg, gec.konum, gec.adres, gec.tarih, gec.saat, gec.durum);
	}
	
	if(yazildi==0)
	{
		fprintf(fg,"%d %s %s %d %s %s %s %s %s %s %s 1", hast.no, hast.ad, hast.soyad, hast.yas, hast.medeni, hast.kan, hast.sosyalg, hast.konum, hast.adres, hast.tarih, hast.saat);

	}
	
	printf("\n\n");
	printf("...Kayit islemi basariyla gerceklestirildi... \n\n");
	fclose(fo);
	fclose(fg);
	remove("Hasta.txt"); //hasta.txt dosyas�n� siler
	rename("Gecici.txt","Hasta.txt"); //ge�ici olarak a�t���m dosyadaki verileri Hasta.txt olarak ismini de�i�tirir
	
}


void kayit_listeleme()
{
	system("cls");
	printf("\n");
	
	fo=fopen("Hasta.txt","r");
	
	while(fscanf(fo,"%d %s %s %d %s %s %s %s %s %s %s %d", &hast.no, hast.ad, hast.soyad, &hast.yas, hast.medeni, hast.kan, hast.sosyalg, hast.konum, hast.adres, hast.tarih, hast.saat, &hast.durum)!=EOF)
	{
	
		if(hast.durum==0)continue;
	
		printf("T.C Kimlik No: %8d\nAd: %8s\nSoyad: %8s\nYas: %8d\nMedeni Hal: %8s\nKan Grubu: %8s\n Sosyal Guvence: %8s\nYasanilan Il/Ilce: %8s\nAdres: %8s\nGiris Tarihi: %8s\nGiris Saati: %8s\n", hast.no, hast.ad, hast.soyad, hast.yas, hast.medeni, hast.kan, hast.sosyalg, hast.konum, hast.adres, hast.tarih, hast.saat);
		printf("*************************************************************************************************** \n");
	        
	}
	
	fclose(fo);
}


void kayit_silme()
{
	system("cls");
	printf("\n");
	
	bool kayitVarmi=false;
	int sayi;
	
	fo=fopen("Hasta.txt","r");
	fg=fopen("Gecici.txt","w+");
	
	printf("Silmek istedi�iniz hastanin kimlik numarasini girin:");
	scanf(" %d", &sayi);
	
	while((fscanf(fo,"%d %s %s %d %s %s %s %s %s %s %s %d", &hast.no, hast.ad, hast.soyad, &hast.yas, hast.medeni, hast.kan, hast.sosyalg, hast.konum, hast.adres, hast.tarih, hast.saat, &hast.durum))!=EOF)
	{
		
		if(hast.no==sayi && hast.durum==1)
		{	
			kayitVarmi=true;
			fprintf(fg,"%d %s %s %d %s %s %s %s %s %s %s 0\n", hast.no, hast.ad, hast.soyad, hast.yas, hast.medeni, hast.kan, hast.sosyalg, hast.konum, hast.adres, hast.tarih, hast.saat);
		}
	
		else{
			fprintf(fg,"%d %s %s %d %s %s %s %s %s %s %s %d\n", hast.no, hast.ad, hast.soyad, hast.yas, hast.medeni, hast.kan, hast.sosyalg, hast.konum, hast.adres, hast.tarih, hast.saat, hast.durum);	
		}
	}
		
	if(kayitVarmi==false)
	{
			printf("...Kayit bulunamadi...");
	}
	
	printf("...Kayit silindi...\n\n");
	
	fclose(fo);
	fclose(fg);
	remove("Hasta.txt");
	rename("Gecici.txt","Hasta.txt"); 
	
}


void kayit_guncelleme()
{
	system("cls");
	printf("\n");
	
	int sayi;
	
	fo=fopen("Hasta.txt","r");
	fg=fopen("Gecici.txt","w+");
	
	printf("Bilgilerini g�ncellemek istedi�iniz hastan�n kimlik numaras�n� girin: ");
	scanf("%d", &sayi);
	
	printf("Hastan�n Ad�: ");
	scanf("%s", gec.ad);
	printf("Hastan�n Soyad�: ");
	scanf("%s", gec.soyad);
	printf("Hastan�n ya��: ");
	scanf("%d", &gec.yas);
	printf("Hastan�n medeni hali: ");
	scanf("%s", gec.medeni);
	printf("Hastan�n kan grubu: ");
	scanf("%s", gec.kan);
	printf("Hastan�n sosyal g�vence durumu: ");
	scanf("%s", gec.sosyalg);
	printf("Hastan�n ikamet etti�i �l/�l�e: ");
	scanf("%s", gec.konum);	
	printf("Hastan�n adresi: ");
	scanf("%s", gec.adres);
	printf("G�ncellenen tarih: ");
	scanf("%s", gec.tarih);
	printf("g�ncellenen saat: ");
	scanf("%s", gec.saat);
	
	int yazildi=1;
	
		
	while(fscanf(fo,"%d %s %s %d %s %s %s %s %s %s %s %d", &hast.no, hast.ad, hast.soyad, &hast.yas, hast.medeni, hast.kan, hast.sosyalg, hast.konum, hast.adres, hast.tarih, hast.saat, &hast.durum)!=EOF)
	{
		
		if(hast.no==sayi && hast.durum==1)
		continue;
		
			if(strcmp(gec.ad, hast.ad)<0 && yazildi==1)
			{
				fprintf(fg,"%d %s %s %d %s %s %s %s %s %s %s 1\n", sayi, gec.ad, gec.soyad, gec.yas, gec.medeni, gec.kan, gec.sosyalg, gec.konum, gec.adres, gec.tarih, gec.saat);
				yazildi=0;
			}
		
			fprintf(fg,"%d %s %s %d %s %s %s %s %s %s %s %d\n", hast.no, hast.ad, hast.soyad, hast.yas, hast.medeni, hast.kan, hast.sosyalg, hast.konum, hast.adres, hast.tarih, hast.saat, hast.durum);	
	} 
	
	if(yazildi==1){
		fprintf(fg,"%d %s %s %d %s %s %s %s %s %s %s 1\n", sayi, gec.ad, gec.soyad, gec.yas, gec.medeni, gec.kan, gec.sosyalg, gec.konum, gec.adres, gec.tarih, gec.saat);	
		yazildi=0;
	}
	
	printf("\n"); 
	printf("...Kayit guncellendi...\n\n");
	
	fclose(fo);
	fclose(fg);
	remove("Hasta.txt");
	rename("Gecici.txt", "Hasta.txt");
	
}


void kayit_noara()
{
	system("cls");
	printf("\n");
	
	int aranansayi;
	bool bulundumu=false;
	
	fo=fopen("Hasta.txt","r");
	
	printf("Aramak istedi�iniz hastan�n kay�t numaras�n� girin: ");
	scanf(" %d", &aranansayi);
	
	while(fscanf(fo,"%d %s %s %d %s %s %s %s %s %s %s %d", &hast.no, hast.ad, hast.soyad, &hast.yas, hast.medeni, hast.kan, hast.sosyalg, hast.konum, hast.adres, hast.tarih, hast.saat, &hast.durum)!=EOF)
	{
	
		if(hast.no==aranansayi && hast.durum==1)
		{
			bulundumu=true;
			printf("T.C Kimlik No: %d\nAd: %s\nSoyad: %s\nYas: %d\nMedeni Hal: %s\nKan Grubu: %s\n Sosyal Guvence: %s\nYasanilan Il/Ilce: %s\nAdres: %s\nGiris Tarihi: %s\nGiris Saati: %s\n", hast.no, hast.ad, hast.soyad, hast.yas, hast.medeni, hast.kan, hast.sosyalg, hast.konum, hast.adres, hast.tarih, hast.saat);
			printf("*************************************************************************************************** \n");
			return;
		}
	}
	
	
	if(bulundumu=false) 
	{
		printf("...Arad���n�z kay�t bulunamad�..!\n");	
	}
	
	fclose(fo);
}


void kayit_adara()
{
	system("cls");
	printf("\n");
	
	int i;
	char dizi[30];
	int b=0, a=0;
	
	//strlen(), karakter dizisinin uzunlu�unu, dizi sonundaki bo� karakter hari� olmak �zere, hesaplar.
	
	printf("Aramak istedi�iniz hastan�n ad�n� girin: ");
	scanf(" %s", dizi);
	
	
	fo=fopen("Hasta.txt","r");
	
	while(fscanf(fo,"%d %s %s %d %s %s %s %s %s %s %s %d", &hast.no, hast.ad, hast.soyad, &hast.yas, hast.medeni, hast.kan, hast.sosyalg, hast.konum, hast.adres, hast.tarih, hast.saat, &hast.durum)!=EOF)
	{

		if(hast.durum==1)
		{
			b=0;
			for(i=0; i<strlen(hast.ad); i++)
			{
				if((dizi[a]!=(hast.ad[b]))) 
				{
					a=0;
					b++;	
				}
				
				else
				{
					if(a==(strlen(dizi)-1))
					{
						printf("T.C Kimlik No: %d\nAd: %s\nSoyad: %s\nYas: %d\nMedeni Hal: %s\nKan Grubu: %s\n Sosyal Guvence: %s\nYasanilan Il/Ilce: %s\nAdres: %s\nGiris Tarihi: %s\nGiris Saati: %s\n", hast.no, hast.ad, hast.soyad, hast.yas, hast.medeni, hast.kan, hast.sosyalg, hast.konum, hast.adres, hast.tarih, hast.saat);
						printf("*************************************************************************************************** \n");
						break;
					}
					
					else
					{
						b++;
						a++;
					}
				}
			}
		}
	}
	
	
	fclose(fo);
}

