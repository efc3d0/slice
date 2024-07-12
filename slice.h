#ifndef SLICE_H
#define SLICE_H
#include<iostream>
#include <cstring>

template <typename T>
struct stack
{
    T * ptr;
    int index;
    stack()
    {
        ptr = new T[50];
        index = 0;
    }
    void push(T c)
    {
        ptr[index++] = c;
    }
    ~stack()
    {
        delete[] ptr;
    }
};

char * slice_from_str(char * f, int r1, int r2 = 0) __attribute__((nonnull(1)));
int * slice_from_integer(int * f, int r1, int r2 = 0) __attribute__((nonnull(1)));
#define err_ret(R, ...) { fprintf(stderr, __VA_ARGS__); return R; }
template<typename T>
T * slice_from_dt(T * f, int r1, int r2 = 0);

template<typename T>
T * slice_from_dt(T * f, int r1, int r2)
{
    if(r2 == 0)
    {
        T * p = new T[sizeof(f)];
        std::memcpy(p, f, r1); // copy from f to p; p1 count bytes
        return p;
    } else {
        T * p = new T[sizeof(f)];
        stack<T> * s = new stack<T>;
        for(int i = r1; i <= r2; i++)
        {
            s->push(f[i]);
        }
        for(int i = 0; s->ptr[i]; i++)
        {
            p[i] = s->ptr[i];
        }
        delete s;
        return p;
    }
}

#endif SLICE_H
