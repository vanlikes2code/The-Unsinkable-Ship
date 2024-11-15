#include <iostream>
#include <string>
// #include <windows.h>
using namespace std;

string player_choice; //initialize player choice and corresponding variables
int num_of_survivors = 705;
int titanic_speed_MPH = 24;
int nos_guess = 0;
int ts_guess = 0;
int iceberg_visibility = 10;
int iceberg_guess = 0;
int hintcounter = 0;
int danger = 0;
int direction1;
string crew;
int remaining_guesses = 2; // initial guesses for each question
int randvariable = rand() % 2;
int lightnumber = 0;
string lights;

int main() {
    //exposition and general directions and facts

    cout << "Welcome to the Unsinkable Ship, AKA: The Titanic!" << endl;
    cout << "\nAs Captain of this esteemed vessel, your responsibility will be to make executive decisions regarding the ship's \nmovement, in other words, steering the ship away from danger!" << endl;
    cout << "\nBut be warned, for I have heard tales of faulty rivets, brittle fractures, and improperly sealed compartments. Not \nto mention, the water below is freezing cold..." << endl;;
    cout << "\nIf you are up for the challenge, enter 'Captain' below." << endl;

    // loop until user enters 'Captain'
    while (true) {
        cin >> player_choice; //input for player's role choice
        if (player_choice == "Captain" || player_choice == "captain") {
            break; // exit the loop if input is correct
        } else {
            cout << "Uh Oh! It seems the game did not expect your input! Please try again." << endl;
        }
    }

    //main game so far
    if (player_choice == "Captain" || player_choice == "captain") {
        cout << "\nYou will be presented with the option to move left, right, or straight, and choose wisely, as your decisions \nare responsible for the lives of 2,240 innocent passengers." << endl;
        cout << "\nDid you know there were only enough lifeboats for one third of the people on board?" << endl;
        cout << "\nWith that in mind, about how many people do you think survived the Titanic?" << endl;

        while (remaining_guesses >= 0) { // guesses loop for survivors question
            cin >> nos_guess;

            //range and outputs given player guess
            if (nos_guess >= 695 && nos_guess <= 715) {
                cout << "HINT: Maybe you should move to the right!" << endl;
                hintcounter = hintcounter + 1;
                break;
            }
            else {
                cout << "Better luck next time. You have " << remaining_guesses << " guesses left." << endl;
                remaining_guesses = remaining_guesses - 1;
                int absNonsense = abs(num_of_survivors - nos_guess);
                cout << "You were " << absNonsense << " off from the correct answer." << endl;
            }
        }

        //first scenario for choosing direction
        do {
            cout << "Would you like to continue straight (0), go left (1), or go right (2)?:" << endl;
            cin >> direction1;

            switch (direction1) { //switch given user input
                case 0:
                    danger += 15;
                break;
                case 1:
                    danger += 13;
                break;
                case 2:
                    danger += 11;
                break;
                default: //if input is invalid
                    cout << "You entered an invalid number. Please try again" << endl;
                cin >> direction1;
            }
        } while (direction1 != 0 && direction1 != 1 && direction1 != 2);

        //context and question
        remaining_guesses = 2; // reset guesses for next question
        cout << "\nThe Titanic is classified as a Luxury Steamboat, most of which only travelled around 15-20 knots an hour." << endl;
        cout << "About how fast, in MPH, do you think the Titanic was travelling?" << endl;

        while (remaining_guesses >= 0) { // guesses loop for speed question
            cin >> ts_guess;

            //2nd range and outputs given player guess
            if (ts_guess >= 24 && ts_guess <= 26) {
                cout << "HINT: Enter a number between 25 & 30!" << endl;
                hintcounter = hintcounter + 1;
                break;
            } else {
                cout << "You entered the number " << ts_guess << "! Which unfortunately was wrong! You have " << remaining_guesses << " guesses left." << endl;
                remaining_guesses = remaining_guesses - 1;
                int absNonsense2 = abs(titanic_speed_MPH - ts_guess);
                cout << "You were " << absNonsense2 << " off from the correct answer." << endl;
            }
        }

        // second scenario: choose speed
        int speed1;
        do
        {
            cout << "\nNext on the agenda! How fast should the Titanic travel?" << endl;
            cout << "Please enter an integer number (5 to 100 mph) for the speed:" << endl;
            cin >> speed1;

            if (speed1 >= 5 && speed1 < 23) { //given user input, how much danger points will be added
                danger += 15;
            }
            else if (speed1 <= 30) {
                danger += 11;
            }
            else if (speed1 <= 100) {
                danger += 17;
            }
            else {
                cout << "You entered an invalid number. Please try again." << endl;
                cin >> speed1;
            }
        } while (speed1 > 100);

        //context and question
        remaining_guesses = 2; // reset guesses for next question
        cout << "\nBy the time the steersmen had realized they were approaching an iceberg, \nit was already too late." << endl;
        cout << "About how much, in terms of a percentage, of an iceberg do you think is actually visible above water?" << endl;

        while (remaining_guesses >= 0) { // guesses loop for iceberg visibility question
            cin >> iceberg_guess;

            //3rd range and outputs given player guess
            if (5 <= iceberg_guess && iceberg_guess <= 15) {
                cout << "HINT: Steer the ship to the right!" << endl;
                hintcounter = hintcounter + 1;
                break;
            } else {
                cout << "You thought " << iceberg_guess << "%?! Well, that was wrong! You have " << remaining_guesses << " guesses left." << endl;
                remaining_guesses = remaining_guesses - 1;
                int absNonsense3 = abs(iceberg_visibility - iceberg_guess);
                cout << "You were " << absNonsense3 << " off from the correct answer." << endl;
            }
        }

        // scenario three: choose direction
        int direction2;
        do
        {
            cout << "\nLooks like the waves are getting rough out there.." << endl;
            cout << "Would you like to continue straight (0), go left (1), or go right (2)?:" << endl;
            cin >> direction2;

            switch (direction2) { //given user input, how many danger points are added
                case 0:
                    danger += 13;
                break;
                case 1:
                    danger += 15;
                break;
                case 2:
                    danger += 11;
                break;
                default:
                    cout << "You entered an invalid number. Please try again." << endl;
                cin >> direction2;
            }
        } while (direction2 != 0 && direction2 != 1 && direction2 != 2);

        //context and question
        cout << "\nA ship as large as the Titanic needs a crew just as mighty." << endl;
        cout << "True or False: There were over 500 crew members aboard the Titanic, including engineers, waitstaff, and deck crews?" << endl;
        cin >> crew;
        if (crew == "true" || crew == "True") {
            cout << "HINT: You should NOT allow the crew to take a break, this ship does not run itself!" << endl;
            hintcounter = hintcounter + 1;
        } else {
            cout << "Sorry, but that's incorrect!" << endl;
        }

        // scenario four: choose number of crew members to go on break
        int crewQU;
        string b;
        do
        {
            cout << "\nYour crew is getting tired" << endl;
            cout << "Will you allow them to take a break? (y/n):" << endl;
            cin >> b;

            if (b.compare("y") == 0) { //if user decides to give crew members a break
                do
                {
                    cout << "How kind! How many crew members will be on break? (1-50):" << endl;
                    cin >> crewQU;
                    if (crewQU <= 3) {
                        danger += 12;
                    }
                    else if (crewQU <= 5) {
                        danger += 15;
                    }
                    else if (crewQU <= 50) {
                        danger += 20;
                    }
                    else {
                        cout << "You entered an invalid number. Please try again." << endl;
                        cin >> crewQU;
                    }
                } while (crewQU > 50);
            }

            else if (b.compare("n") == 0) {  //else if no to the break
                cout << "That was probably for the best." << endl;
                danger += 5;
            }
            else {
                cout << "You entered an invalid response. Please try again." << endl;
                cin >> b;
            }
        } while (b.compare("y") != 0 && b.compare("n") != 0);

        //print hint value and apply bonus
        cout << "You successfully earned " << hintcounter << " hints, now you will receive your bonus." << endl;
        if (hintcounter >= 0 && hintcounter <= 10) {
            danger -= hintcounter/2 + 4;
            if (danger < 0)
            {
                danger = 0;
            }
        }

        if (danger > 37) { //light sequences corresponding with their performance in the game so far
            if (randvariable == 1) {
                cout << "\nEnter 3347 into the other computer, and wait for the lights to flash then rewrite the flashing lights in order into this computer: 'l' for left light, 'r' for right light, 's' for the middle/straight light." << endl << "Example of what it should look like lrlrrss: " << endl;
                cin >> lights;
                if(lights == "lsrsllr") {
                    cout << "You have successful steered the Titanic away from seemingly imminent danger." << endl << "Good Job Captain!" << endl;
                }
                else {
                    cout << "You lose the Titanic has sunk." << endl;
                }
            }
            else{
                cout << "\nEnter 3326 into the other computer, and wait for the lights to flash then rewrite the flashing lights in order into this computer: 'l' for left light, 'r' for right light, 's' for the middle/straight light." << endl << "Example of what it should look like lrlrrss: " << endl;
                cin >> lights;
                if(lights == "lsrlssr") {
                    cout << "You have successful steered the Titanic away from seemingly imminent danger." << endl << "Good Job Captain!" << endl;
                }
                else {
                    cout << "You lose the Titanic has sunk." << endl;
                }
            }
            return 0;
        }

        if (danger > 35) {
            if (randvariable == 1) {
                cout << "\nEnter 2625 into the other computer, and wait for the lights to flash then rewrite the flashing lights in order into this computer: 'l' for left light, 'r' for right light, 's' for the middle/straight light." << endl << "Example of what it should look like lrlrrss: " << endl;
                cin >> lights;
                if(lights == "llrsrls") {
                    cout << "You have successful steered the Titanic away from seemingly imminent danger." << endl << "Good Job Captain!" << endl;
                }
                else {
                    cout << "You lose the Titanic has sunk." << endl;
                }
            }
            else {
                cout << "\nEnter 2355 into the other computer, and wait for the lights to flash then rewrite the flashing lights in order into this computer: 'l' for left light, 'r' for right light, 's' for the middle/straight light." << endl << "Example of what it should look like lrlrrss: " << endl;
                cin >> lights;
                if(lights == "rslsrss") {
                    cout << "You have successful steered the Titanic away from seemingly imminent danger." << endl << "Good Job Captain!" << endl;
                }
                else {
                    cout << "You lose the Titanic has sunk." << endl;
                }
                return 0;
            }
        }
        if (randvariable == 1) {
            cout << "\nEnter 1874 into the other computer, and wait for the lights to flash then rewrite the flashing lights in order into this computer: 'l' for left light, 'r' for right light, 's' for the middle/straight light." << endl << "Example of what it should look like lrlrrss: " << endl;
            cin >> lights;
            if(lights == "lslssrl") {
                cout << "You have successful steered the Titanic away from seemingly imminent danger." << endl << "Good Job Captain" << endl;
            }
            else {
                cout << "You lose the Titanic has sunk." << endl;
            }
        }
        else {
            cout << "\nEnter 1924 into the other computer, and wait for the lights to flash then rewrite the flashing lights in order into this computer: 'l' for left light, 'r' for right light 's' for the middlecc/straight light." << endl << "Example of what it should look like lrlrrss: " << endl;
            cin >> lights;
            if(lights == "lssrslr") {
                cout << "You have successful steered the Titanic away from seemingly imminent danger." << endl << "Good Job Captain." << endl;
            }
            else {
                cout << "You lose the Titanic has sunk." << endl;
            }
        }
    }
        return 0;
}
