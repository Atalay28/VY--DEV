#include <kromozom.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

void kromozom::HafizaTazeleme(){
    ofstream yazici("Dnagecici.txt");
    if(!yazici)
    cout<<"yazici acilamadi"<<endl;
    kromodugum* geciciKr=ilkKromozom;
    while(geciciKr!=nullptr){
        gendugum* geciciGen=geciciKr->ilkgen;
        while(geciciGen!=nullptr){
            yazici<<geciciGen->genHarf<<' ';
            if(geciciGen->sonraki==nullptr)
                yazici<<endl;
                geciciGen=geciciGen->sonraki;
            }
        geciciKr=geciciKr->sonrakikromo;
    }
    yazici.close();
    remove("Dna.txt");
    rename("Dnagecici.txt","Dna.txt");
}
void kromozom::Caprazlama(int index1,int index2){
    kromodugum* birinciKromozom= ilkKromozom;
    kromodugum* ikinciKromozom=ilkKromozom;
    kromodugum* sonKromozom=ilkKromozom;

    while((birinciKromozom->kromozomindex)!=index1){
        if(birinciKromozom->sonrakikromo==nullptr){
            cout<<"1. girilen index yoktur"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
             return;}
        birinciKromozom=birinciKromozom->sonrakikromo;
    }
    while(ikinciKromozom->kromozomindex!=index2){
        if(ikinciKromozom->sonrakikromo==nullptr){
            cout<<"2. girilen index yoktur"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
             return;}
        ikinciKromozom=ikinciKromozom->sonrakikromo;
    }
    while(sonKromozom->sonrakikromo!=nullptr){
        sonKromozom=sonKromozom->sonrakikromo;
    }
    int yeni1Index= sonKromozom->kromozomindex + 1;
    int yeni2Index=sonKromozom->kromozomindex + 2;
    kromodugum* yeni1=new kromodugum(yeni1Index);
    kromodugum* yeni2=new kromodugum(yeni2Index);

    bool k1cif=(birinciKromozom->gensayisi%2==0);
    bool k2cif=(ikinciKromozom->gensayisi%2==0);

    gendugum* genBirinci=birinciKromozom->ilkgen;
    gendugum* genIkinci=ikinciKromozom->ilkgen;
    gendugum* genYeni1=yeni1->ilkgen;
    gendugum* genYeni2=yeni2->ilkgen;

    for(int i=1;i<=birinciKromozom->gensayisi;i++){
        if(k1cif){
            if(i<=birinciKromozom->gensayisi/2){
                yeni1->harfEkle(genBirinci->genHarf);
            }
            if(i>birinciKromozom->gensayisi/2){
                yeni2->harfEkle(genBirinci->genHarf);
            }                
            genBirinci=genBirinci->sonraki;

        }
        else{
            if(i<ceil(static_cast<double>(birinciKromozom->gensayisi)/2)){
                yeni1->harfEkle(genBirinci->genHarf);
            }
            if(i>ceil(static_cast<double>(birinciKromozom->gensayisi)/2)){
                yeni2->harfEkle(genBirinci->genHarf);
            }
            genBirinci=genBirinci->sonraki;
        }
    }
    for(int i=1;i<=ikinciKromozom->gensayisi;i++){
        if(k2cif){
            if(i<=ikinciKromozom->gensayisi/2){
                yeni2->harfEkle(genIkinci->genHarf);
            }
            if(i>birinciKromozom->gensayisi/2){
                yeni1->harfEkle(genIkinci->genHarf);
            }                
            genIkinci=genIkinci->sonraki;

        }
        else{
            if(i<ceil(static_cast<double>(birinciKromozom->gensayisi)/2)){
                yeni2->harfEkle(genIkinci->genHarf);
            }
            if(i>ceil(static_cast<double>(birinciKromozom->gensayisi)/2)){
                yeni1->harfEkle(genIkinci->genHarf);
            }
            genIkinci=genIkinci->sonraki;
        }
    }
    sonKromozom->sonrakikromo=yeni1;
    yeni1->sonrakikromo=yeni2;
}

void kromozom::Mutasyon(int kromozomIndex,int degistirelecekGendex){
    kromodugum* geciciKromozom =ilkKromozom;
        while(geciciKromozom->kromozomindex!=kromozomIndex){
            if(geciciKromozom->sonrakikromo==nullptr){
                cout<<"Girilen index bir kromozom belirtmiyor."<<endl;
                return;
            }else{
                geciciKromozom=geciciKromozom->sonrakikromo;
            }
        }
        gendugum* geciciGen=geciciKromozom->ilkgen;
        while(geciciGen->genindex!=degistirelecekGendex){
            if(geciciGen->sonraki==nullptr){
                cout<<"Kromozomda girilen index'te gen bulunmamakta"<<endl;
                return;
            }
            else{
                geciciGen=geciciGen->sonraki;
            }
        }
       geciciGen->genHarf='X';
}

void kromozom::ekranaYaz(){
    kromodugum* yazilacakKromozom=new kromodugum(-1);
    kromodugum* islemKromozomu=ilkKromozom;
    while(islemKromozomu!=nullptr){
    gendugum* islemgen=islemKromozomu->ilkgen;
        while(islemgen->sonraki!=nullptr){
            islemgen=islemgen->sonraki;;
        }
        while(islemgen->onceki!=nullptr){
            if(islemgen->genHarf<islemKromozomu->ilkgen->genHarf){
                yazilacakKromozom->harfEkle(islemgen->genHarf);
                break;
            }
            islemgen=islemgen->onceki;
            if(islemgen->onceki==nullptr){
                yazilacakKromozom->harfEkle(islemgen->genHarf);
            }
        }
        islemKromozomu=islemKromozomu->sonrakikromo;
    }
    gendugum* yeniIslem=yazilacakKromozom->ilkgen;
    while(yeniIslem!=nullptr){
        cout<<yeniIslem->genHarf<<' ';
        yeniIslem=yeniIslem->sonraki;
    }
    cout<<endl;
    delete yazilacakKromozom;
    delete yeniIslem;
}
