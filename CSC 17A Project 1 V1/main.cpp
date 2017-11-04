/* 
 * File:   main.cpp
 * Author: Alex
 *
 * Created on October 31, 2017, 9:31 AM
 */

#include <iostream>
#include <cstdlib>      
#include <ctime>
#include <string>
#include <cstring>

using namespace std;

struct Player
{
    string name;
    float duration;  
};

struct AdditionOne
{
    int num1;
    int num2;
    int score = 0;
    int hScore = 0;
};

struct AdditionTwo
{
    int num1;
    int num2;
    int score = 0;
    int hScore = 0;
};

struct SubtractionOne
{
    int num1;
    int num2;
    int score = 0;
    int hScore = 0;
};

struct SubtractionTwo
{
    int num1;
    int num2;
    int score = 0;
    int hScore = 0;
};

void Intro();
void Rules();
void Menu();
int getN(int);
AdditionOne PlusOne(Player);
AdditionTwo PlusTwo(Player);
SubtractionOne MinusOne(Player); 
SubtractionTwo MinusTwo(Player);

using namespace std;

int main(int argc, char** argv) 
{
    Player user;
    char play;
    int inN;
    
    cout << "Press enter to begin.\n";
    cin.get();
    
     Intro();
    
     Rules();
     
    cout << "Press enter to continue.\n";
     
    do
    {
        cin.ignore(1,'\n');
        cout << "Please enter the name of the player: " << endl;
        getline(cin,user.name);
        cout << endl << endl;
        
        Menu();
        
        inN = getN(inN);
        
        switch(inN)
        {
          case 1:    PlusOne(user);break;
          case 2:    PlusTwo(user);break;
          case 3:    MinusOne(user);break;
          case 4:    MinusTwo(user);break;
//          case 5:    problem5();break;
//          case 6:    problem6();break;
//          case 7:    problem7();break;
          default:   getN(inN);
        }     
        
        cout << "Would you like to play again? ";
        cin >> play;
        cout << endl << endl;
    }while (play == 'Y' || play == 'y');


    return 0;
}

void Intro()
{
    cout << "Welcome to Alex's Math Mathematician Challenge!" << endl;
    cout << "The point of this program is to present to you, the player,\n";
    cout << "a list of challenges from areas of math like addition, subtraction,\n";
    cout << "multiplication, division, and finding the remainder due to a modulus.\n\n";
}

void Rules()
{
    cout << "\nThe rules of the game are simple. After choosing an area and a\n";
    cout << "difficulty, the player will be shown a mathematical problem to\n";
    cout << "solve. Each difficulty broadens the range numbers that could\n";
    cout << "show up. A high score will be given depending on where you\n";
    cout << "end up and will be saved. After you can choose to play again.\n\n";
}

void Menu()
{
    cout << "Choice #1: Addition Level 1\n";
    cout << "Choice #2: Addition Level 2\n";
}

int getN(int inN)
{
    cout << "Please enter a number to choose a challenge: \n";
    cin >> inN;
    cout << endl;
    return inN;
}

AdditionOne PlusOne (Player user)
{
    AdditionOne plus;
    float timePSec = 1000;
    unsigned seed = time(0);
    srand(seed);                 //Seed random number generator
    clock_t startTime = clock(); //Start timer
    bool proceed;                //Continues the game
    int x;                       //User answer
    int correct;                 //Correct Answer
    
     cout << "Press enter to continue.\n\n";
     cin.get();
     cout << string(50, '\n');
    
    do
    {
        plus.num1 = (rand() % (100 - 1 + 1)) + 1;        //Seed num1 from 1-100
        plus.num2 = (rand() % (100 - 1 + 1)) + 1;        //Seed num2 from 1-100
        
        correct = plus.num1 + plus.num2;
        
        cout << "What is " << plus.num1 << " + " << plus.num2 << "? "; 
        cin >> x;
        
        if (x == correct)
        {
            cout << "Correct!\n\n";
            plus.score += 1;
            proceed = true;
        }
        else
        {
            cout << "Sorry but your answer is incorrect, your game is over.\n\n";
            proceed = false;
        }
    }
    while(proceed);   
    
    user.duration = ( clock() - startTime ) / timePSec;
    
    if (plus.score > plus.hScore)
    {
        plus.hScore = plus.score;
        cout << user.name << " earned a new high score! It is now " << plus.hScore;
        cout << endl << endl;
    }
    
    if (plus.hScore > plus.score)
    {
        cout << user.name << " did not beat their the score of " << plus.hScore 
             << ". You " << "completed a total of " << plus.score << " questions.\n\n"; 
        
    }
    
    cout << "This was many seconds it took for you to get a question wrong: " << user.duration;
    cout << endl << endl;
}

