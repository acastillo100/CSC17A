/* 
 * File:   MathGame.h
 * Author: Alex
 *
 * Created on December 10, 2017, 11:05 AM
 */

#ifndef MATHGAME_H
#define MATHGAME_H

#include <iostream>                        //To accept user input
#include <cstdlib>                         //For randomized numbers     
#include <ctime>                           //For timer function
#include <string>                          //For user inputed name
#include <fstream>                         //To write to binary file

using namespace std;

class Intro
{
protected:
    string name;         //Name of the player
    
public:
    Intro()               //Default constructor
        {name;}
    Intro(string);       //Constructor declaration
    void Introduction(); //Introduces the program and its usage to the player
    void Rules();        //Introduces the rules to the player
    void DRules();       //Introduces the rules for the division problems and integer division
    void ModRules();     //Introduces the rules for modulus problems
    void Menu();         //Presents the menu selection to the user
    virtual void setName(string); //Set the player's name to the protected name string
    string difName(char, string); //Asks if the user wants to change their name
    int getN();          //Asks the user which challenge they want to partake in 
    
    struct Player          //Structure containing long it takes to fail a problem   
{                      
    float duration;    //How long it takes to fail a problem in a category
};
Player *user;
};

class Equation : public Intro
{
public:
struct AddOne     //Structure containing the elements for the first addition level
{
    int num1;         //First number to be created
    int num2;         //Second number to be created and added to num1
    int score;        //How many questions the user has answered
    int hScore = 0;   //The highest amount of questions answered
};

struct AddTwo   //Structure containing the elements for the second addition level
{
    int num1;         //First number to be created
    int num2;         //Second number to be created and added to num1
    int score;        //How many questions the user has answered
    int hScore = 0;   //The highest amount of questions answered
};

struct SubOne    //Structure containing the elements for the first subtraction level
{
    int num1;         //First number to be created
    int num2;         //Second number to be created and subtracted by num1
    int score;        //How many questions the user has answered
    int hScore = 0;   //The highest amount of questions answered
};

struct SubTwo    //Structure containing the elements for the second subtraction level
{
    int num1;         //First number to be created
    int num2;         //Second number to be created and subtracted by num1
    int score;        //How many questions the user has answered
    int hScore = 0;   //The highest amount of questions answered
};

struct MultiOne  //Structure containing the elements for the first multiplication level
{
    int num1;         //First number to be created
    int num2;         //Second number to be created and multiplied by num1
    int score;        //How many questions the user has answered
    int hScore = 0;   //The highest amount of questions answered
};

struct MultiTwo  //Structure containing the elements for the second multiplication level
{
    int num1;         //First number to be created
    int num2;         //Second number to be created and multiplied by num1
    int score;        //How many questions the user has answered
    int hScore = 0;   //The highest amount of questions answered
};

struct DiviOne  //Structure containing the elements for the first division level
{
    int num1;         //First number to be created
    int num2;         //Second number to be created and divided by num1
    int score;        //How many questions the user has answered
    int hScore = 0;   //The highest amount of questions answered
};

struct DiviTwo  //Structure containing the elements for the second division level
{
    int num1;         //First number to be created
    int num2;         //Second number to be created and divided by num1
    int score;        //How many questions the user has answered
    int hScore = 0;   //The highest amount of questions answered
};

struct ModulusOne    //Structure containing the elements for the first modulus level
{
    int num1;         //First number to be created
    int num2;         //Second number to be created and modded by num1
    int score;        //How many questions the user has answered
    int hScore = 0;   //The highest amount of questions answered
};

struct ModulusTwo   //Structure containing the elements for the second modulus level
{
    int num1;         //First number to be created
    int num2;         //Second number to be created and modded by num1
    int score;        //How many questions the user has answered
    int hScore = 0;   //The highest amount of questions answered
};

AddOne plus1;        //Created plus variable of AdditionOne structure
AddTwo plus2;        //Created plus variable of AdditionTwo structure
SubOne minus1;       //Created minus variable of SubtractionOne structure
SubTwo minus2;       //Created minus variable of SubtractionTwo structure
MultiOne mult1;      //Created times variable of MultiplicationOne structure
MultiTwo mult2;      //Created times variable of MultiplicationTwo structure
DiviOne divide1;     //Created divide variable of DivisionOne structure
DiviTwo divide2;     //Created divide variable of DivisionTwo structure
ModulusOne mod1;     //Created mod variable of ModulusOne structure
ModulusTwo mod2;     //Created mod variable of ModulusTwo structure

AddOne PlusOne(Intro,string,fstream&);         //First addition challenge
AddTwo PlusTwo(Intro,string,fstream&);         //Second addition challenge
SubOne MinusOne(Intro,string,fstream&);        //First subtraction challenge
SubTwo MinusTwo(Intro,string,fstream&);        //Second subtraction challenge
MultiOne TimesOne(Intro,string,fstream&);      //First multiplication challenge
MultiTwo TimesTwo(Intro,string,fstream&);      //Second multiplication challenge
DiviOne DivideOne(Intro,string,fstream&);      //First division challenge
DiviTwo DivideTwo(Intro,string,fstream&);      //Second division challenge
ModulusOne ModOne(Intro,string,fstream&);      //First modulus challenge
ModulusTwo ModTwo(Intro,string,fstream&);      //Second modulus challenge   
};
#endif /* MATHGAME_H */