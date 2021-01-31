/**
* @file test.cpp
* @description arayuzsel kontrol islemleri.kaynak kod
* @course 
* @assignment 3 odev
* @date 21/12/2018
* @author B181210377 Merve Yildizer  B181210378 Sevim Suna Kalayci  
*/

#include <iostream>
#include <string>
#include "BagilListe.hpp"
using namespace std;

BagilListe *bagilListe = new BagilListe();
void bagilListeOlustur(string sayi)
{
	for (int i = 0; i < sayi.length(); i++)
		bagilListe->Ekle((int)sayi[i] - 48);
}
int main()
{
	system("cls");
	string rakam;

	cout << "Sayi Giriniz : ";
	cin >> rakam;
	bagilListeOlustur(rakam);
	int sec = 0;
	BagilListe *liste = new BagilListe();
	do
	{

		system("cls");
		cout << "1. Maximum Sil" << endl;
		cout << "2. Minimum Sil" << endl;
		cout << "3. Level Order" << endl;

		cout << "0. Cikis" << endl;
		cout << "=>";
		cin >> sec;
		switch (sec)
		{
		case 1:
		{
			bagilListe->MaxDugumSil();
			break;
		}
		case 2:
		{
			bagilListe->MinDugumSil();
			break;
		}
		case 3:
		{
			bagilListe->Yazdir();
			break;
		}
		}
		cin.ignore();
		cin.get();
	} while (sec != 9);

	delete liste;
}