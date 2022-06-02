/*
    TravellerGeneration, written by Jacob Seadorf on May 30, 2022

    This program creates a character according to some slightly modified Classic Traveller(tm) rules, namely:
    * Dice Modifiers (DMs) are not possible; only straight rolls are used
    * Death during character creation not possible; the optional rule that uses character injury is used instead.
*/


#include "Character.h"

int main() {
    Character c;
    c.init();
    c.enlist();
    return 0;
}
