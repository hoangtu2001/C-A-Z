#include <iostream>

int main(int argc, char const *argv[])
{
    char c;
    std:: cout<<"Enter one character: ";
    std:: cin>>c;
    if(c >= 'A' && c<='Z')
        c = c+ ('a'-'A');
    std:: cout<<"Hello World. You belong to me!\n";
    std:: cout<<"The lowercase character you entered is "<<c<< std::endl;
    return 0;
}

bool notE(int a, int b){
    return a!=b;
}