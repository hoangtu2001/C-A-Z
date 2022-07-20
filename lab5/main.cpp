#include <iostream>
#include "account.h"


int main()
{
    Account fredsAccount("Fred Sanford", 50.0);
    fredsAccount.setName("Fred Sanford");
    fredsAccount.setBalance(50);
    std::cout<< fredsAccount.getName() <<"\n\t"<<fredsAccount.getBalance()<<std::endl;
    std::cout<< fredsAccount.getEvens() <<std::endl;
    return 0;
}