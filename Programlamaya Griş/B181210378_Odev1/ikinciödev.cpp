/*******************************************
** SAKARYA ÜNÝVERSÝTESÝ 
** BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKULTESÝ 
** BÝLGÝSYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
** PROGRAMLAMAYA GÝRÝÞ DERSÝ
** 1. ÖDEV
** SEVÝM SUNA KALAYCI
** B181210378
** 2. ÖÐRETÝM D GRUBU
********************************************/

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Turkish");
	char dizi[100];
	cin.getline(dizi, 100);//Enter basýlana kadar girilen metni okuyor.
	int i, karakter = 0, sesli_harf = 0, sayac_a = 0, sayac_e = 0, sayac_i = 0, sayac_i2 = 0, sayac_o = 0, sayac_o2 = 0, sayac_u = 0, sayac_u2 = 0;
	do
	{


		if (dizi[karakter] == 'a' || dizi[karakter] == 'A')
		{
			sayac_a++; // a harfini bulduðunda sayac a'yý bir arttýr.
			karakter++;// Okuduktan sonra bir harf sonrasýna geç.
			sesli_harf++;
		}
		else if (dizi[karakter] == 'e' || dizi[karakter] == 'E')
		{
			sayac_e++;// e harfini bulduðunda sayac e'yi bir arttýr.
			karakter++;
			sesli_harf++;
		}
		else if (dizi[karakter] == (char)-115 || dizi[karakter] == 'I')
		{
			sayac_i2++;//ý harfini bulduðunda sayac ý'yý bir arttýr.
			karakter++;
			sesli_harf++;
		}
		else if (dizi[karakter] == 'i' || dizi[karakter] == (char)-104)
		{
			sayac_i++;//i harfini bulduðunda sayac i'yi bir arttýr.
			karakter++;
			sesli_harf++;
		}
		else if (dizi[karakter] == 'o' || dizi[karakter] == 'O')
		{
			sayac_o++;//o harfini bulduðunda sayac o'yu bir arttýr.
			karakter++;
			sesli_harf++;
		}
		else if (dizi[karakter] == (char)-108 || dizi[karakter] == (char)-103)
		{
			sayac_o2++;//ö harfini bulduðunda sayac ö'yü bir arttýr.
			karakter++;
			sesli_harf++;
		}
		else if (dizi[karakter] == 'u' || dizi[karakter] == 'U')
		{
			sayac_u++;//u harfini bulduðunda sayac u'yu bir arttýr.
			karakter++;
			sesli_harf++;
		}
		else if (dizi[karakter] == (char)-127 || dizi[karakter] == (char)-102)
		{
			sayac_u2++;//ü harfini bulduðunda sayac ü'yü bir arttýr.
			karakter++;
			sesli_harf++;
		}
		else
		{
			karakter++;
		}

	} while (dizi[karakter] != '\0');
	cout << "H\t\tTS\t";
	for (i = 0; i < sesli_harf; i++)
	{
		cout << i + 1 << "\t";
	}
	cout << endl;
	//Bütün Sayaclarýn 0 dan büyüklüðüne bakarak mevcut harfleri tekrarý kadar yazdýrýrýz.
	if (sayac_a > 0)
	{
		cout << "a\t\t" << sayac_a << "\t";
		for (i = 0; i < sayac_a; i++)
		{
			cout << "a\t";
		}
		cout << endl;
	}
	if (sayac_e > 0)
	{
		cout << "e\t\t" << sayac_e << "\t";
		for (i = 0; i < sayac_e; i++)
		{
			cout << "e\t";
		}
		cout << endl;
	}
	if (sayac_i > 0)
	{
		cout << "i\t\t" << sayac_i << "\t";
		for (i = 0; i < sayac_i; i++)
		{
			cout << "i\t";
		}
		cout << endl;
	}
	if (sayac_i2 > 0)
	{
		cout << "ý\t\t" << sayac_i2 << "\t";
		for (i = 0; i < sayac_i2; i++)
		{
			cout << "ý\t";
		}
		cout << endl;
	}
	if (sayac_o > 0)
	{
		cout << "o\t\t" << sayac_o << "\t";
		for (i = 0; i < sayac_o; i++)
		{
			cout << "o\t";
		}
		cout << endl;
	}
	if (sayac_o2 > 0)
	{
		cout << "ö\t\t" << sayac_o2 << "\t";
		for (i = 0; i < sayac_o2; i++)
		{
			cout << "ö\t";
		}
		cout << endl;
	}
	if (sayac_u > 0)
	{
		cout << "u\t\t" << sayac_u << "\t";
		for (i = 0; i < sayac_u; i++)
		{
			cout << "u\t";
		}
		cout << endl;
	}
	if (sayac_u2 > 0)
	{
		cout << "ü\t\t" << sayac_u2 << "\t";
		for (i = 0; i < sayac_u2; i++)
		{
			cout << "ü\t";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}