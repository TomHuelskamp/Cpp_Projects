#include <iostream>
#include <cstring>
using namespace std;
struct node{
  char name[10];
  node* connections[20];
  node* weights[20];
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
  node* n;
  cin>>n->name;
  cin.get();
  for(int i=0; i<20; i++){
    if(table[i]->name==n->name){
      cout<<"there is already a vertex with this name"<<endl;
      break;
    }else if(table[i]==NULL){
      table[i]=n;
      cout<<"added"<<endl;
      break;
    }
  }
}
void addEdge(node* table[20]){
  cout<<"Add Edge"<<endl;
  cout<<"first name: ";
  char name1[20];
  cout<<"second name: ";
  char name2[20];
  cout<<"weight: ";
}
void adjacencyTable(node* table[20]){
  for(int i=0; i<20; i++){
    if(table[i]!=NULL){
      cout<<table[i]->name<<", ";
    }
  }
}
