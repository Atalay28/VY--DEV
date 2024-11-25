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
        //alttaki silinecek
        void ekranaYazdir() const;
        ~kromodugum();
};

#endif