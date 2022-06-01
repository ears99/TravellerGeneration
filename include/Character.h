#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <random>
#include <ctime>

//services for the character to enlist into
enum services{NAVY, MARINES, ARMY, SCOUTS, MERCHANTS, OTHER};

class Character {
public:

    Character();
    ~Character();
    void init();
    void enlist();
    void rollDraft();
    void rollSurvival();
    void attemptCom(); //attempt commission in Navy, Marines, Army, and Merchants
    void attemptPro(); //attempt promotion in Navy, Marines, Army, and Merchants
    void reEnlist();
    void retire();
    void displayCharacterSheet();
private:
    //stats and other character data
    int _strength;
    int _dexterity;
    int _endurance;
    int _intelligence;
    int _education;
    int _socialStanding;
    float _term;
    int _age;
    int _credits; //amount of money the character has
    int _enlistedInto;
    bool _hardcore;
    bool _dead;
};

#endif // CHARACTER_H
