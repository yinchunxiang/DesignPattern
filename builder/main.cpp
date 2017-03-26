//
// Created by yinchunxiang on 26/03/2017.
//



enum class ManType {
    FatMan,
    ThinMan,
    Nornal
};

class Man {
public:
    void SetHead(ManType type){ m_Type = type; }
    void SetBody(ManType type){ m_Type = type; }
    void SetLeftHand(ManType type){ m_Type = type; }
    void SetRightHand(ManType type){ m_Type = type; }
    void SetLeftFoot(ManType type){ m_Type = type; }
    void SetRightFoot(ManType type){ m_Type = type; }

    void ShowMan() {
        switch (m_Type) {
            case ManType::FatMan:
                cout<<"I'm a fat man"<<endl;
                return;

            case ManType::ThinMan:
                cout<<"I'm a thin man"<<endl;
                return;

            default:
                cout<<"I'm a normal man"<<endl;
                return;
        }
    }

private:
    ManType m_Type;
};


// Builder
class Builder
{
public:
    virtual void BuildHead(){}
    virtual void BuildBody(){}
    virtual void BuildLeftHand(){}
    virtual void BuildRightHand(){}
    virtual void BuildLeftFoot(){}
    virtual void BuildRightFoot(){}
    virtual Man *GetMan(){ return NULL; }
};


// FatManBuilder
class FatManBuilder : public Builder
{
public:
    FatManBuilder(){ m_FatMan = new Man(); }
    void BuildHead(){ m_FatMan->SetHead(kFatMan); }
    void BuildBody(){ m_FatMan->SetBody(kFatMan); }
    void BuildLeftHand(){ m_FatMan->SetLeftHand(kFatMan); }
    void BuildRightHand(){ m_FatMan->SetRightHand(kFatMan); }
    void BuildLeftFoot(){ m_FatMan->SetLeftFoot(kFatMan); }
    void BuildRightFoot(){ m_FatMan->SetRightFoot(kFatMan); }
    Man *GetMan(){ return m_FatMan; }

private:
    Man *m_FatMan;
};


// ThisManBuilder
class ThinManBuilder : public Builder
{
public:
    ThinManBuilder(){ m_ThinMan = new Man(); }
    void BuildHead(){ m_ThinMan->SetHead(kThinMan); }
    void BuildBody(){ m_ThinMan->SetBody(kThinMan); }
    void BuildLeftHand(){ m_ThinMan->SetLeftHand(kThinMan); }
    void BuildRightHand(){ m_ThinMan->SetRightHand(kThinMan); }
    void BuildLeftFoot(){ m_ThinMan->SetLeftFoot(kThinMan); }
    void BuildRightFoot(){ m_ThinMan->SetRightFoot(kThinMan); }
    Man *GetMan(){ return m_ThinMan; }

private:
    Man *m_ThinMan;
};


// Director
class Director
{
public:
    Director(Builder *builder) { m_Builder = builder; }
    void CreateMan() {
        m_Builder->BuildHead();
        m_Builder->BuildBody();
        m_Builder->BuildLeftHand();
        m_Builder->BuildRightHand();
        m_Builder->BuildLeftHand();
        m_Builder->BuildRightHand();
    }

private:
    Builder *m_Builder;
};
