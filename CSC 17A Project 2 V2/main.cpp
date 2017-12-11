/* 
 * File:   main.cpp
 * Author: Alex
 *
 * Created on December 5, 2017, 11:00 AM
 */

#include <cstdlib>                         //For randomized numbers     
#include <ctime>                           //For timer function
#include <fstream>                         //To write to binary file
#include "MathGame.h"
using namespace std;

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

AdditionOne PlusOne(Intro,string,fstream&);        //First addition challenge
AdditionTwo PlusTwo(Intro,string,fstream&);        //Second addition challenge
SubtractionOne MinusOne(Intro,string,fstream&);    //First subtraction challenge
SubtractionTwo MinusTwo(Intro,string,fstream&);    //Second subtraction challenge
MultiplicationOne TimesOne(Intro,string,fstream&); //First multiplication challenge
MultiplicationTwo TimesTwo(Intro,string,fstream&); //Second multiplication challenge
DivisionOne DivideOne(Intro,string,fstream&);      //First division challenge
DivisionTwo DivideTwo(Intro,string,fstream&);      //Second division challenge
ModulusOne ModOne(Intro,string,fstream&);          //First modulus challenge
ModulusTwo ModTwo(Intro,string,fstream&);          //Second modulus challenge


using namespace std;

int main(int argc, char** argv) 
{
//    Player *user;           //Creates a pointer variable user of the Player structure
    string player;         //Name of the player
    char play;             //Character to hold player voice to replay
    int inN;               //Holds player choice of challenge
    fstream hiScore;       //Sends player and score info to a binary file
    Intro start;
    Equation math;
    
    cout << "Press enter to begin.\n";
    cin.get();
    hiScore.open("highscore.txt", ios::out | ios::binary);
    hiScore.write("Name      Score\n", 
                  sizeof("Name      Score\n")); //Setup name/Score
    
    start.Introduction();
    start.Rules();
     
    cout << "Press enter to continue.\n";
    cin.ignore(1,'\n');         //Pause screen
    cout << "Please enter the name of the player: " << endl;
    getline(cin,player);       //Enter name
    start.setName(player);     //Send name to class
     
    do
    {        
        player = start.difName(play);

        cout << "\nWriting name to file.\n";
        hiScore.write(player.c_str(),player.size());
        hiScore.write("\0", sizeof(char));
       
        cout << endl << endl;        
        start.Menu();
        
        inN = start.getN();     //Accept user input for challenge choice
        
        switch(inN)          //Switch for deciding challenges or if misinput
        {
          case 1:   PlusOne(start,player,hiScore);break;
          case 2:   PlusTwo(start,player,hiScore);break;
          case 3:   MinusOne(start,player,hiScore);break;
          case 4:   MinusTwo(start,player,hiScore);break;
          case 5:   TimesOne(start,player,hiScore);break;
          case 6:   TimesTwo(start,player,hiScore);break;
          case 7:   start.DRules();
                    DivideOne(start,player,hiScore);
                    break;
          case 8:   start.DRules();
                    DivideTwo(start,player,hiScore);
                    break;
          case 9:   start.ModRules();
                    ModOne(start,player,hiScore);
                    break;
          case 10:  start.ModRules();
                    ModTwo(start,player,hiScore);
                    break;
          default:  start.getN();
        }     
        
        cout << "Would you like to do another challenge? (Y or N): "; //Ask to play again
        cin >> play;               //User input for
        cout << endl << endl;       
    }while (play == 'Y' || play == 'y');

    hiScore.close();

    return 0;
}

