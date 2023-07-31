/**
* @file BagliListe.cpp
* @course Veri Yapilari 1-A
* @assignment 1.Ödev
* @date 23.07.2023
* @author Mert Eser Meral-G211210047
*/
#include "BagliListe.hpp"
#include <iostream>

BagliListe::BagliListe()
{
    ilk=0;

}
BagliListe::~BagliListe() { //yokedici
    Dugum* current = ilk;
    while (current) {
        Dugum* temp = current;
        current = current->sonraki;
        delete temp;
    }
}
void BagliListe::ekle(int veri) //dugum ekleyen fonksiyon
{
    Dugum *yeni= new Dugum(veri);
    

    if(ilk==0)
    {
        ilk= yeni;
        

    }
    else
    {
        Dugum * gec= ilk;
        while (gec->sonraki!=0)
            gec=gec->sonraki;
            
        gec->sonraki=yeni;
    }
    

}
void BagliListe::degistir(BagliListe& digerListe) {//yer degistiren fonksiyon
    Dugum* tempHead = ilk;
    ilk = digerListe.ilk;
    digerListe.ilk = tempHead;
}
Dugum* BagliListe::dugumAl(int sira) {//ortalama icin istenilen siradaki dugumu getiren fonksiyon
    Dugum* dugum = ilk;
    for (int i = 0; i < sira; i++) {
        if (dugum == nullptr) {
            return nullptr;
        }
        dugum = dugum->sonraki;
    }
    return dugum;
}
int BagliListe::dugumSayisi() { //ortalama icin dugum sayisi veren fonksiyon
    int sayac = 0;
    for (Dugum* dugum = ilk; dugum != nullptr; dugum = dugum->sonraki) {
        sayac++;
    }
    return sayac;
}

