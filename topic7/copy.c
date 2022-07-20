#include "stdio.h"
#include "stdlib.h"

#define BUF_SZ 4096
int main(int agrc, char const *argv[])
{
    int qty;
    unsigned char buffer[BUF_SZ];
    FILE* src = NULL;
    FILE* dst = NULL;

    if((src = fopen("ubunto.iso", "rb")) == NULL)
    {
        printf("Could not open source file!\n");
        exit(1);
    }
    if((dst = fopen("ubunto2.iso", "wb")) == 0 )
    {
        fclose(src);
         printf("Could not open destination file!\n");
        exit(2);
    }
    while((qty = fread(buffer, sizeof(char), BUF_SZ, src)) > 0)
        fwrite(buffer, sizeof(char), qty, dst);
    fclose(src);
    fclose(dst);

    return 0;
}