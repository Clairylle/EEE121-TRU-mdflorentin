#include <iostream>
using namespace std;


void print_message(int n, string message)
{
    
    while (n > 0)
    {
        
        cout << message << endl;
        
        n--;
    }
}

int main()
{
    const int N = 0x121;
    print_message(N, "Hello EEE121!!!");

    return 0;
}
