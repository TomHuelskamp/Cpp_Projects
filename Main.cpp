#include <cstring>
#include <iostream>
using namespace std;
struct Student{//struct with all the information about student
  char fname[20];
  char lname[20];
  int id;
  float gpa;
};
struct node{//Linked List node to go in the hash table so that multipple students can be in one spot
  Student* value;
  node* next;
};
void add(node* table[]);
//void hashf(node* table[], node* n);
int main(){
  int size = 100;
  node* table[size];
  for(int i=0; i<size;i++){
    table[i]=NULL;
  }
  add(table);
  return 0;
}
void add(node* table[]){//creates a student node and passes it into hash
  Student* s = new Student();//create new student
  cout<<"first name: ";
  cin.get(s->fname,10);
  cin.get();
  cout<<"last name: ";
  cin.get(s->lname,10);
  cin.get();
  cout<<"id: ";
  cin>>s->id;
  cout<<"gpa: ";
  cin>>s->gpa;
  cout<<"test";
  cin.ignore(100, '\n');
  node* n = new node();//create new node
  n->value=s;//assign student to node
  int size = 100;
  if(table[size%(n->value->id)]==NULL){//empty spot in hash table
    table[size%(n->value->id)]=n;
  }else if(table[size%(n->value->id)]->next==NULL){
    node* t=table[size%(n->value->id)];
    n->next=t;
    table[size%(n->value->id)]=n;
  }else if(table[size%(n->value->id)]->next->next==NULL){
    node* t=table[size%(n->value->id)];
    n->next=t;
    table[size%(n->value->id)]=n;
  }else{//no room in hash table
    //rehash
    
  }
  /**if(table[size%(n->value->id)]->next->next->next==NULL){//rehash
  }
  
  else{
    node* temp = table[size%n->value->id];
    n->next=temp;
    table[size%n->value->id]=n;
  }
  **/
}
