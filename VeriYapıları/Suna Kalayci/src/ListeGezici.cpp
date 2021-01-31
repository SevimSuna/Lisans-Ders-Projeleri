/**
* @file ListeGezici.cpp
* @description bagil liste icerisindeki dugumler gezinmek icin gerekli sinif. kaynak kod
* @course 
* @assignment 3 odev
* @date 21/12/2018
* @author B181210377 Merve Yildizer  B181210378 Sevim Suna Kalayci 
*/
#include "ListeGezici.hpp"

ListeGezici::ListeGezici()
{
	simdiki = NULL;
}
ListeGezici::ListeGezici(BinarySearchTree *dugum)
{
	simdiki = dugum;
}
bool ListeGezici::SonaGeldimi() const
{
	return simdiki == NULL;
}
void ListeGezici::ilerle() throw(ListeSonu)
{
	if (SonaGeldimi())
		throw ListeSonu();
	simdiki = simdiki->ileri;
}
const BinarySearchTree *ListeGezici::Getir() const throw(NullHatasi)
{
	if (simdiki == NULL)
		throw NullHatasi();
	return simdiki;
}
