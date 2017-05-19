#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Order {
public:
  Movie(string title) { _title= title; }

  virtual double getCharges(int entreCount){ } = 0;


private:
  string _protien;
  string _vegetable;
  string _appetizer;
  string _soup;
}

class ChickenEntre: public Order {
public:
  ChickenEntre(string CkDish){
  switch ( ckDish ){
    case "Gen":


  }
  }
}
