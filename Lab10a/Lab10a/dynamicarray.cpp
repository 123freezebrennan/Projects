// anyone who may look at this code know that this lab is ridiculous and you shouldnt teach people code like this
#include <iostream>
#include "dynamicarray.h"
#include <ostream>
using namespace std;


DynamicArray::~DynamicArray() {}
DynamicArray::DynamicArray() {}
DynamicArray::DynamicArray(const DynamicArray& other) : arr(other.arr) {}

DynamicArray& DynamicArray::operator=(const DynamicArray& assign) {
    arr = assign.arr;
    return *this;
}

void DynamicArray::append(int new_value) {
    arr.push_back(new_value);
}

int DynamicArray::at(int new_value) const {
    return arr.at(new_value);
}
// Print all array elements

void DynamicArray::print(std::ostream& s) const {
    for (int i = 0; i < arr.size(); i++) {
        s << arr.at(i) << " ";
        if (i % 10 == 9) {
            s << endl; // newline every 10 elements
        }
    }
    s << endl;
}

int DynamicArray::sum() const {
    int add = 0;
    for (int i = 0; i < arr.size(); ++i) {
        add = arr.at(i) + add;
    }
    return add;
}

bool DynamicArray::remove(int new_integer) {
    bool value_iden = false;
    for (int j = 0; j < arr.size(); ++j) {
        if (arr.at(j) == new_integer) {
            arr.erase(arr.begin() + j);
            value_iden = true;
            return value_iden;
        }

    }
    return value_iden;
}


bool DynamicArray::operator==(const DynamicArray& compare) const {
    if (compare.arr.size() == arr.size()) {
        for (int i = 0; i < arr.size(); i++) {
            if (compare.arr[i] == arr[i]) {
                continue;
            }
            else {
                return false;
            }
        }
        return true;

    }
    else
        return false;
}





