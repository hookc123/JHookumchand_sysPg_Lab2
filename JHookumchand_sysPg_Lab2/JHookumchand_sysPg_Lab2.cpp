// JHookumchand_sysPg_Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include "Car.h"



void ShowAddress(int number,int* pointer)
{
    std::cout << number << "\t"<< pointer << std::endl;
}
enum EnumColorDefinition {
    Red=1,
    Blue,
    Green,
    Yellow,
    Black,
    White
};
int main()
{
    std::cout << "--------------Program 1--------------" << std::endl;

    srand(time(0));
    int array1[15];
    for (int i = 0; i <15; i++)
        array1[i] = rand();
    for (int& num : array1)
    {
        std::cout << num << "\t"<<&num<<std::endl;
    }

    std::cout << "--------------Program 2--------------" << std::endl;

    int array2[15];
    for (int i = 0; i < 15; i++) {
        array2[i] = rand();
    }
    for (int& num : array2)
    {
        int* numPtr = &num;
        ShowAddress(num, numPtr);
    }

    std::cout << "--------------Program 3--------------" << std::endl;
    struct Car
    {
        //fields
        char mMake[32];
        char mModel[32];
        int mYear;
        int mMileage;
        EnumColorDefinition mColor;

    };
    Car carArray[3];
    for (int i = 0; i < 3;i++) {
        std::cout << "Car " << i + 1 << std::endl;

        std::cout << "What is the Car Make?" << std::endl;
        std::cin.getline(carArray[i].mMake, 32);

        std::cout << "What is the Car Model?" << std::endl;
        std::cin.getline(carArray[i].mModel, 32);

        std::cout << "What is the Car year?" << std::endl;
        std::cin>> carArray[i].mYear;

        std::cout << "What is the Car mileage?" << std::endl;
        std::cin>> carArray[i].mMileage;

        std::cout << "What is the Car color?\n1) Red\n2) Blue\n3) Green\n4) Yellow\n5) Black\n6) White" << std::endl;
        int colorInput;
        std::cin>>colorInput;
        carArray[i].mColor = EnumColorDefinition(colorInput);
    }
    for (Car& car : carArray)
    {
        std::cout << car.mYear << car.mColor << car.mMake << car.mModel << " with " << car.mMileage << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
