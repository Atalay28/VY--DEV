/**
* @file gendugum.cpp
* @description gen düğümlerini yapar.
* @course ikinci öğretim C grubu
* @assignment 1.ödev
* @date 04.11.2024
* @author Atalay Muhsin Baysal atalay.baysal@ogr.sakarya.edu.tr G231210036
*/
#include <gendugum.hpp>
using namespace std;

gendugum::gendugum(char alinacakdeger,int alinacakindex){

    this->genindex=alinacakindex;
    this->genHarf=alinacakdeger;
    sonraki=onceki=nullptr;
}