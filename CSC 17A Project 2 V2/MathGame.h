/* 
 * File:   MathGame.h
 * Author: Alex
 *
 * Created on December 9, 2017, 11:30 AM
 */

#ifndef MATHGAME_H
#define MATHGAME_H

#include <iostream>                        //To accept user input
#include <string>                          //For user inputed name

using namespace std;

//template <class M>
class Intro
{
protected:
    string name;         //Name of the player
    
public:
    Intro()               //Default constructor
        {name = "Null";}
    Intro(string);       //Constructor declaration
    void Introduction(); //Introduces the program and its usage to the player
    void Rules();        //Introduces the rules to the player
    void DRules();       //Introduces the rules for the division problems and integer division
    void ModRules();     //Introduces the rules for modulus problems
    void Menu();         //Presents the menu selection to the user
    void setName(string);
    string difName(char);
    int getN();          //Asks the user which challenge they want to partake in 
    struct Player          //Structure containing long it takes to fail a problem
{                      
    float duration;    //How long it takes to fail a problem in a category
};
Player *user;
};

class Equation : public Intro
{
    
    
};


#endif /* MATHGAME_H */