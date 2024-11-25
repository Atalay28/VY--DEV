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

//alttaki silinecek
void kromodugum::ekranaYazdir() const{
    gendugum* simdikiHarf=ilkgen;
    while (simdikiHarf !=nullptr){
        cout<<"("<<simdikiHarf->genindex<<": "<<simdikiHarf->genHarf<<")";
        simdikiHarf=simdikiHarf->sonraki;
    }
    cout<<endl;
}

kromodugum::~kromodugum(){
    
}