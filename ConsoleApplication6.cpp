#include <iostream>
#include <string>
using namespace std;

class Candidate {
private:
    string code;
    string name;
    string dob;
    float mathScore;
    float literatureScore;
    float englishScore;

public:
    Candidate() {}
    Candidate(string c, string n, string d, float math, float literature, float english) {
        code = c;
        name = n;
        dob = d;
        mathScore = math;
        literatureScore = literature;
        englishScore = english;
    }

    float getTotalScore() {
        return mathScore + literatureScore + englishScore;
    }

    void displayInfo() {
        cout << "Code: " << code << endl;
        cout << "Name: " << name << endl;
        cout << "Date of birth: " << dob << endl;
        cout << "Math score: " << mathScore << endl;
        cout << "Literature score: " << literatureScore << endl;
        cout << "English score: " << englishScore << endl;
        cout << "Total score: " << getTotalScore() << endl;
        cout << endl;
    }
};

class TestCandidate {
private:
    Candidate candidates[100];
    int n;

public:
    void inputCandidates() {
        cout << "Enter the number of candidates: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            string code, name, dob;
            float mathScore, literatureScore, englishScore;

            cout << "Candidate " << i + 1 << ":" << endl;
            cout << "Enter code: ";
            cin >> code;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter date of birth: ";
            cin >> dob;
            cout << "Enter math score: ";
            cin >> mathScore;
            cout << "Enter literature score: ";
            cin >> literatureScore;
            cout << "Enter english score: ";
            cin >> englishScore;

            Candidate c(code, name, dob, mathScore, literatureScore, englishScore);
            candidates[i] = c;
        }
    }

    void displayCandidates() {
        cout << "List of candidates with total score > 15:" << endl;

        for (int i = 0; i < n; i++) {
            Candidate c = candidates[i];
            if (c.getTotalScore() > 15) {
                c.displayInfo();
            }
        }
    }
};

int main() {
    TestCandidate test;
    test.inputCandidates();
    test.displayCandidates();

    return 0;
}
