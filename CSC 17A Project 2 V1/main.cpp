/* 
 * File:   main.cpp
 * Author: Alex
 *
 * Created on December 2, 2017, 10:00 AM
 */

#include <iostream>
#include <cstdlib>                         //For randomized numbers     
#include <ctime>                           //For timer function
#include <string>                          //For iser inputed name
#include <fstream>

using namespace std;

struct Player          //Structure containing long it takes to fail a problem
{                      
    float duration;    //How long it takes to fail a problem in a category
};

struct AdditionOne     //Structure containing the elements for the first addition level
{
    int num1;         //First number to be created
    int num2;         //Second number to be created and added to num1
    int score;        //How many questions the user has answered
    int hScore = 0;   //The highest amount of questions answered
};

struct AdditionTwo
{
    int num1;         //First number to be created
    int num2;         //Second number to be created and added to num1
    int score;        //How many questions the user has answered
    int hScore = 0;   //The highest amount of questions answered
};

struct SubtractionOne
{
    int num1;         //First number to be created
    int num2;         //Second number to be created and subtracted by num1
    int score;        //How many questions the user has answered
    int hScore = 0;   //The highest amount of questions answered
};

struct SubtractionTwo
{
    int num1;         //First number to be created
    int num2;         //Second number to be created and subtracted by num1
    int score;        //How many questions the user has answered
    int hScore = 0;   //The highest amount of questions answered
};

struct MultiplicationOne
{
    int num1;         //First number to be created
    int num2;         //Second number to be created and multiplied by num1
    int score;        //How many questions the user has answered
    int hScore = 0;   //The highest amount of questions answered
};

struct MultiplicationTwo
{
    int num1;         //First number to be created
    int num2;         //Second number to be created and multiplied by num1
    int score;        //How many questions the user has answered
    int hScore = 0;   //The highest amount of questions answered
};

struct DivisionOne
{
    int num1;         //First number to be created
    int num2;         //Second number to be created and divided by num1
    int score;        //How many questions the user has answered
    int hScore = 0;   //The highest amount of questions answered
};

struct DivisionTwo
{
    int num1;         //First number to be created
    int num2;         //Second number to be created and divided by num1
    int score;        //How many questions the user has answered
    int hScore = 0;   //The highest amount of questions answered
};

struct ModulusOne
{
    int num1;         //First number to be created
    int num2;         //Second number to be created and modded by num1
    int score;        //How many questions the user has answered
    int hScore = 0;   //The highest amount of questions answered
};

struct ModulusTwo
{
    int num1;         //First number to be created
    int num2;         //Second number to be created and modded by num1
    int score;        //How many questions the user has answered
    int hScore = 0;   //The highest amount of questions answered
};

void Intro();        //Introduces the program and its usage to the player
void Rules();        //Introduces the rules to the player
void DRules();       //Introduces the rules for the division problems and integer division
void ModRules();     //Introduces the rules for modulus problems
void Menu();         //Presents the menu selection to the user
int getN(int);       //Asks the user which challenge they want to partake in
AdditionOne PlusOne(Player*,string,fstream&);        //First addition challenge
AdditionTwo PlusTwo(Player*,string,fstream&);        //Second addition challenge
SubtractionOne MinusOne(Player*,string,fstream&);    //First subtraction challenge
SubtractionTwo MinusTwo(Player*,string,fstream&);    //Second subtraction challenge
MultiplicationOne TimesOne(Player*,string,fstream&); //First multiplication challenge
MultiplicationTwo TimesTwo(Player*,string,fstream&); //Second multiplication challenge
DivisionOne DivideOne(Player*,string,fstream&);      //First division challenge
DivisionTwo DivideTwo(Player*,string,fstream&);      //Second division challenge
ModulusOne ModOne(Player*,string,fstream&);          //First modulus challenge
ModulusTwo ModTwo(Player*,string,fstream&);          //Second modulus challenge


using namespace std;

