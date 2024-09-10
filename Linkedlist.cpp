#include <iostream>
#include <string>
using namespace std;

class Song {
public:
    string songs;
    string artist;
    Song *next;

    Song(string d,string a) {
        songs = d;
        artist=a;
        next = NULL;
    }
};

class Playlist {
public:
    Song *head = NULL;

    void insert_start(string d,string a) {
        Song *new_song = new Song(d,a);

        if (head == NULL) {
            head = new_song;
            return;
        } else {
            new_song->next = head;
            head = new_song;
        }
    }

    void insertInBetween(string d,string a, int pos) {
        if (pos == 0) {
            insert_start(d,a);
            return;
        }
        Song *temp = head;
        int curr_pos = 0;
        while (temp != NULL && curr_pos < pos - 1) {
            temp = temp->next;
            curr_pos++;
        }

        if (temp == NULL) {
            cout << "Position out of bounds." << endl;
            return;
        }

        Song *new_song = new Song(d,a);
        new_song->next = temp->next;
        temp->next = new_song;
    }

    void insert_last(string d,string a) {
        Song *new_song = new Song(d,a);
        if (head == NULL) {
            head = new_song;
            return;
        }
        Song *temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = new_song;
        new_song->next = NULL;
    }

    void delete_at_Head() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Song *temp = head;
        head = head->next;
        delete temp;
    }

    void delete_in_between(int pos){
        if(pos==0){
          delete_at_Head();
          return;
        }
        
        Song*temp=head;
        int curr_pos=0;
        while(temp != NULL && curr_pos < pos - 1){
            temp=temp->next;
            curr_pos++;
        }
       Song *to_delete = temp->next; 
       temp->next = temp->next->next; 
       delete to_delete;


    }

    void search(string s) {
        Song *temp = head;
        while (temp != NULL) {
            if (temp->songs == s) {
                cout << "Song is playing: " << temp->songs << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Song not found." << endl;
    }

    void delete_at_end() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Song *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    void print() {
        Song *temp = head;
        while (temp != NULL) {
            cout << temp->songs << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

void drivercode() {
    int choice;
    Playlist list;

    do {
        cout << "1. Add song at the head" << endl;
        cout << "2. Add song at the end" << endl;
        cout << "3. Add song in between the linked list" << endl;
        cout << "4. Delete a song at head" << endl;
        cout << "5.Delete a song in between"<<endl;
        cout << "6. Delete song at the end" << endl;
        cout << "7. Search a song" << endl;
        cout << "8. Print Playlist" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  

        switch (choice) {
            case 1: {
                string n;
                string a;
                cout << "Enter the song you want to insert at the head:"<<endl;
                getline(cin, n);
                cout<<"Enter the name of artist"<<endl;
                getline(cin,a);
                list.insert_start(n,a);
                break;
            }

            case 2: {
                string a;
                string n1;
                cout << "Enter the song you want to enter at the end: ";
                getline(cin, n1);
                cout<<"Enter the artist "<<endl;
                getline(cin,a);
                list.insert_last(n1,a);
                break;
            }

            case 3: {
                int pos;
                cout << "Enter the position at which you want to enter the song: ";
                cin >> pos;
                cin.ignore();  
                string n2;
                string a;
                cout << "Enter the song you want to enter: ";
                getline(cin, n2);
                cout<<"Enter the name of artist";
                list.insertInBetween(n2,a ,pos);
                break;
            }

            case 4:
                list.delete_at_Head();
                break;

            case 5:
            int pos;
               cout<<"Enter the position of song you want to delete"<<endl;
               cin>>pos;
               list.delete_in_between(pos);
               break;

            case 6:
                list.delete_at_end();
                break;

            case 7: {
                string s;
                cout << "Enter the name of the song you want to listen to from the playlist: ";
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
    } while (choice != 9);
}

int main() {
    drivercode();
    return 0;
}


