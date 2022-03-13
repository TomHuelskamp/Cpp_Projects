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
void test(node* table[]);
void print(node* table[]);
void rehash(node* table[]);
int main(){
  bool constant=true;
  int size = 100;
  node* table[size];
  for(int i=0; i<size;i++){
    table[i]=NULL;
  }
  char input[10];
  while(constant){
    cout<<"add, print, test, or quit?: ";
    cin.get(input,10);
    cin.get();
    if(strcmp(input,"add")==0){//add
      add(table);
    }else if(strcmp(input,"test")==0){//search
      test(table);
    }else if(strcmp(input,"print")==0){//print
      print(table);
    }else if(strcmp(input,"quit")==0){//quit
      break;
    }
  }
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
  cout<<"id (must be at least 4 digits): ";//id needs to be longer than size
  cin>>s->id;
  cout<<"gpa: ";
  cin>>s->gpa;
  cin.ignore(100, '\n');
  node* n = new node();//create new node
  n->value=s;//assign student to node
  int size = 100;
  if(table[(n->value->id)%size]==NULL){//empty spot in hash table
    table[(n->value->id)%size]=n;
    cout<<"added as a first node in the hash table";
  }else if(table[(n->value->id)%size]->next==NULL){
    node* t=table[(n->value->id)%size];
    n->next=t;
    table[(n->value->id)%size]=n;
    cout<<"added as a second node in the hash table";
  }else if(table[(n->value->id)%size]->next->next==NULL){
    node* t=table[(n->value->id)%size];
    n->next=t;
    table[(n->value->id)%size]=n;
    cout<<"added as a third node in the hash table";
  }else{//no room in hash table
    cout<<"no room in the hash table, rehashing...";
    //rehash
    
  }
  cout<<endl;
}
void test(node* table[]){
  int size=100;
  int id3;
  cout<<"id to be printed: ";
  cin>>id3;
  if(id3<=size){
    cout<<"this id won't work, it is too small";
  }else if(table[id3%size]!=NULL){//location of hash table corresponding to id has  node(s)
    //I'm running into problem when there is a same location but not id, because my if statements are checking for value/id
    //check if the next is null first
    if(table[id3%size]->value->id==id3){
      cout<<table[id3%size]->value->fname
      <<", "<<table[id3%size]->value->lname
      <<", "<<table[id3%size]->value->id
      <<", "<<table[id3%size]->value->gpa;
    }else if(table[id3%size]->next->value->id==id3){
      cout<<table[id3%size]->next->value->fname
      <<", "<<table[id3%size]->next->value->lname
      <<", "<<table[id3%size]->next->value->id
      <<", "<<table[id3%size]->next->value->gpa;
    }else if(table[id3%size]->next->next->value->id==id3){
      cout<<table[id3%size]->next->next->value->fname
      <<", "<<table[id3%size]->next->next->value->lname
      <<", "<<table[id3%size]->next->next->value->id
      <<", "<<table[id3%size]->next->next->value->gpa;
    }else{
      cout<<"no match found(1)";
    }
  }else{
    cout<<"no match found(2)";
  }
  cout<<endl;
  cin.ignore(100, '\n');
}
void print(node* table[]){
  int size=100;
  for(int i=0; i<size;i++){
    if(table[i]!=NULL){
     cout<<table[i]->value->fname
      <<", "<<table[i]->value->lname
      <<", "<<table[i]->value->id
      <<", "<<table[i]->value->gpa<<endl;
      if(table[i]->next!=NULL){
	cout<<table[i]->next->value->fname
	<<", "<<table[i]->next->value->lname
	<<", "<<table[i]->next->value->id
        <<", "<<table[i]->next->value->gpa<<endl;
	if(table[i]->next->next!=NULL){
	  cout<<table[i]->next->next->value->fname
	  <<", "<<table[i]->next->next->value->lname
	  <<", "<<table[i]->next->next->value->id
	  <<", "<<table[i]->next->next->value->gpa<<endl;
	}
      }
    }
  }
}
void rehash(node* table[]){
}
