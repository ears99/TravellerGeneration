#include "Character.h"

std::default_random_engine e(time(0));
std::uniform_int_distribution<int> oneD6(1,6);
std::uniform_int_distribution<int> twoD6(2,12);

Character::Character() {}

Character::~Character() {}

void Character::init() {
    _strength = twoD6(e);
    _dexterity = twoD6(e);
    _endurance = twoD6(e);
    _intelligence = twoD6(e);
    _education = twoD6(e);
    _socialStanding = twoD6(e);
    _age = 18;
    _term = 0.0f;
    _enlistedInto;
    _credits = 0;

    std::cout << "Character Statistics:\n";
    std::cout << "Strength: " << _strength << std::endl;
    std::cout << "Dexterity: " << _dexterity << std::endl;
    std::cout << "Endurance: " << _endurance << std::endl;
    std::cout << "Intelligence: " << _intelligence << std::endl;
    std::cout << "Education: " << _education << std::endl;
    std::cout << "Social Standing: " << _socialStanding << std::endl;
    std::cout << "Age: " << _age << std::endl;
}

void Character::enlist() {
    int enlistmentRoll = twoD6(e);
    int characterEnlistmentChoice;
    int enlistedInto;

    std::cout << "\nWhich service would you like to enlist into?\n";
    std::cout << "1. Navy\n";
    std::cout << "2. Marines\n";
    std::cout << "3. Army\n";
    std::cout << "4. Scouts\n";
    std::cout << "5. Merchants\n";
    std::cout << "6. Other\n";
    std::cout << "7. Retire\n";
    std::cin >> characterEnlistmentChoice;

    switch(characterEnlistmentChoice) {
            case 1: //navy
                if(enlistmentRoll >= 8) {
                    std::cout << "You have been enlisted into the Navy!\n";
                    _enlistedInto = services::NAVY;
                    rollSurvival();
                } else {
                    std::cout << "You have not been accepted into the Navy; roll for the draft\n";
                    rollDraft();
                }
            break;
            case 2: //marines
                if(enlistmentRoll >= 9) {
                    std::cout << "You have been enlisted into the Marines!\n";
                    _enlistedInto = services::MARINES;
                    rollSurvival();
                } else {
                    std::cout << "You have not been accepted into the Marines; roll for the draft\n";
                    rollDraft();
                }
            break;
            case 3: //army
                if(enlistmentRoll >= 5) {
                    std::cout << "You have been enlisted into the Army!\n";
                    _enlistedInto  = services::ARMY;
                    rollSurvival();
                } else {
                    std::cout << "You have not been accepted into the Army; roll for the draft\n";
                    rollDraft();
                }
            break;
            case 4: //scouts
                if(enlistmentRoll >= 7) {
                    std::cout << "You have been enlisted into the Scouts!\n";
                    _enlistedInto  = services::SCOUTS;
                    rollSurvival();
                } else {
                    std::cout << "You have not been accepted into the Scouts, roll for the draft\n";
                    rollDraft();
                }
            break;
            case 5: //merchants
                if(enlistmentRoll >= 7) {
                    std::cout << "You have been enlisted into the Merchant services\n";
                    _enlistedInto  = services::MERCHANTS;
                    rollSurvival();
                } else {
                    std::cout << "You have not been accepted into the Merchant services; roll for the draft\n";
                    rollDraft();
                }
            break;
            case 6: //other
                if(enlistmentRoll >= 3) {
                    std::cout << "You have been enlisted into other services\n";
                    _enlistedInto  = services::OTHER;
                    rollSurvival();
                } else {
                    std::cout << "You have not been accepted into other services; roll for the draft\n";
                    rollDraft();
                }
            break;

            case 7:
                retire();
            break;

            default:
                std::cout << "ERROR: INVALID INPUT\n";
                enlist();
            break;
    }
}

void Character::rollDraft() {
    int draftRoll = oneD6(e);

    //enlistment failed; roll for the draft
    switch(draftRoll) {
        case 1:
            std::cout << "You have been drafted into the Navy\n";
            _enlistedInto  = services::NAVY;
            rollSurvival();
        break;

        case 2:
            std::cout << "You have been drafted into the Marines\n";
            _enlistedInto  = services::MARINES;
            rollSurvival();
        break;

        case 3:
            std::cout << "You have been drafted into the Army\n";
            _enlistedInto  = services::ARMY;
            rollSurvival();
        break;

        case 4:
            std::cout << "You have been drafted into the Scouts\n";
            _enlistedInto  = services::SCOUTS;
            rollSurvival();
        break;

        case 5:
            std::cout << "You have been drafted into the Merchants\n";
            _enlistedInto  = services::MERCHANTS;
            rollSurvival();
        break;

        case 6:
            std::cout << "You have been drafted into other services\n";
            _enlistedInto  = services::OTHER;
            rollSurvival();
        break;
    }
}

