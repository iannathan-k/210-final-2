#include <iostream>
#include <random>
using namespace std;

const int NAMES_LEN = 15;
const int DRINKS_LEN = 10;
const int INITIAL_QUEUE = 3;
const int ROUNDS = 10;
const int MIN_PROB = 1;
const int MAX_PROB = 100;

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
            tail->next = temp;
            tail = temp;
        }
    }

    for (int i = 0; i < ROUNDS; i++) {
        if (head != nullptr) {
            CustomerNode* served = head;
            head = head->next;
            delete served;
        }

        int prob = rand() % (MAX_PROB - MIN_PROB + 1) + MIN_PROB;
        if (prob <= 50) {
            // Code comes from above
            CustomerNode* temp = new CustomerNode;
            temp->name = NAMES[rand() % NAMES_LEN];
            temp->order = DRINKS[rand() % DRINKS_LEN];

            if (head == nullptr) {
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }
        }

        CustomerNode* curr = head;
        cout << "Time Step " << i + 1 << endl;
        if (head == nullptr) {
            cout << "Queue is empty!" << endl;
        }
        while (curr != nullptr) {
            cout << curr->name << " wants a " << curr->order << endl;
            curr = curr->next;
        }
        cout << endl;
    }

    return 0;
}