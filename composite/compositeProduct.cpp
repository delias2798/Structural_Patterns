#include "abstractProduct.cpp"

using namespace std;

class compositeProduct : public abstractProduct{

public:
    int largeProducts = 0;
    explicit compositeProduct(string name);
    double getPrice();
    void addProduct(abstractProduct);
    abstractProduct products[];
};

compositeProduct::compositeProduct(string name): abstractProduct(name, 0){}

double compositeProduct::getPrice() {
    double cost = 0;
    for(int i=0;i<largeProducts;i++){
        cost += products[i].price;
    }
    return cost;
}

void compositeProduct::addProduct(abstractProduct product) {
    products[largeProducts] = product;
    largeProducts ++;
}