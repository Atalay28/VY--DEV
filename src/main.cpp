/**
* @file main.cpp
* @description programı çalıştırır.
* @course ikinci öğretim C grubu
* @assignment 1.ödev
* @date 04.11.2024
* @author Atalay Muhsin Baysal atalay.baysal@ogr.sakarya.edu.tr G231210036
*/

#include <iostream>
#include <fstream>
#include <string>
#include <kromodugum.hpp>
#include <kromozom.hpp>
#include <gendugum.hpp>
#include <sstream>
using namespace std;

int main()
{
    short yapilacakIslem;
    bool cikis = false;
    ifstream dosya("Dna.txt");
    string satirmetni;
    if(!dosya){
        cout<<"Dosya acilamadi"<<endl;
        return 0;
    }
                    
    kromodugum* ilkKromozom=nullptr;
    kromodugum* sonKromozom=nullptr;
    int kromozomIndex=0;
    while (getline(dosya,satirmetni)){
        kromodugum* yeniKromozom = new kromodugum(kromozomIndex++);
        for (char harf: satirmetni){
            if(harf==' '){}
            else{
            yeniKromozom->harfEkle(harf);
            }
         }

        if(ilkKromozom==nullptr){
            ilkKromozom=yeniKromozom;
        }
        else {
            sonKromozom->sonrakikromo=yeniKromozom;
        }
        sonKromozom=yeniKromozom;
        }
        dosya.close();
    do
    {

        cout<<"1-Caprazlama"<<endl<<"2-Mutasyon"<<endl<<"3-Otomatik islemler"<<endl<<"4-Ekrana yaz"<<endl<<"5-cikis"<<endl<<"Yapmak istediginiz numarayi giriniz: ";
        cin>>yapilacakIslem;
        switch (yapilacakIslem){
            case(1):
            {
                kromozom krobj;
                krobj.ilkKromozom=ilkKromozom;
                int index1;
                int index2;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Caprazlamak istediğiniz ilk kromozomun indexini giriniz: ";
                cin>>index1;
                cout<<"Caprazlamak istediginiz ikinici kromozomun indexini giriniz: ";
                cin>>index2;
                krobj.Caprazlama(index1,index2);
                cout<<"Islem tamamlanmistir"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                break;
            }
            case(2):
            {
                kromozom krobj;
                krobj.ilkKromozom=ilkKromozom;
                int kromozomIndex;
                int genIndex;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Mutasyona ugramasini istediginiz kromozom'un indexini giriniz: ";
                cin>>kromozomIndex;
                cout<<"Mutasyona ugramasini istediginiz gen'in indexini giriniz:";
                cin>>genIndex;
                krobj.Mutasyon(kromozomIndex,genIndex);
                cout<<"Islem tamamlanmistir"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                break;
            }
            case(3):
                {
                    kromozom krobj;
                    krobj.ilkKromozom=ilkKromozom;
                    char islem;
                    int islem1;
                    int islem2;
                    ifstream otois("Islemler.txt");
                    string islemsatiri;
                    int i=0;
                    while (getline(otois,islemsatiri))
                    { 
                        stringstream ss(islemsatiri);
                        ss>>islem>>islem1>>islem2;

                        if(islem=='C'){
                            krobj.Caprazlama(islem1,islem2);
                        }else if(islem=='M'){
                            krobj.Mutasyon(islem1,islem2);
                        }
                        else{
                            cout<<i<<". satir hatali"<<endl;
                        }
                        i++;
                    }
                    otois.close();
                    cout<<"Islem tamamlanmistir"<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    break;
                }
            case(4):
                {
                    kromozom krobj;
                    krobj.ilkKromozom=ilkKromozom;
                    krobj.ekranaYaz();
                    break;
                }
            case(5):
                cikis=true;
                break;
        }
    } while (cikis != true);
    cout<<"Program sonlanmistir!!!";
}