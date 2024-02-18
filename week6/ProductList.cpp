#include <iostream>
#include <string>
#include <vector>
#include <format>

using namespace std;

const int DEFAULT_TAX = 10; //Use ALL_CAPS for immutable/constant values

class Product  // Class names should be capitalized by convention, using PascalCase, such as ProductDetail or UserAccount.
{
    double price;
    int discount_percent;   // Using snake_case for this data member. Consistent with the preferred naming convention.
    int taxRate;            // camelCase is also fine. Consider changing to snake_case for consistency across data member names.

public:
    std::string name;
    Product(std::string name = "", double price = 0.0, int discount_pct = 0, int taxRate = DEFAULT_TAX);
    
    void set_price(double);
    double get_price() const { return price; }

    void set_discount_percent(int);
    int get_discount_percent() const 
    {
        return discount_percent;
    }

    string to_str() const;
    void print_product_details() const;
    
    double get_discount_amount() const;
    double get_discount_price() const;
    
    double get_tax_amount() const;
    double get_total_price() const;
    
    void set_taxRate(int);
    double get_taxRate() const;
};

double Product::get_tax_amount() const
{
    double tax_amount = get_taxRate() * get_discount_price() / 100;
    return round(tax_amount * 100) / 100;
};

void Product::set_taxRate(int p_taxRate)
{
    taxRate = p_taxRate;
};

double Product::get_taxRate() const
{
    return taxRate;
}

double Product::get_total_price() const
{
    double total_price = get_discount_price() + get_tax_amount();
    return round(total_price * 100) / 100;
}

void Product::print_product_details() const
{
    cout << "PRODUCT DATA\n"
        << "Name:             " << name << endl
        << "Price:            " << get_price() << endl
        << "Discount percent: " << get_discount_percent() << endl
        << "Discount amount:  " << get_discount_amount() << endl
        << "Discount price:   " << get_discount_price() << endl
        << "Tax amount:       " << get_tax_amount() << endl
        << "Total price:      " << get_total_price() << "\n\n";
}

//Utility function to work with Product objects from outside the class, I used util_ to distinguish it from the member function
void util_print_product_details(const Product& p)
{
    cout << "PRODUCT DATA\n"
        << "Name:             " << p.name << endl
        << "Price:            " << p.get_price() << endl
        << "Discount percent: " << p.get_discount_percent() << endl
        << "Discount amount:  " << p.get_discount_amount() << endl
        << "Discount price:   " << p.get_discount_price() << endl
        << "Tax amount:       " << p.get_tax_amount() << endl
        << "Total price:      " << p.get_total_price() << "\n\n";
}

Product::Product(string p_name, double price, int discount_percent, int taxRate)
{
    name = p_name;
    set_price(price);
    set_discount_percent(discount_percent);
    set_taxRate(taxRate);
}

void Product::set_price(double p_price)
{
    price = round(p_price * 100) / 100;
}

void Product::set_discount_percent(int p_discount_percent)
{
    discount_percent = p_discount_percent;
}

double Product::get_discount_amount() const
{
    double discount_amount = price * discount_percent / 100;
    return round(discount_amount * 100) / 100;
}

double Product::get_discount_price() const
{
    double discount_price = price - get_discount_amount();
    return round(discount_price * 100) / 100;
}

void display_items(vector<Product> p)
{
    for (int i = 0; i<p.size(); ++i)
    {
        cout << i+1 << ". " << p[i].name << endl;
    }
}

int main()
{
    vector<Product> products;
    Product p1("Stanley", 12.99, 62);
    products.push_back(p1);
    products.push_back(Product("National", 15.99, 50, 20));
    
    Product p3 = Product("Economy Duct Tape", 20.00, 10, 30);
    products.push_back(p3);
    
    display_items(products);
    cout << "Which item are you interested in? ";
    
    int item_number;
    cin >> item_number;
    
    products[item_number-1].print_product_details();     //Calling the member function, the next line is the alternative
    util_print_product_details(products[item_number-1]); //Passing the object as a constant reference to the nonmember function
}
