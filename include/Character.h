/*
    Character Creation Checklist:
    1. Roll characteristics
    2. Select service
        A. if rejected, try draft
        B. Roll survival
        C. Attempt rank
            1) if rank 0, attempt commission
            2) if commissioned, attempt promotion
        D. Determine skills
            1) Automatic Skills
            2) Acquired skills
            3) Specify cascade skills
        E. if completing 4th term or later, determine aging effects
        F. Roll for re-enlistment (2B)
    3. Muster Out
        A. Determine benefits
        B. Record characteristics and skills
*/

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
    int _rank;
    bool _commissioned;
};

#endif // CHARACTER_H
