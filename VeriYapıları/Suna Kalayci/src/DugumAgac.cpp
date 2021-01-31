
/**
* @file DugumAgac.cpp
* @description İkili Arama Agaci icerisindeki dugumler icin gerekli sinif. kaynak kod
* @course 
* @assignment 3 odev
* @date 21/12/2018
* @author B181210377 Merve Yildizer  B181210378 Sevim Suna Kalayci 
*/
#include "DugumAgac.hpp"

DugumAgac::DugumAgac(const int &vr, DugumAgac *sl, DugumAgac *sg)
{
	veri = vr;
	sol = sl;
	sag = sg;
};
