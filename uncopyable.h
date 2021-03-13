#ifndef UNCOPYABLE_H
#define UNCOPYABLE_H

class Uncopyable
{
private:
    Uncopyable(Uncopyable const&)=delete;
    Uncopyable& operator=(Uncopyable const&)=delete;
public:
    Uncopyable();
    ~Uncopyable();
};

#endif /* UNCOPYABLE_H */
