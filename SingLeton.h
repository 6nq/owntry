#ifndef SINGLETON_H
#define SINGLETON_H

template<typename T>
class SingLeton
{
protected:
    struct token{};
    SingLeton()noexcept=default;
    virtual ~SingLeton()=default;
private:
    SingLeton(SingLeton const &)=delete;
    SingLeton& operator=(SingLeton const &)=delete;

public:
    static T& GetInstance()noexcept{
         static T instance{token()};
         return instance;
    }
};
class DerivedSingle:public SingLeton<DerivedSingle>{
private:
public:
     DerivedSingle(token){};
     ~DerivedSingle()=default;
};

#endif /* SINGLETON_H */
