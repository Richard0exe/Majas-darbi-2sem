/// G_linked_list.cpp
/*********************************************************
G9. Uzrakstīt funkciju, kas pārbauda, vai sarakstā ir
vismaz divi elementi ar vienādām vērtībām.
********************************************************/
/// Autors: Ričards Bubišs, rb22033
/// Veidota: 21.05.2023
struct elem {
    int num;
    elem *next;
    elem(int n) { num = n; next = nullptr; }
};

void print(elem *first);
void rem(elem *&first);
void append(elem *&first, elem *&last, int n);
bool twoMatches(elem *first);

