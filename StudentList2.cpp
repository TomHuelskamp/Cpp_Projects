#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
struct Student{
  int id;
  int gpa;
};

void function1(vector<Student*> &v);
int main(){
  vector<Student*> vect;
  function1(vect);

  cout<<vect[0]->id<<endl;
  cout<<vect[0]->gpa<<endl;
  
  return 0;
}
void function1(vector<Student*> &v){
  int input;
  int input2;
  char name[6] = "hello";
  cout<<"enter id: ";
  cin>>input;
  cout<<"enter gpa: ";
  cin>>input2;
  
  Student* a = new Student();
  a->id=input;
  a->gpa=input2;

  v.push_back(a);
}
