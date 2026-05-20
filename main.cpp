#include <iostream>
using namespace std;

// COMSC-210 | Final 2 | Ian Kusmiantoro

const int NAMES_LEN = 15;
const int DRINKS_LEN = 10;

// LLM Generated data for names array and drinks array.
const string NAMES[NAMES_LEN] = {
    "Alice", "Bob", "Charlie", "Diana", "Ethan", 
    "Fiona", "George", "Hannah", "Ian", "Julia", 
    "Kevin", "Liam", "Mia", "Noah", "Timothy"
};

const string DRINKS[DRINKS_LEN] = {
    "Espresso", "Latte", "Cappuccino", "Americano", "Mocha",
    "Macchiato", "Flat White", "Iced Coffee", "Cold Brew", "Matcha Latte"
};

struct CustomerNode {
    string name;
    string order;
    CustomerNode* next;
};

int main() {

    // Milestone 1
    CustomerNode* head = nullptr;
    CustomerNode* tail = nullptr;

    return 0;
}