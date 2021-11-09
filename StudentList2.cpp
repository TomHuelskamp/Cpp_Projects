#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
struct Student{
  char fname[10];
  char lname[10];
  int id;
  float gpa;
};

void add(vector<Student*> &v);
int main(){
  vector<Student*> vect;
  add(vect);

  cout<<vect[0]->fname<<endl;
  cout<<vect[0]->lname<<endl;
  cout<<vect[0]->id<<endl;
  cout<<vect[0]->gpa<<endl; 
  
  return 0;
}
void add(vector<Student*> &v){
  
  Student* a = new Student();
  
  cout<<"First Name: ";
  cin.get(a->fname, 10);
  cin.get();
  cout<<"Last Name: ";
  cin.get(a->lname, 10);
  cin.get();
  cout<<"Student ID: ";
  cin>>a->id;
  cout<<"Grade Point Average: ";
  cin>>a->gpa;

  v.push_back(a);
}
