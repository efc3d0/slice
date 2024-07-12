#include "slice.h"

int main(int argc, char ** argv)
{
    int p[10] = {3, 2, 8, 9, 0, 1, 44, 89};
    auto x = slice_from_dt(p, 1, 3);
    for(int i = 0; i <= 3; i++)
    {
        std::cout << *(x+i) << std::endl;
    }

    std::cout << std::endl;

    char c[10] = "aoeuhsq";
    auto f = slice_from_dt<char>(c, 1, 4);
    for(int i = 0; i <= 3; i++)
    {
        std::cout << *(f+i) << std::endl;
    }
    return 0;
}
