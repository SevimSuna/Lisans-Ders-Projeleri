/**
* @file BagilListe.cpp
* @description İkili Arama Agaclari arasinda tek yonlu bagil liste olusturur . kaynak kod
* @course 
* @assignment 3 odev
* @date 21/12/2018
* @author B181210377 Merve Yildizer  B181210378 Sevim Suna Kalayci 
*/
#include "BagilListe.hpp"

ListeGezici BagilListe::OncekiniKonumuIleBul(int konum) const throw(Tasma)
{
	if (konum < 0 || konum > Uzunluk())
		throw Tasma();
	int indeks = 0;
	ListeGezici gezici(basDugum);

	while (!gezici.SonaGeldimi() && konum != indeks++)
		gezici.ilerle();
	return gezici;
}

ListeGezici BagilListe::Ilk() const throw(ListeBos)
{
	if (Bosmu())
		throw ListeBos();
	return ListeGezici(basDugum->ileri);
}

BagilListe::BagilListe()
{
	srand(time(0));
	basDugum = new BinarySearchTree();
	elemanSayisi = 0;
}
bool BagilListe::Bosmu() const
{
	return basDugum->ileri == NULL;
}
int BagilListe::Uzunluk() const
{
	return elemanSayisi;
}
void BagilListe::Yazdir()
{
	ListeGezici listeGezici = Ilk();
	for (; !listeGezici.SonaGeldimi(); listeGezici.ilerle())
	{
		listeGezici.simdiki->Levelorder();
		cout << "\n";
	}
}

const BinarySearchTree *BagilListe::IlkEleman() const throw(ListeBos)
{
	if (Bosmu())
		throw ListeBos();
	return basDugum->ileri;
}

const BinarySearchTree *BagilListe::SonEleman() const throw(ListeBos)
{
	if (Bosmu())
		throw ListeBos();
	return OncekiniKonumuIleBul(elemanSayisi).Getir();
}

void BagilListe::Ekle(const int &yeni)
{
	Ekle(yeni, Uzunluk());
}

void BagilListe::Ekle(const int &yukseklik, int konum) throw(Tasma)
{

	ListeGezici gezici;
	try
	{
		gezici = OncekiniKonumuIleBul(konum);
	}
	catch (Tasma ts)
	{
		throw ts;
	}
	gezici.simdiki->ileri = new BinarySearchTree(gezici.simdiki->ileri);

	while (gezici.simdiki->ileri->Yukseklik() < yukseklik)
	{
		int sayi = (rand() % 500) + 1;
		gezici.simdiki->ileri->Ekle(sayi);
	}
	elemanSayisi++;
}

void BagilListe::MinDugumSil()
{
	if (Bosmu())
	{
		cout << "Bos";
	}
	else
	{

		ListeGezici gezici = Ilk();
		int deger = gezici.simdiki->minValue();
		BinarySearchTree *agac = gezici.simdiki;
		for (; !gezici.SonaGeldimi(); gezici.ilerle())
		{
			if (deger > gezici.simdiki->minValue())
			{
				deger = gezici.simdiki->minValue();
				agac = gezici.simdiki;
			}
		}
		if (agac->Yukseklik() > 1)
		{
			agac->Sil(deger);
		}
		else
		{
			agac->Sil(deger);

			Sil(agac);
		}
		agac = NULL;
	}
}

void BagilListe::MaxDugumSil()
{
	if (Bosmu())
	{
		cout << "Bos";
	}
	else
	{

		ListeGezici gezici = Ilk();
		int deger = gezici.simdiki->maxValue();
		BinarySearchTree *agac = gezici.simdiki;
		for (; !gezici.SonaGeldimi(); gezici.ilerle())
		{
			if (deger < gezici.simdiki->minValue())
			{
				deger = gezici.simdiki->minValue();
				agac = gezici.simdiki;
			}
		}
		if (agac->Yukseklik() > 1)
		{
			agac->Sil(deger);
		}
		else
		{
			agac->Sil(deger);

			Sil(agac);
		}
		agac = NULL;
	}
}

void BagilListe::Sil(const BinarySearchTree *aranan) throw(ElemanYok)
{
	try
	{
		int konum = KonumuBul(aranan);
		KonumdakiniSil(konum);
	}
	catch (ElemanYok ey)
	{
		throw ey;
	}
}
void BagilListe::KonumdakiniSil(int konum) throw(Tasma)
{
	ListeGezici onceki;
	try
	{
		onceki = OncekiniKonumuIleBul(konum);
	}
	catch (Tasma ts)
	{
		throw ts;
	}
	if (onceki.simdiki->ileri != NULL)
	{
		BinarySearchTree *eskiDugum = onceki.simdiki->ileri;

		onceki.simdiki->ileri = onceki.simdiki->ileri->ileri;
		delete eskiDugum;
		elemanSayisi--;
	}
}
bool BagilListe::ElemanBul(BinarySearchTree *aranan) const
{
	for (ListeGezici gezici(basDugum->ileri); !gezici.SonaGeldimi(); gezici.ilerle())
	{
		if (gezici.simdiki == aranan)
			return true;
	}
	return false;
}
int BagilListe::KonumuBul(const BinarySearchTree *aranan) const throw(ElemanYok)
{
	int indeks = 0;
	for (ListeGezici gezici(basDugum->ileri); !gezici.SonaGeldimi(); gezici.ilerle())
	{
		if (gezici.simdiki == aranan)
			return indeks;
		indeks++;
	}
	throw ElemanYok();
}

void BagilListe::Temizle()
{
	while (!Bosmu())
		Sil(Ilk().Getir());
}
BagilListe::~BagilListe()
{
	Temizle();
	delete basDugum;
}
