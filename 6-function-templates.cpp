//* FUNCTION TEMPLATES

#include <iostream>

using namespace std;

// Template function is a blueprint.
template<typename T= int&> // <- Default type parameter.
T maximum(T& a, T& b) { // <- Passing arguments by reference.

  // Type traits.
  if(!(is_integral<T> || is_floating_point<T>))
    throw ("Only integral or floating point type of arguments supported");

  if(a > b)
    return a;
  else return b;
}

template<typename T>
T minimum(T a, T b) {
  if(a > b)
    return a;
  else return b;
}
// Template specialization -
// This is not a function blueprint, rather it is actual C++ code.
template<>
int* minimum<int*>(int* a, int* b) {
  if(*a < *b)
    return a;
  else return b;
}
// Template specialization is actual C++ code. Instead, we can use 'template overloading'.
// (The actual code will be generated during compilation time).
// Precedance(template overloading) < Precedance(template specialization).
template<typename T>
T* minimum(T* a, T* b) {
  if(*a < *b)
    return a;
  else return b;
}

int main( ) {
  unsigned int a= 1, b= 2;

  // When we invoke the template function, the compiler generates the actual function with required
  // types inferred from the function invokation.
  // The generated function is called a template instance.
  cout<<"Maximum is = "<<maximum<unsigned int&>(a, b)<<endl;

  // We explicitly mention value of the type parameter T. The arguments are implicitly converted to
  // the type parameter first and then passed on to the function.
  minimum<int>(a, 0.1);

  // decltype is used to get the type of an expression. For example here we are getting the type of
  // the expression 'minimum<int>(1, 2.)'.
  decltype(minimum(1, 2)) c= 10;

  // Named template parameters for Lambda functions
  auto maximumLambdaFn=
    [ ]
    <typename T>
    (T a, T b) -> T {
      return a + b;
    };

  return 0;
}