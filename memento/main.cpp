//
// Created by yinchunxiang on 26/03/2017.
//

#include <iostream>

using namespace std;

struct State
{
	wchar_t wcsState[260];
};



class Memento
{
public:
	Memento(State *pState) : m_pState(pState){}

	State *GetState() { return m_pState; }

private:
	friend class Originator;

	State *m_pState;
};

class Originator
{
public:
	Originator() : m_pState(NULL) {}
	~Originator()
	{
		// Delete the storage of the state
		if (m_pState)
		{
			delete m_pState;
			m_pState = NULL;
		}
	}

	void SetMemento(Memento *pMemento);
	Memento *CreateMemento();

	void SetValue(wchar_t *value)
	{
		memset(wcsValue, 0, 260 * sizeof(wchar_t));
		wcscpy_s(wcsValue, 260, value);
	}

	void PrintState() { wcout<<wcsValue<<endl; }

private:
	State *m_pState; // To store the object's state

	wchar_t wcsValue[260]; // This is the object's real data
};

//创建memento， 保存数据到memento
Memento *Originator::CreateMemento()
{
	m_pState = new State;
	if (m_pState == NULL)
	{
		return NULL;
	}

	Memento *pMemento = new Memento(m_pState);

	wcscpy_s(m_pState->wcsState, 260, wcsValue); // Backup the value
	return pMemento;
}

// 从memento恢复数据
void Originator::SetMemento(Memento *pMemento)
{
	m_pState = pMemento->GetState();

	// Recovery the data
	memset(wcsValue, 0, 260 * sizeof(wchar_t));
	wcscpy_s(wcsValue, 260, m_pState->wcsState);
}



int main(int argc, const char *argv[]) {
	//TODO

	return 0;
}
