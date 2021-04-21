#include <iostream>
#include <fstream>
#include <wx/wx.h>

void new_file();
void read_file();

using namespace std;

int main() {
    read_file();
    return 0;
}

void new_file() {
    fstream NEW;
    NEW.open("Untitled.txt", ios::out);
    if(NEW) {
        cout << "Created new file\n";
    }
    else {
        cout << "Failed to write file\n";
    }
    NEW << "Nothing\nAbsolutely nothing";
    NEW.close();
    cout << "File written\n";

}

void read_file() {
    ifstream file("Untitled.txt");
    string contents;
    while(getline(file, contents))
    {
        cout << contents << endl;
    }
    file.close();
}
