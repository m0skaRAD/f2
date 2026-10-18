#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void task1(const string& inFileN, const string& outFileN) {
    ifstream inFile(inFileN);
    ofstream outFile(outFileN);

    int count = 0;
    string line;
    while (getline(inFile, line)) {
        count++;
    }
    inFile.close();
    inFile.open(inFileN);
    string* lines = new string[count];
    for (int i = 0; i < count; i++) {
        getline(inFile, lines[i]);
    }
    for (int i = 0; i < count-1; i++) {
        outFile << lines[i] << "\n";
    }
    inFile.close();
    outFile.close();
    delete[] lines;
}

int task2(const string& inFileN) {
    ifstream inFile(inFileN);
    
    int count = 0;
    string line;
    while (getline(inFile, line)) {
        count++;
    }
    inFile.close();
    inFile.open(inFileN);
    string* lines = new string[count];
    for (int i = 0; i < count; i++) {
        getline(inFile, lines[i]);
    }
    int maxSize = 0;
    inFile.close();
    inFile.open(inFileN);
    for(int i = 0; i < count; i++){
        if (lines[i].length() > maxSize) {
            maxSize = lines[i].length();
        }
    }
    return maxSize;
}

int task3(const string& inFileN, const string str) {
    ifstream inFile(inFileN);

    string word;
    int count = 0;
    while (inFile >> word) {
        if (word == str) {
            count++;
        }
    }
    inFile.close();
    return count;
}

void task4(const string& inFileN, const string& target, const string& changer) {
    ifstream inFile(inFileN);

    string line;
    int count = 0;
    while (getline(inFile, line)) {
        count++;
    }
    inFile.close();
    inFile.open(inFileN);
    string* lines = new string[count];
    for (int i = 0; i < count; i++) {
        getline(inFile, lines[i]);
    }
    inFile.close();
    inFile.open(inFileN);
    for (int i = 0; i < count; i++) {
        size_t pos = lines[i].find(target);
        while (pos != string::npos) {
            lines[i].replace(pos, target.length(), changer);
            pos = lines[i].find(target, pos + changer.length());
        }
    }
    inFile.close();
    ofstream outfile(inFileN);
    for (int i = 0; i < count; i++) {
        outfile << lines[i] << "\n";
    }
    outfile.close();
    delete[] lines;
}

int main()
{
    task1("i1.txt", "o1.txt");
    cout << "Task 2: " << task2("i2.txt") << endl;;
    cout << "Task 3: " << task3("i3.txt", "lorem") << endl;
    task4("i4.txt", "lorem", "FIND");
}
