#include <iostream>
using namespace std;

template<typename T>
class Singleton
{
public:
    static T& getInstance(){
        static T instance{token()};
        return instance;
    }   
    virtual ~Singleton()=default;
    Singleton(const Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;
protected:
    struct token{};
    Singleton()noexcept=default;
};


class DerivedSingle:public Singleton<DerivedSingle>{
public:
    DerivedSingle(token){cout<< "constructor called!"<<endl;}
    DerivedSingle(const DerivedSingle&)=delete;
    DerivedSingle& operator=(const DerivedSingle&)=delete;
    ~DerivedSingle(){ cout<< "destructor called!" <<endl; }
private:
};

int main(void)
{
    return 0;
}
