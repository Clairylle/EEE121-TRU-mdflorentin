#include <iostream>
#include <string>
using namespace std;

// A function to check if a string is a palindrome or not
bool isPalindrome(string inputString)
{
    // Get the length of the string
    int length = inputString.length();

    // Loop from the first and last characters of the string
    for (int i = 0, j = length - 1; i < j; i++, j--)
    {
        // If the characters are not equal, the string is not a palindrome
        if (inputString[i] != inputString[j])
        {
            return false;
        }
    }

    // If the loop ends, the string is a palindrome
    return true;
}

int main()
{
    string inputString;
    char choice;

    do
    {
        cout << "INPUT A STRING: ";
        cin >> inputString;

        if (isPalindrome(inputString))
        {
            cout << inputString << " IS A PALINDROME" << endl;
        }
        else
        {
            cout << inputString << " IS NOT A PALINDROME" << endl;
        }

        cout << "DO YOU WANT TO CONTINUE? (Y/N): ";
        cin >> choice;


    } while (choice == 'y' || choice == 'Y');


    return 0;
}
