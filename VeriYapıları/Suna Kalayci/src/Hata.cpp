/**
* @file Hata.hpp
* @description hata sinifi. prototip kod
* @course 
* @assignment 3 odev
* @date 21/12/2018
* @author B181210377 Merve Yildizer  B181210378 Sevim Suna Kalayci 
*/

#include "Hata.hpp"

Hata::Hata(string msg)
{
	mesaj = msg;
}
string Hata::Mesaj() const
{
	return mesaj;
}