//Displays addition problems from the first difficulty
AdditionOne PlusOne (Intro times, string player, fstream &hiScore)
{
    AdditionOne plus;             //Created plus variable of AdditionOne structure
    static float timePSec = 1000; //Time per second to 1000 to show time in seconds
    unsigned seed = time(0);      //Set seed to zero time
    srand(seed);                  //Seed random number generator
    clock_t startTime = clock();  //Start timer
    bool proceed;                 //Continues the game
    int x;                        //User answer
    int correct;                  //Correct Answer
    char play[1];                 //Character array, to play again, of one 
    
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
    
        times.user->duration = ( clock() - startTime ) / timePSec;
    
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
    
        cout << "This was how many seconds it took for you to get a question wrong: " << times.user->duration;
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
AdditionTwo PlusTwo (Intro times, string player, fstream &hiScore)
{
    AdditionTwo plus;             //Create variable plus of AdditionTwo structure
    static float timePSec = 1000; //Time per second to 1000 to show time in seconds
    unsigned seed = time(0);      //Set seed to zero time
    srand(seed);                  //Seed random number generator
    clock_t startTime = clock();  //Start timer
    bool proceed;                 //Continues the game
    int x;                        //User answer
    int correct;                  //Correct Answer
    char play[1];                 //Character array, to play again, of one 
    
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
    
        times.user->duration = ( clock() - startTime ) / timePSec;
    
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
    
        cout << "This was how many seconds it took for you to get a question wrong: " << times.user->duration;
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
SubtractionOne MinusOne (Intro times, string player, fstream &hiScore)
{
    SubtractionOne minus;         //Created minus variable of SubtractionOne structure
    static float timePSec = 1000; //Time per second to 1000 to show time in seconds
    unsigned seed = time(0);      //Set seed to zero time
    srand(seed);                  //Seed random number generator
    clock_t startTime = clock();  //Start timer
    bool proceed;                 //Continues the game
    int x;                        //User answer
    int correct;                  //Correct Answer
    char play[1];                 //Character array, to play again, of one 
    
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
    
        times.user->duration = ( clock() - startTime ) / timePSec;
    
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
    
        cout << "This was how many seconds it took for you to get a question wrong: " << times.user->duration;
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
SubtractionTwo MinusTwo (Intro times, string player, fstream &hiScore)
{
    SubtractionTwo minus;         //Created minus variable of SubtractionTwo structure
    static float timePSec = 1000; //Time per second to 1000 to show time in seconds
    unsigned seed = time(0);      //Set seed to zero time
    srand(seed);                  //Seed random number generator
    clock_t startTime = clock();  //Start timer
    bool proceed;                 //Continues the game
    int x;                        //User answer
    int correct;                  //Correct Answer
    char play[1];                 //Character array, to play again, of one 
    
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
    
        times.user->duration = ( clock() - startTime ) / timePSec;
    
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
    
        cout << "This was how many seconds it took for you to get a question wrong: " << times.user->duration;
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
MultiplicationOne TimesOne (Intro times, string player, fstream &hiScore)
{
    MultiplicationOne mult;      //Created times variable of MultiplicationOne structure
    static float timePSec = 1000; //Time per second to 1000 to show time in seconds
    unsigned seed = time(0);      //Set seed to zero time
    srand(seed);                  //Seed random number generator
    clock_t startTime = clock();  //Start timer
    bool proceed;                 //Continues the game
    int x;                        //User answer
    int correct;                  //Correct Answer
    char play[1];                 //Character array, to play again, of one 
    
     cout << "Press enter to continue.\n\n";
     cin.get();
     cout << string(50, '\n');
    
    do{
        mult.score = 0;
        cout << string(50, '\n');
    
        do
        {
            mult.num1 = (rand() % (12) + 0);        //Seed num1 from 0-12
            mult.num2 = (rand() % (12) + 0);        //Seed num2 from 0-12
        
            correct = mult.num1 * mult.num2;
        
            cout << "What is " << mult.num1 << " * " << mult.num2 << "? "; 
            cin >> x;
        
            if (x == correct)
            {
              cout << "Correct!\n\n";
              mult.score += 1;
              proceed = true;
            }
            else
            {
                cout << "Sorry but your answer is incorrect, your game is over.\n\n";
                proceed = false;
            }
        }
        while(proceed);   
    
        times.user->duration = ( clock() - startTime ) / timePSec;
    
        if (mult.score > mult.hScore)
        {
            mult.hScore = mult.score;
            cout << player << " earned a new high score! It is now " << mult.hScore;
            cout << endl << endl;
        }
    
        if (mult.hScore > mult.score)
        {
            cout << player << " did not beat their the score of " << mult.hScore 
                << ". You " << "completed a total of " << mult.score << " questions.\n\n";        
        }
    
        cout << "This was how many seconds it took for you to get a question wrong: " << times.user->duration;
        cout << endl << endl;
        
        hiScore.write("      ", sizeof("     "));
        hiScore.write(reinterpret_cast<char *>(&mult.score), sizeof(mult.score));
        hiScore.write("\n", sizeof("\n"));
        
        cout << "Would you like to play again? (Y or N): ";
        cin >> play;
        cout << endl << endl;
    }while(play[0] == 'Y' || play[0] == 'y');
}

//Displays multiplication problems from the second difficulty
MultiplicationTwo TimesTwo (Intro times, string player, fstream &hiScore)
{
    MultiplicationTwo mult;      //Created times variable of MultiplicationTwo structure
    static float timePSec = 1000; //Time per second to 1000 to show time in seconds
    unsigned seed = time(0);      //Set seed to zero time
    srand(seed);                  //Seed random number generator
    clock_t startTime = clock();  //Start timer
    bool proceed;                 //Continues the game
    int x;                        //User answer
    int correct;                  //Correct Answer
    char play[1];                 //Character array, to play again, of one 
    
     cout << "Press enter to continue.\n\n";
     cin.get();
     cout << string(50, '\n');
    
    do{
        mult.score = 0;
        cout << string(50, '\n');
    
        do
        {
            mult.num1 = (rand() % (25) + 0);        //Seed num1 from 0-25
            mult.num2 = (rand() % (20) + 0);        //Seed num2 from 0-20
        
            correct = mult.num1 * mult.num2;
        
            cout << "What is " << mult.num1 << " * " << mult.num2 << "? "; 
            cin >> x;
        
            if (x == correct)
            {
              cout << "Correct!\n\n";
              mult.score += 1;
              proceed = true;
            }
            else
            {
                cout << "Sorry but your answer is incorrect, your game is over.\n\n";
                proceed = false;
            }
        }
        while(proceed);   
    
        times.user->duration = ( clock() - startTime ) / timePSec;
    
        if (mult.score > mult.hScore)
        {
            mult.hScore = mult.score;
            cout << player << " earned a new high score! It is now " << mult.hScore;
            cout << endl << endl;
        }
    
        if (mult.hScore > mult.score)
        {
            cout << player << " did not beat their the score of " << mult.hScore 
                << ". You " << "completed a total of " << mult.score << " questions.\n\n";        
        }
    
        cout << "This was how many seconds it took for you to get a question wrong: " << times.user->duration;
        cout << endl << endl;
        
        hiScore.write("      ", sizeof("     "));
        hiScore.write(reinterpret_cast<char *>(&mult.score), sizeof(mult.score));
        hiScore.write("\n", sizeof("\n"));
        
        cout << "Would you like to play again? (Y or N): ";
        cin >> play;
        cout << endl << endl;
    }while(play[0] == 'Y' || play[0] == 'y');
}

//Displays division problems from the first difficulty
DivisionOne DivideOne(Intro times, string player, fstream &hiScore)
{
    DivisionOne divide;            //Created divide variable of DivisionOne structure
    static float timePSec = 1000; //Time per second to 1000 to show time in seconds
    unsigned seed = time(0);      //Set seed to zero time
    srand(seed);                  //Seed random number generator
    clock_t startTime = clock();  //Start timer
    bool proceed;                 //Continues the game
    int x;                        //User answer
    int correct;                  //Correct Answer
    char play[1];                 //Character array, to play again, of one 
    
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
    
        times.user->duration = ( clock() - startTime ) / timePSec;
    
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
    
        cout << "This was how many seconds it took for you to get a question wrong: " << times.user->duration;
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
DivisionTwo DivideTwo(Intro times, string player, fstream &hiScore)
{
    DivisionTwo divide;           //Created divide variable of DivisionTwo structure
    static float timePSec = 1000; //Time per second to 1000 to show time in seconds
    unsigned seed = time(0);      //Set seed to zero time
    srand(seed);                  //Seed random number generator
    clock_t startTime = clock();  //Start timer
    bool proceed;                 //Continues the game
    int x;                        //User answer
    int correct;                  //Correct Answer
    char play[1];                 //Character array, to play again, of one 
    
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
    
        times.user->duration = ( clock() - startTime ) / timePSec;
    
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
    
        cout << "This was how many seconds it took for you to get a question wrong: " << times.user->duration;
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
ModulusOne ModOne(Intro times, string player, fstream &hiScore)
{
    ModulusOne mod;               //Created mod variable of ModulusOne structure
    static float timePSec = 1000; //Time per second to 1000 to show time in seconds
    unsigned seed = time(0);      //Set seed to zero time
    srand(seed);                  //Seed random number generator
    clock_t startTime = clock();  //Start timer
    bool proceed;                 //Continues the game
    int x;                        //User answer
    int correct;                  //Correct Answer
    char play[1];                 //Character array, to play again, of one 
    
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
    
        times.user->duration = ( clock() - startTime ) / timePSec;
    
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
    
        cout << "This was how many seconds it took for you to get a question wrong: " << times.user->duration;
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
ModulusTwo ModTwo(Intro times,string player, fstream &hiScore)
{
    ModulusTwo mod;               //Created mod variable of ModulusTwo structure
    static float timePSec = 1000; //Time per second to 1000 to show time in seconds
    unsigned seed = time(0);      //Set seed to zero time
    srand(seed);                  //Seed random number generator
    clock_t startTime = clock();  //Start timer
    bool proceed;                 //Continues the game
    int x;                        //User answer
    int correct;                  //Correct Answer
    char play[1];                 //Character array, to play again, of one 
    
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
    
        times.user->duration = ( clock() - startTime ) / timePSec;
    
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
    
        cout << "This was how many seconds it took for you to get a question wrong: " << times.user->duration;
        cout << endl << endl;
        
        hiScore.write("      ", sizeof("     "));
        hiScore.write(reinterpret_cast<char *>(&mod.score), sizeof(mod.score));
        hiScore.write("\n", sizeof("\n"));
        
        cout << "Would you like to play again? (Y or N): ";
        cin >> play;
        cout << endl << endl;
    }while(play[0] == 'Y' || play[0] == 'y');
}