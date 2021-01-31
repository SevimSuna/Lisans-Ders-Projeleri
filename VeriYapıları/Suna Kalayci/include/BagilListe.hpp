/**
* @file BagilListe.hpp
* @description İkili Arama Agaclari arasinda tek yonlu bagil liste olusturur .prototip kod
* @course 
* @assignment 3 odev
* @date 21/12/2018
* @author B181210377 Merve Yildizer  B181210378 Sevim Suna Kalayci 
*/
#ifndef BAGILLISTE_HPP
#define BAGILLISTE_HPP

#include "ListeGezici.hpp"
#include "BinarySearchTree.hpp"
#include <ctime>
class BagilListe
{
  private:
	BinarySearchTree *basDugum;
	int elemanSayisi;
	ListeGezici OncekiniKonumuIleBul(int konum) const throw(Tasma);
	ListeGezici Ilk() const throw(ListeBos);

  public:
	BagilListe();
	bool Bosmu() const;
	int Uzunluk() const;
	void Yazdir();
	const BinarySearchTree *IlkEleman() const throw(ListeBos);
	const BinarySearchTree *SonEleman() const throw(ListeBos);
	void Ekle(const int &yeni);
	void Ekle(const int &yukseklik, int konum) throw(Tasma);
	void MinDugumSil();
	void MaxDugumSil();
	void Sil(const BinarySearchTree *aranan) throw(ElemanYok);
	void KonumdakiniSil(int konum) throw(Tasma);
	bool ElemanBul(BinarySearchTree *aranan) const;
	int KonumuBul(const BinarySearchTree *aranan) const throw(ElemanYok);
	void Temizle();
	~BagilListe();
};
#endif