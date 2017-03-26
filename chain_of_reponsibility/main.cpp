//
// Created by yinchunxiang on 26/03/2017.
//

#include <iostream>

using namespace std;


class HolidayRequest
{
public:
    HolidayRequest(int hour) : m_iHour(hour){}
    int GetHour() { return m_iHour; }
private:
    int m_iHour;
};


// The holiday request handler interface
class Manager
{
public:
	virtual bool HandleRequest(HolidayRequest *pRequest) = 0;
};

// Project manager
class PM : public Manager
{
public:
	PM(Manager *handler) : m_pHandler(handler){}
	bool HandleRequest(HolidayRequest *pRequest)
	{
		if (pRequest->GetHour() <= 2 || m_pHandler == NULL)
		{
			cout<<"PM said:OK."<<endl;
			return true;
		}
		return m_pHandler->HandleRequest(pRequest);
	}
private:
	Manager *m_pHandler;
};



// Department manager
class DM : public Manager
{
public:
	DM(Manager *handler) : m_pHandler(handler){}
	bool HandleRequest(HolidayRequest *pRequest)
	{
		cout<<"DM said:OK."<<endl;
		return true;
	}

	// The department manager is in?
	bool IsIn() {
		return true;
	}
private:
	Manager *m_pHandler;
};

// Project supervisor
class PS : public Manager
{
public:
	PS(Manager *handler) : m_pHandler(handler){}
	bool HandleRequest(HolidayRequest *pRequest)
	{
		DM *pDM = dynamic_cast<DM *>(m_pHandler);
		if (pDM != NULL)
		{
			if (pDM->IsIn())
			{
				return pDM->HandleRequest(pRequest);
			}
		}
		cout<<"PS said:OK."<<endl;
		return true;
	}
private:
	Manager *m_pHandler;
};


int main(int argc, const char *argv[]) {
	//TODO

	return 0;
}


