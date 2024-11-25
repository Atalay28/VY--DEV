#include <gendugum.hpp>
using namespace std;

gendugum::gendugum(char alinacakdeger,int alinacakindex){

    this->genindex=alinacakindex;
    this->genHarf=alinacakdeger;
    sonraki=onceki=nullptr;
}

gendugum::~gendugum(){
}