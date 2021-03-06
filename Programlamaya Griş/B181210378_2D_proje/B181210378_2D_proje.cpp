/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI: PROJE
**				ÖĞRENCİ ADI: Sevim Suna Kalaycı
**				ÖĞRENCİ NUMARASI.: B181210378
**				DERS GRUBU…………: 2D
****************************************************************************/


#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;



enum YON
{
	YON_SAG = 1,
	YON_SOL = 2,
	YON_YUKARI = 3,
	YON_ASAGI = 4
};

struct UcakHucre {
	int x;
	int y;
	char karakter;
	YON yon;
};

struct DusmanHucre {
	int x;
	int y;
	char karakter;
	YON yon;
};

struct KursunHucre {
	int x;
	int y;
	char karakter;
	YON yon;
};


const int   genislik = 80;
const int   yukseklik = 20;
const int   UcakUzunlugu = 5;
const int   DusmanSirasi = 500;
const int   maxKursunSayisi = 500;
int		    KursunSirasi = 0;
int		    DusmanBuyuklugu = 3;
char	    sahne[genislik][yukseklik];
char	    tuslar[256];
DusmanHucre Dusman[DusmanSirasi][DusmanSirasi];
UcakHucre   Ucak[UcakUzunlugu];
KursunHucre Kursun[maxKursunSayisi];

void ucakOlustur()
{
	for (int i = 0; i < UcakUzunlugu; i++)
	{
		if (i < 3)
		{
			Ucak[i].x = 1 + i;
		}
		else
		{
			Ucak[i].x = 5 - i;
		}
		Ucak[i].y = 7 + i;
		Ucak[i].karakter = 219;
	}
}
void ucakSahneyeYerlestir()
{
	for (int i = 0; i < UcakUzunlugu; i++)
	{
		int x = Ucak[i].x;
		int y = Ucak[i].y;
		sahne[x][y] = 219;
	}
}
void ucakHareketEttir()
{
	if (tuslar['W'] != 0 || tuslar['S'])
	{
		for (int i = 0; i < UcakUzunlugu; i++)
		{
			switch (Ucak[i].yon)
			{
			case YON_YUKARI:
				Ucak[i].y--;
				break;
			case YON_ASAGI:
				Ucak[i].y++;
				break;
			default:
				break;
			}
		}
	}
	else
	{
		return;
	}
	
	
	
}
void KursunOlstur()
{
	if (tuslar['D'] != 0)
	{
		KursunSirasi++;

		Kursun[KursunSirasi].x = Ucak[2].x + 1;
		Kursun[KursunSirasi].y = Ucak[2].y;
		Kursun[KursunSirasi].karakter = 168;
		Kursun[KursunSirasi].yon = YON_SAG;
	}
}
void KursunSahneyeYerlestir()
{
	
		int x = Kursun[KursunSirasi].x;
		int y = Kursun[KursunSirasi].y;
		sahne[x][y] = Kursun[KursunSirasi].karakter;
	
}
void KursunHaraketEttir()
{
	switch (Kursun[KursunSirasi].yon)
	{
	case YON_SAG:
		if (Kursun[KursunSirasi].x < 80)
		{
			Kursun[KursunSirasi].x++;
		}
		else
			return;
	}
}
void DusmanOlustur()
{
	srand(time(NULL));
	int sayi = 3 + rand() % 14;
	for (int i = 0; i < DusmanBuyuklugu; i++)
	{
		for (int j = 0; j < DusmanBuyuklugu; j++)
		{
			Dusman[i][j].x = 78 + j;
			Dusman[i][j].y = sayi + i;
			Dusman[i][j].karakter = 35;
			Dusman[i][j].yon = YON_SOL;
		}
		
	}
	
}

void DusmaniHareketEttir()
{
	for (int i = 0; i < DusmanBuyuklugu; i++)
	{
		for (int j = 0; j < DusmanBuyuklugu; j++)
		{
			if (Dusman[i][j].x > -3)
			{
				Dusman[i][j].x--;
			}
			else
				return;
		}
	}
}

void DusmaniSahneyeYerlestir()
{
	for (int i = 0; i < DusmanBuyuklugu; i++)
	{
		for (int j = 0; j < DusmanBuyuklugu; j++)
		{
			int x = Dusman[i][j].x;
			int y = Dusman[i][j].y;
			sahne[x][y] = Dusman[i][j].karakter;
		}
		
		
	}
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void kursorGizle()
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void sahneyiCiz()
{
	for (int y = 0; y < yukseklik; y++)
	{
		for (int x = 0; x < genislik; x++)
		{
			cout << sahne[x][y];
		}
		cout << endl;
	}
}

void sahneyiTemizle()
{
	for (int y = 0; y < yukseklik; y++)
	{
		for (int x = 0; x < genislik; x++)
		{
			sahne[x][y] = ' ';
		}
	}
}

void sinirlariOlustur()
{
	for (int x = 0; x < genislik; x++)
	{
		sahne[x][0] = 219;
		sahne[x][yukseklik - 1] = 219;
	}
	for (int y = 0; y < yukseklik; y++)
	{
		sahne[0][y] = 219;
		sahne[genislik-1][y] = 219;
	}
}

void klavyeOku(char tuslar[])
{
	for (int x = 0; x < 256; x++)
	{
		tuslar[x] = (char)(GetAsyncKeyState(x) >> 8);
	}
}

void klavyeKontrol()
{
	klavyeOku(tuslar);

	if (tuslar['D'] != 0)
	{
		Kursun[KursunSirasi].yon = YON_SAG;
		//sahne[9][4] = 220;
	}
	if (tuslar['W'] != 0)
	{
		for (int i = 0; i < UcakUzunlugu; i++)
		{
			Ucak[i].yon = YON_YUKARI;
		}
	}
	if (tuslar['S'] != 0)
	{
		for (int i = 0; i < UcakUzunlugu; i++)
		{
			Ucak[i].yon = YON_ASAGI;
		}
	}
}

int main()
{
	sinirlariOlustur();
	kursorGizle();
	DusmanOlustur();
	ucakOlustur();	
	//int i = 0;
	while (true)
	{
		sahneyiTemizle();
		sinirlariOlustur();
		klavyeKontrol();
		//ucakCiz();
		ucakHareketEttir();
		ucakSahneyeYerlestir();
		DusmaniSahneyeYerlestir();
		DusmaniHareketEttir();
		
		if (tuslar['D'] != 0)
		{
			KursunOlstur();
			
		}
		KursunSahneyeYerlestir();
		KursunHaraketEttir();
		
	
		
		gotoxy(0, 0);
		sahneyiCiz();
		Sleep(50);
		//sahne[4 + i][9] = 'a';
		//i+=2;
	}

	cin.get();
}
