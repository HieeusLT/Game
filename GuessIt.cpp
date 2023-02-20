#include<bits/stdc++.h>

using namespace std;
int GenerateNum();
int GetPlayerGuess();
int GetPoint(int count);
void PrintAnswer(int guess, int SecreteNum);
void PlayGuessIt();
int main()
{
    while (true)
    {
    string question;
    PlayGuessIt();
    cout << "Do you want to play again?" << endl;
    cout << "Enter Y to keep playing guess it or N to quit game : " ;
    cin >> question;
    if (question == "Y")
    {
        PlayGuessIt();
    }
    else return 0;
    }
}
int GetPlayerGuess()
{
int guess;
cout << "Your guess : ";
cin >> guess;
return guess;
}
int GenerateNum()
{
    return rand()%100 + 1;
}
int GetPoint(int count)
{
    string TimePlay, Point;
    if (count > 1)
    {
        TimePlay = " times";
        Point = " points";
    }
    else{
        TimePlay = " time";
        Point = " point";
    }
    cout << "You have guessed " << count << TimePlay << endl;
    cout << "You get " << 100 - count << Point << endl;
}
void PrintAnswer(int guess, int SecreteNum)
{
    if (guess < SecreteNum)
    {
        cout << "Your number is too small try bigger one " << endl;
    }
    else if (guess > SecreteNum)
    {
        cout << "Your number is too big, try smaller one " << endl;
    }
    else cout << "Congratulations, your number is right" << endl ;
}
void PlayGuessIt()
{
   srand(time(0));
    int guess, count = 0 ;
    int SecreteNum = GenerateNum();
    do
    {
        guess = GetPlayerGuess();
        count++;
         PrintAnswer(guess,SecreteNum);
    } while (guess != SecreteNum);
    GetPoint(count);  
}