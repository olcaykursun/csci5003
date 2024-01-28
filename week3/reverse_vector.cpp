//Reverse a vector in two different ways

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void print_vector(vector<double> prices_to_print)
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
    vector<double> prices;           // create empty vector
    print_vector(prices);
    
    prices.push_back(9.99);          // add element to vector
    print_vector(prices);
    
    prices.push_back(149.99);
    print_vector(prices);
    
    auto size = prices.size();       // size is 2
    double first = prices.front();   // first is 9.99
    double last = prices.back();     // last is 149.99
    double second = prices.at(1);    // second is 149.99
    prices.pop_back();               // remove back element
    print_vector(prices);
    
    size = prices.size();            // size is 1
    bool is_empty = prices.empty();  // is_empty is false
    last = prices.back();            // last is 9.99

    prices.push_back(15);
    print_vector(prices);
    prices.push_back(16);
    print_vector(prices);

    for (auto idx_plus_one = prices.size(); idx_plus_one>0; --idx_plus_one)
    {
        cout << prices.at(idx_plus_one - 1) << ' ';
    }
    cout << endl;
    print_vector(prices);

/*
    vector<double> reversed_prices;
    while (!prices.empty())
    {
        double price = prices.back();
        prices.pop_back();
        reversed_prices.push_back(price);
    }
    print_vector(prices);
    print_vector(reversed_prices);
 */

//reverse the prices using swapping ith element from the left and ith element from the right
    int n = prices.size();
    for (int left = 0, right = n-1 ; left < right; ++left, --right)
    {
        double temp = prices.at(left);
        prices[left] = prices[right];
        prices[right] = temp;
    }
    print_vector(prices);
    
    return 0;
}
