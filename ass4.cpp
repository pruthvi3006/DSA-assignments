#include <iostream>
using namespace std;

class Text {
public:
    string text;
    Text *next;
    Text *prev;

    Text() {
        text = "";
        next = NULL;
        prev = NULL;
    }

    Text(string s) {
        text = s;
        next = NULL;
        prev = NULL;
    }
};

class Editor {
public:
    Text *head = NULL;

    void insert_start(string s) {
        Text *nn = new Text(s);
        if (head == NULL) {
            head = nn;
            return;
        }
        nn->next = head;
        head->prev = nn;
        head = nn;
    }

    void insert_end(string s) {
        if (head == NULL) {
            insert_start(s);
            return;
        }
        Text *nn = new Text(s);
        Text *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nn;
        nn->prev = temp;
    }

    void insert_between(string s, int pos) {
        if (pos == 0) {
            insert_start(s);
            return;
        }
        Text *nn = new Text(s);
        Text *temp = head;
        int curr_pos = 0;
        while (temp != NULL && curr_pos < pos - 1) {
            temp = temp->next;
            curr_pos++;
        }
        if (temp == NULL || temp->next == NULL) {
            cout << "Position out of bounds." << endl;
            return;
        }
        nn->next = temp->next;
        temp->next->prev = nn;
        temp->next = nn;
        nn->prev = temp;
    }

    void delete_start() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Text *temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
    }

    void delete_end() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Text *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    void delete_between(int pos) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        if (pos == 0) {
            delete_start();
            return;
        }
        Text *temp = head;
        int curr_pos = 0;
        while (temp != NULL && curr_pos < pos - 1) {
            temp = temp->next;
            curr_pos++;
        }
        if (temp == NULL || temp->next == NULL) {
            cout << "Position out of bounds." << endl;
            return;
        }
        Text *to_delete = temp->next;
        temp->next = to_delete->next;
        if (to_delete->next != NULL) {
            to_delete->next->prev = temp;
        }
        delete to_delete;
    }

    void print() {
        Text *temp = head;
        while (temp != NULL) {
            cout << temp->text << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void search(string s) {
        Text *temp = head;
        while (temp != NULL) {
            if (temp->text == s) {
                cout << "Text found: " << temp->text << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Text not found" << endl;
    }
    void reverse(){
        Text*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        while (temp != NULL) {
            cout << temp->text << " -> ";
            temp = temp->prev;
        }
        // temp=head;

    }
};

void drivercode() {
    int choice;
    Editor list;

    do {
        cout << "1. Add text at the head" << endl;
        cout << "2. Add text at the end" << endl;
        cout << "3. Add text in between the linked list" << endl;
        cout << "4. Delete text at head" << endl;
        cout << "5. Delete text in between" << endl;
        cout << "6. Delete text at the end" << endl;
        cout << "7. Search text" << endl;
        cout << "8. Print Editor" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string n;
            cout << "Enter the text you want to insert at the head:" << endl;
            getline(cin, n);
            list.insert_start(n);
            break;
        }
        case 2: {
            string n1;
            cout << "Enter the text you want to enter at the end: ";
            getline(cin, n1);
            list.insert_end(n1);
            break;
        }
        case 3: {
            int pos;
            cout << "Enter the position at which you want to enter the text: ";
            cin >> pos;
            cin.ignore();
            string n2;
            cout << "Enter the text you want to enter: ";
            getline(cin, n2);
            list.insert_between(n2, pos);
            break;
        }
        case 4:
            list.delete_start();
            break;
        case 5: {
            int pos;
            cout << "Enter the position of the text you want to delete: ";
            cin >> pos;
            list.delete_between(pos);
            break;
        }
        case 6:
            list.delete_end();
            break;
        case 7: {
            string s;
            cout << "Enter the name of the text you want to search: ";
            getline(cin, s);
            list.search(s);
            break;
        }
        case 8:
            list.print();
            break;
        case 9:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
    while(choice!=9);
}
int main(){
    drivercode();
}
