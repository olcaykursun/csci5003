#include <iostream>

using namespace std;

bool isPrime(int number) {
    if (number <= 1) return false;
    for (int i = 2; i <= sqrt(number); i++) 
    {
        if (number % i == 0) 
            return false;
    }
    return true;
}

int main() {
    int start, end;
    std::cout << "Enter the start of the interval: ";
    std::cin >> start;
    std::cout << "Enter the end of the interval: ";
    std::cin >> end;

    if (start > end || start < 0) 
    {
        std::cout << "Invalid interval." << std::endl;
        return 1;  //error
    }
    
    for (int number = start; number <= end; number++)
    {
        if (isPrime(number))
            cout << number << ": " <<  "Prime" << endl;
        else
            cout << number << ": " <<  "Composite" << endl;
        
        //alternatively - even though we haven't yet covered the ternary operator (? :), it comes in handy here
        string prime_or_composite = isPrime(number) ? "Prime" : "Composite";
        std::cout << number << ": " << prime_or_composite << std::endl;
    }
    
    return 0;
}
