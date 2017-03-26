//
// Created by yinchunxiang on 26/03/2017.
//


#include <iostream>

using namespace std;


class Target {
public:
	virtual void Request() {
		cout << "Target::Request" << endl;
	}
};

class Adaptee {
public:
	void SpecificRequest() {
		cout << "Adaptee::SpecificRequest" << endl;
	}
};

class Adapter : public Target{
public:
	Adapter() = default;
	~Adapter() {
        if (nullptr != adaptee_) {
			delete adaptee_;
		}
	}

	void Request() {
		adaptee_->SpecificRequest();
	}
private:
	Adaptee *adaptee_ = new Adaptee();

};


int main(int argc, const char *argv[]) {
	//TODO

	Target* t = new Adapter();
	t->Request();
	return 0;
}


