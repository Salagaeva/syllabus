#include <iostream>
#include "curriculum.h"

using namespace std;

int main() {
    Curriculum plan;

    int choice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Enter curriculum data" << endl;
        cout << "2. Activate curriculum" << endl;
        cout << "3. Display curriculum information" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        while (!(cin >> choice)) {
            cout << "Error: Enter an integer number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            plan.inputData();
            break;
        case 2:
            plan.activatePlan();
            break;
        case 3:
            cout << "\nCurriculum Information:\n" << endl;
            cout << "Code: " << plan.getCode() << endl;
            cout << "Name: " << plan.getName() << endl;
            cout << "Responsible: " << plan.getResponsible() << endl;
            cout << "Target number of credits: " << plan.getTargetCredits() << endl;
            cout << "Degree level: " << plan.getDegree() << endl;
            cout << "Number of disciplines: " << plan.getNumDisciplines() << endl;
            cout << "Total number of credits: " << plan.getTotalCredits() << endl;
            cout << "State: " << plan.getState() << endl;
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}