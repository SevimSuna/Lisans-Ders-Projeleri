#include "pch.h"
#ifndef Sifre_h
#define Sifre_h

#include <iostream>
#include <cstdlib>
using namespace std;

char *mtn;

class Sifre
{
public:
	Sifre(char *alfabe, char *sifre);
	Sifre();

	char* sifrele(char*);
	char* sifrecoz(char*);
	void sifreKelimesiAta(char*);

private:
	char* alfebe;
	char* sifreKelimesi;
};

Sifre::Sifre(char *alfabe, char *sifre)
{
	alfebe = alfabe;
	sifreKelimesi = sifre;
}


void Sifre::sifreKelimesiAta(char *metin) //girilen metinin boyunu hesaplayıp şifreli metnin tekrarını oluşturdum.
{
	int sayi = 0, sifresayisi = 0;
	char mtn;
	while (*metin != NULL)
	{
		sayi++;
		metin++;
	}
	while (*sifreKelimesi != NULL)
	{
		sifresayisi++;
		sifreKelimesi++;
	}
	char dizi[50];
	for (int i = 0; i < sayi; i++)
	{
		if (*sifreKelimesi == NULL)
		{
			int k = 0;
			while (k < sifresayisi)
			{
				sifreKelimesi--;
				k++;
			}
			dizi[i] = *sifreKelimesi;
			sifreKelimesi++;
		}
	}
	sifreKelimesi = dizi;
}

char* Sifre::sifrele(char* metin)//alfabenin uunluğunu hesaplayıp 2 boyutlu bir diziye alfabeyi olusturdum. 
{
	char dizi[50][50],sifrelidizi[50];
	char *sifreliMetin;
	int sayi = 0, sifrelisayi = 0;
	sifreKelimesiAta(sifreKelimesi);
	while (*alfebe != NULL)
	{
		alfebe++;
		sayi++;
	}
	for (int i = 0; i < sayi; i++)
	{
		for (int j = 0; j < sayi; i++)
		{
			int k = 0;
			if (*alfebe == NULL)
			{
				while (k <= sayi)
				{
					alfebe--;
					k++;
				}
			}
			dizi[i + 1][j + 1] = *alfebe;
			alfebe++;
		}
	}
	int ksayi = 0;
	while (*sifreKelimesi != NULL)
	{
		ksayi++;
		sifreKelimesi++;
	}
	while (*metin != NULL)//dizide sutun için girilen metnin harflerini baz alarak, satir için sifre kelimesini baz alarak şifreli metni olusturdum.
	{
		if (*sifreKelimesi == NULL)
		{
			int k = 0;
			while (k <= ksayi)
			{
				sifreKelimesi--;
				k++;
			}
		}
		int satir, sutun;
		for (int i = 0; i < sayi; i++)
		{
			if (dizi[i][0] == *sifreKelimesi)
			{
				satir = i;
				continue;
			}
		}
		for (int j = 0; j < sayi; j++)
		{
			if (dizi[0][j] == *metin)
			{
				sutun = j;
				continue;
			}
		}
		dizi[satir][sutun] = sifrelidizi[sifrelisayi];
		metin++;
		sifreKelimesi++;
		sifrelisayi++;
	}
	sifreliMetin = sifrelidizi;
	return sifreliMetin;
	
}

char* Sifre::sifrecoz(char* sifreliMetin)//alfabenin boyunu hesaplayarak 2 boyutlu matris oluşturdum ve alfabeyi içine yerleştirdim.
{
	int sayi = 0, satir, sutun, sifrelisayi = 0;
	char dizi[50][50],desifrelidizi[50];
	char *desifreliMetin;
	while (*alfebe != NULL)
	{
		alfebe++;
		sayi++;
	}
	for (int i = 0; i < sayi; i++)
	{
		for (int j = 0; j < sayi; i++)
		{
			int k = 0;
			if (*alfebe == NULL)
			{
				while (k <= sayi)
				{
					alfebe--;
					k++;
				}
			}
			dizi[i + 1][j + 1] = *alfebe;
			alfebe++;
		}
	}
	int ksayi = 0;//sifreli kelimeyi baz alarak harfleri ile hangi sutuna denk geldiğini hesapladım ve o sutun içerisinde sifreli metnin hangi satıra denk geldiğini hesapladım.
	while (*sifreKelimesi != NULL)//sifreli harflerin satırlarını sırası ile metin için diziye atadım. 
	{
		ksayi++;
		sifreKelimesi++;
	}
	while (*sifreliMetin != NULL)
	{
		int k = 0;
		if (*sifreKelimesi == NULL)
		{
			while (k <= ksayi)
			{
				sifreKelimesi--;
			}
		}
		for (int j = 0; j < sayi; j++)
		{
			if (dizi[0][j] == *sifreKelimesi)
			{
				sutun = j;
				continue;
			}
		}
		for (int i = 0; i < sayi; i++)
		{
			if (dizi[i][sutun] == *sifreliMetin)
			{
				satir = i;
				continue;
			}
		}
		desifrelidizi[sifrelisayi] = dizi[satir][0];
		sifrelisayi++;
		sifreliMetin++;
		sifreKelimesi++;
	}
	desifreliMetin = desifrelidizi;
	return desifreliMetin;
}

Sifre::Sifre()//mainde çalıştırmak için class içindeki fonksionlarımızı içine yerlestirdim.
{
	char *sflmtn, *dsfmtn;
	sifreKelimesiAta(sifreKelimesi);
	sflmtn=sifrele(mtn);
	dsfmtn = sifrecoz(sflmtn);
	cout << "SIFRELENMIS METİN:\t";
	while (*sflmtn != NULL)
	{
		cout << *sflmtn;
		sflmtn++;
	}
	
	cout << "DESIFRELI METİN:\t";
	while (*dsfmtn != NULL)
	{
		cout << *dsfmtn;
		dsfmtn++;
	}
}


int main()//alfabe, sifre ve metin giridilerini aldım.
{
	int sayi = 0;
	char *sfrmtn, *alfb;
	char sfr[20], alfbe[50], metn[100];
	cout << "ALFABE\t:"; gets_s(alfbe);
	cout << "SIFRE\t:";  gets_s(sfr);
	cout << "METIN\t";   gets_s(metn);
	alfb = alfbe;
	sfrmtn = sfr; 
	mtn = metn;
	Sifre(alfb, sfrmtn);
	Sifre();
}

#endif // !Sifre_h
