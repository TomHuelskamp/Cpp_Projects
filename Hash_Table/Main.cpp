//This program stores and creates students in a hash table
//Thomas Huelskamp
//March 15, 2022
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
struct Student{//struct for student with first name, last name, id, and gpa
  char fname[20];
  char lname[20];
  int id;
  double gpa;
};
struct node{//node is to be stored in the hash table, lists of nodes are used in case of collisions
  Student* value;
  node* next;
};
void add(node** &table, int &size);//function to manually add a student to the table
void test(node** &table, int &size);//this function isn't complete, it lets you search a student in the table
void print(node** &table, int &size);//function prints all the students from the table
void rehash(node** &table, int &size);//function creates a duplicate table that is twice as long and reassigns the table to the new table
void hash1(node** &table, int &size, char ifname[20], char ilname[20], int iid, double igpa, bool callFromGenerate);//function automatically adds a student to the original or rehashed table
void delete1(node** &table, int &size);//function deletes a student from the table
void generate(node** &table, int &size, int &counter);//function creates data for random students and adds them to the table
double round(double original);//function rounds the gpas of students to two decimal places
int main(){
  bool constant=true;//boolean used to keep a continous loop of prompts
  int size = 101;//the size of the original table is 101, so that it can be rehashed without being identical
  node** table = new node*[size];//hash table is a table of node pointers (each with the value of student). table and size are pushed into all the functions
  for(int i=0; i<size;i++){//fills the table with NULL in each slot
    table[i]=NULL;
  }
  int counter=100051;//the id for random students, incremented by one each new student
  while(constant){
    char input1[10];
    srand(time(NULL));
    cout<<"add, print, delete, generate, or quit?: ";//runs functions based on user input
    cin.get(input1,10);
    cin.get();
    if(strcmp(input1,"add")==0){//add
      add(table, size);
    }else if(strcmp(input1,"test")==0){
      test(table, size);
    }else if(strcmp(input1,"print")==0){//print
      print(table, size);
    }else if(strcmp(input1,"quit")==0){//quit
      break;
    }else if(strcmp(input1,"rehash")==0){//rehash
      rehash(table, size);
    }else if(strcmp(input1,"delete")==0){//delete
      delete1(table,size);
    }else if(strcmp(input1,"generate")==0){//generate
      cout<<"how many students do you want to generate?: ";//runs generate however many times the user chooses
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
void add(node** &table, int &size){
  //prompts the user for all the student's information and assigns student to a node
  Student* s = new Student();
  cout<<"first name: ";
  cin.get(s->fname,20);
  cin.get();
  cout<<"last name: ";
  cin.get(s->lname,20);
  cin.get();
  cout<<"id (must be at least 4 digits): ";
  cin>>s->id;
  cout<<"gpa: ";
  cin>>s->gpa;
  cin.ignore(100, '\n');
  node* n = new node();
  n->value=s;
  //adds the student node to the table depending on how many other students share the spot
  if(table[(n->value->id)%size]==NULL){//adds as a first node in the hash table
    table[(n->value->id)%size]=n;
    cout<<"added as a first node in the hash table";
  }else if(table[(n->value->id)%size]->next==NULL){//adds as a second node in the hash table
    node* t=table[(n->value->id)%size];
    n->next=t;
    table[(n->value->id)%size]=n;
    cout<<"added as a second node in the hash table";
  }else if(table[(n->value->id)%size]->next->next==NULL){//adds as a third node in the table
    node* t=table[(n->value->id)%size];
    n->next=t;
    table[(n->value->id)%size]=n;
    cout<<"added as a third node in the hash table";
  }else{//rehashes because there is no more room in the table
    cout<<"no room in the hash table, rehashing...";
    rehash(table, size);
    cout<<endl<<"the table has been rehashed, run add again to add this student"<<endl;
  }
  cout<<endl;
}
void test(node** &table, int &size){//this is an unrequired function used to debug
  int id3;
  cout<<"id to be printed: ";
  cin>>id3;
  if(id3<=size){
    cout<<"this id won't work, it is too small";
  }else if(table[id3%size]!=NULL){
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
  for(int i=0; i<size;i++){//goes through the table
    if(table[i]!=NULL){//prints the first node at location i
     cout<<table[i]->value->fname
      <<", "<<table[i]->value->lname
      <<", "<<table[i]->value->id
      <<", "<<round(table[i]->value->gpa)<<endl;
     if(table[i]->next!=NULL){//prints the second node at location i
	cout<<table[i]->next->value->fname
	<<", "<<table[i]->next->value->lname
	<<", "<<table[i]->next->value->id
	<<", "<<round(table[i]->next->value->gpa)<<endl;
	if(table[i]->next->next!=NULL){//prints the third node at location i
	  cout<<table[i]->next->next->value->fname
	  <<", "<<table[i]->next->next->value->lname
	  <<", "<<table[i]->next->next->value->id
	  <<", "<<round(table[i]->next->next->value->gpa)<<endl;
	}
      }
    }
  }
}
void rehash(node** &table, int &size){
  int size2=size*2;
  node** table2 = new node*[size2];//creates a second table that is twice as big as the original
  for(int i=0; i<=size2;i++){//fills the new table with nodes
    table2[i]=NULL;
  }
  for(int i=0; i<size;i++){//goes through the original table, adding all the students to the second table
    if(table[i]!=NULL){//adds the first node at location i to the new table
      hash1(table2, size2
	   ,table[i]->value->fname
	   ,table[i]->value->lname
	   ,table[i]->value->id
	    ,table[i]->value->gpa,false);
      if(table[i]->next!=NULL){//adds the second node at location i to the new table
	hash1(table2, size2
	     ,table[i]->next->value->fname
	     ,table[i]->next->value->lname
	     ,table[i]->next->value->id
	      ,table[i]->next->value->gpa,false);
	if(table[i]->next->next!=NULL){//adds the third node at a location i to the new table
	  hash1(table2, size2
	       ,table[i]->next->next->value->fname
	       ,table[i]->next->next->value->lname
	       ,table[i]->next->next->value->id
		,table[i]->next->next->value->gpa,false);
	}
      }
    }
   }
  table = table2;//reassigns table and size to the new table and doubled size
  size = size2;
}
void hash1(node** &table, int &size, char ifname[20], char ilname[20], int iid, double igpa,bool callFromGenerate){
  //this function is the same as add, but takes in information that is from the program
  //creates a new student with the given information and assigns the student as a value to a new node
  Student* s = new Student();
  strcpy(s->fname, ifname);
  strcpy(s->lname, ilname);
  s->id=iid;
  s->gpa=igpa;
  node* n = new node();
  n->value=s;
  if(table[iid%size]==NULL){//adds as a first node in the table
    table[iid%size]=n;
  }else if(table[iid%size]->next==NULL){//adds as a second node in the table
    node* t=table[iid%size];
    n->next=t;
    table[iid%size]=n;
  }else if(table[iid%size]->next->next==NULL){//adds as a third node in the table
    node* t=table[iid%size];
    n->next=t;
    table[iid%size]=n;
  }else if(callFromGenerate==true){//will not call rehash if the data is being hashed to a new table to prevent problematic loops
    rehash(table, size);
  }
}
void delete1(node** &table, int &size){
  int id3;
  cout<<"id to be deleted: ";
  cin>>id3;
  if(id3<=size){//filters out incorrect ids
    cout<<"this id won't work, it is too small";
  }
  else if(table[id3%size]!=NULL){//if the table has students with the same location as the hashed id
    if(table[id3%size]->value->id==id3){//deletes a matching first node
      if(table[id3%size]->next!=NULL){//reassigns the first node
	node* temp=table[id3%size]->next;
	table[id3%size]=temp;
	cout<<"deleted"<<endl;
      }else{
	table[id3%size]=NULL;
	cout<<"deleted"<<endl;
      }
    }else if(table[id3%size]->next!=NULL){//checks that a second node isn't empty to prevent problems
      if(table[id3%size]->next->value->id==id3){//deletes a matching second node
	if(table[id3%size]->next->next!=NULL){//reassigns the second node
	  node* temp=table[id3%size]->next->next;
	  table[id3%size]->next=temp;
	  cout<<"deleted"<<endl;
	}else{
	  table[id3%size]->next=NULL;
	  cout<<"deleted"<<endl;
	}
      }
    }else if(table[id3%size]->next->next!=NULL){//checks that a third node isn't empty to prevent problems
      if(table[id3%size]->next->next->value->id==id3){//deletes a matching third node
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
  //I got the file fnames.txt from Aaron Gao
  char fnamei[20];
  int line = 0;
  int rand1=(rand()%101);
  while(line<rand1){//sets the first name a random amount of times 
    if(fnames.is_open()){
      fnames>>fnamei;
    }
    line++;
  }
  fnames.close();

  ifstream lnames;
  lnames.open("lnames.txt");
  //I got the file lnames.txt from Aaron Gao
  char lnamei[20];
  int line2 = 0;
  int rand2 =(rand()%101) ;
  while(line2<rand2){//sets the last name a random amount of times
    if(lnames.is_open()){
      lnames>>lnamei;
    }
    line2++;
  }
  lnames.close();
  double rand3=(rand()%500);//creates a random gpa with two decimal places
  rand3 = rand3/100;
  hash1(table,size,fnamei,lnamei,counter,rand3,true);
  counter++;
}
double round(double original){
  double roundInt = (int)(original*100+.5);//takes the leading digits from the gpa and rounds
  return (double)roundInt/100;//reconverts the integer to the proper gpa size
}
