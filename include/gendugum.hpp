/**
* @file gendugum.hpp
* @description gen düğümlerinin başlık dosyası.
* @course ikinci öğretim C grubu
* @assignment 1.ödev
* @date 04.11.2024
* @author Atalay Muhsin Baysal atalay.baysal@ogr.sakarya.edu.tr G231210036
*/
#ifndef gendugum_hpp
#define gendugum_hpp

class gendugum
{
    public:
        char genHarf;
        int genindex;
        gendugum* sonraki;
        gendugum* onceki;
        gendugum(char alinacakdeger,int alinacakindex);
};

#endif