int main(int argc, char** argv) 
{
    Player *user;           //Creates a pointer variable user of the Player structure
    string player;         //Name of the player
    char play;             //Character to hold player voice to replay
    char change;           //Character to hold player choice of name change
    int inN;               //Holds player choice of challenge
    fstream hiScore;       //Sends player and score info to a binary file
    
    cout << "Press enter to begin.\n";
    cin.get();
    hiScore.open("highscore.txt", ios::out | ios::binary);
    hiScore.write("Name      Score\n", 
                  sizeof("Name      Score\n")); //Setup name/Score
    
    Intro();
    
    Rules();
     
    cout << "Press enter to continue.\n";
    cin.ignore(1,'\n');         //Pause screen
    cout << "Please enter the name of the player: " << endl;
    getline(cin,player);
     
    do
    {        
        if (play == 'Y' || play == 'y') //Only activates on replay
        {
            cout << "Would you like to change your name? (Y or N): ";
            cin >> change;
            cout << endl << endl;
        
            if (change == 'Y' || change == 'y') //If name wants to be changed
            {
                cin.ignore(1000,'\n');      //Prevent skipping of name on retry
                cout << "Please enter the name of the player: ";
                getline(cin,player);        //Enter new game
                cout << endl << endl;
            }
        }

//        hiScore.open("highscore.txt", ios::out | ios::binary);
        cout << "\nWriting name to file.\n";
//        hiScore.write("Name      Score\n", sizeof("Name      Score\n"));
        hiScore.write(player.c_str(),player.size());
        hiScore.write("\0", sizeof(char));
//        hiScore.close();
        
        
        cout << endl << endl;
        
        Menu();              //Call in menu
        
        inN = getN(inN);     //Accept user input for challenge choice
        
        switch(inN)          //Switch for deciding challenges or if misinput
        {
          case 1:    PlusOne(user,player,hiScore);break;
          case 2:    PlusTwo(user,player,hiScore);break;
          case 3:    MinusOne(user,player,hiScore);break;
          case 4:    MinusTwo(user,player,hiScore);break;
          case 5:    TimesOne(user,player,hiScore);break;
          case 6:    TimesTwo(user,player,hiScore);break;
          case 7:    DRules();
                     DivideOne(user,player,hiScore);
                     break;
          case 8:    DRules();
                     DivideTwo(user,player,hiScore);
                     break;
          case 9:   ModRules();
                    ModOne(user,player,hiScore);
                    break;
          case 10:  ModRules();
                    ModTwo(user,player,hiScore);
                    break;
          default:   getN(inN);
        }     
        
        cout << "Would you like to do another challenge? (Y or N): "; //Ask to play again
        cin >> play;               //User input for
        cout << endl << endl;       
    }while (play == 'Y' || play == 'y');

    hiScore.close();

    return 0;
}

//Presents the program to player and the challenges they can choose from
void Intro()
{
    cout << "Welcome to Alex's Math Mathematician Challenge!" << endl;
    cout << "The point of this program is to present to you, the player,\n";
    cout << "a list of challenges from areas of math like addition, subtraction,\n";
    cout << "multiplication, division, and finding the remainder due to a modulus.\n\n";
}

//Presents the rules and how high scores will be saved
void Rules()
{
    cout << "\nThe rules of the game are simple. After choosing an area and a\n";
    cout << "difficulty, the player will be shown a mathematical problem to\n";
    cout << "solve. Each difficulty broadens the range numbers that could\n";
    cout << "show up. A high score will be given depending on where you\n";
    cout << "end up and will be saved. After you can choose to play again.\n\n";
}

//Presents rules for when the player chooses the division challenges
void DRules()
{
    cout << "\nThis division section uses integer division. Which means all you\n";
    cout << "have to do is enter how many of the second number goes into the\n";
    cout << "first number. I.E. 31 / 10 would equal 3. Or 10 / 31 is 0.\n";
    cout << "Press enter to continue.\n\n";
    cin.get();
}

//Presents rules for when the player chooses the modulus challenge
void ModRules()
{
    cout << "\nThis modulus section requires you to insert the number left\n";
    cout << "over from the division of the two numbers you see.\n";
    cout << "I.E. 31 / 10 would equal 1. Or 39 / 8 is 7.\n";
    cout << "Press enter to continue.\n\n";
    cin.get();
}

//Presents the menu for the player to look at and choose a challenge
void Menu()
{
    cout << "Choice #1: Addition Level 1\n";
    cout << "Choice #2: Addition Level 2\n";
    cout << "Choice #3: Subtraction Level 1\n";
    cout << "Choice #4: Subtraction Level 2\n";
    cout << "Choice #5: Multiplication Level 1\n";
    cout << "Choice #6: Multiplication Level 2\n";
    cout << "Choice #7: Division Level 1\n";
    cout << "Choice #8: Division Level 2\n";
    cout << "Choice #9: Modulus Level 1\n";
    cout << "Choice #10: Modulus Level 2\n";
}

