// Print digits of a number with spacing
// Use different approaches

#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> prices_to_print)
{
    if (prices_to_print.empty())
    {
        cout << "empty vector" << endl;
        return;
    }
    for (auto price: prices_to_print)
    {
        cout <<  price << ' ';
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    int x;
    cout << "Please enter a number: ";
    cin >> x;
    int original_number = x;
    int y = 1;
    int number_of_digits = 0;
    while (x/y > 0)
    {
        y *= 10;
        number_of_digits++;
    }
    
   for (int i = number_of_digits-1; i>=0; --i)
    {
        float weight = pow(10,i);
        int digit = floor(x/weight);
        cout << digit << ' ';
        x = x - weight*digit;
   }
    cout << endl << endl;

//----------------------------------
    int reversed_number = 0;
//    cout << original_number << endl;
    while (original_number > 0)
    {
        reversed_number = reversed_number*10 + original_number % 10;
        original_number /= 10;
    }
//    cout << reversed_number << endl;
    while (reversed_number > 0)
    {
        cout << reversed_number % 10 << ' ';
        reversed_number /= 10;
    }
    cout << endl;
    
//----------------------------------
/*
    use mod and div to find the digits of a user-entered number from right to left
    insert them into a vector and then reverse it and then print the vector
*/
    cout << "the last part" << endl;
    x = 456;
    vector<int> digits;
    while (x>0)
    {
        digits.push_back(x%10);
        x /= 10;
    }
    
    int n = digits.size();
    for (int left = 0, right = n-1 ; left < right; ++left, --right)
    {
        std:swap(digits[left], digits[right]);
    }
    print_vector(digits);
    return 0;
}
