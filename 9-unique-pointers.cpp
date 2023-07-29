//* UNIQUE POINTERS (part of SMART POINTERS)

#include <memory>
#include <string>
#include <iostream>

using namespace std;

class Dog{
  private:
    string name;

  public:
    Dog(string name)
      : name(name)
    { }

    void printName( ) {
      cout<<this->name<<endl;
    }
};

int main( ) {
  // This unique pointer cannot be copied or copy constructors cannot be used, since only 1 pointer
  // is allowed to manage the stack allocated memory.
  unique_ptr<Dog> dog= make_unique<Dog>("Good boy");
  // When 'dog' goes out of scope, 'delete' statement is automatically executed. We don't need to
  // write it explicitly.

  dog.get( )->printName( );

  // Move ownership of the memory from one to another unqiue pointer. the 'dog' unique pointer now
  // becomes null pointer.
  unique_ptr<Dog> newDogManager= move(dog);

  // Stop the unique pointer from managing that memory. 'newDogManager' now becomes null pointer.
  newDogManager.release( );

  return 0;
}