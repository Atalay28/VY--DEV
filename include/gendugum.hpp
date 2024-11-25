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
        ~gendugum();
};

#endif