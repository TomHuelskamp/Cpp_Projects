#include <iostream>
#include <cstring>
using namespace std;
/**
struct node{
  char name[10];
  node* connections[20];
  int  weights[20];
};
void adjacencyTable(node* table[20]);
void addVertex(node* table[20]);
void addEdge(node* table[20]);
int main(){
  node* table[20];
  for(int i=0;i<20;i++){
    table[i]=NULL;
  }
  bool loop=true;
  while(loop){
    cout<<"add 'vertex', add 'edge', print adjacency 'table',or 'quit'?: ";
    char input[10];
    cin.get(input, 10);
    cin.get();
    if(strcmp(input,"vertex")==0){
      addVertex(table);
    }else if(strcmp(input,"edge")==0){
      addEdge(table);
    }else if(strcmp(input,"table")==0){
      adjacencyTable(table);
    }else{
      break;
    }
  }
  return 0;
}
void addVertex(node* table[20]){
  cout<<"Add Vertex"<<endl;
  cout<<"name: ";
  node* n = new node();;
  cin>>n->name;
  cin.get();
  for(int i=0; i<20; i++){
    if(table[i]==NULL){
      table[i]=n;
      cout<<"added"<<endl;
      break;
    }else if(strcmp(table[i]->name,n->name)==0){
      cout<<"a vertex already has this name"<<endl;
      break;
    }
  }
}
void addEdge(node* table[20]){
  cout<<"Add Edge"<<endl;
  cout<<"first name: ";
  char n1[20];
  cout<<"second name: ";
  char n2[20];
  cout<<"weight: ";
  int wt;
  for(int i=0; i<20; i++){
    if(table[i]!=NULL){
      if(strcmp(table[i]->name,n1)==0){
	for(int j; j<20; j++){
	}
      }
    }else{
      cout<<"vertices couldn't be found"<<endl;
    }
  }
}
void adjacencyTable(node* table[20]){
  for(int i=0; i<20; i++){
    if(table[i]!=NULL){
      cout<<table[i]->name<<", ";
    }
  }
  cout<<endl;
}
**/
struct node{
  char name[10];
};
void addVertex(int **connections, node* **names);
int main(){
  int connections[20][20];
  node* names[20][20];
  bool loop=true;
  while(loop){
    cout<<"add 'vertex', add 'edge', print 'table', or 'quit'?: ";
    char input[10];
    cin.get(input,10);
    cin.get();
    if(strcmp(input,"vertex")==0){
      
    }else if(strcmp(input,"edge")==0){

    }else if(strcmp(input,"table")==0){

    }else{
    }
  }
  return 0;
}
void addVertex(int **connections, node* **names){
}
