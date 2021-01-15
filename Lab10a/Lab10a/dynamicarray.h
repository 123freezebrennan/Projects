#include <iostream>
#include <vector>
using namespace std;
class DynamicArray {
public:

    DynamicArray();
    DynamicArray(const DynamicArray& other);
    ~DynamicArray();
    DynamicArray& operator= (const DynamicArray& assign);
    int cap() const { return arr.capacity(); }
    void append(int newVal);
    int at(int index) const;
    void print(std::ostream& s) const;
    int sum() const;
    bool operator==(const DynamicArray& compare) const;
    bool remove(int valToDelete);

private:
    vector <int> arr;

};
