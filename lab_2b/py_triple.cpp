/*
This is the standard template for CSCI 140 Lab.
Unless otherwise directed, start your programs with this template file. 
Be sure to rename the file appropriately when used for a lab.
Also you can/should remove this comment before use. Leave the following 
comments.
*/
// who: Hoang Tu Huynh
// what:  determine the py truples and counting them
// why: lab 2b
// when: 03/20/2022
// includes go here
#include <iostream>

int main(int argc, char const *argv[])
{
    
    int side1, side2, side3;
    int counter = 0;
    std::cout<<std::endl;
    std::cout<<"\t"<<"Side 1"<<"\t"<<"Side 2"<<"\t"<<"Side 3"; 
    std::cout<<std::endl; 
    for(side3 = 5; side3<=500;side3++){
        for(side2 = 1; side2<=side3;side2++){
            for(side1=1; side1<=side2;side1++){
                if(side1*side1+side2*side2 == side3*side3){
                    std::cout<<"\t"<<side1<<"\t"<<side2<<"\t"<<side3;
                    std::cout<<std::endl;
                    counter++;
                }
            }
        }   
    }
    std::cout<<"A total of "<<counter<<" triples was found.";
    std::cout<<std::endl;
 
    return 0;
}