/*******************************************
** SAKARYA �N�VERS�TES�
** B�LG�SAYAR VE B�L���M B�L�MLER� FAKULTES�
** B�LG�SYAR M�HEND�SL��� B�L�M�
** PROGRAMLAMAYA G�R�� DERS�
** 1. �DEV
** SEV�M SUNA KALAYCI
** B181210378
** 2. ��RET�M D GRUBU
********************************************/

#include "pch.h"
#include <iostream>

using namespace std;
int main()
{
	int satir, sutun;
	for (satir = 0; satir <= 10; satir++)//Matrisimizi olu�turduk.
	{
		for (sutun = 0; sutun <= 10; sutun++)
		{
			if (satir == 1 || satir == 9) //Benzer y�ntemler oldu�u i�in 2. sat�r ile sonun sat�r� ayn� �ekilde kar��la�t�r�p bo�luk istedi�imiz yerleri belirttik.
			{
				if (sutun > 3 && sutun < 7)
				{
					cout << " "; //Bo�luk olan noktalar� belirledik.
				}
				else
				{
					cout << "*";//Sat�r�n kalan� y�ld�z dedik.

				}
			}
			else if (satir == 2 || satir == 8)// Ayn� �eyleri di�er sat�rlar i�in tekrarlad�k.
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
				cout << "*";//Bo�luk noktalar�n� belirledi�imiz i�in kalan yerlere y�ld�z koyduk.
			}
		}
		cout << endl;//Her sat�r� bitirdikten sonra bir alt sat�ra indik.
	}
	system("pause");

}

