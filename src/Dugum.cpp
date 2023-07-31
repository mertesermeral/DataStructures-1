/**
* @file Dugum.cpp
* @course Veri Yapilari 1-A
* @assignment 1.Ödev
* @date 23.07.2023
* @author Mert Eser Meral-G211210047
*/
#include "Dugum.hpp"

Dugum::Dugum(int veri)
{
    this->veri = veri;
    this->sonraki = nullptr;
}
int Dugum::degerAl() { //dugum verisini dondurur.
    return veri;
}