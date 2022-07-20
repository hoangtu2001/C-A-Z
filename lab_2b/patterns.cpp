/*
This is the standard template for CSCI 140 Lab.
Unless otherwise directed, start your programs with this template file. 
Be sure to rename the file appropriately when used for a lab.
Also you can/should remove this comment before use. Leave the following 
comments.
*/
// who: Hoang Tu Huynh
// what: printing the patterns
// why: lab 2b
// when: 03/20/2022
// includes go here
#include <iostream>

int main(int argc, char const *argv[])
{
    for (int i = 1; i<=10; i++) {
        for (int j = 1;j<=i; j++ ) {
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl; 

    for (int i = 10; i>=1; i--) {
        for (int j = 1;j<=i; j++ ) {
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;

    for (int i = 1; i<=10; i++) {
        for(int k = 1;k<=i;k++){
            std::cout<<" ";

        }
        for (int j = 10;j>=i; j-- ) {
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;

    for (int i = 1; i<=10; i++) {
        for(int k = 10;k>=i;k--){
            std::cout<<" ";

        }
        for (int j = 1;j<=i; j++ ) {
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }

    
 
    return 0;
}