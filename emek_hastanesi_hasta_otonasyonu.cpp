#include <stdio.h> 
//dosya giriþ-çýkýþ iþlemleri için stdio.h kütüphanesindeki fonksiyonlar deðiþkenler ve sabitler kullanýlýr
//bu kütüphaneyi kullanarak bilgisayardaki klavye, ekran, disk sürücü veya port'lara eriþim saðlayarak iþlem yapabiliriz
//fclose fopenf fprintf fscanf prinft scanf remove rename FILE(veri) EOF(sbt) NULL(sbt)

#include<stdlib.h>
//stdlib.h kütüphanesinde, dinamik bellek yönetimi, rasgele sayý üretimi, çevre ile iletiþim, tamsayý aritmetiði, arama, sýralama ve dönüþtürme gibi çeþitli genel amaçlý fonksiyonlar tanýmlanmýþtýr
//exit ve system 

#include<ctype.h> 
//karakterlerle ilgili fonksiyonlar için kullanýlýr
//büyük-küçük harf 

#include<conio.h> 
//program çýktýsýný alabilmek için
//getche() ve getch()

#include<string.h> 
//string.h kütüphanesinde karakter dizileri ile ilgili fonksiyon, veri türü içerir
//strcmp, strlen 

#include<time.h> 
//time.h kütüphanesinde tarih ve saat iþlemleri için fonskiyon ve deðiþken tanýmlamalarý yer alýr
//time, ctime

#include<locale.h> 
//Türkçe karakterleri kullanabilmek için yerel fonk ve verileri içerir
//setlocale

#include<stdbool.h> 
//bool verileri için, ikili sayi sistem ver, türü depðerleri ile ilgili tanýmlamalar 
//bool, true, false

FILE *fo, *fg; //file tipinde pointerleri tanýmladýk, Ýþaretçilerin diðer deðiþkenlerden tek farký baþka bir deðiþkenin bellek adresini içeriyor olmasýdýr.

//Eðer bir fonksiyonun adýnýn baþýnda veri türü tanýmlanmazsa, fonksiyon int bir deðer geri verir. 
// oluþturulan fonksiyonnlar, main() fonksiyonundan sonra yer alýyorsa, mutlaka main() fonksiyonunda önce fonksiyon bildirimi(fonksiyon prototipi yöntemiyle bildirimi) yapýlmalýdýr.
void sifrekullanici(); //bilgisayara fonksiyonlar tanýmlandý
void kayit_ekleme();
void kayit_listeleme();
void kayit_silme();
void kayit_guncelleme();
void kayit_noara();
void kayit_adara();

//Yapý, farklý veri türlerini bir grup altýnda toplayan kullanýcý tanýmlý bir veri türüdür. 
//Ýki veya daha fazla elemandan oluþur. Bir yapý içindeki bütün veri tipleri ayný olabileceði gibi, her veri türü birbirinden farklý da olabilir.
struct hasta {  //struct yapýsý tanýmlandý 
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

struct hasta hast,gec; //gecici ve hasta dosylarýnda kullanýlacak iki deðiþken tanýmladýk
//yukarýda tanýmladýðýmýz deðiþkenleri 2 farklý deðiþken olarak kullanabileceðiz 

int main() 
{
	system("cls"); //clearing the screen
	//Bilgisayar ortamýnýn komut iþlemcisini command parametre deðeri ile çaðýrarak, sistemin bu komutu uygulamasýný saðlar.
	
	setlocale(LC_ALL, "Turkish"); // türkçe karakterler için kullanýlan fonksiyon, yerel verileri okuyan veya ayarlayan fonk
	
	time_t t; //zaman bilgisini göstermeye yarar
    time(&t);
    
    int secenek;
	char x='E';
	
	//printf("\n\n\n\n\t\t\t\t\t%s", ctime(&t));  //ctime Timer parametresi ile gösterilen time_t deðerini yerel zamana çevirdikten sonra yýl, ay, gün ve saat bilgilerini içeren karakter dizisini geri döndürür.
    
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
                    exit(0); //Kaynaklarý tamamen temizleyerek programý normal bir þekilde sonlandýrýr.
                    
                break;
        	}        
         
		 	x='H';
         	printf("Ana menuye donmek icin E, cikis yapmak icin H:");
       	 	scanf(" %c", &x); 
         
       	 	system("cls");    // daha once ekrana yazdýrýlmýþ çýktýlarý ekrandan temizler.
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
		printf("\n\n\n\n\t\t\t\tKullanýcý Adý ve Þifrenizi Giriniz :)");
		printf("\n\n\n\t\t\t\t\tKullanýcý Adý:");
		scanf(" %s", kullaniciadi);
	
		printf("\n\n\t\t\t\t\tÞifre:");
		scanf(" %s", sifre);
	
