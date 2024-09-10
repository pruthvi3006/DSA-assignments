#include <iostream>
using namespace std;
class student
{
public:
    string name;
    string PRN;
    int id;
    void getdata()
    {
        cout << "Enter name of student" << endl;
        cin >> name;
        cout << "Enter PRN" << endl;
        cin >> PRN;
        cout << "Enter id of student" << endl;
        cin >> id;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "PRN: " << PRN << endl;
        cout << "ID: " << id << endl;
    }
};
void sort(student s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i - 1;
        student val = s[i];
        while (j >= 0 && s[j].id > val.id)
        {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = val;
    }
}
void shellsort(student arr[], int n)
{

    int intvl = n / 2;
    for (int gap = intvl; gap >= 1; gap /= 2)
    {
        for (int j = gap; j <= n - 1; j++)
        {
            for (int i = j - gap; i >= 0; i -= gap)
            {
                if (arr[i + gap].id > arr[i].id)
                {
                    break;
                }
                else
                {
                    student temp = arr[i];
                    arr[i] = arr[i + gap];
                    arr[i + gap] = temp;
                }
            }
        }
    }
    
}

void driverCode()
{
    int n;
    cout << "Enter no. of students" << endl;
    cin >> n;
    student s[n];

    int choice;
    do
    {

        cout << "1.Get data" << endl;
        cout << "2.Display data" << endl;
        cout << "3.Sort using insertion sort" << endl;
        cout << "4.Sort using shell sort" << endl;
        cout << "5.Exit" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:

            for (int i = 0; i < n; i++)
            {
                s[i].getdata();
            }
            break;

        case 2:
            for (int i = 0; i < n; i++)
            {
                s[i].display();
            }
            break;

        case 3:
            sort(s, n);
            for(int i=0;i<n;i++){
         s[i].display();
        }
            break;

        case 4:
            shellsort(s, n);
            for(int i=0;i<n;i++){
             s[i].display();
           }
            break;

        case 5:
            break;

        default:
            break;
        }

    } while (choice != 5);
}

int main()
{
    // int n;
    // cout<<"Enter no. of students"<<endl;
    // cin>>n;
    // student s[n];
    // for(int i=0;i<n;i++){
    //     s[i].getdata();
    // }

    // shellsort(s,n);

    // for(int i=0;i<n;i++){
    //     s[i].display();
    // }
    driverCode();
}
