#include<iostream>
using namespace std;
bool ratmaze(char maze[11][11],int solution[11][11],int i,int j,int N,int M)
{
    if(maze[i][j]=='X')
  {
    return false;
  }
  if(i==N && j==M)
  {
    solution[i][j]=1;
    for(int x=0;x<=N;x++)
    {
      for(int y=0;y<=M;y++)
      {
        cout<<solution[x][y]<<" ";
      }
      cout<<endl;
    }
    return true;
  }
  if(i>N || j>M || i<0 || j<0)
  {
    return false;
  }
  
  solution[i][j]=1;
  bool rightSuccess,downSuccess,topSuccess,leftSuccess;
  if(solution[i+1][j]==0){
    downSuccess=ratmaze(maze,solution,i+1,j,N,M);
  }
  if(solution[i][j+1]==0 && !downSuccess){
    rightSuccess=ratmaze(maze,solution,i,j+1,N,M);
  }
  if(solution[i-1][j]==0 && !downSuccess && !rightSuccess){
    topSuccess=ratmaze(maze,solution,i-1,j,N,M);
  }
  if(solution[i][j-1]==0 && !downSuccess && !rightSuccess && !topSuccess){
    leftSuccess=ratmaze(maze,solution,i,j-1,N,M);
  }
  if(leftSuccess || rightSuccess || topSuccess || downSuccess){
    return true;
  }
  solution[i][j]=0;
  return false;
}
int main() 
{
	int N,M;
	cin>>N>>M;
	char maze[11][11];
	for(int i=0;i<N;i++){
	  for(int j=0;j<M;j++){
	    cin>>maze[i][j];
	  }
	}
	int solution[11][11]={0};
	bool y=ratmaze(maze,solution,0,0,N-1,M-1);
	if(y==0)
	{
	  cout<<"NO PATH FOUND";
	}
	return 0;
}