void Character::rollSurvival() {
    int survival = twoD6(e);
    _age = _age + 4;
    _term = _term + 1;

    switch(_enlistedInto) {

        case NAVY: //5+
            if(survival >= 5) {
                std::cout << "You have survived your term without incident\n";

                std::cout << "Age: " << _age << std::endl;
                std::cout << "Term: " << _term << std::endl;
                reEnlist();
            } else {
                std::cout << "You have been injured in the line of duty!\n";
                std::cout << "Age: " << _age << std::endl;
                std::cout << "Term: " << _term - 0.5f << std::endl;
                reEnlist();
            }
        break;

        case MARINES: //6+
            if(survival >= 6) {
                std::cout << "You have survived your term without incident\n";
                std::cout << "Age: " << _age << std::endl;
                std::cout << "Term: " << _term << std::endl;
                reEnlist();
            } else {
                std::cout << "You have been injured in the line of duty!\n";
                std::cout << "Age: " << _age << std::endl;
                std::cout << "Term: " << _term - 0.5f << std::endl;
                reEnlist();
            }
        break;

        case ARMY: //5+
        if(survival >= 5) {
                std::cout << "You have survived your term without incident\n";
                std::cout << "Age: " << _age << std::endl;
                std::cout << "Term: " << _term << std::endl;
                reEnlist();
            } else {
                std::cout << "You have been injured in the line of duty!\n";
                std::cout << "Age: " << _age << std::endl;
                std::cout << "Term: " << _term - 0.5f<< std::endl;
                reEnlist();
            }
        break;

        case SCOUTS: //7+
        if(survival >= 7) {
                std::cout << "You have survived your term without incident\n";
                std::cout << "Age: " << _age << std::endl;
                std::cout << "Term: " << _term << std::endl;
                reEnlist();
            } else {
                std::cout << "You have been injured in the line of duty!\n";
                std::cout << "Age: " << _age << std::endl;
                std::cout << "Term: " << _term - 0.5f << std::endl;
                reEnlist();
            }
        break;

        case MERCHANTS: //5+
        if(survival >= 5) {
                std::cout << "You have survived your term without incident\n";
                std::cout << "Age: " << _age << std::endl;
                std::cout << "Term: " << _term << std::endl;
                reEnlist();
            } else {
                std::cout << "You have been injured in the line of duty!\n";
                std::cout << "Age: " << _age << std::endl;
                std::cout << "Term: " << _term - 0.5f << std::endl;
                reEnlist();
            }
        break;

        case OTHER: //5+
        if(survival >= 5) {
                std::cout << "You have survived your term without incident\n";
                std::cout << "Age: " << _age << std::endl;
                std::cout << "Term: " << _term << std::endl;
                reEnlist();
            } else {
                std::cout << "You have been injured in the line of duty!\n";
                std::cout << "Age: " << _age << std::endl;
                std::cout << "Term: " << _term - 0.5f << std::endl;
                reEnlist();
            }
        break;
    }
}

void Character::attemptCom() {

}

void Character::attemptPro() {

}

