#include <fstream>
#include <iostream>

int main()
{
    int32_t number;
    double dnumbers[8000];
    double* dnumber;
    dnumber=dnumbers;

    std::ifstream infile("testdata.txt");
    while(infile>>number)
    {
        std::cout<<number <<";";
        // double d_tmp=(double)number;
        // *dnumber=d_tmp;
        // dnumber=dnumber+1;
    }
    // std::cout<<"double next:"<<std::endl;

    // for(int i=0;i<8000;i++)
    // {
    //     std::cout<<dnumbers[i]<<";";
    // }

}