// JHookumchand_sysPg_Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>




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
struct Car
{
    //fields
    char mMake[32];
    char mModel[32];
    int mYear;
    int mMileage;
    EnumColorDefinition mColor;

};
void repaintCar(Car* ptrCar, EnumColorDefinition newcolor)
{
    ptrCar->mColor = newcolor;
}
void printCar(Car c)
{
    std::cout << c.mYear << " ";
    switch (c.mColor)
    {
    case 1:
        std::cout << "Red "; break;
    case 2:
        std::cout << "Blue "; break;
    case 3:
        std::cout << "Green "; break;
    case 4:
        std::cout << "Yellow "; break;
    case 5:
        std::cout << "Black "; break;
    case 6:
        std::cout << "White "; break;
    }
    std::cout << c.mMake << " " << c.mModel << " with " << c.mMileage << " miles" << std::endl;
}
void printCarPointer(Car* ptrCar)
{
    //using the * on a pointer shows the value of what is at the address which is a Car type aka derefearence
    printCar(*ptrCar);
}
void addMileage(Car* ptrCar, int milesToAdd)
{
    ptrCar->mMileage += milesToAdd;
}


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
    
    Car carArray[3]{};
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
        // need to clear the input buffer having trouble getting new user input
        std::cin.clear();
        std::cin.ignore(INT_MAX,'\n');
    }

    for (int i = 0; i<3;i++)
    {
        std::cout << "Car " << i + 1 << " ";
        printCar(carArray[i]);
    }
    int choice;
    std::cout << "Do you wish to repaint any car?\n" << "1) Yes\n2) No"<<std::endl;
    std::cin>> choice;
    if (choice == 1)
    {
        std::cout << "Which car do you wish to repaint?" << std::endl;
        for (int i = 0; i < 3; i++)
        {
            std::cout<< i + 1<< ") ";
            printCar(carArray[i]);
        }
        std::cin >> choice;
        std::cout << "What is the Car color?\n1) Red\n2) Blue\n3) Green\n4) Yellow\n5) Black\n6) White" << std::endl;
        int colorInput;
        std::cin >> colorInput;
        if (choice == 1)
        {
            repaintCar(&carArray[0], EnumColorDefinition(colorInput));
        }
        if (choice == 2)
        {
            repaintCar(&carArray[1], EnumColorDefinition(colorInput));
        }
        if (choice == 3)
        {
            repaintCar(&carArray[2], EnumColorDefinition(colorInput));
        }
        printCar(carArray[choice-1]);
        std::cout << std::endl;
    }
  
    
    std::cout << "Do you wish add milage to any car?\n" << "1) Yes\n2) No" << std::endl;
    std::cin >> choice;
    std::cout << std::endl;
    if (choice == 1)
    {
        std::cout << "Which car do you wish to add milage to?" << std::endl;
        for (int i = 0; i < 3; i++)
        {
            std::cout << i + 1 << ") ";
            printCar(carArray[i]);
        }
        std::cin >> choice;
        std::cout << "How much do you wish to add" << std::endl;
        int addMilage;
        std::cin >> addMilage;
        if (choice == 1)
        {
            addMileage(&carArray[0], addMilage);
        }
        if (choice == 2)
        {
            addMileage(&carArray[1], addMilage);
        }
        if (choice == 3)
        {
            addMileage(&carArray[2], addMilage);
        }
        printCar(carArray[choice-1]);

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
