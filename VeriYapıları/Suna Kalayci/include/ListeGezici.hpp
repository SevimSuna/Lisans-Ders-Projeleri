/**
* @file ListeGezici.hpp
* @description bagil liste icerisindeki dugumler gezinmek icin gerekli sinif. prototip kod
* @course 
* @assignment 3 odev
* @date 21/12/2018
* @author B181210377 Merve Yildizer  B181210378 Sevim Suna Kalayci 
*/
#ifndef LISTEGEZICI_HPP
#define LISTEGEZICI_HPP

#include "Hatalar.hpp"
#include "BinarySearchTree.hpp"
class ListeGezici
{
  public:
	BinarySearchTree *simdiki;
	ListeGezici();
	ListeGezici(BinarySearchTree *dugum);
	bool SonaGeldimi() const;
	void ilerle() throw(ListeSonu);
	const BinarySearchTree *Getir() const throw(NullHatasi);
};
#endif