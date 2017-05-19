#include<iostream>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;

class Movie {

public:
    Movie( string title ) {
        _title = title;
    }

    virtual int frequentRenterPoints(int daysRented) {
        return 1;
    }

    virtual double getCharges(int daysRented) = 0;

    string getTitle() {
        return _title;
    }

private:                                                          
    string _title;
};

class RegularMovie: public Movie {
public:
    RegularMovie(string title): Movie(title) {}

    double getCharges(int daysRented) {
        double thisAmount = 2;
        if( daysRented > 2 )
            thisAmount += ( daysRented - 1 ) * 1.5;
        return thisAmount;
    }

};

class NewReleaseMovie: public Movie {
public:
    NewReleaseMovie(string title): Movie(title) {}

    virtual double getCharges(int daysRented) {
        return daysRented * 3;
    }

    virtual int frequentRenterPoints(int daysRented) {
        return daysRented > 1 ? 2 : 1;
    }

};

class ChildrensMovie: public Movie {
public:
    ChildrensMovie(string title): Movie(title) {}

    virtual double getCharges(int daysRented) {
        double thisAmount = 1.5;
        if( daysRented > 3 ) 
            thisAmount += ( daysRented - 3 ) * 1.5;
        return thisAmount;
    }
};

class Rental {

public:
    Rental( Movie *movie, int daysRented ) {
        _movie = movie;
        _daysRented = daysRented;
    }

    int frequentRenterPoints() {
        return getMovie()->frequentRenterPoints(getDaysRented());
    }

    double getCharges() {
        return getMovie()->getCharges(getDaysRented());
    }

    int getDaysRented() {  return _daysRented;    }

    Movie *getMovie()   {  return _movie;         }

private:
    Movie *_movie;
    int _daysRented;
};

class Customer {

public:
     Customer( string name ) {
        _name = name;
    }

    void addRental( Rental *arg ) {  _rentals.push_back( arg );    }

    string getName()              {  return _name;                 }
    
    string statement() {
        char buf[10];
        double totalAmount = 0;
        int totalRenterPoints = 0;
        string result = "Rental Record for " + getName() +"\n";

        for( auto rental = _rentals.begin(); rental != _rentals.end(); ++rental ) {
            // determine amount for each rental

            double thisAmount = (*rental)->getCharges();
            totalRenterPoints += (*rental)->frequentRenterPoints();

            // show figures for this rental
            sprintf( buf, "%.2f", thisAmount );
            result += "\t" + (*rental)->getMovie()->getTitle() + "\t" + buf + "\n";
            totalAmount += thisAmount;
        }

        // add footer lines
        sprintf( buf, "%.2f", totalAmount) ;
        result = result + "Amount owed is " +  buf + "\n";
        sprintf( buf, "%d", totalRenterPoints);
        result = result + "You earned " + buf + " frequent renter points";
        return result;
    }

private:
    string _name;
    vector<Rental *> _rentals;
};

int main( int argc, char *argv[] ) 
{
    Customer *thisCustomer = new Customer( "John Smith" );
    Movie *movie1 = new RegularMovie( "The Departed" );
    Rental *rental = new Rental( movie1, 4 ); 
    thisCustomer->addRental( rental );

    Movie *movie2 = new NewReleaseMovie( "The Imitation Game" );
    Rental *rental2 = new Rental( movie2, 2 );
     thisCustomer->addRental( rental2 );
    cout <<  thisCustomer->statement() << endl;
    return 0;
}
