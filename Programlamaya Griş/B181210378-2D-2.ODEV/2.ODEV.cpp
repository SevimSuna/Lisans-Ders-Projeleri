/***********************************************
**		SAKARYA ÜNİVERSİTESİ
**  BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**      BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**         PROGRAMLAMAYA GİRİŞ DERSİ
**
**	   ÖDEV NUMARASI: 2. ÖDEV
**	   ÖĞRENCİ ADI: SEVİM SUNA KALAYCI
**     ÖĞRENCİ NUMARASI: B181210378
**     DERS GRUBU: 2. ÖĞRETİM D GRUBU
************************************************/



#include "pch.h"
#include <iostream>
#include <ctime>

using namespace std;
int harf[5][10]; 
bool kontrol1(int kar_sat, int kar_sut); //Dizimizde aynı harfler için karşılaştırma yapacağımız fonksiyon
int main()
{
	srand(time(0));
	int sayi;
	cout << "Tekrarsiz ve Rastgele Dizi"<<endl;
	for (int satir = 0; satir < 5; satir++)
	{
		for (int sutun = 0; sutun < 10; sutun++)
		{
			if (sutun % 2 == 0) //Çift sayi olan sutunlara büyük harfler
			{
				sayi = 65;
				harf[satir][sutun] = sayi + rand() % 26;
			}
			else if (sutun % 2 != 0) //Tek sayi olan sutunlara küçük harfler
			{
				sayi = 97;
				harf[satir][sutun] = sayi + rand() % 26;
			}
		}
	}
	for (int satir = 0; satir < 5; satir++)
	{
		for (int sutun = 0; sutun < 10; sutun++)
		{
			if (sutun % 2 == 0)
			{
				sayi = 65;
				if (kontrol1(satir, sutun) == false)
				{
					while (kontrol1(satir, sutun) == false)// Çift satırları tekraladığını kontrol ediyoruz
					{
						harf[satir][sutun] = sayi + rand() % 26;
					}
					cout << char(harf[satir][sutun]) << "\t";
				}
				else
				{
					cout << char(harf[satir][sutun]) << "\t";
				}
			}
			else if (sutun % 2 != 0) //Tek satırları tekraladığını kontrol ediyoruz
			{
				sayi = 97;
				if (!kontrol1(satir, sutun))
				{
					while (kontrol1(satir, sutun) == false)
					{
						harf[satir][sutun] = sayi + rand() % 26;
					}
					cout << char(harf[satir][sutun]) << "\t";
				}
				else
				{
					cout << char(harf[satir][sutun]) << "\t";
				}
			}
		}
		cout << endl;
	}
	cout << endl << "SiralAnmis Dizi" << endl;
	int y_satir = 0, gecici;
	while (y_satir < 5)
	{
		int y_sutun = 0;
		while (y_sutun < 10)//Yedek satır ve yedek sutun numaraları ile bütün elemanları ek tek birbiri ile karşılatır
		{
			for (int satir = 0; satir < 5; satir++)
			{
				for (int sutun = 0; sutun < 10; sutun++)
				{
					if (harf[y_satir][y_sutun] < harf[satir][sutun])
					{
						gecici = harf[satir][sutun];
						harf[satir][sutun] = harf[y_satir][y_sutun];
						harf[y_satir][y_sutun] = gecici;
					}
				}
			}
			y_sutun++;
		}
		y_satir++;
	}
	for (int satir = 0; satir < 5; satir++)//Sıralanmış diziyi yazdır
	{
		for (int sutun = 0; sutun < 10; sutun++)
		{
			cout << char(harf[satir][sutun]) << "\t";
		}
		cout << endl;
	}
	system("pause");
}
bool kontrol1(int kar_sat, int kar_sut)
{
	for (int satir = 0; satir < 5; satir++)
	{
		for (int sutun = 0; sutun < 10; sutun++)
		{
			if (harf[satir][sutun] == harf[kar_sat][kar_sut] && kar_sat == satir && kar_sut != sutun)//Eleman matristeki aynı satır başka sutunun da elemanı olabilir
			{
				return false;
			}
			else if (harf[satir][sutun] == harf[kar_sat][kar_sut] && kar_sat != satir && kar_sut == sutun)//Eleman matristeki aynı sutun başka satırın da elemanı olabilir
			{
				return false;
			}
			else if (harf[satir][sutun] == harf[kar_sat][kar_sut] && kar_sat != satir && kar_sut != sutun)//Eleman matristeki farklı satır ve sutunun da elemanı olabilir
			{
				return false;
			}
		}
	}
	return true;
}