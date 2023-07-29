#include <string>
#include <iostream>

using namespace std;

// The friend function should be declared before the class.
void debugDog(Dog dog) {
  cout<<dog.name<<endl;
}

class Dog {

  private:

    string name;

    // Declaring the debugDog function as friend of this Dog class.
    // now the debugDog function can access the private data and methods of a Dog object.
    // Friend declarations can be in the private or public section (both ways are same).
    friend void debugDog(Dog);

    // declaring a friend class.
    friend class CustomDebugger;

};

class CustomDebugger {
  public:
    void debugDog(Dog dog) {
      cout<<dog.name<<endl;
    }
};