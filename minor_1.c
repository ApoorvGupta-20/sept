//#include<iostream>
//using namespace std;
#include<stdio.h>
#define INT_MAX 999999
int n;
int n=4;
int s;
int dp[16][4];
int dist[10][10] = {
		{0,20,42,25},
		{20,0,30,34},
		{42,30,0,10},
		{25,34,10,0}
};

//int visited;
int visited = (1<<4)- 1;

int tsp(int mask,int pos){
	if(mask==visited){
		return dist[pos][0];
	}
	if(dp[mask][pos]!=-1){
		return dp[mask][pos];
	}
	int ans;
	ans=INT_MAX;
	int city;
	for(city=0;city<n;city++){
		if((mask&(1<<city))==0){
			int newAns; 
			newAns = dist[pos][city] + tsp(mask|(1<<city),city);
	               // ans = min(ans,newAns);
	                if (ans < newAns)
				 ans = ans;
			else
				ans = newAns;
	}
}
	return dp[mask][pos] = ans;
}
int main()
{
	int i, j;
	for(i=0;i<(1<<n);i++){
		for(j=0;j<n;j++){
			dp[i][j] = -1;}
  		}
	//cout << "Please enter the source value:\n";
	printf("Please enter the source value:\n");
	//cin >> s;
	scanf("%d",&s);
	//cout<<"The minimum distance to cover all the cities is: "<<tsp(s,0)<<endl;
	printf("/nThe minimum distance to cover all the cities is: %d",tsp(s,0));
	return 0;
}
