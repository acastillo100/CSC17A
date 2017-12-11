#include "MathGame.h"

//template <class M>
Intro::Intro(string player)
{
    player = name;
}

void Intro::setName(string player)
{
    name = player;
}

//template <class M>
void Intro::Introduction()
{
    cout << "Welcome to Alex's Math Mathematician Challenge!" << endl;
    cout << "The point of this program is to present to you, the player,\n";
    cout << "a list of challenges from areas of math like addition, subtraction,\n";
    cout << "multiplication, division, and finding the remainder due to a modulus.\n\n";
}

//template <class M>
void Intro::Rules()
{
    cout << "\nThe rules of the game are simple. After choosing an area and a\n";
    cout << "difficulty, the player will be shown a mathematical problem to\n";
    cout << "solve. Each difficulty broadens the range numbers that could\n";
    cout << "show up. A high score will be given depending on where you\n";
    cout << "end up and will be saved. After you can choose to play again.\n\n";
}

//Presents rules for when the player chooses the division challenges
//template <class M>
void Intro::DRules()
{
    cout << "\nThis division section uses integer division. Which means all you\n";
    cout << "have to do is enter how many of the second number goes into the\n";
    cout << "first number. I.E. 31 / 10 would equal 3. Or 10 / 31 is 0.\n";
    cout << "Press enter to continue.\n\n";
    cin.get();
}

//Presents rules for when the player chooses the modulus challenge
//template <class M>
void Intro::ModRules()
{
    cout << "\nThis division section uses integer division. Which means all you\n";
    cout << "have to do is enter how many of the second number goes into the\n";
    cout << "first number. I.E. 31 / 10 would equal 3. Or 10 / 31 is 0.\n";
    cout << "Press enter to continue.\n\n";
    cin.get();
}

//Presents the menu for the player to look at and choose a challenge
//template <class M>
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

string Intro::difName(char change)
{
    string player = "Null";
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
            return player;
        }
}

int Intro::getN()
{
    int inN = 0;
    cout << "Please enter a number to choose a challenge: ";
    cin >> inN;
    cout << endl;
    return inN;   
}