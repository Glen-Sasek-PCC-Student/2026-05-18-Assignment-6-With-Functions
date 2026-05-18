// ------------- FILE HEADER -------------
// Author ✅: 
// Assignment ✅:
// Date ✅:
// Citations: 


// ------------- ZYBOOKS SCORES -------------
// Chapter ✅: 
// Participation ✅: 
// Challenge ✅:
// Labs ✅:


// ------------- DISCORD POSTS -------------
// https://discord.com/invite/URYKKf8YHm
// Count ✅:
// Links (Optional): 


// ------------- DESIGN DOCUMENT -------------
// A. INPUT ✅: 
// B. OUTPUT ✅:
// C. CALCULATIONS ✅:
// D. LOGIC and ALGORITHMS ✅:
//    (Optional) flow chart link or file name: 


// ------------- TESTING -------------
// PASS ALL GIVEN SAMPLE RUN TESTS ✅: 
// (Optional) Additional tests count:   


// ------------- CODE -------------
#include <iostream>
#include <limits>
#include <iomanip> // For setprecision
#include <cctype>  // For tolower

using namespace std;

// Function prototypes (if any)

const float COFFEE_USD = 0.39;
const float TEA_USD = 0.59;

// Main function
// https://en.cppreference.com/w/cpp/language/main_function.html
int main(int argc, char* argv[]) {
    cout << fixed << setprecision(2) << endl;

    cout << "Welcome to my Coffee/Tea Vending Machine!" << endl;

    bool next_main_loop = true;
    double balance_USD = 0.0;

    while(next_main_loop) {
        // Get Coins
        bool next_coin = true;
        while(next_coin) {
            bool invalid_input = false;
            int coin = -1;
            cout << "Enter coins - 5, 10, or 25 only [0 to end input]: ";

            if(cin.peek() == EOF) {
                cerr << endl << endl << "DETECTED END OF FILE EXITING PROGRAM" << endl;
                return 2;
            }

            cin >> coin;
            if(cin) {
                switch(coin) {
                    case 0: 
                        next_coin = false;
                        break;
                    case 5: // Fallthrough
                    case 10: // Fallthrough
                    case 25: // OK
                        balance_USD += coin / 100.0;
                        break;
                    default:
                        invalid_input = true;
                }
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                invalid_input = true;
            }
            if(invalid_input) {
                cout << "Bad input ;(" << endl;
            }
        }

        cout << "Your balance is $" << balance_USD << endl;

        // Get choice and count
        bool next_option = true;
        char option = '\0';
        char lower_option = '\0';
        float option_USD = 0.0;
        while(next_option) {
            cout << "Please pick an option:" << endl;
            cout << "    C/c: Coffee [" << COFFEE_USD << "]" << endl;
            cout << "    T/t: Tea[" << TEA_USD << "]" << endl;
            cout << "    Q/q: Quit" << endl;
            cin >> option;
            lower_option = tolower(option); 

            next_option = false;
            switch(lower_option) {
                case 'c':
                    option_USD = COFFEE_USD;
                    break;
                case 't':
                    option_USD = TEA_USD;
                    break;
                case 'q':
                    option_USD = 0.0;
                    break;
                default:
                    cout << "Invalid Option! Please choose a valid option!" << endl;
                    next_option = true;
            }
        }

        int how_many = 0;
        bool next_how_many = true;
        while(next_how_many) {
            if(lower_option != 'q') {
                cout << "How many would you like?" << endl;
                cin >> how_many;
            }
            if(cin && how_many >= 0) {
                // process sale, check balance, etc...
                next_how_many = false;

                float total_USD = option_USD * how_many;
                cout << "Your total is $" << total_USD << endl;

                float change_USD = balance_USD - total_USD;
                
                if(change_USD >= 0) {
                    cout << "Your change is $" << change_USD << endl;
                    next_main_loop = false;
                } else {
                    cout << "Your balance is $" << balance_USD << endl;
                    cout << "Not enough change!! Please add more coins.";
                }
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }

    cout << "Thank you for using my Vending Machine Program!" << endl;
  return 0;
}

// Function implementations (if any)


// ------------- DESIGN -------------
/* 
Program Name:

Program Description:

Design:
A. INPUT
Define the input variables including name data type. 

B. OUTPUT
Define the output variables including data types. 

C. CALCULATIONS
Describe calculations used by algorithms in step D.  
List all formulas. 
If there are no calculations needed, state there are no calculations.

D. LOGIC and ALGORITHMS
Design the logic of your program using pseudocode or flowcharts. 
Use conditionals, loops, functions or array constructs.
List the steps in transforming inputs into outputs. 
https://github.com/Glen-Sasek-PCC-Instructor/2025-06-22/blob/main/Pseudocode-Reference.txt


SAMPLE RUNS

Welcome to my Coffee/Tea Vending Machine!
Enter coins - 5, 10, or 25 only: 5
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 5
Enter coins - 5, 10, or 25 only: 10
Enter coins - 5, 10, or 25 only: 10
Enter coins - 5, 10, or 25 only: 0
Your balance is $0.80
Please pick an option ($0.25 each):
    C/c: Coffee
    T/t: Tea
    Q/q: Quit
>> k
Invalid Option! Please choose a valid option!
>> 9
Invalid Option! Please choose a valid option!
>> c
How many would you like?
>> f
Invalid Option!
How many would you like?
>> 2
Your total: $0.50
Your balance: $0.30
Thank you for using my Vending Machine Program!
Welcome to my Coffee/Tea Vending Machine!
Enter coins - 5, 10, or 25 only: 5
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 0
Your balance is $0.30
Please pick an option ($0.25 each):
    C/c: Coffee
    T/t: Tea
    Q/q: Quit
>> c
How many would you like?
>> 2
Your total is $0.50
Your balance is $0.30
Not enough change!! Please add more coins.
Enter coins - 5, 10, or 25 only: 5
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 0
Your balance: $0.60
Please pick an option ($0.25 each):
    C/c: Coffee
    T/t: Tea
    Q/q: Quit
>> T
How many would you like?
>> 1
Your total is $0.25
Your balance is $0.35
Thank you for using my Vending Machine Program!



Welcome to my Coffee/Tea Vending Machine!
Enter coins - 5, 10, or 25 only: 5
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 0
Your balance is $0.30
Please pick an option ($0.25 each):
    C/c: Coffee
    T/t: Tea
    Q/q: Quit
>> q
Your total is $0
Your balance is $0.30
Thank you for using my Vending Machine Program!



*/
