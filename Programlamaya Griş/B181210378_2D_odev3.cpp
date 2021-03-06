#include "pch.h"
#include <iostream>

using namespace std;

int cekirdekBoyutu;
int cekirdek[15][15];
int kaymaMiktari;

struct Islem {
	int giris[5][5] = { 3,2,5,1,4,
					   6,2,1,0,7,
					   3,0,0,2,0,
					   1,1,3,2,2,
					   0,3,1,0,0 };
	int girisBoyut = 5;
	float cikisSutun;
	float cikisSatir;
	int cikis[100][100];

};

int sonucMatris();

int main()
{
	Islem yeniMatris;
	cout << "Cekirdek boyutunu giriniz: "; cin >> cekirdekBoyutu;
	cout << "Kayma miktarini giriniz: "; cin >> kaymaMiktari;

	if (kaymaMiktari > yeniMatris.girisBoyut)
	{
		cout << "Bu islem yapilamaz.";
		return 0;
	}
	else if ((yeniMatris.girisBoyut - cekirdekBoyutu) % kaymaMiktari != 0)
	{
		cout << "Bu islem yapilamaz!";
		return 0;
	}
	else if ((yeniMatris.girisBoyut - cekirdekBoyutu) % kaymaMiktari == 0)
	{
		for (int i = 0; i < cekirdekBoyutu; i++)
		{
			for (int j = 0; j < cekirdekBoyutu; j++)
			{
				cout << "Cekirdek[" << i << "][" << j << "]"; cin >> cekirdek[i][j];
			}
		}
		sonucMatris();
	}

	system("pause");
}

int sonucMatris()
{
	Islem matris;
	matris.cikisSatir = ((matris.girisBoyut - cekirdekBoyutu) / kaymaMiktari) + 1;
	matris.cikisSutun = ((matris.girisBoyut - cekirdekBoyutu) / kaymaMiktari) + 1;



	int sayac1 = 0;
	int sayac2 = 0;
	for (int i = 0; i < matris.cikisSatir; i++)
	{
		for (int j = 0; j < matris.cikisSutun; j++)
		{
			int toplam = 0;
			for (int k = 0; k < cekirdekBoyutu; k++)
			{
				for (int l = 0; l < cekirdekBoyutu; l++)
				{
					toplam += (matris.giris[i + k+sayac2][j + l + sayac1] * cekirdek[k][l]);

				}
			}
			matris.cikis[i][j] = toplam;
			cout << matris.cikis[i][j] << "\t";
			sayac1 += (kaymaMiktari-1);

		}
		cout << endl;
		sayac2 += (kaymaMiktari - 1);
		sayac1 = 0;
	}
	return 0;


}