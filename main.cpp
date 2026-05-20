#include <iostream>
#include <random>
#include <deque>
#include <vector>
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
        temp->next = nullptr;

        if (head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    deque<string> muffin_booth;
    for (int i = 0; i < INITIAL_QUEUE; i++) {
        string temp = NAMES[rand() % NAMES_LEN];
        muffin_booth.push_back(temp);
    }

    vector<string> bracelet_booth;
    for (int i = 0; i < INITIAL_QUEUE; i++) {
        string temp = NAMES[rand() % NAMES_LEN];
        bracelet_booth.push_back(temp);
    }

    for (int i = 0; i < ROUNDS; i++) {
        cout << "===== Time Step " << i + 1 << "=====" << endl;

        if (head != nullptr) {
            CustomerNode* served = head;
            head = head->next;
            cout << served->name << " was served a " << served->order << endl;
            delete served;
        }

        int prob = rand() % (MAX_PROB - MIN_PROB + 1) + MIN_PROB;
        if (prob <= 50) {
            // Code comes from above
            CustomerNode* temp = new CustomerNode;
            temp->name = NAMES[rand() % NAMES_LEN];
            temp->order = DRINKS[rand() % DRINKS_LEN];
            temp->next = nullptr;

            if (head == nullptr) {
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }

            cout << temp->name << " joined wanting " << temp->order << endl;
        }

        CustomerNode* curr = head;
        
        if (head == nullptr) {
            cout << "Queue is empty!";
        } else {
            cout << "Queue: ";
        }
        while (curr != nullptr) {
            cout << "[" << curr->name << ", " << curr->order << "] ";
            curr = curr->next;
        }
        cout << endl << endl;

        // Milestone 3
        if (muffin_booth.size() > 0) {
            string served = muffin_booth.front();
            muffin_booth.pop_front();

            cout << served << " was served" << endl;
        }

        prob = rand() % (MAX_PROB - MIN_PROB + 1) + MIN_PROB;
        if (prob <= 50) {
            string temp = NAMES[rand() % NAMES_LEN];
            muffin_booth.push_back(temp);

            cout << temp << " joined the deque" << endl;
        }

        if (muffin_booth.size() == 0) {
            cout << "Deque is empty!";
        } else {
            cout << "Deque: ";
        }
        for (string name : muffin_booth) {
            cout << name << " ";
        }
        cout << endl << endl;

        // Milestone 4
        if (bracelet_booth.size() > 0) {
            string served = bracelet_booth.at(0);
            bracelet_booth.erase(bracelet_booth.begin());
            cout << served << " was served" << endl;
        }

        prob = rand() % (MAX_PROB - MIN_PROB + 1) + MIN_PROB;
        if (prob <= 50) {
            string temp = NAMES[rand() % NAMES_LEN];
            bracelet_booth.push_back(temp);

            cout << temp << " joined the vector" << endl;
        }

        if (bracelet_booth.size() == 0) {
            cout << "Vector is empty!";
        } else {
            cout << "Vector: ";
        }
        for (string name : bracelet_booth) {
            cout << name << " ";
        }
        cout << endl << endl;
    }

    return 0;
}