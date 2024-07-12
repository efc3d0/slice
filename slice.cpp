#include "slice.h"
char * slice_from_str(char * f, int r1, int r2)
{
    if(r2 == 0)
    {
        char * p = new char[sizeof(f)];
        std::memcpy(p, f, r1); // copy from f to p; p1 count bytes
        return p;
    } else {
        char * p = new char[sizeof(f)];
        stack<char> *s = new stack<char>;
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

int * slice_from_integer(int * f, int r1, int r2)
{
    if(r2 == 0)
    {
        int * p = new int[sizeof(f)];
        std::memcpy(p,f, r1*4);
        return p;
    } else {
        int * p = new int[sizeof(f)];
        stack<int> *n = new stack<int>;
        for(int i = r1; i <= r2; i++)
        {
            n->push(f[i]);
        }
        for(int i = 0; n->ptr[i]; i++)
        {
            p[i] = n->ptr[i];
        }
        delete n;
        return p;
    }
}
