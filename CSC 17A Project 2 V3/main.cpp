/* 
 * File:   main.cpp
 * Author: Alex
 *
 * Created on December 10, 2017, 11:00 AM
 */
#include "MathGame.h"

using namespace std;

int main(int argc, char** argv) 
{
    string player;         //Name of the player
    char play = 'N';       //Character to hold player voice to replay
    int inN;               //Holds player choice of challenge
    fstream hiScore;       //Sends player and score info to a binary file
    Intro start;           //start variable for the intro class to present info
    Equation math;         //math variable to display questions and present info
                           //after losing
    
    cout << "Press enter to begin.\n";
    cin.get();
    hiScore.open("highscore.txt", ios::out | ios::binary);  //Open binary file
    hiScore.write("Name      Score\n", 
                  sizeof("Name      Score\n")); //Setup name/Score
    
    start.Introduction();
    start.Rules();
     
    cout << "Press enter to continue.\n";
    cin.ignore(1,'\n');         //Pause screen
    cout << "Please enter the name of the player: " << endl;
    getline(cin,player);       //Enter name
    cout << "\nThis is name: " << player << endl;
    start.setName(player);     //Send name to class
     
    do
    {        
        player = start.difName(play, player);

        cout << "\nWriting name to file.\n";
        hiScore.write(player.c_str(),player.size()); //Write name to binary file
        hiScore.write("\0", sizeof(char));           //Write null term
       
        cout << endl << endl;        
        start.Menu();         //Display menu
        
        inN = start.getN();     //Accept user input for challenge choice
        
        switch(inN)          //Switch for deciding challenges or if misinput
        {
          case 1:   math.PlusOne(start,player,hiScore);break;
          case 2:   math.PlusTwo(start,player,hiScore);break;
          case 3:   math.MinusOne(start,player,hiScore);break;
          case 4:   math.MinusTwo(start,player,hiScore);break;
          case 5:   math.TimesOne(start,player,hiScore);break;
          case 6:   math.TimesTwo(start,player,hiScore);break;
          case 7:   start.DRules();
                    math.DivideOne(start,player,hiScore);
                    break;
          case 8:   start.DRules();
                    math.DivideTwo(start,player,hiScore);
                    break;
          case 9:   start.ModRules();
                    math.ModOne(start,player,hiScore);
                    break;
          case 10:  start.ModRules();
                    math.ModTwo(start,player,hiScore);
                    break;
          default:  start.getN();
        }     
        
        cout << "Would you like to do another challenge? (Y or N): "; //Ask to play again
        cin >> play;               //User input for replay
        cout << endl << endl;       
    }while (play == 'Y' || play == 'y');

    hiScore.close();          //Close binary file
    return 0;
}