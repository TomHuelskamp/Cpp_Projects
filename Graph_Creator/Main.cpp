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
void addVertex(int** connections, node*** names);
void addEdge(int** connections, node*** names);
int main(){
  int** connections= new int*[20];
  node*** names=new node**[20];
  for (int a=0; a<20; a++){
    connections[a]=new int[20];
    names[a]=new node*[20];
  }
  for (int y=0; y<20; y++){
    for(int x=0; x<20; x++){
      connections[y][x]=0;
      names[y][x]=NULL;
    }
  }
  bool loop=true;
  while(loop){
    cout<<"add 'vertex', add 'edge', print 'table', or 'quit'?: ";
    char input[10];
    cin.get(input,10);
    cin.get();
    if(strcmp(input,"vertex")==0){
      addVertex(connections, names);
    }else if(strcmp(input,"edge")==0){
      addEdge(connections, names);
    }else if(strcmp(input,"table")==0){

    }else{
    }
  }
  return 0;
}
void addVertex(int** connections, node*** names){
  cout<<"add vertex"<<endl;
  cout<<"name: ";
  node* n=new node();
  cin>>n->name;
  cin.get();
  for(int e=0; e<20; e++){
    if(!names[0][e]){
      names[0][e]=n;
      names[e][0]=n;
      break;
    }
  }
}
void addEdge(int** connections, node*** names){
  cout<<"add edge"<<endl;
  cout<<"name 1: ";
  char name1[10];
  cin.get(name1, 10);
  cin.get();
  cout<<"name 2: ";
  char name2[10];
  cin.get(name2, 10);
  cin.get();
  bool found=false;
  for(int y=0; y<20; y++){
    for(int x=0; x<20; x++){
      if((names[y][0]->name==name1 && names[0][x]->name==name2)||(names[y][0]->name==name2 && names[0][x]->name==name1)){
	int size;
	cout<<"distance: ";
	cin>>size;
	cin.get();
	connections[y][x]=size;
	connections[x][y]=size;
	found=true;
      }
    }
  }
  if(!found){
    cout<<"your chosen vertices couldn't be found";
  }
}
