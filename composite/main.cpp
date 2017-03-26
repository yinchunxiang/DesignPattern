//
// Created by yinchunxiang on 26/03/2017.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

//// 抽象的部件类描述将来所有部件共有的行为
class Component {
public:
    Component(string name): name_(name) {
    }
    virtual ~Component() = default;

    virtual void Operation() = 0;

    virtual void Add(Component *) = 0;
    virtual void Remove(Component *) = 0;
    virtual Component *GetChild(int) = 0;
    virtual void Print() = 0;


    string name() {
        return name_;
    }

protected:
    string name_;
};


class Leaf : public Component{
public:
    Leaf(string name) : Component(name) {}
    void Operation() {
        cout << "I am " << name_ << endl;
    }
    void Add(Component *pComponent){}
    void Remove(Component *pComponent){}
    Component *GetChild(int index) {
        return NULL;
    }
    void Print(){}

};

class Composite : public Component {
public:
    Composite(string name) : Component(name) {}
    ~Composite() {
        for (auto it = vec_.begin(); it != vec_.end(); ++it) {
            if (nullptr == *it) {
                continue;
            }
            cout << "=== delete " << (*it)->name() << "======" << endl;
            delete *it;
        }
    }
    void Operation() {
        cout << "I am " << name_ << endl;
    }
    void Add(Component* c) {
        cout << "----> add " << c->name() << endl;
        vec_.push_back(c);
    }
    void Remove(Component* c) {
        vec_.erase(std::remove(vec_.begin(), vec_.end(), c));
    }
    Component* GetChild(int index) {
        if (index >= vec_.size()) {
            return nullptr;
        }
        return vec_[index];
    }
    void Print() {
        cout << "{ ";
        for (auto c : vec_) {
            cout << c->name() <<  ", ";
            c->Print();
        }
        cout << "}" << endl;
    }
private:
    vector<Component *> vec_;
};





int main(int argc, const char *argv[]) {
	//TODO
    Component *pNode = new Composite("Beijing Head Office");
    Component *pNodeHr = new Leaf("Beijing Human Resources Department");
    Component *pSubNodeSh = new Composite("Shanghai Branch");
    Component *pSubNodeCd = new Composite("Chengdu Branch");
    Component *pSubNodeBt = new Composite("Baotou Branch");
    pNode->Add(pNodeHr);
    pNode->Add(pSubNodeSh);
    pNode->Add(pSubNodeCd);
    pNode->Add(pSubNodeBt);
    pNode->Print();

    Component *pSubNodeShHr = new Leaf("Shanghai Human Resources Department");
    Component *pSubNodeShCg = new Leaf("Shanghai Purchasing Department");
    Component *pSubNodeShXs = new Leaf("Shanghai Sales department");
    Component *pSubNodeShZb = new Leaf("Shanghai Quality supervision Department");
    pSubNodeSh->Add(pSubNodeShHr);
    pSubNodeSh->Add(pSubNodeShCg);
    pSubNodeSh->Add(pSubNodeShXs);
    pSubNodeSh->Add(pSubNodeShZb);
    pNode->Print();
    // 公司不景气，需要关闭上海质量监督部门
    pSubNodeSh->Remove(pSubNodeShZb);

	return 0;
}
