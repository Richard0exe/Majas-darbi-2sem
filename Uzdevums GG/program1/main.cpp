/// G_linked_list.cpp
/*********************************************************
G9. Uzrakstīt funkciju, kas pārbauda, vai sarakstā ir
vismaz divi elementi ar vienādām vērtībām.
********************************************************/
/// Autors: Ričards Bubišs, rb22033
/// Veidota: 21.05.2023
#include "header.h"
#include <iostream>
using namespace std;

int main() {
        int ok;
        do{
        elem *first=NULL,*last;
        int i;
    cout << "Ievadiet skaitļu virknes elementu (0, ja gribat beigt): " << endl;
    cin >> i;
    /// ievadīšana, kamēr nav sastapta 0
    while (i != 0){
        append(first,last,i);
        cout << "Ievadiet skaitļu virknes elementu (0, ja gribat beigt): " << endl;
        cin >> i;
    }


        print(first);
        try{
            if(twoMatches(first))
                cout<<"There IS two equal numbers"<<endl;
            else
                cout<<"There ISN'T 2 equal numbers"<<endl;
        }
        catch (const exception& e){
            cout<<"Izņēmums: Saraksts ir tukšs"<<endl;
        }
        print(first);

        rem(first);
        cout<<"Turpināt(1) vai beigt(0)?"<<endl;
        cin>>ok;
        }while(ok!=0);

}

