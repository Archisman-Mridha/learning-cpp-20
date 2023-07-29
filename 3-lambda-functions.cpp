//* LAMBDA FUNCTIONS

#include <iostream>

using namespace std;

int main( ) {

  auto sayHello= [ ]( ) -> void {
    cout<<"Hello from a Lambda function"<<endl;
  };
  sayHello( );

  double sum= [ ](double a, double b) -> double {
    return a + b;
  }(1., 2.);

  double a= 1., b= 2.;
  // [ ] is called the Capture List. It is used by the Lambda function to capture variables from
  // its parent context. By default, the variables are copied. But we can also capture them by
  // reference by using an '&' sign in front of the variable.
  double multiply= [&a, &b]( ) -> double {
    return a * b;
  }( );

  // We can also capture everything from the parent context inside the Lambda function.
  // [=] -> capture everything by copy.
  // [&] -> captre everything by reference.
  auto divide= [=]( ) -> double {
    return a / b;
  };

  return 0;
}