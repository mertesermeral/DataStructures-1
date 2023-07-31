/**
* @file Dugum.hpp
* @course Veri Yapilari 1-A
* @assignment 1.Ödev
* @date 23.07.2023
* @author Mert Eser Meral-G211210047
*/
#ifndef Dugum_hpp
#define Dugum_hpp

class Dugum
{
public:
    Dugum(int veri); 
    int veri;
    Dugum* sonraki;
    int degerAl();
    
};
#endif