void Character::reEnlist() {
    int reEnlistmentRoll = twoD6(e);
    //check for the service the player was enlisted in, roll to re-enlist
    switch(_enlistedInto) {
         case NAVY:
            if(reEnlistmentRoll >= 6) {
                //re-enlistment was successful
                std::cout << "You have been re-enlisted into the Navy\n";
                _enlistedInto = services::NAVY;
                rollSurvival();
            } else if(reEnlistmentRoll == 12) {
                //mandatory re-enlistment
                std::cout << "The Navy is in dire need of your service!\n";
                _enlistedInto = services::NAVY;
                rollSurvival();
            } else {
                std::cout << "The Navy has no need of your services\n";
                enlist();
            }
         break;
         case MARINES:
            if(reEnlistmentRoll >= 6) {
                std::cout << "You have been re-enlisted into the Marines!\n";
                _enlistedInto = services::MARINES;
                rollSurvival();
            } else if(reEnlistmentRoll == 12) {
                std::cout << "The Marines have dire need of your service!\n";
                _enlistedInto = services::MARINES;
                rollSurvival();
            } else {
                std::cout << "The Marines have no need of your services\n";
                enlist();
            }
         break;
         case ARMY:
            if(reEnlistmentRoll >= 7) {
                std::cout << "You have been re-enlisted into the Army!\n";
                _enlistedInto = services::ARMY;
                rollSurvival();
            } else if(reEnlistmentRoll == 12) {
                std::cout << "The army has dire need of your service!\n";
                _enlistedInto = services::ARMY;
                rollSurvival();
            } else {
                std::cout << "The army has no need of your service\n";
                enlist();
            }
         break;
         case SCOUTS:
            if(reEnlistmentRoll >= 3) {
                std::cout << "You have been re-enlisted into the Scout services!\n";
                _enlistedInto = services::SCOUTS;
                rollSurvival();
            } else if(reEnlistmentRoll == 12) {
                std::cout << "The scout services have dire need of your service!\n";
                _enlistedInto = services::SCOUTS;
                rollSurvival();
            } else {
                std::cout << "The scout services have no need of your service\n";
                enlist();
            }
         break;
         case MERCHANTS:
            if(reEnlistmentRoll >= 4) {
                std::cout << "You have been re-enlisted into the Merchant services\n";
                _enlistedInto = services::MERCHANTS;
                rollSurvival();
            } else if(reEnlistmentRoll == 12) {
                std::cout << "The merchant service has dire need of your service!\n";
                _enlistedInto = services::SCOUTS;
                rollSurvival();
            } else {
                std::cout << "The merchant service has no need for your service\n";
                enlist();
            }
         break;
         case OTHER:
            if(reEnlistmentRoll >= 5) {
                std::cout << "You have been re-enlisted into other services\n";
                _enlistedInto = services::OTHER;
                rollSurvival();
            } else if(reEnlistmentRoll == 12) {
                std::cout << "Other services have dire need of your service!\n";
                _enlistedInto = services::OTHER;
                rollSurvival();
            } else {
                std::cout << "Other services don't have any work for you\n";
                enlist();
            }
         break;
    }
}

