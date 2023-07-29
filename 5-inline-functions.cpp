//* INLINE FUNCTIONS

#include <iostream>

using namespace std;

inline int maximum(int a, int b) {
  if(a > b)
    return a;
  else return b;
}

int main( ) {
  int a, b;

  cout<<"Enter a : ";
  cin>>a;
  cout<<endl;

  cout<<"Enter b : ";
  cin>>b;
  cout<<endl;

  // Observe that while defining the function 'maximum', we marked it as inline. This means, during
  // compilation, the function invokation will be replaced with the actual function sourcecode.
  // This will increase the applicatio binary size but will avoid the function  call overhead.
  // Inline functions should be short and simple.
  //* NOTE -
  // If the compiler sees that the function we are trying to inline is very long and contains
  // complicated logic, then it will not inline that function.
  cout<<"The maximum of "<<a<<"and"<<b<<" is = "<<maximum(a, b)<<endl;

  return 0;
}