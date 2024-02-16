#include <iostream>
#include <string>

using namespace std;

class Product {
    double price;
    int discount_percent;
    int taxRate;

public:
    std::string name;
    Product(std::string name = "", double price = 0.0, int discount_pct = 0);
    void set_price(double);
    double get_price()
    {
        return price;
    }

    void set_discount_percent(int);

    int get_discount_percent()
    {
        return discount_percent;
    }

    string to_str();
    void print_product_details();
    
    double get_discount_amount() ;
    double get_discount_price() ;
};

void Product::print_product_details()
{
    cout << "PRODUCT DATA\n"
        << "Name:             " << name << endl
        << "Price:            " << get_price() << endl
        << "Discount percent: " << get_discount_percent() << endl
        << "Discount amount:  " << get_discount_amount() << endl
    << "Discount price:   " << get_discount_price() << "\n\n";
}

string Product::to_str()
{
    return name + " for $" +to_string(price);
}

Product::Product(string p_name, double price, int discount_percent)
{
    name = p_name;
    set_price(price);
    set_discount_percent(discount_percent);
}


void Product::set_price(double p_price)
{
    price = round(p_price * 100) / 100;
}

void Product::set_discount_percent(int p_discount_percent)
{
    discount_percent = p_discount_percent;
}

double Product::get_discount_amount()  {
    double discount_amount = price * discount_percent / 100;
    return round(discount_amount * 100) / 100;
}

double Product::get_discount_price()  {
    double discount_price = price - get_discount_amount();
    return round(discount_price * 100) / 100;
}



class Product2 {
    double price;
    int discount_percent;
    int taxRate;

public:
    std::string name;
    Product2(std::string name = "", double price = 0.0, int discount_pct = 0);
    void set_price(double);
    double get_price() const
    {
        return price;
    }

    void set_discount_percent(int);

    int get_discount_percent() const
    {
        return discount_percent;
    }

    string to_str() const;
    void print_product_details() const;
    
    double get_discount_amount() const;
    double get_discount_price() const;
};

void Product2::print_product_details() const
{
    cout << "PRODUCT DATA\n"
        << "Name:             " << name << endl
        << "Price:            " << get_price() << endl
        << "Discount percent: " << get_discount_percent() << endl
        << "Discount amount:  " << get_discount_amount() << endl
    << "Discount price:   " << get_discount_price() << "\n\n";
}

string Product2::to_str() const
{
    return name + " for $" +to_string(price);
}

Product2::Product2(string p_name, double price, int discount_percent)
{
    name = p_name;
    set_price(price);
    set_discount_percent(discount_percent);
}

void Product2::set_price(double p_price)
{
    price = round(p_price * 100) / 100;
}

void Product2::set_discount_percent(int p_discount_percent)
{
    discount_percent = p_discount_percent;
}

double Product2::get_discount_amount() const
{
    double discount_amount = price * discount_percent / 100;
    return round(discount_amount * 100) / 100;
}

double Product2::get_discount_price() const
{
    double discount_price = price - get_discount_amount();
    return round(discount_price * 100) / 100;
}






/*
void show_product(const Product& p)
{
    cout << "PRODUCT DATA\n"
        << "Name:             " << p.name << endl

        << "Price:            " << p.get_price() << endl
        //'this' argument to member function 'get_discount_amount' has type 'const Product', but function is not marked const
        //it means that get_price could possibly modify the object p which is const

        << "Discount Percent:     " << p.discount_percent << endl;
        //'discount_percent' is a private member of 'Product' so it cannot be accessed directly
}
*/


void show_product_pass_by_reference(Product& p) 
{
    cout << "PRODUCT DATA\n"
         << "Name:             " << p.name << endl // Accessible as get_name() is a const method
         << "Price:            " << p.get_price() << endl
         << "Discount Percent: " << p.get_discount_percent() << endl;

    p.name = "Dangerous";
}

void show_product_pass_by_value(Product p) 
{
    cout << "PRODUCT DATA\n"
         << "Name:             " << p.name << endl // Accessible as get_name() is a const method
         << "Price:            " << p.get_price() << endl
         << "Discount Percent: " << p.get_discount_percent() << endl;

    p.name = "Dangerous";
}

void show_product_pass_by_constant_reference(const Product2& p) 
{
    cout << "PRODUCT DATA\n"
         << "Name:             " << p.name << endl // Accessible as get_name() is a const method
         << "Price:            " << p.get_price() << endl
         << "Discount Percent: " << p.get_discount_percent() << endl;

    // p.set_price(100);  //it will not allow changes to name or price
}




int main()
{
    Product p("Stanley", 12.99, 62);

    //I will call it twice so that we can see that only local copy changes
    show_product_pass_by_value(p);
    show_product_pass_by_value(p);
    
    //I will call it twice so that we can see that the original changes
    show_product_pass_by_reference(p); //This prints and then makes an "accidental" change
    show_product_pass_by_reference(p);
    
    
    Product2 p2("Stanley", 12.99, 62); //Product2 class is defined better with the correct use of "const"
    
    //no need to call this twice because it will not allow (won't compile) if we make changes to the object in the function
    show_product_pass_by_constant_reference(p2); //Most efficient
}
