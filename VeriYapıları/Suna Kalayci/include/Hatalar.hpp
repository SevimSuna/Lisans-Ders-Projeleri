/**
* @file Hatalar.cpp
* @description hatalar sinifi. kaynak kod
* @course 
* @assignment 3 odev
* @date 21/12/2018
* @author B181210377 Merve Yildizer  B181210378 Sevim Suna Kalayci 
*/

#ifndef HATALAR_HPP
#define HATALAR_HPP
#include "Hata.hpp"
class ListeSonu : public Hata
{
  public:
	ListeSonu(string msg = "Listenin sonu") : Hata(msg) {}
};

class NullHatasi : public Hata
{
  public:
	NullHatasi(string msg = "NULL hatasi") : Hata(msg) {}
};

class ListeBos : public Hata
{
  public:
	ListeBos(string msg = "Liste bos") : Hata(msg) {}
};

class Tasma : public Hata
{
  public:
	Tasma(string msg = "Tasma hatasi") : Hata(msg) {}
};

class ElemanYok : public Hata
{
  public:
	ElemanYok(string msg = "Listede eleman bulunamadi") : Hata(msg) {}
};
#endif