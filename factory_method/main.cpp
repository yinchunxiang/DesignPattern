//
// Created by yinchunxiang on 26/03/2017.
//


#include <iostream>
#include <string>

using namespace std;

enum class ProductType {
    ProductA,
    ProductB,
};


class Product {
public:
    virtual void show() = 0;
};

class ProductA : public Product {
public:
    void show() {
        cout << "I am ProductA" << endl;
    }
};

class ProductB : public Product {
public:
    void show() {
        cout << "I am ProductB" << endl;
    }
};

class Factory {
public:
    virtual Product* CreateProduct() = 0;
};

class FactoryA : public Factory {
public:
    Product* CreateProduct() {
        return new ProductA();
    }
};

class FactoryB : public Factory {
public:
    Product* CreateProduct() {
        return new ProductB();
    }
};

class Factory {
public:
    Product* CreateProduct(ProductType pt) {
        switch (pt) {
            case ProductType::ProductA:
                return new ProductA();
            case ProductType::ProductB:
                return new ProductB();
            default:
                return nullptr;
        }
    }
};

int main(int argc, const char *argv[]) {
    //TODO
    Factory* f = new Factory();
    Product* a = f->CreateProduct(ProductType::ProductA);
    a->show();
    Product* b = f->CreateProduct(ProductType::ProductB);
    b->show();
    return 0;
}


