#include<iostream>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;
//class is an abstrac class you can't create instances of it
class Movie {

public:
    Movie( string title, int priceCode ) {
        _title = title;
    }


    string getTitle() {
        return _title;
    }
    virtual int frequentRenterPoints( int daysRented){
      return 1;
    }
    virtual double getCharges( int daysRented ) = 0;

    /*
    virtual int frequentRenterPoints( int daysRented ){
      int defaultRenterPoints = 1;
      //TODO getPriceCode only == no need scope resu getDaysRented only
      if( thisRental->getMovie()->getPriceCode() == Movie::NEW_RELEASE &&
          thisRental->getDaysRented() > 1 )
          defaultRenterPoints++;
      return defaultRenterPoints;
      }
      */

private:
    string _title;
};

class RegularMovie : public Movie {
public:
  //this is called an initializer list
  // this is how you pass arguments to the super class
  RegularMovie(string title): Movie(title){}

  double getCharges( int daysRented){
    double thisAmount = 2;
    if( daysRented > 2 ){
      thisAmount += ( daysRented - 1) * 1.5;
      return thisAmount;
    }
  }

}

class NewReleaseMovie : public Movie {
public:

  virtual double getCharges( int daysRented ){
    return  daysRented * 3;
  }

  virtual int frequentRenterPoints( int daysRented){
    return daysRented  > 1 ? 2 : 3;
  }
}

class ChilrendsMovie : public Movie {
public:

  virtual double getCharges( int daysRented ){

  }
}

class Rental {

public:
    Rental( Movie *movie, int daysRented ) {
        _movie = movie;
        _daysRented = daysRented;
    }

    int getDaysRented() {
        return _daysRented;
    }

    Movie *getMovie() {
        return _movie;
    }




//TODO missing int's belongs in Rental
    double getCharges( ){
      int numDaysRented = thisRental->getDaysRented();
      //should just be getPriceCode
      switch( thisRental->getMovie()->getPriceCode() ) {
          case Movie::REGULAR:
              thisAmount += 2;
              if( numDaysRented > 2 )
                  thisAmount += ( numDaysRented - 1 ) * 1.5;
              break;
          case
              break;
          case Movie::CHILDRENS:
              thisAmount += 1.5;
              if( numDaysRented > 3 )
                  thisAmount += ( numDaysRented - 3 ) * 1.5;
              break;
      }
      return thisAmount;
    }

private:
    Movie *_movie;
    int _daysRented;
};

class Customer {

public:
     Customer( string name ) {
        _name = name;
    }

    void addRental( Rental *arg ) {
        _rentals.push_back( arg );
    }

    string getName() {
        return _name;
    }

//TODO

    string statement() {
        char buf[10];
        double totalAmount = 0;
        int totalRenterPoints = 0;
        string result = "Rental Record for " + getName() +"\n";

        for( vector<Rental *>::iterator iter = _rentals.begin(); iter != _rentals.end(); ++iter ) {
            // determine amount for each rental
            Rental *thisRental = *iter;
            double thisAmount = getCharges( thisRental );
            totalRenterPoints += frequentRenterPoints( thisRental );
        }


            // add bonus for a two day new relase rental


            // show figures for this rental
            sprintf( buf, "%.2f", thisAmount );
            result += "\t" + thisRental->getMovie()->getTitle() + "\t" + buf + "\n";
            totalAmount += thisAmount;
        }

        // add footer lines
        sprintf( buf, "%.2f", totalAmount) ;
        result = result + "Amount owed is " +  buf + "\n";
        sprintf( buf, "%d", frequentRenterPoints);
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
    Movie *movie1 = new Movie( "The Departed", Movie::REGULAR );
    Rental *rental = new Rental( movie1, 4 );
    thisCustomer->addRental( rental );

    Movie *movie2 = new Movie( "The Imitation Game", Movie::NEW_RELEASE );
    thisCustomer->addRental( new Rental( movie2, 2 ) );
    cout <<  thisCustomer->statement() << endl;
    return 0;
}
