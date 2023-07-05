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
    if(first==NULL){
        throw 5;
    }
    elem *p=first;
    while(p!=NULL){
        elem *p1 = p->next;
        while(p1!=NULL){
            if(p->num == p1->num){      /// ja 2 vienādi elementi atgriež true.
                return true;
            }
            p1= p1->next;
        }
        p = p->next;
    }
    return false;
}

