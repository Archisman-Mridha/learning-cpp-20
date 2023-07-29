//* CONCEPTS - Used to set constraints on type parameters of a template function.

#include <iostream>

using namespace std;

template <typename T>
requires integral<T> // <- Built in concept.
/*
template <T>
requires is_integral_v<T> // <- alternate syntax

template <integral T> // <- alternate compact syntax

//* Another alternate syntax
template <typename T>
T add(T a, T b)
requires integral T
*/
T add(T a, T b) {
  return a + b;
}

// Custom concept
template<typename T>
concept MyCustomConcept= requires(T a) {
  // This means that the type parameter T should be such that, any value of T is multipliable to
  // another value of type T.
  // The compiler only checks the syntax and doesn't actually do the operations.
  a * a;

  // NOTE - you can take a look at nested and compound requirements.
};
template<MyCustomConcept T> // <- Using the custom concept
T someFn(T someParam) { }

template<typename T>
concept AnotherCustomConcept= is_floating_point_v<T>;

template<typename T>
requires MyCustomConcept<T> && AnotherCustomConcept<T> // <- Conjunction (&&) or disjunction (||) of concepts
T someOtherFn(T t) { }

int main( ) {
  return 0;
}