#include <iostream>
#include <random>
#include <ctime>
using namespace std; 

void showBoard(char board[][3]);
void showInstructions() ;
void initialise(char board[][3]) ;
void declareWinner(int whoseTurn) ;
bool rowCrossed(char board[][3]) ;
bool columnCrossed(char board[][3]) ;
bool diagonalCrossed(char board[][3]) ;
bool gameOver(char board[][3]) ;
int minimax(char board[][3], int depth, bool isAI);
int bestMove(char board[][3], int moveIndex);
void Player_vs_AI(int whoseTurn) ;
int CountBoard(char board[][3], char symbol);
void Player_vs_player();
#define AI 1 
#define player 2 

char playermove;
char AImove;
int main() 
{   
	char cont;
	
	do{
		cout << endl << "-------------------------------------------------------------------"<< endl << endl;
		cout << "           		  " << "Tic-Tac-Toe"<< endl <<endl;
		cout << "-------------------------------------------------------------------"<< endl << endl;
		cout << "			" << "Select game mode" << endl << endl;
		cout << "1.Player vs player" << "				    " << "2.Player vs AI" << endl << endl;
		int level;
		cin >> level;
		switch(level) {
			case 1 :
				{
					Player_vs_player();
					cout << "Do you want to quit(y/n): "; 
       				cin >> cont;
					break;
				}
			case 2:
				{
					char choice;
	 				cout << "Do you want to start first(y/n): "; 
	 				cin >> choice;

					if(choice=='n') 
					{
						AImove = 'X';
						playermove = 'O';
						Player_vs_AI(AI);
					}
					else if(choice=='y') 
					{
						playermove = 'X';
						AImove = 'O';
						Player_vs_AI(player);
					}
					else
					{
						cout << "Invalid position" << endl; 
					} 
					cout << "Do you want to quit(y/n): "; 
       				cin >> cont;
					break;
				}		  
			default :
				cout << "Select again your bullshit brain!!!" << endl;
				break;
		}	
	} while(cont == 'n');
	
	return (0); 
}

//Tạo Bảng

void showBoard(char board[][3]) 
{ 
	cout << "                         " <<  board[0][0] << " " <<  "|" << " " << board[0][1] << " " << "|" << " " <<board[0][2] << endl;   
	cout << "                        " << "-----------"<< endl; 
	cout << "                         " <<  board[1][0] << " " <<  "|" << " " << board[1][1] << " " << "|" << " " <<board[1][2] << endl;   
	cout << "                        " << "-----------"<< endl; 
	cout << "                         " <<  board[2][0] << " " <<  "|" << " " << board[2][1] << " " << "|" << " " <<board[2][2] << endl;   
} 

//Hàm chỉ ra vị trí với số tương ứng trên bảng

void showInstructions() 
{ 
    cout << endl << "Select number as below to play :" << endl << endl; 
	cout << "                         " << "1 | 2 | 3 "<< endl; 
	cout << "                        " << "-----------"<< endl; 
	cout << "                         " << "4 | 5 | 6 "<< endl; 
	cout << "                        " << "-----------"<< endl; 
	cout << "                         " << "7 | 8 | 9 "<< endl; 
} 

//Hàm khởi tạo giá trị trắng cho từng vị trí trong bảng

void initialise(char board[][3]) 
{	
	for (int i=0; i<3; i++) 
	{ 
		for (int j=0; j<3; j++) 
			board[i][j] = ' '; 
	} 
} 

//Hàm xác định người chiến thắng

void declareWinner(int whoseTurn) 
{ 
	if (whoseTurn == AI) 
		cout << "AI has won!"<< endl;
	else
		cout << "You have won!" << endl;
} 

//Kiểm tra hàng

bool rowCrossed(char board[][3]) 
{ 
	for (int i=0; i<3; i++) 
	{ 
		if (board[i][0] == board[i][1] && 
			board[i][1] == board[i][2] && 
			board[i][0] != ' ') 
			return (true); 
	} 
	return(false); 
} 

//Kiểm tra cột 
bool columnCrossed(char board[][3]) 
{ 
	for (int i=0; i<3; i++) 
	{ 
		if (board[0][i] == board[1][i] && 
			board[1][i] == board[2][i] && 
			board[0][i] != ' ') 
			return (true); 
	} 
	return(false); 
} 
 
//Kiểm tra đường chéo

bool diagonalCrossed(char board[][3]) 
{ 
	if (board[0][0] == board[1][1] && 
		board[1][1] == board[2][2] && 
		board[0][0] != ' ') 
		return(true); 
		
	if (board[0][2] == board[1][1] && 
		board[1][1] == board[2][0] && 
		board[0][2] != ' ') 
		return(true); 

	return(false); 
} 

// Kiểm tra game đã kết thúc hay chưa
bool gameOver(char board[][3]) 
{ 
	return(rowCrossed(board) || columnCrossed(board) || diagonalCrossed(board) ); 
}

//Hàm tính toán bằng thuật toán minimax

