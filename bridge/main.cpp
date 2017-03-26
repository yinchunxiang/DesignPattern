//
// Created by yinchunxiang on 26/03/2017.
//

#include <iostream>

using namespace std;


class Implement {
public:
    virtual void Impl() = 0;
};

class ConcreteImplement : public Implement {
public:
    void Impl() {
        cout << "concreate impl" << endl;
    }
};

class Abstraction {
public:
    Abstraction(Implement* impl): impl_(impl){
    }
    virtual void operation() = 0;

protected:
    Implement* impl_;
};

class RedifinedAbstraction : public Abstraction {
public:
    RedifinedAbstraction(Implement* impl) : Abstraction(impl) {
    }
    void operation() {
        impl_->Impl();
    }
};

int main(int argc, const char *argv[]) {
	//TODO
    Implement* impl = new ConcreteImplement();
    Abstraction* a = new RedifinedAbstraction(impl);
    a->operation();

	return 0;
}
