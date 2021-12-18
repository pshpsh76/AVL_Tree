#include <iostream>
#include "AVLTree.h"

using namespace std;


int main() {
    AVLTree a;
    cout << "INSTRUCTIONS!!!\n"
            "If you want to insert element input '1' then the value you want to add\n"
            "If you want to find out if such an element exists in the set of added elements input '2'"
            "then the key by which the search will take place\n"
            "If you want to know the minimum element input '3'\n"
            "If you want to remove the minimum element input '4'\n"
            "If you want to remove an element by key, input '5', and then the key itself\n"
            "If you want to see the tree input '6'\n"
            "If you want to end the program, input '-1'" << endl;
    while (true) {
        cout << "Input action type:\n";
        int type;
        cin >> type;
        if (type == 1) {
            int n;
            cout << "Input the key you want to add: ";
            cin >> n;
            a.insert(n);
            a.print_tree();
            cout << endl;
        }
        if (type == 2) {
            cout << "Input the key by which the search will take place: ";
            int n;
            cin >> n;
            Node* b = a.search(n);
            if (b == nullptr) {
                cout << "Key not found" << endl;
            } else {
                cout << "Key found!" << endl;
            }
        }
        if (type == 3) {
            Node* b = a.min();
            cout << "Minimum: " << b->getval() << endl;
        }
        if (type == 4) {
            a.remove_min();
            a.print_tree();
            cout << endl;
        }
        if (type == 5) {
            cout << "Input the key to be deleted: ";
            int n;
            cin >> n;
            a.remove(n);
            a.print_tree();
            cout << endl;
        }
        if (type == 6) {
            a.print_tree();
            cout << endl;
        }
        if (type == -1) {
            cout << "Good bye!" << endl;
            return 0;
        }
    }
    return 0;
}
