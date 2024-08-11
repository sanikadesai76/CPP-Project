#include<bits/stdc++.h>
#include <conio.h> 
using namespace std;

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void createMatrix(int arr[][4]){
	int n=15;
	int num[n],i=0,j=0;
	for(i=0;i<n;i++){
		num[i]=i+1;
	}

	 srand(time(NULL));   //for random number generation
	 int lastindex=n-1,index;

	 for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(lastindex >= 0){
				index=rand() % (lastindex+1);
				arr[i][j]=num[index];
				num[index]=num[lastindex--];
			}
		}
	 }
	 arr[3][3]=0;
}

void showMatrix(int arr[][4]) {
    for(int i=0;i<13;i++)
        cout<<"--";
    cout<<"-";
    cout<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<"|";
        for(int j=0;j<4;j++)
        {
                if(arr[i][j]!=0)
                {
                    if(arr[i][j]/10==0)
                      cout<<" "<<arr[i][j]<<"  |  ";
                    else
                      cout<<" "<<arr[i][j]<<" |  ";
                }
                else
                     cout<<"  "<<"  |  ";               // WE INSERT SPACE INSTEAD OF 0 TO MAKE IT BLANK


        }
        cout<<endl;
        if(i!=3)
          cout<<"|----|------|------|------|";       // FOR LAYOTING PURPOSE
        else
       {
           for(int i=0;i<13;i++)
                cout<<"--";
            cout<<"-";
       }
       cout<<endl;
    
    }
}

int winner(int arr[][4]) {
    int k = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++, k++) {
            if (arr[i][j] != k && k != 16)
                return 0;
        }
    }
    return 1;
}

void swap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
    cout<<" ";
}

int readEnterKey() {
    int c;
    c = _getch();
    if (c == 0 || c == 224)
        c = _getch();
    return c; 
}

int shiftUp(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
            {
                break;
            }
        }
        if (j < 4)
        {
            break;
        }
    }
    if (i == 3)
    { // shifting not possible
        return 0;
    }

    // successfully swapped two numbers 
    swap(&arr[i][j], &arr[i + 1][j]);
    return 1; 
}

int shiftDown(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
            {
                break;
            }
        }
        if (j < 4)
        {
            break;
        }
    }
    if (i == 0)
    { // Shifting not possible
        return 0;
    }
    swap(&arr[i][j], &arr[i - 1][j]); // swap number

    return 1; // Shift Down success
}

int shiftRight(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
        break;
    }
      if(j==0)                 // shifting not possible
        return 0;
             swap(&arr[i][j],&arr[i][j-1]);

        return 1;               // shift up success
}

int shiftLeft(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
        break;
    }
      if(j==3)                 // shifting not possible
        return 0;
                swap(&arr[i][j],&arr[i][j+1]);
        return 1;               // shift up success
}

void gameRule(int arr[][4]) {
    system("cls"); 
    cout << "\t\t MATRIX PUZZLE\n\n";
    cout << "\033[1;31m              RULE OF THIS GAME            \033[0m\n";
    cout << "\033[1;31m1. You can move only 1 step at a time by arrow key\033[0m\n";
    cout << "\tMove Up    : by Up arrow key\n";
    cout << "\tMove Down  : by Down arrow key\n";
    cout << "\tMove Left  : by Left arrow key\n";
    cout << "\tMove Right : by Right arrow key\n";

    cout << "\033[1;31m2. You can move a number to an empty position only\033[0m\n";
    cout << "3. For Each Valid Move: Your total number of moves will decrease by 1\n";
    cout << "\033[1;31m4. Winning Situation\033[0m\n";
    cout << "   Numbers in a 4*4 matrix should be in order from 1 to 15\n";

    cout << "\n          Winning Situation\n\n";
    cout << "\033[1;33m----------------------\n\033[0m";

    for (int i = 0; i < 4; i++) {
        cout << " | ";
        for (int j = 0; j < 4; j++) {
            if (arr[i][j] != 0) {
                cout << (4 * i + j + 1 < 10 ? " " : "") << 4 * i + j + 1 << " | ";
            } else {
                cout << "   |  ";
            }
        }
        cout << "\n";
    }

    cout << "\033[1;33m-----------------------\n\033[0m";
    cout << "5. You can exit the game at any time by pressing 'E' or 'e'\n\n";
    cout << "So Try to win in the minimum number of moves\n";
    cout << "\nEnter any key to start........";

		readEnterKey();
    
}

int main(){
	int arr[4][4];  
	int maxTry=100;   //Maximum move
	 string name;

	cout<<"\n\n\n";

	cout<<"Player Name: ";
	cin>>name;

	system("cls");

	while(1){
		createMatrix(arr);  //function to create matrix
		gameRule(arr); 
		
		while (!winner(arr)) {
        system("cls");

        // for remaining zero move
        if (!maxTry)
            break;

        cout << "\n\n Player Name:" << name << "  ,  Move Remaining:" << maxTry << "\n\n";
        showMatrix(arr); // show matrix

        int key = readEnterKey(); // this will return ascii code of user entered key  
        switch (key) {
            case 101: // ascii of E
            case 69:  // ascii of e
                cout << "\a\a\a\a\a\a\n   Thanks for Playing !\n\a";
                cout << "\nHit 'Enter' to exit the game\n";
                key = readEnterKey();
                exit(0);

            case 72: // arrow up
                if (shiftUp(arr))
                    maxTry--;
                break;

            case 80: // arrow down
                if (shiftDown(arr))
                    maxTry--;
                break;

            case 77: // arrow right
                if (shiftRight(arr))
                    maxTry--;
                break;

            case 75: // arrow left
                if (shiftLeft(arr))
                    maxTry--;
                break;

            default:
                cout << "\n\n      \a\a Not Allowed\a";
        }
	   }

		 if (!maxTry) {
        cout << "\n\a           You Lose!          \a\a\n";
    } else {
        cout << "\n\a!!!!!!!!!!!!!!!!! Congratulation " << name << " for winning this game !!!!!!!!!!!!!!!!!!\a\a\n";
    }
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
    char check;
    cout << "\nWant to Play again?\n";
    cout << "Enter 'y' to play again:  ";
    cin >> check;

    if ((check != 'y') && (check != 'Y')){
        return -1; 
    }

    maxTry = 50;

	}
	return 0;
}