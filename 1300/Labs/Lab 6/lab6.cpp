// Lab 6 created by Gabriel Snider and David Gregory 

#include <iostream>

using namespace std;

const double PI= 3.14;

void displayMenu()
{
    
    cout <<"Choose a shape to calculate area or 5 to quit:" << endl;
    cout <<"\t 1. Square" << endl;
    cout <<"\t 2. Rectangle" << endl;
    cout <<"\t 3. Parallelogram" << endl;
    cout <<"\t 4. Circle" << endl;
    cout <<"\t 5. End Program" << endl;
    cout <<"CHOOSE 1-5:";
    
    
}

void areaSquare(double height)
{
    double squareArea;
    squareArea=height * height;
    cout <<"The area of your Square is " << squareArea << endl;
}

void areaRectangle(double height, double base)
{
    double rectangleArea;
    rectangleArea= base * height;
    cout <<"The area of your Rectangle is " << rectangleArea << endl;
}

void areaParallelogram(double height, double base)
{
    double parallelogramArea;
    parallelogramArea= height * base;
    cout <<"The area of your Parallelogram is " << parallelogramArea << endl;
}

void areaCircle(double radius)
{
    double circleArea;
    circleArea= PI * (radius*radius);
    cout <<"The area of your Circle is " << circleArea << endl;
}

int main()
{
    int userChoice;
    do {
    double squareHeight;
    double rectangleHeight;
    double rectangleBase;
    double paraHeight;
    double paraBase;
    double circleRadius;
    displayMenu();
    cin >> userChoice;
    while (userChoice < 1  || userChoice > 5)
    {
        cout <<"Please enter a valid number 1-5." << endl;
        cin >> userChoice;
    }

    switch (userChoice)
    {
        case 1:

            cout <<"Enter the height of the square:" << endl;
            cin >> squareHeight;

            areaSquare(squareHeight);
            break;
        
        case 2:
        
            cout <<"Enter the height and width of the rectangle, press enter after each one." << endl;
            cin >> rectangleHeight;
            cin >> rectangleBase;

            areaRectangle(rectangleHeight, rectangleBase);
            break;
        
        case 3:
        
            cout <<"Enter the base and height of the parallelogram, press enter after each one." << endl;
            cin >> paraBase;
            cin >> paraHeight;

            areaParallelogram(paraBase, paraHeight);
            break;
        
        case 4:
        
            cout <<"Enter the radius of the circle:" << endl;
            cin >> circleRadius;

            areaCircle(circleRadius);
            break;
        default:
            break;

    }
    
    }while (userChoice != 5);
}

