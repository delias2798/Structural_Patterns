#include "abstractProduct.cpp"

using namespace std;

class simpleProduct : public abstractProduct{

public:
    string brand;
    explicit simpleProduct(string name, double price, string brand);
};

simpleProduct::simpleProduct(string name, double price, string brand): abstractProduct(name, price) {
    this->brand =  brand;
}