AdditionTwo PlusTwo (Player user)
{
    AdditionTwo plus;
    float timePSec = 1000;
    unsigned seed = time(0);
    srand(seed);                 //Seed random number generator
    clock_t startTime = clock(); //Start timer
    bool proceed;                //Continues the game
    int x;                       //User answer
    int correct;                 //Correct Answer
    
     cout << "Press enter to continue.\n\n";
     cin.get();
     cout << string(50, '\n');
    
    do
    {
        plus.num1 = (rand() % (500) + 100);        //Seed num1 from 100-500
        plus.num2 = (rand() % (500) + 100);        //Seed num2 from 100-500
        
        correct = plus.num1 + plus.num2;
        
        cout << "What is " << plus.num1 << " + " << plus.num2 << "? "; 
        cin >> x;
        
        if (x == correct)
        {
            cout << "Correct!\n\n";
            plus.score += 1;
            proceed = true;
        }
        else
        {
            cout << "Sorry but your answer is incorrect, your game is over.\n\n";
            proceed = false;
        }
    }
    while(proceed);   
    
    user.duration = ( clock() - startTime ) / timePSec;
    
    if (plus.score > plus.hScore)
    {
        plus.hScore = plus.score;
        cout << user.name << " earned a new high score! It is now " << plus.hScore;
        cout << endl << endl;
    }
    
    if (plus.hScore > plus.score)
    {
        cout << user.name << " did not beat their the score of " << plus.hScore 
             << ". You " << "completed a total of " << plus.score << " questions.\n\n"; 
        
    }
    
    cout << "This was many seconds it took for you to get a question wrong: " << user.duration;
    cout << endl << endl;
}

SubtractionOne MinusOne (Player user)
{
    SubtractionOne minus;
    float timePSec = 1000;
    unsigned seed = time(0);
    srand(seed);                 //Seed random number generator
    clock_t startTime = clock(); //Start timer
    bool proceed;                //Continues the game
    int x;                       //User answer
    int correct;                 //Correct Answer
    
     cout << "Press enter to continue.\n\n";
     cin.get();
     cout << string(50, '\n');
    
    do
    {
        minus.num1 = (rand() % (100) + 1);        //Seed num1 from 1-100
        minus.num2 = (rand() % (100) + 1);        //Seed num2 from 1-100
        
        correct = minus.num1 - minus.num2;
        
        cout << "What is " << minus.num1 << " - " << minus.num2 << "? "; 
        cin >> x;
        
        if (x == correct)
        {
            cout << "Correct!\n\n";
            minus.score += 1;
            proceed = true;
        }
        else
        {
            cout << "Sorry but your answer is incorrect, your game is over.\n\n";
            proceed = false;
        }
    }
    while(proceed);   
    
    user.duration = ( clock() - startTime ) / timePSec;
    
    if (minus.score > minus.hScore)
    {
        minus.hScore = minus.score;
        cout << user.name << " earned a new high score! It is now " << minus.hScore;
        cout << endl << endl;
    }
    
    if (minus.hScore > minus.score)
    {
        cout << user.name << " did not beat their the score of " << minus.hScore 
             << ". You " << "completed a total of " << minus.score << " questions.\n\n"; 
        
    }
    
    cout << "This was many seconds it took for you to get a question wrong: " << user.duration;
    cout << endl << endl;
}

SubtractionTwo MinusTwo (Player user)
{
    SubtractionTwo minus;
    float timePSec = 1000;
    unsigned seed = time(0);
    srand(seed);                 //Seed random number generator
    clock_t startTime = clock(); //Start timer
    bool proceed;                //Continues the game
    int x;                       //User answer
    int correct;                 //Correct Answer
    
     cout << "Press enter to continue.\n\n";
     cin.get();
     cout << string(50, '\n');
    
    do
    {
        minus.num1 = (rand() % (500) + 100);        //Seed num1 from 100-500
        minus.num2 = (rand() % (500) + 100);        //Seed num2 from 100-500
        
        correct = minus.num1 - minus.num2;
        
        cout << "What is " << minus.num1 << " - " << minus.num2 << "? "; 
        cin >> x;
        
        if (x == correct)
        {
            cout << "Correct!\n\n";
            minus.score += 1;
            proceed = true;
        }
        else
        {
            cout << "Sorry but your answer is incorrect, your game is over.\n\n";
            proceed = false;
        }
    }
    while(proceed);   
    
    user.duration = ( clock() - startTime ) / timePSec;
    
    if (minus.score > minus.hScore)
    {
        minus.hScore = minus.score;
        cout << user.name << " earned a new high score! It is now " << minus.hScore;
        cout << endl << endl;
    }
    
    if (minus.hScore > minus.score)
    {
        cout << user.name << " did not beat their the score of " << minus.hScore 
             << ". You " << "completed a total of " << minus.score << " questions.\n\n"; 
        
    }
    
    cout << "This was many seconds it took for you to get a question wrong: " << user.duration;
    cout << endl << endl;
}