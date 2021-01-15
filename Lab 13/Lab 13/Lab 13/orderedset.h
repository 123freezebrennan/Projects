#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* prev;
    Node* next;
};

class OrderedSet {

public:
    OrderedSet();
    OrderedSet(const OrderedSet& other);
   // ~OrderedSet();

    void apply(void function(int& param));
    bool Insert(int v);
    bool Delete(int v);
    int Size() const { return size; }

    void PrintBackwards(ostream& out);
    void clear();
    bool exists(int v);

   // OrderedSet& operator=(const OrderedSet& other);
    OrderedSet operator+(const OrderedSet& other);
    OrderedSet operator*(const OrderedSet& other);
    bool operator==(const OrderedSet& other) const;
    friend ostream& operator<< (ostream& out, const OrderedSet& LL);

private:
    Node* first;
    Node* last;
    int size;

    bool InsertFirst(int v);
    bool InsertLast(int v);
    bool DeleteFirst();
    bool DeleteLast();
};
