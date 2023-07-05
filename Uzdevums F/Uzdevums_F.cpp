/// Uzdevums_F.cpp
/*********************************************************
Uzdevums F. F9. Izvadīt dotajā teksta failā f sastapto
latīņu alfabēta burtu lietojuma biežuma tabulu
(nešķirojot lielos un mazos burtus) failā f1.
Tabulai jābūt sakārtotai alfabētiski.
********************************************************/
/// Autors: Ričards Bubišs, rb22033
/// Veidota: 22.02.2023
#include <fstream>
#include <iostream>
using namespace std;

int main(){
    fstream f;
    fstream f1;
    string s;
    int ok=0;
    do{
    int biezumi[256]={0};  /// elements ar indeksu biezumi[i] satur biežumu simbolam ar kodu i.

    f.open ("f.txt", ios::in);
    if(!f){ cout<<"Nav faila!"<<endl;;return 13;};
    f1.open("f1.txt",ios::out);

    getline(f,s);                         ///secīgas nolasīšanas shēma.
    while (f){
        for(int i=0;i<s.length();i++){
            s[i] = tolower(s[i]);             ///visi burti mazie, lai netiek šķiroti lielie un mazie.
            biezumi[(unsigned int)s[i]]++;

        }
       getline(f,s);
    };
f.close ();

    for(int i=0;i<256;i++){                                ///Tabula tiek izdrukāta failā f1.
            if(biezumi[i]!=0){
        f1<< "Simbols '" <<(char)i<<"' parādās failā "<<biezumi[i]<< " reizes" <<endl;
        cout<< "Simbols '" <<(char)i<<"' parādās failā "<<biezumi[i]<< " reizes" <<endl;
    }

}
cout<<"Vai vēlaties turpināt(1), vai beigt(0)? "<<endl;
cin>>ok;

}while(ok==1);


}




/************************************* Testa plāns **********************************************************
    f.txt                                                    paredzamais rezultāts(f1.txt)
_____________________________________________________________________________________________________________

    nav izveidots                                             Nav faila!
-------------------------------------------------------------------------------------------------------------
    Ricards                                                 Simbols 'a' parādās failā 1 reizes
                                                            Simbols 'c' parādās failā 1 reizes
                                                            Simbols 'd' parādās failā 1 reizes
                                                            Simbols 'i' parādās failā 1 reizes
                                                            Simbols 'r' parādās failā 2 reizes
                                                            Simbols 's' parādās failā 1 reizes
-------------------------------------------------------------------------------------------------------------
    "aas d   ds sdsds"
    "dsds\"
    "dsd "
    "ty"
                                                            Simbols ' ' parādās failā 6 reizes
                                                            Simbols '\' parādās failā 1 reizes
                                                            Simbols 'a' parādās failā 2 reizes
                                                            Simbols 'd' parādās failā 8 reizes
                                                            Simbols 's' parādās failā 8 reizes
                                                            Simbols 't' parādās failā 1 reizes
                                                            Simbols 'y' parādās failā 1 reizes
-------------------------------------------------------------------------------------------------------------
    ""                                                          Tukšs fails

***************************************************************************************************************/