//Asks the user to choose a challenges and accepts user input
int getN(int inN)
{
    cout << "Please enter a number to choose a challenge: ";
    cin >> inN;
    cout << endl;
    return inN;
}

//Displays addition problems from the first difficulty
AdditionOne PlusOne (Player *user, string player, fstream &hiScore)
{
    AdditionOne plus;            //Created plus variable of AdditionOne structure
    float timePSec = 1000;       //Time per second to 1000 to show time in seconds
    unsigned seed = time(0);     //Set seed to zero time
    srand(seed);                 //Seed random number generator
    clock_t startTime = clock(); //Start timer
    bool proceed;                //Continues the game
    int x;                       //User answer
    int correct;                 //Correct Answer
    char play[1];                //Character array, to play again, of one 
    
    cout << "Press enter to continue.\n\n";
    cin.get();
    
    do{
        plus.score = 0;       
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
    
        user->duration = ( clock() - startTime ) / timePSec;
    
        if (plus.score > plus.hScore)
        {
            plus.hScore = plus.score;
            cout << player << " earned a new high score! It is now " << plus.hScore;
            cout << endl << endl;
        }
    
        if (plus.hScore > plus.score)
        {
            cout << player << " did not beat their the score of " << plus.hScore 
                << ". You " << "completed a total of " << plus.score << " questions.\n\n";        
        }
    
        cout << "This was many seconds it took for you to get a question wrong: " << user->duration;
        cout << endl << endl;
        
        hiScore.write("      ", sizeof("     "));
        hiScore.write(reinterpret_cast<char *>(&plus.score), sizeof(plus.score));
        hiScore.write("\n", sizeof("\n"));
        
        cout << "Would you like to play again? (Y or N): ";
        cin >> play;
        cout << endl << endl;
    }while(play[0] == 'Y' || play[0] == 'y');
}

