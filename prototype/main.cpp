//
// Created by yinchunxiang on 26/03/2017.
//

#include <iostream>

using namespace std;

class Prototype {
public:
	Prototype() = default;
	virtual ~Prototype() = default;
	virtual Prototype* Clone() = 0;
};


class ConcreatePrototype : public Prototype {
public:
	ConcreatePrototype() = default;
	virtual  ~ConcreatePrototype() = default;

    // copy construct
	ConcreatePrototype(const ConcreatePrototype &rhs) {
		counter_ = rhs.counter_;
	}

	virtual ConcreatePrototype* Clone() {
		return new ConcreatePrototype(*this);
	}
	int counter() {
		return counter_;
	}
    void IncCounter() {
		++counter_;
	}

private:
	int counter_ = 0;
};


int main(int argc, const char *argv[]) {
	//TODO
	ConcreatePrototype* a = new ConcreatePrototype();
	cout << a->counter() << endl;
	a->IncCounter();

	ConcreatePrototype* copy = a->Clone();
	cout << copy->counter() << endl;


	return 0;
}
