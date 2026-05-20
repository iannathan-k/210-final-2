#include <iostream>
#include <random>
using namespace std;

// COMSC-210 | Final 2 | Ian Kusmiantoro

const int NAMES_LEN = 15;
const int DRINKS_LEN = 10;
const int INITIAL_QUEUE = 3;
const int ROUNDS = 10;
const int MIN_PROB = 1;
const int MAX_PROB = 100;

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

    // Milestone 2
    srand(time(0));
    for (int i = 0; i < INITIAL_QUEUE; i++) {
        CustomerNode* temp = new CustomerNode;
        temp->name = NAMES[rand() % NAMES_LEN];
        temp->order = DRINKS[rand() % DRINKS_LEN];

        if (head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            temp->next = tail;
            tail = temp;
        }
    }

    for (int i = 0; i < ROUNDS; i++) {
        int prob = rand() % (MAX_PROB - MIN_PROB + 1) + MIN_PROB;

        if (head == nullptr) {

        } else {
            
        }
    }

    return 0;
}