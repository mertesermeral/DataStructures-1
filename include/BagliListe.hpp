/**
* @file BagliListe.hpp
* @course Veri Yapilari 1-A
* @assignment 1.Ödev
* @date 23.07.2023
* @author Mert Eser Meral-G211210047
*/
#ifndef BagliListe_hpp
#define BagliListe_hpp
#include "Dugum.hpp"
class BagliListe {
public:
    BagliListe();
    ~BagliListe();
    void ekle(int veri);
    void degistir(BagliListe& digerListe);
    Dugum*ilk;
    Dugum* dugumAl(int sira);
    int dugumSayisi();
    

private:
};

#endif 
