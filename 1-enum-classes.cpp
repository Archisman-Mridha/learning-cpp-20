//* ENUM CLASSES

#include <iostream>

using namespace std;

// The default type associated with an enum class is int. Which means each enumeration has a size
// of 4 bytes.
// We can change the type associated with the enumeration class.
enum class Month : unsigned char {

  // Multiple enumerations with same value
  Jan= 1, January= Jan,

  February,
  March,
  April,
  May,
  June,
  July,
  August,
  September,
  October,
  November,
  December
};

int main( ) {
  Month month= Month::January;
  cout<<"Month is "<<static_cast<unsigned char>(month)<<endl;

  switch(month) {
    using enum Month; // <-

    case January:
      cout<<"The month is January"<<endl;

    case February:
      cout<<"The month is February"<<endl;

    default:
      cout<<"The month is something else"<<endl;
  }

  return 0;
}