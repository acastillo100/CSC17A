/* 
 * File:   Presentation.cpp
 * Author: Alex
 *
 * Created on December 10, 2017, 11:45 AM
 */
#include "MathGame.h"

//Constructor that sets the name to the protected variable
Intro::Intro(string player)
{
    player = name;

}

//Sets the user inputed name to the protected name variable
void Intro::setName(string player)
{
    name = player;
}

//Presents introduction for when the player boots up program
void Intro::Introduction()
{
    cout << "Welcome to Alex's Math Mathematician Challenge!" << endl;
    cout << "The point of this program is to present to you, the player,\n";
    cout << "a list of challenges from areas of math like addition, subtraction,\n";
    cout << "multiplication, division, and finding the remainder due to a modulus.\n\n";
}

//Presents rules for the mathematical challenges
void Intro::Rules()
{
    cout << "\nThe rules of the game are simple. After choosing an area and a\n";
    cout << "difficulty, the player will be shown a mathematical problem to\n";
    cout << "solve. Each difficulty broadens the range numbers that could\n";
    cout << "show up. A high score will be given depending on where you\n";
    cout << "end up and will be saved. After you can choose to play again.\n\n";
}

//Presents rules for when the player chooses the division challenges
void Intro::DRules()
{
    cout << "\nThis division section uses integer division. Which means all you\n";
    cout << "have to do is enter how many of the second number goes into the\n";
    cout << "first number. I.E. 31 / 10 would equal 3. Or 10 / 31 is 0.\n";
    cout << "Press enter to continue.\n\n";
    cin.get();
}

//Presents rules for when the player chooses the modulus challenge
void Intro::ModRules()
{
    cout << "\nThis division section uses integer division. Which means all you\n";
    cout << "have to do is enter how many of the second number goes into the\n";
    cout << "first number. I.E. 31 / 10 would equal 3. Or 10 / 31 is 0.\n";
    cout << "Press enter to continue.\n\n";
    cin.get();
}

//Presents the menu for the player to look at and choose a challenge
void Intro::Menu()
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

//Function if the user wants to change their name after finishing a challenge
string Intro::difName(char change, string player)
{
    if (change == 'Y' || change == 'y') //Only activates on replay
        {
            cout << "Would you like to change your name? (Y or N): ";
            cin >> change;     //Character to hold player choice of name change
            cout << endl << endl;
        
            if (change == 'Y' || change == 'y') //If name wants to be changed
            {
                cin.ignore(1000,'\n');      //Prevent skipping of name on retry
                cout << "Please enter the name of the player: ";
                getline(cin,player);        //Enter new name
                Intro::setName(player);
                cout << endl << endl;
            }
        }
    return player;
}

//Get the user variable for the challenge choice
int Intro::getN()
{
    int inN = 0;
    cout << "Please enter a number to choose a challenge: ";
    cin >> inN;
    cout << endl;
    return inN;   
}

//Displays addition problems from the first difficulty
Equation::AddOne Equation::PlusOne(Intro times, string player, fstream &hiScore)
{
    AddOne plus;             //Created plus variable of AdditionOne structure
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
Equation::AddTwo Equation::PlusTwo(Intro times, string player, fstream &hiScore)
{
    AddTwo plus;             //Create variable plus of AdditionTwo structure
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
Equation::SubOne Equation::MinusOne(Intro times, string player, fstream &hiScore)
{
    SubOne minus;         //Created minus variable of SubtractionOne structure
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
Equation::SubTwo Equation::MinusTwo(Intro times, string player, fstream &hiScore)
{
    SubTwo minus;         //Created minus variable of SubtractionTwo structure
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
Equation::MultiOne Equation::TimesOne(Intro times, string player, fstream &hiScore)
{
    MultiOne mult;      //Created times variable of MultiplicationOne structure
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
Equation::MultiTwo Equation::TimesTwo(Intro times, string player, fstream &hiScore)
{
    MultiTwo mult;      //Created times variable of MultiplicationTwo structure
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
Equation::DiviOne Equation::DivideOne(Intro times, string player, fstream &hiScore)
{
    DiviOne divide;            //Created divide variable of DivisionOne structure
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
Equation::DiviTwo Equation::DivideTwo(Intro times, string player, fstream &hiScore)
{
    DiviTwo divide;           //Created divide variable of DivisionTwo structure
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
Equation::ModulusOne Equation::ModOne(Intro times, string player, fstream &hiScore)
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
Equation::ModulusTwo Equation::ModTwo(Intro times,string player, fstream &hiScore)
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