/**
* @file Hata.cpp
* @description hata sinifi. kaynak kod
* @course 
* @assignment 3 odev
* @date 21/12/2018
* @author B181210377 Merve Yildizer  B181210378 Sevim Suna Kalayci 
*/

#ifndef HATA_HPP
#define HATA_HPP

#include <iostream>
using namespace std;
class Hata
{
  private:
	string mesaj;

  public:
	Hata(string);
	string Mesaj() const;
};
#endif