#include <iostream>
#include <string>
#include <vector>

using namespace std;

string to_upper(const string& str)
{
    string upper_str;
    for (const char& c : str)
    {
        upper_str.push_back(toupper(c));
    }
    return upper_str;
}

class Movie {
private:                         // data members are private
    string title = "";
    int year = 0;
public:                          // member functions are public
    void set_title(string);
    string get_title();
    void set_year(int);
    int get_year();
    bool equals(const Movie&);
    bool iequals(const Movie&);
    void print();
};

// member function definitions
void Movie::set_title(string title_param) {
    title = title_param;
}
string Movie::get_title() {
    return title;
}

void Movie::set_year(int year_param) {
    if (year_param < 1888) {
        throw invalid_argument("Year must be 1888 or later.");
    }
    year = year_param;
}
int Movie::get_year() {
    return year;
}

bool Movie::equals(const Movie& to_compare) //case-sensitive
{
    return (title == to_compare.title &&
            year == to_compare.year);
}

bool Movie::iequals(const Movie& to_compare) //case-insensitive
{
    return (to_upper(title) == to_upper(to_compare.title) &&
            year == to_compare.year);
}

void Movie::print()
{
    cout << "MOVIE DATA\n"
         << "Title: " << get_title() << endl   // get title
         << "Year:  " << get_year() << endl;   // get year
}

void print_movies(vector<Movie> movies)
{
    for (auto & m: movies)
    {
        m.print();
        cout << endl;
    }
}

int main() {
    Movie movie1, movie2, movie3, movie4;
    movie1.set_title("Roundhay Garden Scene");
    movie1.set_year(1888);
    movie2.set_title("ABC");
    movie2.set_year(1950);
    movie3.set_title("ABC");
    movie3.set_year(1950);
    movie4.set_title("ABC");
    movie4.set_year(2000);

    vector<Movie> movies = {movie1, movie2, movie3, movie4};
    for (int i = 0; i < movies.size()-1; i++)  //size() also works because j starts from i+1
        for (int j = i+1; j < movies.size(); j++)
            if (movies[i].iequals(movies[j]))
                //cannot access private "title": cout << "duplicate found! " << movies[i].title << "and" < movies[j].title << "\n";
                cout << "duplicate found: " << movies[i].get_title() << " and " << movies[j].get_title() << "\n";

    
    //Get the title and year of a 5th movie.Then add this movie to the movies vector.

    Movie movie5; //At this point we dont know the constructor concept, do it as follows:
    
    string title;
    cout << "Please enter the title of the movie: ";
    cin >> title;
    
    int year;
    cout << "Please enter the year of the movie: ";
    cin >> year;

    movie5.set_title(title);
    movie5.set_year(year);
    
    movies.push_back(movie5);
    
    cout << "The original list of " << movies.size() << " movies:" << endl;
    print_movies(movies);

    
    vector<Movie> unique_movies;
    while (!movies.empty())
    {
        Movie movie = movies.back();    //get the last movie in the vector of n movies
        movies.pop_back();              //remove the last movie
        bool is_unique = true;          //check if you can find the movie in the vector of n-1 movies
        for (const Movie& to_compare: movies)
        {
            if (movie.iequals(to_compare))
            {
                is_unique = false;
                break;
            }
        }
        if (is_unique)                  //if not found elsewhere, then it is unique
        {
            unique_movies.push_back(movie);
        }
    }
    cout << "The unique movie list with " << unique_movies.size() << " movies:" << endl;
    print_movies(unique_movies);
    
    return 0;
}
