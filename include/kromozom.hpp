/**
* @file kromozom.hpp
* @description kromozom işlemlerinin başlık dosyası.
* @course ikinci öğretim C grubu
* @assignment 1.ödev
* @date 04.11.2024
* @author Atalay Muhsin Baysal atalay.baysal@ogr.sakarya.edu.tr G231210036
*/ 
#ifndef kromozom_hpp
#define kromozom_hpp
#include <kromodugum.hpp>
#include <gendugum.hpp>
class kromozom
{
    public:
        void Caprazlama(int index1, int index2);
        void Mutasyon(int kromozomIndex,int degistirelecekGendex);
        void ekranaYaz();
        kromodugum* ilkKromozom;
};

#endif