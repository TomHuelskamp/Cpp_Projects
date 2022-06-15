#include <iostream>
#include <cstring>
using namespace std;
struct node{
  char name[5];
};
void addVertex(int** connections, node*** names);
void addEdge(int** connections, node*** names);
void adjacencyTable(int** connections, node*** names);
void removeVertex(int** connections, node*** names);
void removeEdge(int** connections, node*** names);
void shortestPath(int** connections, node*** names);
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
    cout<<"'add vertex', 'add edge', 'print table', 'remove vertex', 'remove edge', 'find shortest path', or 'quit'?: ";
    char input[25];
    cin.get(input,25);
    cin.get();
    if(strcmp(input,"add vertex")==0){
      addVertex(connections, names);
    }else if(strcmp(input,"add edge")==0){
      addEdge(connections, names);
    }else if(strcmp(input,"print table")==0){
      adjacencyTable(connections,names);
    }else if(strcmp(input,"remove vertex")==0){
      removeVertex(connections,names);
    }else if(strcmp(input,"remove edge")==0){
      removeEdge(connections,names);
    }else if(strcmp(input,"quit")==0){
      break;
    }else if(strcmp(input,"find shortest path")==0){
      shortestPath(connections,names);
    }
  }
  return 0;
}
void addVertex(int** connections, node*** names){
  cout<<"add vertex"<<endl;
  cout<<"name(must be 4 or less characters!): ";
  char nn[5];
  cin.get(nn, 5);
  cin.get();

  for(int e=1; e<20; e++){
    if(!names[0][e]){
      names[0][e]=new node();
      names[e][0]=new node();
      strcpy(names[0][e]->name,nn);
      strcpy(names[e][0]->name,nn);
      break;
    }
  }
}
void addEdge(int** connections, node*** names){
  cout<<"add edge"<<endl;
  cout<<"vertex 1: ";
  char name1[5];
  cin.get(name1, 5);
  cin.get();
  
  cout<<"vertex 2: ";
  char name2[5];
  cin.get(name2, 5);
  cin.get();
  
  bool found=false;
  for(int y=0; y<20; y++){
    for(int x=0; x<20; x++){
      if(names[y][0]!=NULL&&names[0][x]!=NULL){
	if(strcmp(names[y][0]->name,name1)==0 && strcmp(names[0][x]->name,name2)==0){
	  int size;
	  cout<<"distance: ";
	  cin>>size;
	  cin.get();
	  connections[x][y]=size;
	  found=true;
      }
      }
    }
  }
  if(!found){
    cout<<"your chosen vertices couldn't be found"<<endl;
  }
}
void adjacencyTable(int** connections, node*** names){
  for(int y=0; y<20; y++){
    for(int x=0; x<20; x++){
      if(y==0||x==0){//name
	if(names[y][x]!=NULL){
	  int size=5-strlen(names[y][x]->name);
	  cout<<names[y][x]->name;
	  while(size>0){
	    cout<<" ";
	    size--;
	  }
	}else if(x==0&&y==0){
	  cout<<"     ";
	}else{
	  cout<<"-----";
	}
      }else{//distance
	cout<<""<<connections[y][x]<<"    ";
      }
      cout<<" ";
    }
    cout<<endl;
  }
}
void removeVertex(int** connections, node*** names){
  char vertex[5];
  cout<<"vertex: ";
  cin.get(vertex, 5);
  cin.get();
  for(int y=0; y<20; y++){
    for(int x=0; x<20; x++){
      if(names[y][x]!=NULL && strcmp(names[y][x]->name,vertex)==0){
	names[y][x]=NULL;
	if(y==0){
	  for(int i=0; i<20; i++){
	    connections[i][x]=0;
	  }
       }else{
	  for(int i=0; i<20; i++){
	    connections[y][i]=0;
	  }
	}
      }
    }
  }
}
void removeEdge(int** connections, node*** names){
  cout<<"vertex 1: ";//y
  char vertex1[5];
  cin.get(vertex1,5);
  cin.get();
  cout<<"vertex 2: ";//x
  char vertex2[5];
  cin.get(vertex2,5);
  cin.get();
  for(int y=0; y<20; y++){
    for(int x=0; x<20; x++){
      if(names[y][0]!=NULL&&names[0][x]!=NULL&&strcmp(names[y][0]->name,vertex1)==0&&strcmp(names[0][x]->name,vertex2)==0){
	connections[y][x]=0;
      }
    }
  }
}
void shortestPath(int** connections, node*** names){
  char start[5];
  cout<<"starting vertex: ";
  cin.get(start,5);
  cin.get();
  char destination[5];
  cout<<"destination vertex: ";
  cin.get(destination,5);
  cin.get();
  bool spresent=false;
  bool dpresent=false;
  bool present=false;
  int X;
  int Y;
  int connections2[20][20]=connections;
  int unvisitedIndexes[20];
  int distances[2][20];
  for(int i=0; i<20; i++){
    unvisitedIndexes[i]=i;
    distances[0][i]=i;
  }
  for(int y=0; y<20; y++){
    for(int x=0; x<20; x++){
      
    }
  }
  for(int y=0; y<20; y++){
    for(int x=0; x<20; x++){
      if(names[y][x]!=NULL&&strcmp(names[y][x]->name,start)==0){
	X=x;
	spresent=true;
	for(int i=0; i<20; i++){
	  ditances[1][i]=connections[i][X];
	}
      }
    }
  }
}
