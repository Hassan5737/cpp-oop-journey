#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// =========================
// Write to File (Text)
// =========================
void writeToFile(const string& filename)
{
    ofstream outFile(filename);

    if (!outFile)
    {
        cout << "Error opening file for writing" << endl;
        return;
    }

    outFile << "Hello Hassan" << endl;
    outFile << "Learning File I/O in C++" << endl;
    outFile << 12345 << endl;

    outFile.close();
}

// =========================
// Read from File (Text)
// =========================
void readFromFile(const string& filename)
{
    ifstream inFile(filename);

    if (!inFile)
    {
        cout << "Error opening file for reading" << endl;
        return;
    }

    string line;

    while (getline(inFile, line))
    {
        cout << line << endl;
    }

    inFile.close();
}

// =========================
// Read Word by Word
// =========================
void readWords(const string& filename)
{
    ifstream inFile(filename);

    string word;

    while (inFile >> word)
    {
        cout << word << endl;
    }

    inFile.close();
}

// =========================
// Append to File
// =========================
void appendToFile(const string& filename)
{
    ofstream outFile(filename, ios::app);

    outFile << "Appended Line" << endl;

    outFile.close();
}

// =========================
// fstream Read & Write
// =========================
void readWriteFile(const string& filename)
{
    fstream file(filename, ios::in | ios::out | ios::app);

    if (!file)
    {
        cout << "Error opening file" << endl;
        return;
    }

    file << "New Line from fstream" << endl;

    file.seekg(0);

    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

// =========================
// Binary File Example
// =========================
struct Student
{
    int id;
    char name[50];
};

void writeBinary(const string& filename)
{
    ofstream outFile(filename, ios::binary);

    Student s1 = {1, "Hassan"};
    Student s2 = {2, "Ahmed"};

    outFile.write((char*)&s1, sizeof(s1));
    outFile.write((char*)&s2, sizeof(s2));

    outFile.close();
}

void readBinary(const string& filename)
{
    ifstream inFile(filename, ios::binary);

    Student s;

    while (inFile.read((char*)&s, sizeof(s)))
    {
        cout << "ID: " << s.id << " Name: " << s.name << endl;
    }

    inFile.close();
}


int main()
{
    string textFile = "data.txt";
    string binaryFile = "students.dat";

    cout << "Writing to file..." << endl;
    writeToFile(textFile);

    cout << "\nReading from file..." << endl;
    readFromFile(textFile);

    cout << "\nAppending..." << endl;
    appendToFile(textFile);

    cout << "\nReading after append..." << endl;
    readFromFile(textFile);

    cout << "\nReading word by word..." << endl;
    readWords(textFile);

    cout << "\nUsing fstream..." << endl;
    readWriteFile(textFile);

    cout << "\nWriting binary file..." << endl;
    writeBinary(binaryFile);

    cout << "\nReading binary file..." << endl;
    readBinary(binaryFile);

    return 0;
}