/**
* @file kromodugum.cpp
* @description kromozomları düğüm yapar.
* @course ikinci öğretim C grubu
* @assignment 1.ödev
* @date 04.11.2024
* @author Atalay Muhsin Baysal atalay.baysal@ogr.sakarya.edu.tr G231210036
*/
#include <kromodugum.hpp>
#include <iostream>
using namespace std;


kromodugum::kromodugum(int index)
{
    this->kromozomindex=index;
    sonrakikromo=0;
    ilkgen=nullptr;
    gensayisi=0;
}

void kromodugum::harfEkle(char harf){
    int harfIndex=gensayisi;
    gensayisi++;
    
    gendugum* yeniHarf = new gendugum(harf,harfIndex); 
    if(ilkgen==nullptr){
        ilkgen=yeniHarf;
    }
    else{
        gendugum* gecici = ilkgen;
        while(gecici->sonraki !=nullptr){
            gecici=gecici->sonraki;
        }
        gecici->sonraki=yeniHarf;
        yeniHarf->onceki=gecici;
    }
}
