/**
* @file kromodugum.hpp
* @description kromozom düğümlerinin başlık dosyası.
* @course ikinci öğretim C grubu
* @assignment 1.ödev
* @date 04.11.2024
* @author Atalay Muhsin Baysal atalay.baysal@ogr.sakarya.edu.tr G231210036
*/
#ifndef kromodugum_hpp
#define kromodugum_hpp
#include <gendugum.hpp>

class kromodugum
{
    public:
        gendugum* ilkgen;
        kromodugum* sonrakikromo;
        int gensayisi;
        int kromozomindex;
        kromodugum(int index);
        void harfEkle(char harf);
};

#endif