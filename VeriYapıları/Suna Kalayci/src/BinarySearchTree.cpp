/**
* @file BinarySearchTree.cpp
* @description İkili Arama Agaci uzerinden ekle sil gibi islemler yapar. kaynak kod
* @course 
* @assignment 3 odev
* @date 21/12/2018
* @author B181210377 Merve Yildizer  B181210378 Sevim Suna Kalayci 
*/

#include "BinarySearchTree.hpp"

void BinarySearchTree::AraveEkle(DugumAgac *&alt_Dugum, const int &yeni)
{
	if (alt_Dugum == NULL)
		alt_Dugum = new DugumAgac(yeni);
	else if (yeni < alt_Dugum->veri)
		AraveEkle(alt_Dugum->sol, yeni);
	else if (yeni > alt_Dugum->veri)
		AraveEkle(alt_Dugum->sag, yeni);
	else
		return;
}
bool BinarySearchTree::AraveSil(DugumAgac *&alt_Dugum, const int &yeni)
{
	if (alt_Dugum == NULL)
		return false;
	if (alt_Dugum->veri == yeni)
		return DugumSil(alt_Dugum);
	else if (yeni < alt_Dugum->veri)
		return AraveSil(alt_Dugum->sol, yeni);
	else
		return AraveSil(alt_Dugum->sag, yeni);
}
bool BinarySearchTree::DugumSil(DugumAgac *&alt_Dugum)
{
	DugumAgac *silinecekDugum = alt_Dugum;

	if (alt_Dugum->sag == NULL)
		alt_Dugum = alt_Dugum->sol;
	else if (alt_Dugum->sol == NULL)
		alt_Dugum = alt_Dugum->sag;
	else
	{
		silinecekDugum = alt_Dugum->sol;
		DugumAgac *ebeveynDugum = alt_Dugum;
		while (silinecekDugum->sag != NULL)
		{
			ebeveynDugum = silinecekDugum;
			silinecekDugum = silinecekDugum->sag;
		}
		alt_Dugum->veri = silinecekDugum->veri;
		if (ebeveynDugum == alt_Dugum)
			alt_Dugum->sol = silinecekDugum->sol;
		else
			ebeveynDugum->sag = silinecekDugum->sol;
	}
	delete silinecekDugum;
	return true;
}
void BinarySearchTree::Inorder(DugumAgac *alt_Dugum) const
{
	if (alt_Dugum != NULL)
	{
		Inorder(alt_Dugum->sol);
		cout << alt_Dugum->veri << " ";
		Inorder(alt_Dugum->sag);
	}
}

void BinarySearchTree::Preorder(DugumAgac *alt_Dugum) const
{
	if (alt_Dugum != NULL)
	{
		cout << alt_Dugum->veri << " ";
		Preorder(alt_Dugum->sol);
		Preorder(alt_Dugum->sag);
	}
}
void BinarySearchTree::Postorder(DugumAgac *alt_Dugum) const
{
	if (alt_Dugum != NULL)
	{
		Postorder(alt_Dugum->sol);
		Postorder(alt_Dugum->sag);
		cout << alt_Dugum->veri << " ";
	}
}
void BinarySearchTree::SeviyeyiYazdir(DugumAgac *alt_Dugum, int seviye) const
{
	if (alt_Dugum == NULL)
		return;
	if (seviye == 0)
		cout << alt_Dugum->veri << " ";
	else
	{
		SeviyeyiYazdir(alt_Dugum->sol, seviye - 1);
		SeviyeyiYazdir(alt_Dugum->sag, seviye - 1);
	}
}
int BinarySearchTree::Yukseklik(DugumAgac *alt_Dugum) const
{
	if (alt_Dugum == NULL)
		return -1;
	return 1 + max(Yukseklik(alt_Dugum->sol), Yukseklik(alt_Dugum->sag));
}
bool BinarySearchTree::Ara(DugumAgac *alt_Dugum, const int &aranan)
{
	if (alt_Dugum == NULL)
		return false;
	if (alt_Dugum->veri == aranan)
		return true;
	if (aranan < alt_Dugum->veri)
		return Ara(alt_Dugum->sol, aranan);
	if (aranan > alt_Dugum->veri)
		return Ara(alt_Dugum->sag, aranan);
}

BinarySearchTree::BinarySearchTree(BinarySearchTree *ileri)
{
	root = NULL;
	this->ileri = ileri;
}
int BinarySearchTree::minValue()
{
	DugumAgac *current = root;

	while (current->sol != NULL)
	{
		current = current->sol;
	}
	return (current->veri);
}
int BinarySearchTree::maxValue()
{
	return getMax(root);
}
int BinarySearchTree::getMax(DugumAgac *current)
{
	if (current->sag == NULL)
	{
		return current->veri;
	}
	else
	{
		return getMax(current->sag);
	}
}
bool BinarySearchTree::Bosmu() const
{
	return root == NULL;
}
void BinarySearchTree::Ekle(const int &yeni)
{
	AraveEkle(root, yeni);
}
void BinarySearchTree::Sil(const int &veri) throw(ElemanYok)
{
	if (AraveSil(root, veri) == false)
		throw ElemanYok();
}
void BinarySearchTree::Inorder() const
{
	Inorder(root);
}
void BinarySearchTree::Preorder() const
{
	Preorder(root);
}
void BinarySearchTree::Postorder() const
{
	Postorder(root);
}
void BinarySearchTree::Levelorder() const
{
	int h = Yukseklik();
	for (int level = 0; level <= h; level++)
		SeviyeyiYazdir(root, level);
}
bool BinarySearchTree::Arama(const int &aranan)
{
	return Ara(root, aranan);
}
void BinarySearchTree::Temizle()
{
	while (!Bosmu())
		DugumSil(root);
}
int BinarySearchTree::Yukseklik() const
{
	return Yukseklik(root);
}
BinarySearchTree::~BinarySearchTree()
{
	Temizle();
}
