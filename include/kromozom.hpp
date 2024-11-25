#ifndef kromozom_hpp
#define kromozom_hpp
#include <kromodugum.hpp>
#include <gendugum.hpp>
class kromozom
{
    public:
        void HafizaTazeleme();
        void Caprazlama(int index1, int index2);
        void Mutasyon(int kromozomIndex,int degistirelecekGendex);
        void ekranaYaz();
        kromodugum* ilkKromozom;
};

#endif