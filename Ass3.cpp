#include "Stack.h"
#include <iostream>

int main()
{
    int no;
    cout << "Welcome To ASSIGNMENT 3 SOLUTION " << endl;
    cout << "In order to proceed, Following are your options:" << endl;
    cout << "1: Delimiters Operation " << endl;
    cout << "2: Infix to Postfix Conversion " << endl;
    cout << "3: Postfix Evaluation " << endl;
    cout << "Kindly select your desired operation by selecting 1,2 or 3. In case you enter any other number, the program will terminate.. " << endl;

    cin >> no;

 //Task 1
    if (no == 1)
    {
        cout << "You have selected TASK 1 (Delimiters Operation)" << endl;
        cout << "Note: '0' will mean false, '1' will mean true. Incase of empty string, error message will be displayed..." << endl;
        string str;
        cout << "Enter your desired string = ";
        cin >> str;
        cout << "The output after performing operation is = "<< delimitersOk(str) << endl;
        cout << endl;

    }
    
 //Task 2(a)   
    else if (no == 2)
    {
        cout << "You have selected TASK 2a (Infix to Postfix Conversion)" << endl;
        string str;
        cout << "Enter your desired string = ";
        cin >> str;
        cout << "The Converted string is = " << InfixToPostfix(str) << endl;
        cout << endl;

    }

 //Task2(b)
    else if (no == 3)
    {
        cout << "You have selected TASK 2b (Postfix Evaluation)" << endl;
        string str;
        cout << "Enter your desired string = ";
        cin >> str;
        cout << "The output after evaluation is = " << evaluatePostfix(str) << endl;
        cout << endl;

    }

    else
    {
        cout << "Invalid Option Selected. The program has been terminated." << endl;
    }

}
