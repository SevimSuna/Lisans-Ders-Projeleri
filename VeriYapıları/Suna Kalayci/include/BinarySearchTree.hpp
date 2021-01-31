/**
* @file BinarySearchTree.hpp
* @description İkili Arama Agaci uzerinden ekle sile gibi islemler yapar. prototip kod
* @course 
* @assignment 3 odev
* @date 21/12/2018
* @author B181210377 Merve Yildizer  B181210378 Sevim Suna Kalayci 
*/

#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include "DugumAgac.hpp"
#include <cmath>
#include "Hatalar.hpp"
class BinarySearchTree
{
  private:
	DugumAgac *root;

	void AraveEkle(DugumAgac *&alt_Dugum, const int &yeni);
	bool AraveSil(DugumAgac *&alt_Dugum, const int &yeni);
	bool DugumSil(DugumAgac *&alt_Dugum);
	void Inorder(DugumAgac *alt_Dugum) const;

	void Preorder(DugumAgac *alt_Dugum) const;
	void Postorder(DugumAgac *alt_Dugum) const;
	void SeviyeyiYazdir(DugumAgac *alt_Dugum, int seviye) const;
	int Yukseklik(DugumAgac *alt_Dugum) const;
	bool Ara(DugumAgac *alt_Dugum, const int &aranan);

  public:
	BinarySearchTree *ileri;
	BinarySearchTree(BinarySearchTree *ileri = NULL);
	int minValue();
	int maxValue();
	int getMax(DugumAgac *current);
	bool Bosmu() const;
	void Ekle(const int &yeni);
	void Sil(const int &veri) throw(ElemanYok);
	void Inorder() const;
	void Preorder() const;
	void Postorder() const;
	void Levelorder() const;
	bool Arama(const int &aranan);
	void Temizle();
	int Yukseklik() const;
	~BinarySearchTree();
};

#endif