int minimax(char board[][3], int depth, bool isAI)
{
	int score = 0;
	int bestScore = 0;
	if (gameOver(board) == true)
	{
		if (isAI == true) 
			return -1;
		if (isAI == false) 
			return +1;
	}
	else
	{
		if(depth < 9)
		{
			if(isAI == true)
			{
				bestScore = -999;
				for(int i=0; i<3; i++)
				{
					for(int j=0; j<3; j++)
					{
						if (board[i][j] == ' ')
						{
							board[i][j] = AImove;
							score = minimax(board, depth + 1, false);
							board[i][j] = ' '; 
							if(score > bestScore)
							{
								bestScore = score; 
							}
						}
					}
				}
				return bestScore;
			}
			else
			{
				bestScore = 999;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						if (board[i][j] == ' ')
						{
							board[i][j] = playermove;
							score = minimax(board, depth + 1, true);
							board[i][j] = ' '; 
							if (score < bestScore)
							{
								bestScore = score;
							}
						}
					}
				}
				return bestScore;
			}
		}
		else
		{
			return 0;
		}
	}
}

//Hàm tìm ra nước đi tốt nhất dựa trên minimax

int bestMove(char board[][3], int moveIndex)
{
	int x = -1, y = -1;
	int score = 0, bestScore = -999;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
			{
				board[i][j] = AImove;
				score = minimax(board, moveIndex+1, false);
				board[i][j] = ' ';
				if(score > bestScore)
				{
					bestScore = score;
					x = i;
					y = j;
				}
			}
		}
	}
	return x*3+y;
}
// Chơi với máy
void Player_vs_AI(int whoseTurn) 
{ 
	system("cls");
	char board[3][3];
	int moveIndex = 0, x = 0, y = 0;

	initialise(board);
	showInstructions(); 
	
	while (gameOver(board) == false && moveIndex != 3*3) 
	{ 
		int n;
		if (whoseTurn == AI) 
		{
			n = bestMove(board, moveIndex);
			x = n / 3;
			y = n % 3;
			board[x][y] = AImove; 
            cout << endl << "AI has put a "<< AImove << " " << "in cell " << n+1<< endl << endl;
			showBoard(board);
			moveIndex ++; 
			whoseTurn = player;
		} 
		
		else if (whoseTurn == player) 
		{
            
            cout << endl << endl << "Enter the position : ";
            cin >> n; 
			n--; 
			x = n / 3;
			y = n % 3; 
			if(board[x][y] == ' ' && n<9 && n>=0)
			{
				board[x][y] = playermove; 
                cout << endl << "You has put a "<< playermove<< " " << "in cell " << n+1<< endl << endl;
				showBoard(board); 
				moveIndex ++; 
				whoseTurn = AI;
			}
			else if(board[x][y] != ' ' && n<9 && n>=0)
			{
                cout << endl << "Please select an empty position" << endl << endl;
			}
			else if(n<0 || n>8) 
			{
				cout << "Invalid position" <<endl;
			}
		} 
	} 

	if (gameOver(board) == false && moveIndex == 3 * 3) 
		cout << "It's a draw!" << endl; 
	else
	{ 
		if (whoseTurn == AI) 
			whoseTurn = player; 
		else if (whoseTurn == player) 
			whoseTurn = AI; 
		
		declareWinner(whoseTurn); 
	} 
} 
// Đếm số lượng X và O đã đi
int CountBoard(char board[][3], char symbol){
	int total = 0;
	for (int i = 0 ; i < 3 ; i++){
		for (int j = 0 ; j < 3 ; j++){
			if (board[i][j] == symbol){
				total++;
			}
		}
	}
	return total;
}
// Hai người chơi
void Player_vs_player() {
	system("cls");
	char board[3][3];
	int x = 0, y = 0;
	string PlayerXName, PlayerOName;
	cout << "Enter Player X name :" ; cin >> PlayerXName;
	cout << "Enter Player O name :" ; cin >> PlayerOName;
	initialise(board);
	showInstructions();
	while (gameOver(board) == false && (CountBoard(board, 'X') + CountBoard(board, 'O')) < 9 ){
		if (CountBoard(board,'X') == CountBoard(board,'O')){
			cout << PlayerXName << "'s turn :";
			int PlayerXchoice;
			do{
				cin >> PlayerXchoice;
				PlayerXchoice--;
				x = PlayerXchoice/3;
				y = PlayerXchoice%3;
				if (board[x][y] != ' ') cout << "Please select an empty position :";
			}while(board[x][y] != ' ');
			board[x][y] = 'X';
			showBoard(board);
		}
		else {
			cout << PlayerOName << "'s turn :";
			int PlayerOchoice;
			do{
				cin >> PlayerOchoice;
				PlayerOchoice--;
				x = PlayerOchoice/3;
				y = PlayerOchoice%3;
				if (board[x][y] != ' ') cout << "Please select an empty position :";
			}while(board[x][y] != ' ');
			board[x][y] = 'O';
			showBoard(board);
		}
	}
	if (gameOver(board) == true && CountBoard(board, 'X') > CountBoard(board, 'O')){
		cout << PlayerXName << " has won!" << endl ;
	}
	else if (gameOver(board) == true && CountBoard(board, 'X') == CountBoard(board, 'O')){
		cout << PlayerOName <<" has won!" << endl;
	}
	else {
		cout << "game is draw!" << endl;
	}

	
}

