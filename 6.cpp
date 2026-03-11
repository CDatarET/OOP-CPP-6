#include <iostream>
#include <fstream>
using namespace std;

class Student{
    private:
        int prn;
        string name;
        char panel;

    public:
        Student() {}

        Student(int prn, string name, char panel){
            this->prn = prn;
            this->name = name;
            this->panel = panel;
        }

        void disp(){
            cout << "PRN: " << prn << endl;
            cout << "Name: " << name << endl;
            cout << "Panel: " << panel << endl << endl;
        }

        void write(ofstream &file2){
            file2 << prn << " " << name << " " << panel << endl;
        }
};

int main(){

    Student s[10];
    int c = 0;

    ifstream file1("file1.txt");

    int prn;
    string name;
    char panel;
    while(file1 >> prn >> name >> panel){
        s[c++] = Student(prn, name, panel);
    }
    file1.close();

    cout << "Data Recorded\n\n";

    for(int i = 0; i < c; i++){
        s[i].disp();
    }

    return 0;
}