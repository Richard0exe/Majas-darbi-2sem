/// G_linked_list.cpp
/*********************************************************
G9. Uzrakstīt funkciju, kas pārbauda, vai sarakstā ir
vismaz divi elementi ar vienādām vērtībām.
********************************************************/
/// Autors: Ričards Bubišs, rb22033
/// Veidota: 28.03.2023
#include<iostream>
using namespace std;
struct elem {
    int num;
    elem *next;
    elem(int n) { num=n; next=NULL; }
};
void print(elem *first) {
    elem *p=first;
    while(p) {
        cout<<p->num<<" ";
        p=p->next;
    }
    cout<<endl;
}
void rem(elem *&first) {
    while(first) {
        elem *p = first->next;
        delete first;
        first=p;
    }
}
void append(elem *&first,elem *&last,int n) {
    elem *p=new elem(n);
    if (first==NULL) {
        first=last=p;
    }
    else {
        last->next=p;
        last = p;
    }
}
/**
bool twoMatches (elem *first)
Funkcija twoMatches(first)-
pārbauda vai saistītajā sarakstā ir vismaz 2 elementi ar vienādām vērtībām.
**/
bool twoMatches (elem *first) {
    elem *p=first;
    while(p!=NULL){
        elem *p1 = p->next;
        while(p1!=NULL){
            if(p->num == p1->num){      /// ja 2 vienādi elementi atgriež true.
                throw exception()
;            }
            p1= p1->next;
        }
        p = p->next;
    }
    return false;
}

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
            cout<<"Izņēmums: Nav vismaz divu elementu ar vienādām vērtībām"<<endl;
        }
        print(first);

        rem(first);
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

