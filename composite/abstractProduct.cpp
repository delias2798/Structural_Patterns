#include <iostream>
#include "array"

using namespace std;

class abstractProduct{

public:
    string name;
    double price;
    explicit abstractProduct(string name, double price);
};

abstractProduct::abstractProduct(string name, double price) {
    this->name = name;
    this->price = price;
}