		if (strcmp(kullaniciadi, dogru_kullaniciadi)==0 && strcmp(sifre, dogru_sifre)==0)
		{
			printf("\n\n\n\t\t\t\t...Baþarýyla Giriþ Yapýldý...");
	 	
			getch();
			//main();
			break;
		}
		else
		{
			printf("\n\t\t\tYanlýþ Giriþ Yaptýnýz. Yeniden Deneyin:");
			e++;
			getch();
		}
	}
    while(e<=2);
   
	if(e>2)
	{
		printf("Deneme hakkýnýz dolmuþtur. Giriþ yapamazsýnýz. :( :(");
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
	
	fo=fopen("Hasta.txt","r");	// argüman olarak dosya adý ve dosyanýn hangi modla acýlacýðý girilir, r modunda okuma için bir metin dosyasý açýlýr, dosya mevcut olmalýdýr.
	
	printf("Hastanin kimlik numarasini girin : ");
	scanf(" %d", &hast.no);
	
	while(fscanf(fo,"%d %s %s %d %s %s %s %s %s %s %s %d", &gec.no,gec.ad,gec.soyad, &gec.yas, gec.medeni,gec.kan,gec.sosyalg, gec.konum, gec.adres, gec.tarih, gec.saat, &gec.durum)!=EOF)
	{
	
		if(hast.no==gec.no && gec.durum==1) 
		{
			printf("Girdiðiniz kimlik numarasýna sahip hastanýn kaydý yapýlmýþ, baþka bir kimlik numarasý giriniz:\n");
			fclose(fo);
			return;
			
			//return ifadesi bir fonksiyondan çýkýþ yapmak ve program içinde fonksiyon çaðrýsýnýn yapýldýðý iþlem satýrýndan bir sonraki iþlem satýrýna geçiþ yapmak için kullanýlýr.	
		}
	}
	
	fclose(fo); //acýlan dosyayý  kapatýr.
	
	fo=fopen("Hasta.txt","r+"); //r+ Okuma ve yazma için bir metin dosyasý açar. Dosya mevcut olmalýdýr.
	fg=fopen("Gecici.txt","w+"); //w+	Okuma ve yazma için bir metin dosyasý oluþturur.
	
	printf("Hastanýn adý: ");
	scanf("%s", hast.ad);
	printf("Hastanýn soyadý: ");
	scanf("%s", hast.soyad);
	printf("Hastanýn yaþý: ");
	scanf("%d", &hast.yas);
	printf("Hastanýn medeni hali: ");
	scanf("%s", hast.medeni);
	printf("Hastanýn kan grubu: ");
	scanf("%s", hast.kan);
	printf("Hastanýn sosyal güvence durumu: ");
	scanf("%s", hast.sosyalg);
	printf("Hastanýn ikamet ettiði il/ilçe: ");
	scanf("%s", hast.konum);	
	printf("Hastanýn adresi: ");
	scanf("%s", hast.adres);
	printf("Kayýt edilen tarih(gg/aa/yyyy): ");
	scanf("%s", hast.tarih);
	printf("Kayýt edilen saat(ss:dd): ");
	scanf("%s", hast.saat);
	
	//fprintf, printf ile benzerdir ama ekrana deðil dosyaya yazar.
	//fscanf, scanf ile benzerdir ama klavyeden deðil dosyadan veri okur.
	//strcmp, karakter dizilerini karþýlaþtýrýr. Eðer her iki karakter dizisindeki tüm karakterler ayný ise sýfýr deðeri, aksi takdirde sýfýrdan farklý bir deðer geri döndürür.
	//<0 ise str1 bellek içeriði str2 bellek içeriðinden küçüktür.
	//>0 ise str2 bellek içeriði str1 bellek içeriðinden küçüktür.
	//=0 ise str1 bellek içeriði str2 bellek içeriðine eþittir.
	
	
	int yazildi=0;
	
	while(fscanf(fo,"%d %s %s %d %s %s %s %s %s %s %s %d", &gec.no, gec.ad, gec.soyad, &gec.yas, gec.medeni, gec.kan, gec.sosyalg, gec.konum, gec.adres, gec.tarih, gec.saat, &gec.durum) != EOF)
	{ 
		
		if(strcmp(hast.ad, gec.ad)<0 && yazildi==0)
		{ //alfabetik sýralama için 
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
	remove("Hasta.txt"); //hasta.txt dosyasýný siler
	rename("Gecici.txt","Hasta.txt"); //geçici olarak açtýðým dosyadaki verileri Hasta.txt olarak ismini deðiþtirir
	
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
	
	printf("Silmek istediðiniz hastanin kimlik numarasini girin:");
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
	
	printf("Bilgilerini güncellemek istediðiniz hastanýn kimlik numarasýný girin: ");
	scanf("%d", &sayi);
	
	printf("Hastanýn Adý: ");
	scanf("%s", gec.ad);
	printf("Hastanýn Soyadý: ");
	scanf("%s", gec.soyad);
	printf("Hastanýn yaþý: ");
	scanf("%d", &gec.yas);
	printf("Hastanýn medeni hali: ");
	scanf("%s", gec.medeni);
	printf("Hastanýn kan grubu: ");
	scanf("%s", gec.kan);
	printf("Hastanýn sosyal güvence durumu: ");
	scanf("%s", gec.sosyalg);
	printf("Hastanýn ikamet ettiði Ýl/Ýlçe: ");
	scanf("%s", gec.konum);	
	printf("Hastanýn adresi: ");
	scanf("%s", gec.adres);
	printf("Güncellenen tarih: ");
	scanf("%s", gec.tarih);
	printf("güncellenen saat: ");
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
	
	printf("Aramak istediðiniz hastanýn kayýt numarasýný girin: ");
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
		printf("...Aradýðýnýz kayýt bulunamadý..!\n");	
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
	
	//strlen(), karakter dizisinin uzunluðunu, dizi sonundaki boþ karakter hariç olmak üzere, hesaplar.
	
	printf("Aramak istediðiniz hastanýn adýný girin: ");
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

