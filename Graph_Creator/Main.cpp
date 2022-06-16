//This program creates weighted directional graphs and prints them in an adjacency table
//Thomas Huelskamp
//June 15, 2022
#include <iostream>
#include <cstring>
using namespace std;
struct node{//used to fill an array of names
  char name[5];
};
void addVertex(int** connections, node*** names);
void addEdge(int** connections, node*** names);
void adjacencyTable(int** connections, node*** names);
void removeVertex(int** connections, node*** names);
void removeEdge(int** connections, node*** names);
void shortestPath(int** connections, node*** names);
int main(){
  int** connections= new int*[20];//table of weighted connections from y to x
  node*** names=new node**[20];//table of names
  for (int a=0; a<20; a++){
    connections[a]=new int[20];
    names[a]=new node*[20];
  }
  for (int y=0; y<20; y++){//names are all null and weights are all 0
    for(int x=0; x<20; x++){
      connections[y][x]=0;
      names[y][x]=NULL;
    }
  }
  bool loop=true;
  while(loop){//commands
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

  for(int e=1; e<20; e++){//adds names to the first empty space in the name table
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
      if(names[y][0]!=NULL&&names[0][x]!=NULL){//once names are located
	if(strcmp(names[y][0]->name,name1)==0 && strcmp(names[0][x]->name,name2)==0){//adds weight in connections table
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
      if(y==0||x==0){//names are at the top and left edges
	if(names[y][x]!=NULL){
	  int size=5-strlen(names[y][x]->name);//keeps even spacing for different length names (doesn't even out for wieghts yet though)
	  cout<<names[y][x]->name;
	  while(size>0){
	    cout<<" ";
	    size--;
	  }
	}else if(x==0&&y==0){
	  cout<<"     ";
	}else{
	  cout<<"-----";//no name
	}
      }else{//weights are all the rest
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
      if(names[y][x]!=NULL && strcmp(names[y][x]->name,vertex)==0){//locates vertex
	names[y][x]=NULL;
	if(y==0){//zeroes out the row
	  for(int i=0; i<20; i++){
	    connections[i][x]=0;
	  }
	}else{//zeroes out the column
	  for(int i=0; i<20; i++){
	    connections[y][i]=0;
	  }
	}
      }
    }
  }
}
void removeEdge(int** connections, node*** names){
  cout<<"vertex 1: ";//y or row
  char vertex1[5];
  cin.get(vertex1,5);
  cin.get();
  cout<<"vertex 2: ";//x or column
  char vertex2[5];
  cin.get(vertex2,5);
  cin.get();
  for(int y=0; y<20; y++){
    for(int x=0; x<20; x++){//if the names exist, replace weight with 0
      if(names[y][0]!=NULL&&names[0][x]!=NULL&&strcmp(names[y][0]->name,vertex1)==0&&strcmp(names[0][x]->name,vertex2)==0){
	connections[y][x]=0;
      }
    }
  }
}
void shortestPath(int** connections, node*** names){//finds the weight of the shortest path
  char start[5];
  cout<<"starting vertex: ";
  cin.get(start,5);
  cin.get();
  char destination[5];
  cout<<"destination vertex: ";
  cin.get(destination,5);
  cin.get();
  int X;
  int Y;
  int** connections2 = new int*[20];
  for(int a=0; a<20; a++){
    connections2[a]=new int[20];
  }
  for(int y=0; y<20; y++){
    for(int x=0; x<20; x++){
      connections2[y][x]=connections[y][x];
    }
  }
  for(int i=0; i<20; i++){
      if(names[0][i]!=NULL&&strcmp(names[0][i]->name,start)==0){
	X=i;	
	cout<<"start found"<<endl;
      }
      if(names[i][0]!=NULL&&strcmp(names[i][0]->name,destination)==0){
	Y=i;
	cout<<"destination found"<<endl;
      }
  }
  for(int x=1; x<20; x++){//x,y is the spot where connections are being tested
    for(int y=1; y<20; y++){
      
      for(int nx=1; nx<20; nx++){//nx is used to find the distance from the connection to any destination
	for(int ny=1; ny<20; ny++){//ny is used to find the distance from the "test vertex" to one of its immeadiate connections
	  
	  if(y!=x&&!(ny==y&&nx==x)){//if a shorter path is found from the test vertex to any second test vertex, record in the shortest path table  
	    if(connections[y][nx]!=0&&connections[ny][x]!=0){
	      if((connections2[y][x]==0||connections2[y][x]>connections2[y][nx]+connections2[ny][x])&&connections2[y][nx]+connections2[ny][x]>0){
		connections2[y][x]=connections2[y][nx]+connections2[ny][x];
	      }
	    }
	  }

	}
      }
    }
  }
  if(connections2[Y][X]>0){
    cout<<"weight-> "<<connections2[Y][X]<<endl;
  }else{
    cout<<"no connection"<<endl;
  }
}