void Character::retire() {
    int response;
    int roll = oneD6(e);
    std::cout << "You have chosen to retire:\n";
    std::cout << "1. Muster Out\n";
    std::cout << "2. Credits\n";
    std::cin >> response;

    if(response == 1) {
        //muster out
        switch(roll) {
            case 1:
            if(_enlistedInto = services::NAVY) {
                    std::cout << "You have received a free Low Passage\n";
                    displayCharacterSheet();
                } else if(_enlistedInto = services::MARINES) {
                    std::cout << "You have received a free Low Passage\n";
                    displayCharacterSheet();
                } else if(_enlistedInto = services::ARMY) {
                    std::cout << "You have received a free Low Passage\n";
                    displayCharacterSheet();
                } else if(_enlistedInto = services::SCOUTS) {
                    std::cout << "You have received a free Low Passage\n";
                    displayCharacterSheet();
                } else if(_enlistedInto = services::MERCHANTS) {
                    std::cout << "You have received a free Low Passage\n";
                    displayCharacterSheet();
                } else if(_enlistedInto = services::OTHER) {
                    std::cout << "You have received a free Low Passage\n";
                    displayCharacterSheet();
                }
            break;

            case 2:
            if(_enlistedInto = services::NAVY) {
                    std::cout << "Your intelligence has been increased by 1!\n";
                    _intelligence += 1;
                    displayCharacterSheet();
                } else if(_enlistedInto = services::MARINES) {
                    std::cout << "Your intelligence has been increased by 2!\n";
                    _intelligence += 2;
                    displayCharacterSheet();
                } else if(_enlistedInto = services::ARMY) {
                    std::cout << "Your intelligence has been increased by 1!\n";
                    _intelligence += 1;
                    displayCharacterSheet();
                } else if(_enlistedInto = services::SCOUTS) {
                    std::cout << "Your intelligence has been increased by 2!\n";
                    _intelligence += 2;
                    displayCharacterSheet();
                } else if(_enlistedInto = services::MERCHANTS) {
                    std::cout << "Your intelligence has been increased by 1!\n";
                    _intelligence += 1;
                    displayCharacterSheet();
                } else if(_enlistedInto = services::OTHER) {
                    std::cout << "Your intelligence has been increased by 1!\n";
                    _intelligence += 1;
                    displayCharacterSheet();
                }
            break;

            case 3:
            if(_enlistedInto = services::NAVY) {
                std::cout << "Your education has been increased by 2!\n";
                _education += 2;
                displayCharacterSheet();
                } else if(_enlistedInto = services::MARINES) {
                std::cout << "Your education has been increased by 1!\n";
                _education += 1;
                displayCharacterSheet();
                } else if(_enlistedInto = services::ARMY) {
                std::cout << "Your education has been increased by 2!\n";
                _education += 2;
                displayCharacterSheet();
                } else if(_enlistedInto = services::SCOUTS) {
                std::cout << "Your education has been increased by 2!\n";
                _education += 2;
                displayCharacterSheet();
                } else if(_enlistedInto = services::MERCHANTS) {
                std::cout << "Your education has been increased by 1!\n";
                _education += 1;
                displayCharacterSheet();
                } else if(_enlistedInto = services::OTHER) {
                std::cout << "Your education has been increased by 1!\n";
                _education += 1;
                displayCharacterSheet();
                }
            break;

            case 4:
            if(_enlistedInto = services::NAVY) {
                std::cout << "You have received skill in Blade!\n";
                displayCharacterSheet();
                } else if(_enlistedInto = services::MARINES) {
                std::cout << "You have received skill in Blade!\n";
                displayCharacterSheet();
                } else if(_enlistedInto = services::ARMY) {
                std::cout << "You have received skill in Gun!\n";
                displayCharacterSheet();
                } else if(_enlistedInto = services::SCOUTS) {
                std::cout << "You have received skill in Blade!\n";
                displayCharacterSheet();
                } else if(_enlistedInto = services::MERCHANTS) {
                std::cout << "You have received skill in Gun!\n";
                displayCharacterSheet();
                } else if(_enlistedInto = services::OTHER) {
                std::cout << "You have received skill in Gun!\n";
                displayCharacterSheet();
                }
            break;

            case 5:
            if(_enlistedInto = services::NAVY) {
                std::cout << "You've been invited to join the Traveller's Aid Society!\n";
                displayCharacterSheet();
                } else if(_enlistedInto = services::MARINES) {
                std::cout << "You've been invited to join the Traveller's Aid Society!\n";
                displayCharacterSheet();
                } else if(_enlistedInto = services::ARMY) {
                std::cout << "You have been given a high passage!\n";
                displayCharacterSheet();
                } else if(_enlistedInto = services::SCOUTS) {
                std::cout << "You have gained skill in Gun!\n";
                displayCharacterSheet();
                } else if(_enlistedInto = services::MERCHANTS) {
                std::cout << "You have gained skill in Blade!\n";
                displayCharacterSheet();
                } else if(_enlistedInto = services::OTHER) {
                std::cout << "You have been given a high passage!\n";
                displayCharacterSheet();
                }
            break;

            case 6:
            if(_enlistedInto = services::NAVY) {
                std::cout << "You have been given a high passage!\n";
                displayCharacterSheet();
                } else if(_enlistedInto = services::MARINES) {
                std::cout << "You have been given a high passage!\n";
                displayCharacterSheet();
                } else if(_enlistedInto = services::ARMY) {
                std::cout << "You have been given a middle passage!\n";
                displayCharacterSheet();
                } else if(_enlistedInto = services::SCOUTS) {
                std::cout << "You have been given a Scout Ship!\n";
                displayCharacterSheet();
                } else if(_enlistedInto = services::MERCHANTS) {
                std::cout << "You have been given a low passage!\n";
                displayCharacterSheet();
                }
            break;
        }
    } else {
        //credits
        switch(roll) {
            case 1:
                if(_enlistedInto == services::NAVY) {
                  _credits += 1000;
                  displayCharacterSheet();
                } else if(_enlistedInto == services::MARINES) {
                  _credits += 2000;
                  displayCharacterSheet();
                } else if(_enlistedInto == services::ARMY) {
                  _credits += 2000;
                  displayCharacterSheet();
                } else if(_enlistedInto == services::SCOUTS) {
                  _credits += 20000;
                  displayCharacterSheet();
                } else if(_enlistedInto == services::MERCHANTS) {
                   _credits + 1000;
                   displayCharacterSheet();
                } else if(_enlistedInto == services::OTHER) {
                   _credits += 1000;
                   displayCharacterSheet();
                }
            break;

            case 2:
            if(_enlistedInto == services::NAVY) {
                   _credits += 5000;
                   displayCharacterSheet();
                } else if(_enlistedInto == services::MARINES) {
                   _credits += 5000;
                   displayCharacterSheet();
                } else if(_enlistedInto == services::ARMY) {
                   _credits += 5000;
                   displayCharacterSheet();
                } else if(_enlistedInto == services::SCOUTS) {
                    _credits += 20000;
                    displayCharacterSheet();
                } else if(_enlistedInto == services::MERCHANTS) {
                    _credits += 5000;
                    displayCharacterSheet();
                } else if(_enlistedInto == services::OTHER) {
                    _credits += 5000;
                    displayCharacterSheet();
                }
            break;

            case 3:
            if(_enlistedInto == services::NAVY) {
                   _credits += 5000;
                   displayCharacterSheet();
                } else if(_enlistedInto == services::MARINES) {
                   _credits += 5000;
                   displayCharacterSheet();
                } else if(_enlistedInto == services::ARMY) {
                   _credits += 10000;
                   displayCharacterSheet();
                } else if(_enlistedInto == services::SCOUTS) {
                    _credits += 30000;
                    displayCharacterSheet();
                } else if(_enlistedInto == services::MERCHANTS) {
                   _credits += 10000;
                   displayCharacterSheet();
                } else if(_enlistedInto == services::OTHER) {
                   _credits += 10000;
                   displayCharacterSheet();
                }
            break;

            case 4:
            if(_enlistedInto == services::NAVY) {
                   _credits += 10000;
                   displayCharacterSheet();
                } else if(_enlistedInto == services::MARINES) {
                   _credits += 10000;
                   displayCharacterSheet();
                } else if(_enlistedInto == services::ARMY) {
                   _credits += 10000;
                   displayCharacterSheet();
                } else if(_enlistedInto == services::SCOUTS) {
                   _credits += 30000;
                   displayCharacterSheet();
                } else if(_enlistedInto == services::MERCHANTS) {
                   _credits += 20000;
                   displayCharacterSheet();
                } else if(_enlistedInto == services::OTHER) {
                   _credits += 10000;
                   displayCharacterSheet();
                }
            break;

            case 5:
            if(_enlistedInto == services::NAVY) {
               _credits += 20000;
               displayCharacterSheet();
                } else if(_enlistedInto == services::MARINES) {
                _credits += 20000;
                displayCharacterSheet();
                } else if(_enlistedInto == services::ARMY) {
                _credits += 10000;
                displayCharacterSheet();
                } else if(_enlistedInto == services::SCOUTS) {
                _credits += 50000;
                displayCharacterSheet();
                } else if(_enlistedInto == services::MERCHANTS) {
                _credits += 20000;
                displayCharacterSheet();
                } else if(_enlistedInto == services::OTHER) {
                _credits += 10000;
                displayCharacterSheet();
                }
            break;

            case 6:
            if(_enlistedInto == services::NAVY) {
                   _credits += 50000;
                   displayCharacterSheet();
                } else if(_enlistedInto == services::MARINES) {
                    _credits += 30000;
                    displayCharacterSheet();
                } else if(_enlistedInto == services::ARMY) {
                   _credits += 20000;
                   displayCharacterSheet();
                } else if(_enlistedInto == services::SCOUTS) {
                   _credits += 50000;
                   displayCharacterSheet();
                } else if(_enlistedInto == services::MERCHANTS) {
                   _credits += 40000;
                   displayCharacterSheet();
                } else if(_enlistedInto == services::OTHER) {
                   _credits += 50000;
                   displayCharacterSheet();
                }
            break;
        }
    }
}

void Character::displayCharacterSheet() {
    //display character stats, skills, credits, rank (if applicable), age, number of terms
    std::cout << "\n\n========= CHARACTER SHEET =========\n\n";
    std::cout << "======== STATISTICS ========\n";
    std::cout << "Credits: " << _credits << std::endl;
    std::cout << "Age: " << _age << std::endl;
    std::cout << "Strength: " << _strength << std::endl;
    std::cout << "Dexterity: " << _dexterity << std::endl;
    std::cout << "Endurance: " << _endurance << std::endl;
    std::cout << "Intelligence: " << _intelligence << std::endl;
    std::cout << "Education: " << _education << std::endl;
    std::cout << "Social Standing: " << _socialStanding << std::endl;
}
