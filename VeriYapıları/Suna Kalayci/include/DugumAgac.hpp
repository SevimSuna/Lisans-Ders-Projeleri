/**
* @file DugumAgac.hpp
* @description İkili Arama Agaci icerisindeki dugumler icin gerekli sinif. prototip kod
* @course 
* @assignment 3 odev
* @date 21/12/2018
* @author B181210377 Merve Yildizer  B181210378 Sevim Suna Kalayci  
*/
#ifndef DUGUMAGAC_HPP
#define DUGUMAGAC_HPP

#include <iostream>
using namespace std;

class DugumAgac
{
public:
	int veri;
	DugumAgac *sol;
	DugumAgac *sag;
	DugumAgac(const int &vr, DugumAgac *sl = NULL, DugumAgac *sg = NULL);
};
#endif