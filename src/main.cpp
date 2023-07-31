/**
* @file main.cpp
* @course Veri Yapilari 1-A
* @assignment 1.Ödev
* @date 23.07.2023
* @author Mert Eser Meral-G211210047
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include "Dugum.hpp"
#include "BagliListe.hpp"

double ortalamaHesapla(BagliListe*Liste,int satirSayac){ //ortalama hesaplayan fonksiyon.
int maxDugumSayisi = 0;
    for (int i = 0; i < satirSayac; i++) { 
    int dugumSayisi = Liste[i].dugumSayisi();
    if (dugumSayisi > maxDugumSayisi) {
        maxDugumSayisi = dugumSayisi;
    }
    }   
double toplamOrtalama = 0.0;

// Her bir sira için
for (int i = 0; i < maxDugumSayisi; i++) {
    double toplam = 0.0;
    int sayac = 0;

    // Her bir bagli liste için
    for (int j = 0; j < satirSayac; j++) {
        Dugum* dugum = Liste[j].dugumAl(i); // i. siradaki dügümü al

        if (dugum != nullptr) {
            toplam += dugum->degerAl();
            sayac++;
        }
    }

    if (sayac > 0) { //Dügümlerin ortalamasini alip toplayan kisim.
        double ortalama = toplam / sayac;
        toplamOrtalama += ortalama;
    }
}
return toplamOrtalama; //Ortalamalarin toplamini dondurur.

}

using namespace std;
int main() {
    string satir;
    ifstream veriOku("Sayilar.txt"); // Dosya okuma kismi.

    BagliListe* birlerListe = nullptr; // Birler basamagi icin dinamik dizi
    BagliListe* onlarListe = nullptr; // Onlar basamagi icin dinamik dizi
    int satirSayac = 0;

    while (getline(veriOku, satir)) {//Dosya okunup bagli listeler olusturuluyor.
        int num;
        istringstream iss(satir);
        BagliListe* tempBirlerListe = birlerListe;
        BagliListe* tempOnlarListe = onlarListe;

        birlerListe = new BagliListe[satirSayac + 1];
        onlarListe = new BagliListe[satirSayac + 1];

        while (iss >> num) {
            birlerListe[satirSayac].ekle(num % 10); // Birler basamagi
            onlarListe[satirSayac].ekle(num / 10); // Onlar basamagi
        }

        for (int i = 0; i < satirSayac; i++) {
            birlerListe[i].degistir(tempBirlerListe[i]);
            onlarListe[i].degistir(tempOnlarListe[i]);
        }

        delete[] tempBirlerListe;
        delete[] tempOnlarListe;
        satirSayac++;
    }
    veriOku.close();

    int konumA, konumB;
    cout << "Konum A: "; //kullanicidan indeks aliniyor.
    cin >> konumA;
    cout << "Konum B: ";
    cin >> konumB;

    if (konumA < 0 || konumA >= satirSayac || konumB < 0 || konumB >= satirSayac) {//Hatali indeks girisi olursa uyari veren kisim.
        cerr << "Hatali indeks girildi." << endl;

        // Bellek temizleme
        delete[] onlarListe;
        delete[] birlerListe;

        return 1;
    }
    onlarListe[konumA].degistir(birlerListe[konumB]);   //Degistir fonksiyonu ile girilen verilere göre bagli listeler yer degistiriyor.
    cout << "Ust: "<< ortalamaHesapla(onlarListe,satirSayac) << endl;
    cout << "Alt: "<< ortalamaHesapla(birlerListe,satirSayac) <<endl;
   
    // Bellek temizleme
    delete[] onlarListe;
    delete[] birlerListe;

    return 0;
}