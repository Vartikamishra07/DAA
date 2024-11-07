#include<bits/stdc++.h>
using namespace std;

bool isSafe(int **arr, int x, int y, int n){
    for(int row=0;row<x;row++){
        if(arr[row][y]==1){    //vertical column check
            return false;
        }
    }
    int row = x;
    int col = y;
    while(row>=0 && col>=0){
        if(arr[row][col]==1){      //upper left diagonal
            return false;
        }
        row--;
        col--;
    }
    row =x;
    col =y;
    while(row>=0 && col<n){
        if(arr[row][col]==1){
            return false;         //upper right diagonal
        }
        row--;
        col++;
    }
    return true;
}

void printBoard(int **arr, int n){
	for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
			if(arr[i][j] == 1) cout << "[Q]";
			else cout << "[]";
		}
        cout << endl; //separation between rows
	}
	cout << endl; //separations between boards
	cout << endl;
}

void nQueen(int **arr, int x, int n){
    if(x == n)
    {
        printBoard(arr, n);
		return;
    }

    for(int col=0;col<n;col++){
        if(isSafe(arr,x,col,n))
        {
            arr[x][col]=1; //place queen
            nQueen(arr,x+1,n); //recursive calls for next rows
            arr[x][col]=0; //backtrack
        }
    }
}


int main()
{
    int n;
    cout<<"Enter the number of queens: ";
    cin >> n;
    
    int **arr = new int*[n];    
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }

	cout << "--------All possible solutions--------"<<endl;
	nQueen(arr, 0, n);
    return 0;
}