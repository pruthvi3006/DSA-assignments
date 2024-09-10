#include <iostream>
using namespace std;

class Route {
public:
    string route;
    Route *next;

    Route() {
        route = "";
        next = NULL;
    }

    Route(string s) {
        route = s;
        next = NULL;
    }
};

class Navigator {
public:
    Route *head;

    Navigator() {
        head = NULL;
    }

    void add_route_start(string s) {
        Route *new_route = new Route(s);
        if (head == NULL) {
            head = new_route;
            head->next = head; // Circular link
            return;
        }
        Route *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = new_route;
        new_route->next = head;
        head = new_route;
    }

    void add_route_end(string s) {
        Route *new_route = new Route(s);
        if (head == NULL) {
            head = new_route;
            head->next = head;
            return;
        }
        Route *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = new_route;
        new_route->next = head;
    }

    void add_route_between(string s, int pos) {
        if (pos == 0) {
            add_route_start(s);
            return;
        }
        Route *new_route = new Route(s);
        Route *temp = head;
        int curr_pos = 0;
        while (curr_pos < pos - 1 && temp->next != head) {
            temp = temp->next;
            curr_pos++;
        }
        if (curr_pos != pos - 1) {
            cout << "Position out of range." << endl;
            delete new_route;
            return;
        }
        new_route->next = temp->next;
        temp->next = new_route;
    }

    void delete_route_start() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        Route *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        Route *to_delete = head;
        head = head->next;
        temp->next = head;
        delete to_delete;
    }

    void delete_end() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        Route *temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        Route *to_delete = temp->next;
        temp->next = head;
        delete to_delete;
    }

    void delete_between(int pos) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        if (pos == 0) {
            delete_route_start();
            return;
        }
        Route *temp = head;
        int curr_pos = 0;
        while (curr_pos < pos - 1 && temp->next != head) {
            temp = temp->next;
            curr_pos++;
        }
        if (temp->next == head || curr_pos != pos - 1) {
            cout << "Position out of range." << endl;
            return;
        }
        Route *to_delete = temp->next;
        temp->next = to_delete->next;
        delete to_delete;
    }

    void print() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Route *temp = head;
        do {
            cout << temp->route << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }
};

void drivercode() {
    int choice;
    Navigator list;

    do {
        cout << "\n1. Add route at the start" << endl;
        cout << "2. Add route at the end" << endl;
        cout << "3. Add route in between the linked list" << endl;
        cout << "4. Delete a route at start" << endl;
        cout << "5. Delete a route in between" << endl;
        cout << "6. Delete route at the end" << endl;
        cout << "7. Print Routes" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string n;
            cout << "Enter the route you want to insert at the start: ";
            getline(cin, n);
            list.add_route_start(n);
            break;
        }
        case 2: {
            string n1;
            cout << "Enter the route you want to enter at the end: ";
            getline(cin, n1);
            list.add_route_end(n1);
            break;
        }
        case 3: {
            int pos;
            cout << "Enter the position at which you want to enter the route: ";
            cin >> pos;
            cin.ignore();
            string n2;
            cout << "Enter the route you want to enter: ";
            getline(cin, n2);
            list.add_route_between(n2, pos);
            break;
        }
        case 4:
            list.delete_route_start();
            break;
        case 5: {
            int pos;
            cout << "Enter the position of the route you want to delete: ";
            cin >> pos;
            list.delete_between(pos);
            break;
        }
        case 6:
            list.delete_end();
            break;
        case 7:
            list.print();
            break;
        case 8:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 8);
}

int main() {
    drivercode();
    return 0;
}