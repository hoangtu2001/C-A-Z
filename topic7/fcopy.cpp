
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#define BUFFER_SZ 8106
int main(int agrc, char const *argv[])
{
    char buff[BUFFER_SZ];
    int qty;
    std::ifstream src("text1.iso", std::ios::in | std::ios::binary);
    std::ofstream dst("text2.iso", std::ios::out | std::ios::binary);

    if(!src || !dst) exit(EXIT_FAILURE);

    while(src)
    {
        src.read(buff, BUFFER_SZ);
        qty = src.gcount();
        dst.write(buff, qty);
        dst<<"Account\t Balance";
    }

    return 0;
}
