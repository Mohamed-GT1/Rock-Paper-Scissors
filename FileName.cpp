#include<iostream>
#include<cstdlib>
using namespace std;

enum GameChoice {
	Rock = 1, Paper = 2, Scissors = 3

};

enum WhoWon 
{ PersonWin = 1, ComputerWin = 2, draw = 3 };

struct RoundInfo {
	
	GameChoice playerChoice;
	GameChoice computerChoice;
	WhoWon  winner;
};

struct GameResults {
	int totalRounds = 0;
	int playerWinCount=0;
	int computerWinCount=0;
	int drawCount=0;

};

int RandomNumber(int from, int to) {
	return rand() % (to - from + 1) + from;
}


int ReadNumberInRange(string message, int from, int to) {
	int number;

	do {
		cout << message << endl;
		cin >> number;

		if (number < from || number > to)
			cout << "invalid input try again";

	} while (number < from || number > to);
	return number;

}

WhoWon DecideWinOrLoseOrDraw(GameChoice Personchoice, GameChoice Computerchoice) {

	if (Personchoice == Computerchoice)
		return WhoWon::draw;

	if (Personchoice == GameChoice::Rock && Computerchoice == GameChoice::Scissors)
		return WhoWon::PersonWin;
	else if (Personchoice == GameChoice::Paper && Computerchoice == GameChoice::Rock)
		return WhoWon::PersonWin;
	else if (Personchoice == GameChoice::Scissors && Computerchoice == GameChoice::Paper)
		return WhoWon::PersonWin;
	else 
		return WhoWon::ComputerWin;
}


void UpdateFinalGameResults(GameResults& gameResults,RoundInfo roundInfo) {
	


	if (roundInfo.winner == WhoWon::PersonWin)
		gameResults.playerWinCount++;
	else if (roundInfo.winner == WhoWon::ComputerWin)
		gameResults.computerWinCount++;
	else
		gameResults.drawCount++;


}

void ChangeScreenColor(WhoWon winner) {

	if (winner == PersonWin)
		system("color A0");
	else if (winner == ComputerWin)
		system("color 40");
	else
		system("color E0");

}

string GetChoice(GameChoice choice) {

	string choiceNames[] = { "rock","paper","scissors" };  // must be the same order as the enum for this to work right


	return choiceNames[choice - 1];  //choice get automatically converted into int here 



	/*if (choice == GameChoice::Rock)
		return "rock";
	else if (choice == GameChoice::Paper)
		return "paper";
	else
		return "scissors";*/

}

string GetWinner(WhoWon winner) {

	string WinnerName[] = { "player","computer","draw" };

	return WinnerName[winner - 1];


	/*if (winner == WhoWon::PersonWin)
		return "player";
	else if (winner == WhoWon::ComputerWin)
		return "computer";
	else
		return "draw";*/

}

void PrintRoundInfo(RoundInfo roundinfo) {

	cout << endl;



	cout << "your choice     : " << GetChoice(roundinfo.playerChoice) << endl;
	cout << "computer choice : " << GetChoice(roundinfo.computerChoice) << endl;
	cout << "the winner      : " << GetWinner(roundinfo.winner) << endl;


}

void PrintFinalGameResults(GameResults gameResult)
{
	


	cout << "\ntotal Rounds    : " <<gameResult.totalRounds<<endl;
	cout << "player won      : " << gameResult.playerWinCount << " times" << endl;
	cout << "computer won    : " << gameResult.computerWinCount << " times" << endl;
	cout << "number of draws : " << gameResult.drawCount << " times" << endl;

	cout << "\n-------------****final winner is ";

	if (gameResult.playerWinCount > gameResult.computerWinCount)
		cout << "player****--------------\n";
	else if (gameResult.playerWinCount < gameResult.computerWinCount)
		cout << "Computer****--------------\n";
	else
		cout << "No one (draw)****--------------\n";
}

void PrintGameOver() {

	cout << "************ Game Over ************\n";

}

RoundInfo PlayRound() {

	RoundInfo roundInfo;

	roundInfo.playerChoice = (GameChoice)ReadNumberInRange("your choice : [1] Rock  [2] Paper  [3] Scissors ", 1, 3);
	roundInfo.computerChoice = (GameChoice)RandomNumber(1, 3);

	roundInfo.winner = DecideWinOrLoseOrDraw(roundInfo.playerChoice, roundInfo.computerChoice);

	ChangeScreenColor(roundInfo.winner);

	return roundInfo;


}



void ResetScreen() {

	system("cls");
	system("color 07");

}


void StartGame() {
	int numberOfRounds = ReadNumberInRange("how many rounds do you want the game to be ? 1 to 10", 1, 10);

	RoundInfo roundInfo;
	GameResults gameResults;

	
	

	for(int roundNumber = 1;  roundNumber <= numberOfRounds; roundNumber++) {
		cout << "\n---------------------------------------------------------\n";
		cout << "\nRound [" << roundNumber << "] \n";

		roundInfo = PlayRound();

		PrintRoundInfo(roundInfo);

		UpdateFinalGameResults(gameResults, roundInfo);

		cout << "\n---------------------------------------------------------\n\n\n";
	}


	PrintGameOver();

	gameResults.totalRounds = numberOfRounds;
	PrintFinalGameResults(gameResults);

	

	
}

void Game() {

	char playAgain;

	do {

		ResetScreen();

		StartGame();


		cout << "\ndo you want to play again ? [y]Yes [n]No \n";
		cin >> playAgain;
		

	} while (playAgain == 'y' || playAgain == 'Y');

}


int main() {

	srand((unsigned)time(NULL));
	
	Game();
	
}







