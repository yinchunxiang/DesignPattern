//
// Created by yinchunxiang on 26/03/2017.
//


#include <iostream>

using namespace std;

class Receiver {
public:
	void Action() {
		cout<<"Receiver->Action"<<endl;
	}
};

class Command {
public:
	virtual void Execute() = 0;
};

class ConcreteCommand : public Command {
public:
	ConcreteCommand(Receiver *pReceiver) : m_pReceiver(pReceiver){}
	void Execute() {
		m_pReceiver->Action();
	}
private:
	Receiver *m_pReceiver;
};

class Invoker {
public:
	Invoker(Command *pCommand) : m_pCommand(pCommand){}
	void Invoke() {
		m_pCommand->Execute();
	}
private:
	Command *m_pCommand;
};



int main(int argc, const char *argv[]) {
	//TODO
	Receiver *pReceiver = new Receiver();
	Command *pCommand = new ConcreteCommand(pReceiver);
	Invoker *pInvoker = new Invoker(pCommand);
	pInvoker->Invoke();

	return 0;
}

