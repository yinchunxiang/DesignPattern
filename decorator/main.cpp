//
// Created by yinchunxiang on 26/03/2017.
//

#include <iostream>

using namespace std;

class Component
{
public:
	virtual void Operation() = 0;
};

class ConcreteComponent : public Component
{
public:
	void Operation()
	{
		cout<<"I am no decoratored ConcreteComponent"<<endl;
	}
};

class Decorator : public Component
{
public:
	Decorator(Component *pComponent) : m_pComponentObj(pComponent) {}
	void Operation()
	{
		if (m_pComponentObj != NULL)
		{
			m_pComponentObj->Operation();
		}
	}
protected:
	Component *m_pComponentObj;
};


class ConcreteDecoratorA : public Decorator
{
public:
	ConcreteDecoratorA(Component *pDecorator) : Decorator(pDecorator){}
	void Operation()
	{
		AddedBehavior();
		Decorator::Operation();
	}
	void  AddedBehavior()
	{
		cout<<"This is added behavior A."<<endl;
	}
};

class ConcreteDecoratorB : public Decorator
{
public:
	ConcreteDecoratorB(Component *pDecorator) : Decorator(pDecorator){}
	void Operation()
	{
		AddedBehavior();
		Decorator::Operation();
	}
	void  AddedBehavior()
	{
		cout<<"This is added behavior B."<<endl;
	}
};


int main(int argc, const char *argv[]) {
	//TODO
	Component *pComponentObj = new ConcreteComponent();
	Decorator *pDecoratorAOjb = new ConcreteDecoratorA(pComponentObj);
	pDecoratorAOjb->Operation();
	cout<<"============================================="<<endl;
	Decorator *pDecoratorBOjb = new ConcreteDecoratorB(pComponentObj);
	pDecoratorBOjb->Operation();
	cout<<"============================================="<<endl;
	Decorator *pDecoratorBAOjb = new ConcreteDecoratorB(pDecoratorAOjb);
	pDecoratorBAOjb->Operation();
	cout<<"============================================="<<endl;
	return 0;
}
