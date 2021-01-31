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
	int satir, sutun;
	for (satir = 0; satir <= 10; satir++)//Matrisimizi oluþturduk.
	{
		for (sutun = 0; sutun <= 10; sutun++)
		{
			if (satir == 1 || satir == 9) //Benzer yöntemler olduðu için 2. satýr ile sonun satýrý ayný þekilde karþýlaþtýrýp boþluk istediðimiz yerleri belirttik.
			{
				if (sutun > 3 && sutun < 7)
				{
					cout << " "; //Boþluk olan noktalarý belirledik.
				}
				else
				{
					cout << "*";//Satýrýn kalaný yýldýz dedik.

				}
			}
			else if (satir == 2 || satir == 8)// Ayný þeyleri diðer satýrlar için tekrarladýk.
			{
				if (sutun > 2 && sutun < 8)
				{
					cout << " ";
				}
				else
				{
					cout << "*";
				}
			}
			else if (satir == 3 || satir == 7)
			{
				if (sutun > 1 && sutun < 9)
				{
					cout << " ";
				}
				else
				{
					cout << "*";
				}
			}
			else if (satir == 4 || satir == 6)
			{
				if (sutun > 0 && sutun < 10)
				{
					cout << " ";
				}
				else
				{
					cout << "*";
				}
			}
			else if (sutun == 5 || satir == 5)
			{
				cout << " ";
			}
			else
			{
				cout << "*";//Boþluk noktalarýný belirlediðimiz için kalan yerlere yýldýz koyduk.
			}
		}
		cout << endl;//Her satýrý bitirdikten sonra bir alt satýra indik.
	}
	system("pause");

}