//Displays addition problems from the second difficulty
AdditionTwo PlusTwo (Player *user, string player, fstream &hiScore)
{
    AdditionTwo plus;            //Create variable plus of AdditionTwo structure
    float timePSec = 1000;       //Time per second to 1000 to show time in seconds
    unsigned seed = time(0);     //Set seed to zero time
    srand(seed);                 //Seed random number generator
    clock_t startTime = clock(); //Start timer
    bool proceed;                //Continues the game
    int x;                       //User answer
    int correct;                 //Correct Answer
    char play[1];                //Character array, to play again, of one 
    
     cout << "Press enter to continue.\n\n";
     cin.get();
     cout << string(50, '\n');
    
    do{
        plus.score = 0;
        cout << string(50, '\n');
    
        do
        {
            plus.num1 = (rand() % (500) + 100);          //Seed num1 from 100-500
            plus.num2 = (rand() % (500) + 100);          //Seed num2 from 100-500
        
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
    
        user->duration = ( clock() - startTime ) / timePSec;
    
        if (plus.score > plus.hScore)
        {
            plus.hScore = plus.score;
            cout << player << " earned a new high score! It is now " << plus.hScore;
            cout << endl << endl;
        }
    
        if (plus.hScore > plus.score)
        {
            cout << player << " did not beat their the score of " << plus.hScore 
                << ". You " << "completed a total of " << plus.score << " questions.\n\n";        
        }
    
        cout << "This was many seconds it took for you to get a question wrong: " << user->duration;
        cout << endl << endl;
        
        hiScore.write("      ", sizeof("     "));
        hiScore.write(reinterpret_cast<char *>(&plus.score), sizeof(plus.score));
        hiScore.write("\n", sizeof("\n"));
        
        cout << "Would you like to play again? (Y or N): ";
        cin >> play;
        cout << endl << endl;
    }while(play[0] == 'Y' || play[0] == 'y');
}

//Displays subtraction problems from the first difficulty
SubtractionOne MinusOne (Player *user, string player, fstream &hiScore)
{
    SubtractionOne minus;        //Created minus variable of SubtractionOne structure
    float timePSec = 1000;       //Time per second to 1000 to show time in seconds
    unsigned seed = time(0);     //Set seed to zero time
    srand(seed);                 //Seed random number generator
    clock_t startTime = clock(); //Start timer
    bool proceed;                //Continues the game
    int x;                       //User answer
    int correct;                 //Correct Answer
    char play[1];                //Character array, to play again, of one 
    
     cout << "Press enter to continue.\n\n";
     cin.get();
     cout << string(50, '\n');
    
    do{
        minus.score = 0;
        cout << string(50, '\n');
    
        do
        {
            minus.num1 = (rand() % (100) + 41);      //Seed num1 from 41-100
            minus.num2 = (rand() % (60) + 1);        //Seed num2 from 1-60
        
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
    
        user->duration = ( clock() - startTime ) / timePSec;
    
        if (minus.score > minus.hScore)
        {
            minus.hScore = minus.score;
            cout << player << " earned a new high score! It is now " << minus.hScore;
            cout << endl << endl;
        }
    
        if (minus.hScore > minus.score)
        {
            cout << player << " did not beat their the score of " << minus.hScore 
                << ". You " << "completed a total of " << minus.score << " questions.\n\n";        
        }
    
        cout << "This was many seconds it took for you to get a question wrong: " << user->duration;
        cout << endl << endl;
        
        hiScore.write("      ", sizeof("     "));
        hiScore.write(reinterpret_cast<char *>(&minus.score), sizeof(minus.score));
        hiScore.write("\n", sizeof("\n"));
        
        cout << "Would you like to play again? (Y or N): ";
        cin >> play;
        cout << endl << endl;
    }while(play[0] == 'Y' || play[0] == 'y');
}

//Displays subtraction problems from the second difficulty
SubtractionTwo MinusTwo (Player *user, string player, fstream &hiScore)
{
    SubtractionTwo minus;        //Created minus variable of SubtractionTwo structure
    float timePSec = 1000;       //Time per second to 1000 to show time in seconds
    unsigned seed = time(0);     //Set seed to zero time
    srand(seed);                 //Seed random number generator
    clock_t startTime = clock(); //Start timer
    bool proceed;                //Continues the game
    int x;                       //User answer
    int correct;                 //Correct Answer
    char play[1];                //Character array, to play again, of one 
    
     cout << "Press enter to continue.\n\n";
     cin.get();
     cout << string(50, '\n');
    
    do{
        minus.score = 0;
        cout << string(50, '\n');
    
        do
        {
            minus.num1 = (rand() % (150) + 1);        //Seed num1 from 1-150
            minus.num2 = (rand() % (130) + 1);        //Seed num2 from 1-130
        
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
    
        user->duration = ( clock() - startTime ) / timePSec;
    
        if (minus.score > minus.hScore)
        {
            minus.hScore = minus.score;
            cout << player << " earned a new high score! It is now " << minus.hScore;
            cout << endl << endl;
        }
    
        if (minus.hScore > minus.score)
        {
            cout << player << " did not beat their the score of " << minus.hScore 
                << ". You " << "completed a total of " << minus.score << " questions.\n\n";        
        }
    
        cout << "This was many seconds it took for you to get a question wrong: " << user->duration;
        cout << endl << endl;
        
        hiScore.write("      ", sizeof("     "));
        hiScore.write(reinterpret_cast<char *>(&minus.score), sizeof(minus.score));
        hiScore.write("\n", sizeof("\n"));
        
        cout << "Would you like to play again? (Y or N): ";
        cin >> play;
        cout << endl << endl;
    }while(play[0] == 'Y' || play[0] == 'y');
}

//Displays multiplication problems from the first difficulty
MultiplicationOne TimesOne (Player *user, string player, fstream &hiScore)
{
    MultiplicationOne times;     //Created times variable of MultiplicationOne structure
    float timePSec = 1000;       //Time per second to 1000 to show time in seconds
    unsigned seed = time(0);     //Set seed to zero time
    srand(seed);                 //Seed random number generator
    clock_t startTime = clock(); //Start timer
    bool proceed;                //Continues the game
    int x;                       //User answer
    int correct;                 //Correct Answer
    char play[1];                //Character array, to play again, of one 
    
     cout << "Press enter to continue.\n\n";
     cin.get();
     cout << string(50, '\n');
    
    do{
        times.score = 0;
        cout << string(50, '\n');
    
        do
        {
            times.num1 = (rand() % (12) + 0);        //Seed num1 from 0-12
            times.num2 = (rand() % (12) + 0);        //Seed num2 from 0-12
        
            correct = times.num1 * times.num2;
        
            cout << "What is " << times.num1 << " * " << times.num2 << "? "; 
            cin >> x;
        
            if (x == correct)
            {
              cout << "Correct!\n\n";
              times.score += 1;
              proceed = true;
            }
            else
            {
                cout << "Sorry but your answer is incorrect, your game is over.\n\n";
                proceed = false;
            }
        }
        while(proceed);   
    
        user->duration = ( clock() - startTime ) / timePSec;
    
        if (times.score > times.hScore)
        {
            times.hScore = times.score;
            cout << player << " earned a new high score! It is now " << times.hScore;
            cout << endl << endl;
        }
    
        if (times.hScore > times.score)
        {
            cout << player << " did not beat their the score of " << times.hScore 
                << ". You " << "completed a total of " << times.score << " questions.\n\n";        
        }
    
        cout << "This was many seconds it took for you to get a question wrong: " << user->duration;
        cout << endl << endl;
        
        hiScore.write("      ", sizeof("     "));
        hiScore.write(reinterpret_cast<char *>(&times.score), sizeof(times.score));
        hiScore.write("\n", sizeof("\n"));
        
        cout << "Would you like to play again? (Y or N): ";
        cin >> play;
        cout << endl << endl;
    }while(play[0] == 'Y' || play[0] == 'y');
}

//Displays multiplication problems from the second difficulty
MultiplicationTwo TimesTwo (Player *user, string player, fstream &hiScore)
{
    MultiplicationTwo times;     //Created times variable of MultiplicationTwo structure
    float timePSec = 1000;       //Time per second to 1000 to show time in seconds
    unsigned seed = time(0);     //Set seed to zero time
    srand(seed);                 //Seed random number generator
    clock_t startTime = clock(); //Start timer
    bool proceed;                //Continues the game
    int x;                       //User answer
    int correct;                 //Correct Answer
    char play[1];                //Character array, to play again, of one 
    
     cout << "Press enter to continue.\n\n";
     cin.get();
     cout << string(50, '\n');
    
    do{
        times.score = 0;
        cout << string(50, '\n');
    
        do
        {
            times.num1 = (rand() % (25) + 0);        //Seed num1 from 0-25
            times.num2 = (rand() % (20) + 0);        //Seed num2 from 0-20
        
            correct = times.num1 * times.num2;
        
            cout << "What is " << times.num1 << " * " << times.num2 << "? "; 
            cin >> x;
        
            if (x == correct)
            {
              cout << "Correct!\n\n";
              times.score += 1;
              proceed = true;
            }
            else
            {
                cout << "Sorry but your answer is incorrect, your game is over.\n\n";
                proceed = false;
            }
        }
        while(proceed);   
    
        user->duration = ( clock() - startTime ) / timePSec;
    
        if (times.score > times.hScore)
        {
            times.hScore = times.score;
            cout << player << " earned a new high score! It is now " << times.hScore;
            cout << endl << endl;
        }
    
        if (times.hScore > times.score)
        {
            cout << player << " did not beat their the score of " << times.hScore 
                << ". You " << "completed a total of " << times.score << " questions.\n\n";        
        }
    
        cout << "This was many seconds it took for you to get a question wrong: " << user->duration;
        cout << endl << endl;
        
        hiScore.write("      ", sizeof("     "));
        hiScore.write(reinterpret_cast<char *>(&times.score), sizeof(times.score));
        hiScore.write("\n", sizeof("\n"));
        
        cout << "Would you like to play again? (Y or N): ";
        cin >> play;
        cout << endl << endl;
    }while(play[0] == 'Y' || play[0] == 'y');
}

//Displays division problems from the first difficulty
DivisionOne DivideOne(Player *user, string player, fstream &hiScore)
{
   DivisionOne divide;           //Created divide variable of DivisionOne structure
    float timePSec = 1000;       //Time per second to 1000 to show time in seconds
    unsigned seed = time(0);     //Set seed to zero time
    srand(seed);                 //Seed random number generator
    clock_t startTime = clock(); //Start timer
    bool proceed;                //Continues the game
    int x;                       //User answer
    int correct;                 //Correct Answer
    char play[1];                //Character array, to play again, of one 
    
     cin.get();
     cout << string(50, '\n');
    
    do{
        divide.score = 0;
        cout << string(50, '\n');
    
        do
        {
            divide.num1 = (rand() % (10) + 0);        //Seed num1 from 0-10
            divide.num2 = (rand() % (30) + 0);        //Seed num2 from 0-30
        
            correct = divide.num2 / divide.num1;
        
            cout << "What is " << divide.num2 << " / " << divide.num1 << "? "; 
            cin >> x;
        
            if (x == correct)
            {
              cout << "Correct!\n\n";
              divide.score += 1;
              proceed = true;
            }
            else
            {
                cout << "Sorry but your answer is incorrect, your game is over.\n\n";
                proceed = false;
            }
        }
        while(proceed);   
    
        user->duration = ( clock() - startTime ) / timePSec;
    
        if (divide.score > divide.hScore)
        {
            divide.hScore = divide.score;
            cout << player << " earned a new high score! It is now " << divide.hScore;
            cout << endl << endl;
        }
    
        if (divide.hScore > divide.score)
        {
            cout << player << " did not beat their the score of " << divide.hScore 
                << ". You " << "completed a total of " << divide.score << " questions.\n\n";        
        }
    
        cout << "This was many seconds it took for you to get a question wrong: " << user->duration;
        cout << endl << endl;
        
        hiScore.write("      ", sizeof("     "));
        hiScore.write(reinterpret_cast<char *>(&divide.score), sizeof(divide.score));
        hiScore.write("\n", sizeof("\n"));
        
        cout << "Would you like to play again? (Y or N): ";
        cin >> play;
        cout << endl << endl;
    }while(play[0] == 'Y' || play[0] == 'y'); 
}

//Displays division problems from the second difficulty
DivisionTwo DivideTwo(Player *user, string player, fstream &hiScore)
{
    DivisionTwo divide;          //Created divide variable of DivisionTwo structure
    float timePSec = 1000;       //Time per second to 1000 to show time in seconds
    unsigned seed = time(0);     //Set seed to zero time
    srand(seed);                 //Seed random number generator
    clock_t startTime = clock(); //Start timer
    bool proceed;                //Continues the game
    int x;                       //User answer
    int correct;                 //Correct Answer
    char play[1];                //Character array, to play again, of one 
    
     cin.get();
     cout << string(50, '\n');
    
    do{
        divide.score = 0;
        cout << string(50, '\n');
    
        do
        {
            divide.num1 = (rand() % (20) + 0);        //Seed num1 from 0-20
            divide.num2 = (rand() % (100) + 0);       //Seed num2 from 0-100
        
            correct = divide.num2 / divide.num1;
        
            cout << "What is " << divide.num2 << " / " << divide.num1 << "? "; 
            cin >> x;
        
            if (x == correct)
            {
              cout << "Correct!\n\n";
              divide.score += 1;
              proceed = true;
            }
            else
            {
                cout << "Sorry but your answer is incorrect, your game is over.\n\n";
                proceed = false;
            }
        }
        while(proceed);   
    
        user->duration = ( clock() - startTime ) / timePSec;
    
        if (divide.score > divide.hScore)
        {
            divide.hScore = divide.score;
            cout << player << " earned a new high score! It is now " << divide.hScore;
            cout << endl << endl;
        }
    
        if (divide.hScore > divide.score)
        {
            cout << player << " did not beat their the score of " << divide.hScore 
                << ". You " << "completed a total of " << divide.score << " questions.\n\n";        
        }
    
        cout << "This was many seconds it took for you to get a question wrong: " << user->duration;
        cout << endl << endl;
        
        hiScore.write("      ", sizeof("     "));
        hiScore.write(reinterpret_cast<char *>(&divide.score), sizeof(divide.score));
        hiScore.write("\n", sizeof("\n"));
        
        cout << "Would you like to play again? (Y or N): ";
        cin >> play;
        cout << endl << endl;
    }while(play[0] == 'Y' || play[0] == 'y'); 
}

//Displays modulus problems from the first difficulty
ModulusOne ModOne(Player *user, string player, fstream &hiScore)
{
    ModulusOne mod;              //Created mod variable of ModulusOne structure
    float timePSec = 1000;       //Time per second to 1000 to show time in seconds
    unsigned seed = time(0);     //Set seed to zero time
    srand(seed);                 //Seed random number generator
    clock_t startTime = clock(); //Start timer
    bool proceed;                //Continues the game
    int x;                       //User answer
    int correct;                 //Correct Answer
    char play[1];                //Character array, to play again, of one 
    
     cout << string(50, '\n');   
    do{
        mod.score = 0;
        cout << string(50, '\n');
    
        do
        {
            mod.num1 = (rand() % (15) + 0);        //Seed num1 from 0-15
            mod.num2 = (rand() % (50) + 0);        //Seed num2 from 0-50
        
            correct = mod.num2 % mod.num1;
        
            cout << "What is " << mod.num2 << " % " << mod.num1 << "? "; 
            cin >> x;
        
            if (x == correct)
            {
              cout << "Correct!\n\n";
              mod.score += 1;
              proceed = true;
            }
            else
            {
                cout << "Sorry but your answer is incorrect, your game is over.\n\n";
                proceed = false;
            }
        }
        while(proceed);   
    
        user->duration = ( clock() - startTime ) / timePSec;
    
        if (mod.score > mod.hScore)
        {
            mod.hScore = mod.score;
            cout << player << " earned a new high score! It is now " << mod.hScore;
            cout << endl << endl;
        }
    
        if (mod.hScore > mod.score)
        {
            cout << player << " did not beat their the score of " << mod.hScore 
                << ". You " << "completed a total of " << mod.score << " questions.\n\n";        
        }
    
        cout << "This was many seconds it took for you to get a question wrong: " << user->duration;
        cout << endl << endl;
        
        hiScore.write("      ", sizeof("     "));
        hiScore.write(reinterpret_cast<char *>(&mod.score), sizeof(mod.score));
        hiScore.write("\n", sizeof("\n"));
        
        cout << "Would you like to play again? (Y or N): ";
        cin >> play;
        cout << endl << endl;
    }while(play[0] == 'Y' || play[0] == 'y');
}

//Displays modulus problems from the second difficulty
ModulusTwo ModTwo(Player *user,string player, fstream &hiScore)
{
    ModulusTwo mod;              //Created mod variable of ModulusTwo structure
    float timePSec = 1000;       //Time per second to 1000 to show time in seconds
    unsigned seed = time(0);     //Set seed to zero time
    srand(seed);                 //Seed random number generator
    clock_t startTime = clock(); //Start timer
    bool proceed;                //Continues the game
    int x;                       //User answer
    int correct;                 //Correct Answer
    char play[1];                //Character array, to play again, of one 
    
    cout << string(50, '\n');   
    do{
        mod.score = 0;
        cout << string(50, '\n');
    
        do
        {
            mod.num1 = (rand() % (35) + 0);        //Seed num1 from 0-35
            mod.num2 = (rand() % (100) + 0);       //Seed num2 from 0-100
        
            correct = mod.num2 % mod.num1;
        
            cout << "What is " << mod.num2 << " % " << mod.num1 << "? "; 
            cin >> x;
        
            if (x == correct)
            {
              cout << "Correct!\n\n";
              mod.score += 1;
              proceed = true;
            }
            else
            {
                cout << "Sorry but your answer is incorrect, your game is over.\n\n";
                proceed = false;
            }
        }
        while(proceed);   
    
        user->duration = ( clock() - startTime ) / timePSec;
    
        if (mod.score > mod.hScore)
        {
            mod.hScore = mod.score;
            cout << player << " earned a new high score! It is now " << mod.hScore;
            cout << endl << endl;
        }
    
        if (mod.hScore > mod.score)
        {
            cout << player << " did not beat their the score of " << mod.hScore 
                << ". You " << "completed a total of " << mod.score << " questions.\n\n";        
        }
    
        cout << "This was many seconds it took for you to get a question wrong: " << user->duration;
        cout << endl << endl;
        
        hiScore.write("      ", sizeof("     "));
        hiScore.write(reinterpret_cast<char *>(&mod.score), sizeof(mod.score));
        hiScore.write("\n", sizeof("\n"));
        
        cout << "Would you like to play again? (Y or N): ";
        cin >> play;
        cout << endl << endl;
    }while(play[0] == 'Y' || play[0] == 'y');
}