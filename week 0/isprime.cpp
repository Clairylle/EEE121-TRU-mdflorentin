#include <iostream>
using namespace std;

// A function to check if a number is prime or not
bool isPrime(int number)
{
    // If the number is less than 2, it is not prime
    if (number < 2)
    {
        return false;
    }

    // Loop from 2 to the square root of the number
    for (int i = 2; i * i <= number; i++)
    {
        // If the number is divisible by i, it is not prime
        if (number % i == 0)
        {
            return false;
        }
    }

    // If the loop ends, the number is prime
    return true;
}

int main()
{
    int inputNumber;
    char choice;

    do
    {
        cout << "INPUT AN INTEGER: ";
        cin >> inputNumber;
        if (isPrime(inputNumber))
        {
            cout << inputNumber << " IS A PRIME NUMBER" << endl;
        }
        else
        {
            cout << inputNumber << " IS NOT A PRIME NUMBER" << endl;
        }
        cout << "DO YOU WANT TO CONTINUE? (Y/N): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
