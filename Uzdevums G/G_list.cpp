/// G_list.cpp
/*********************************************************
G9. Uzrakstīt funkciju, kas pārbauda, vai sarakstā ir
vismaz divi elementi ar vienādām vērtībām.
********************************************************/
/// Autors: Ričards Bubišs, rb22033
/// Veidota: 28.03.2023
#include <iostream>
#include <list>
using namespace std;

/**
bool twoMatches (list<int> aa)
Funkcija twoMatches(aa)-
pārbauda vai sarakstā ir vismaz 2 elementi ar vienādām vērtībām.
**/

bool twoMatches(list<int> aa){
    auto it = aa.begin();
    for(auto i = it;i!=aa.end();i++){
            auto it2 = next(it);
        for(auto j= it2 ;j!=aa.end();j++){
            if(*i==*j) return true;
                it2 = next(it2);
            }
            it = next(it);
        }
    }


int main()
{
    int ok;
    do{
    int i;
    cout << "Ievadiet skaitļu virknes elementu (0, ja gribat beigt): " << endl;
    cin>>i;
    list<int> aa = {};
    while(i!=0){
       aa.push_back(i);
       cout << "Ievadiet skaitļu virknes elementu (0, ja gribat beigt): " << endl;
        cin >> i;
    }

    for(auto &a: aa){
        cout<<a<<" ";
    }
    cout<<endl;
if(twoMatches(aa)) cout<<"There IS two identical numbers"<<endl;
else cout<<"There ISN'T two identical numbers"<<endl;

    for(auto &a: aa){
        cout<<a<<" ";
    }
    cout<<endl;
    cout<<"Turpināt(1) vai beigt(0)?"<<endl;
    cin>>ok;
    }while(ok!=0);

}

/************************************* Testa plāns **********************************************************
    Ievads                                                    paredzamais rezultāts
_____________________________________________________________________________________________________________

    12145                                                      There IS two identical numbers
-------------------------------------------------------------------------------------------------------------
    12345                                                      There ISN'T two identical numbers
-------------------------------------------------------------------------------------------------------------
    76747                                                      There IS two identical numbers
-------------------------------------------------------------------------------------------------------------
    777                                                        There IS two identical numbers
*************************************************************************************************************/
