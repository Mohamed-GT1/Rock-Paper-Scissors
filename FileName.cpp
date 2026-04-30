#include<iostream>
using namespace std;

enum GameChoice {
	Rock = 1, Paper = 2, Scissors = 3

};

enum Players { person = 1, computer = 2 };

enum WhoWon { PersonWin = 1, ComputerWin = 2, draw = 3 };


int RandomNumber(int from, int to) {
	return rand() % (to - from + 1) + from;
}

int ReadPositiveNumber(string message) {
	int number;

	do {
		cout << message << endl;
		cin >> number;

	} while (number < 0);
	return number;
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

	if (Personchoice == GameChoice::Rock && Computerchoice == GameChoice::Scissors)
		return WhoWon::PersonWin;
	else if (Personchoice == GameChoice::Paper && Computerchoice == GameChoice::Rock)
		return WhoWon::PersonWin;
	else if (Personchoice == GameChoice::Scissors && Computerchoice == GameChoice::Paper)
		return WhoWon::PersonWin;
	else if (Personchoice == Computerchoice)
		return WhoWon::draw;
	else
		return WhoWon::ComputerWin;
}



void PrintWinner(WhoWon gm) {
	if (gm == WhoWon::PersonWin)
		cout << "you won";
	else if (gm == WhoWon::ComputerWin)
		cout << "computer won";
	else if (gm == WhoWon::draw)
		cout << "draw";

	cout << endl;
}

void PrintChoice(GameChoice choice, string message) {
	cout << message;

	if (choice == Rock)
		cout << "rock";
	else if (choice == Paper)
		cout << "paper";
	else if (choice == Scissors)
		cout << "scissors";

	cout << endl;

}
void CountWinAndLoss(WhoWon winner, int& personWins, int& computerWins, int& draws) {



	if (winner == WhoWon::PersonWin)
		personWins++;
	else if (winner == WhoWon::ComputerWin)
		computerWins++;
	else
		draws++;


}

void ChangeScreenColor(WhoWon winner) {

	if (winner == PersonWin)
		system("color A0");
	else if (winner == ComputerWin)
		system("color 40");
	else
		system("color E0");

}



WhoWon Round() {

	GameChoice personChoice;
	GameChoice computerChoice;



	personChoice = (GameChoice)ReadNumberInRange("your choice : [1] Rock  [2] Paper  [3] Scissors ", 1, 3);
	computerChoice = (GameChoice)RandomNumber(1, 3);

	WhoWon winner = DecideWinOrLoseOrDraw(personChoice, computerChoice);

	ChangeScreenColor(winner);


	PrintChoice(personChoice, "your choice : ");
	PrintChoice(computerChoice, "computer choice : ");
	PrintWinner(winner);


	return winner;



}

void PrintResults(int personWins, int computerWins, int draws) {
	cout << endl;

	cout << "************ Game Over ************\n";
	cout << "Total Rounds : " << personWins + computerWins + draws;
	cout << "\nperson won " << personWins << " times\n";
	cout << "computer won " << computerWins << " times\n";
	cout << "draw " << draws << " times\n";

	cout << "\n-------------****final winner is ";

	if (personWins > computerWins)
		cout << "Person****-------------\n";
	else if (personWins < computerWins)
		cout << "Computer****-------------\n";
	else
		cout << "No one (draw)****-------------\n";
}

void ResetScreen() {

	system("cls");
	system("color 07");

}


int main() {
	srand((unsigned)time(NULL));

	char moreRounds;
	do {
		int numberOfRounds = ReadNumberInRange("how many rounds do you want the game to be ? 1 to 10", 1, 10);

		int personWins = 0;
		int computerWins = 0;
		int draws = 0;

		WhoWon winner;

		for (int i = 1; i <= numberOfRounds; i++) {
			cout << "\n---------------------------------------------------------\n";
			cout << "\nRound [" << i << "] \n";
			winner = Round();

			CountWinAndLoss(winner, personWins, computerWins, draws);
			cout << "\n---------------------------------------------------------\n\n\n";
		}

		PrintResults(personWins, computerWins, draws);

		cout << "\ndo you want to play again ? [y]Yes [n]No \n";
		cin >> moreRounds;

		ResetScreen();

	} while (moreRounds == 'y' || moreRounds == 'Y');
}







//void Game() {
//	int numberOfRounds = ReadNumberInRange("how many rounds do you want the game to be ? 1 to 10", 1, 10);
//
//	int personWins = 0;
//	int computerWins = 0;
//	int draws = 0;
//
//	WhoWon winner;
//
//	for (int i = 1; i <= numberOfRounds; i++) {
//		cout << "\n---------------------------------------------------------\n";
//		cout << "\nRound [" << i << "] \n";
//		winner = Round();
//
//		CountWinAndLoss(winner, personWins, computerWins, draws);
//		cout << "\n---------------------------------------------------------\n\n\n";
//	}
//
//	PrintResults(personWins, computerWins, draws);
//
//	
//
//	
//}
//
//
//int main() {
//	srand((unsigned)time(NULL));
//
//	char playAgain;
//	do {
//
//		Game();
//
//
//		cout << "\ndo you want to play again ? [y]Yes [n]No \n";
//		cin >> playAgain;
//		ResetScreen();
//
//	} while (playAgain == 'y' || playAgain == 'Y');
//}









