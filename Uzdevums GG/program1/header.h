struct elem {
    int num;
    elem *next;
    elem(int n) { num = n; next = nullptr; }
};

void print(elem *first);
void rem(elem *&first);
void append(elem *&first, elem *&last, int n);
bool twoMatches(elem *first);

