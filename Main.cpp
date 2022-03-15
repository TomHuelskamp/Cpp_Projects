//add input
//fix rehash: seg fault, and need a new hash function
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
struct Student{//struct with all the information about student
  char fname[20];
  char lname[20];
  int id;
  double gpa;
};
struct node{//Linked List node to go in the hash table so that multipple students can be in one spot
  Student* value;
  node* next;
};
void add(node** &table, int &size);
//void hashf(node* table[], node* n);
void test(node** &table, int &size);
void print(node** &table, int &size);
void rehash(node** &table, int &size);
void hash1(node** &table, int &size, char ifname[20], char ilname[20], int iid, double igpa, bool callFromGenerate);
void delete1(node** &table, int &size);
void generate(node** &table, int &size, int &counter);
int main(){
  bool constant=true;
  int size = 101;
  node** table = new node*[size];
  for(int i=0; i<size;i++){
    table[i]=NULL;
  }
  int counter=100051;
  while(constant){
    char input1[10];
    srand(time(NULL));
    cout<<"add, print, delete, generate, or quit?: ";
    cin.get(input1,10);
    cin.get();
    if(strcmp(input1,"add")==0){//add
      add(table, size);
    }else if(strcmp(input1,"test")==0){//search
      test(table, size);
    }else if(strcmp(input1,"print")==0){//print
      print(table, size);
    }else if(strcmp(input1,"quit")==0){//quit
      break;
    }else if(strcmp(input1,"rehash")==0){
      rehash(table, size);
    }else if(strcmp(input1,"delete")==0){//delete
      delete1(table,size);
    }else if(strcmp(input1,"generate")==0){
      cout<<"how many students do you want to generate?: ";
      int manytimes=0;
      cin>>manytimes;
      cin.get();
      while(manytimes>0){
	generate(table,size,counter);
	manytimes--;
      }
    }
    cout<<endl;
  }
  return 0;
}
void add(node** &table, int &size){//creates a student node and passes it into hash
  Student* s = new Student();//create new student
  cout<<"first name: ";
  cin.get(s->fname,20);
  cin.get();
  cout<<"last name: ";
  cin.get(s->lname,20);
  cin.get();
  cout<<"id (must be at least 4 digits): ";//id needs to be longer than size
  cin>>s->id;
  cout<<"gpa: ";
  cin>>s->gpa;
  cin.ignore(100, '\n');
  node* n = new node();//create new node
  n->value=s;//assign student to node
  //int size = 100;
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
    rehash(table, size);
    cout<<endl<<"the table has been rehashed, run add again to add this student"<<endl;
  }
  cout<<endl;
}
void test(node** &table, int &size){
  // int size=100;
  int id3;
  cout<<"id to be printed: ";
  cin>>id3;
  if(id3<=size){
    cout<<"this id won't work, it is too small";
  }else if(table[id3%size]!=NULL){//location of hash table corresponding to id has  node(s)
    //I'm running into problem when there is a same location but not id, because my if statements are checking for value/id
    //check if the next is null first
    //problem fixed in the delete function
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
void print(node** &table, int &size){
  for(int i=0; i<size;i++){
    if(table[i]!=NULL){
     cout<<table[i]->value->fname
      <<", "<<table[i]->value->lname
      <<", "<<table[i]->value->id
	 <<", "<<setprecision(2)<<table[i]->value->gpa<<endl;
      if(table[i]->next!=NULL){
	cout<<table[i]->next->value->fname
	<<", "<<table[i]->next->value->lname
	<<", "<<table[i]->next->value->id
	    <<", "<<setprecision(2)<<table[i]->next->value->gpa<<endl;
	if(table[i]->next->next!=NULL){
	  cout<<table[i]->next->next->value->fname
	  <<", "<<table[i]->next->next->value->lname
	  <<", "<<table[i]->next->next->value->id
	      <<", "<<setprecision(3)<<table[i]->next->next->value->gpa<<endl;
	}
      }
    }
  }
}
void rehash(node** &table, int &size){
  int size2=size*2;
  node** table2 = new node*[size2];
  for(int i=0; i<=size2;i++){
    table2[i]=NULL;
  }
  for(int i=0; i<size;i++){
    if(table[i]!=NULL){
      hash1(table2, size2
	   ,table[i]->value->fname
	   ,table[i]->value->lname
	   ,table[i]->value->id
	    ,table[i]->value->gpa,false);
      if(table[i]->next!=NULL){
	hash1(table2, size2
	     ,table[i]->next->value->fname
	     ,table[i]->next->value->lname
	     ,table[i]->next->value->id
	      ,table[i]->next->value->gpa,false);
	if(table[i]->next->next!=NULL){
	  hash1(table2, size2
	       ,table[i]->next->next->value->fname
	       ,table[i]->next->next->value->lname
	       ,table[i]->next->next->value->id
		,table[i]->next->next->value->gpa,false);
	}
      }
    }
   }
  table = table2;
  size = size2;
}
void hash1(node** &table, int &size, char ifname[20], char ilname[20], int iid, double igpa,bool callFromGenerate){//this function should be nearly identical to add, but is necessary for hash from table and rehash
  Student* s = new Student();
  strcpy(s->fname, ifname);
  strcpy(s->lname, ilname);
  s->id=iid;
  s->gpa=igpa;
  node* n = new node();
  n->value=s;
  if(table[iid%size]==NULL){
    table[iid%size]=n;
  }else if(table[iid%size]->next==NULL){
    node* t=table[iid%size];
    n->next=t;
    table[iid%size]=n;
  }else if(table[iid%size]->next->next==NULL){
    node* t=table[iid%size];
    n->next=t;
    table[iid%size]=n;
  }else if(callFromGenerate==true){
    rehash(table, size);
  }
}
void delete1(node** &table, int &size){//test, but deletes not prints
  int id3;
  cout<<"id to be deleted: ";
  cin>>id3;
  if(id3<=size){
    cout<<"this id won't work, it is too small";
  }
  else if(table[id3%size]!=NULL){//location of hash table corresponding to id has  node(s)
    if(table[id3%size]->value->id==id3){
      if(table[id3%size]->next!=NULL){//rm node is the first in a list
	node* temp=table[id3%size]->next;
	table[id3%size]=temp;
	cout<<"deleted"<<endl;
      }else{//rm node is the only
	table[id3%size]=NULL;
	cout<<"deleted"<<endl;
      }
    }else if(table[id3%size]->next!=NULL){
      if(table[id3%size]->next->value->id==id3){
	if(table[id3%size]->next->next!=NULL){//node after rm node
	  node* temp=table[id3%size]->next->next;
	  table[id3%size]->next=temp;
	  cout<<"deleted"<<endl;
	}else{//no node after rm node
	  table[id3%size]->next=NULL;
	  cout<<"deleted"<<endl;
	}
      }
    }else if(table[id3%size]->next->next!=NULL){
      if(table[id3%size]->next->next->value->id==id3){
	table[id3%size]->next->next=NULL;
	cout<<"deleted"<<endl;
      }
    }else{
      cout<<"no match found(1)"<<endl;
    }
  }
  else{
    cout<<"no match found(2)"<<endl;
  }
  cin.ignore(100, '\n');
}
void generate(node** &table, int &size, int &counter){
  ifstream fnames;
  fnames.open("fnames.txt");
  char fnamei[20];
  int line = 0;
  int rand1=(rand()%101);
  while(line<rand1){
    if(fnames.is_open()){
      fnames>>fnamei;
    }
    line++;
  }
  fnames.close();

  ifstream lnames;
  lnames.open("lnames.txt");
  char lnamei[20];
  int line2 = 0;
  int rand2 =(rand()%101) ;
  while(line2<rand2){
    if(lnames.is_open()){
      lnames>>lnamei;
    }
    line2++;
  }
  lnames.close();
  double rand3=(rand()%5);
  hash1(table,size,fnamei,lnamei,counter,rand3,true);
  counter++;
}
