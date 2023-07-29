//* STATIC VARIABLES

#include <iostream>

using namespace std;

unsigned int increaseStudentCount( ) {
  // studentCount here is a static variable. It is scoped to this function only. But its lifetime
  // is as long as the program.
  static unsigned int studentCount= 0;

  studentCount += 1;

  return studentCount;
}

int main( ) {
  cout<<increaseStudentCount( )<<endl;
  cout<<increaseStudentCount( )<<endl;

  return 0;
}