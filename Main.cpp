#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <cctype> // Для функции isalpha

using namespace std;

class Curriculum {
private:
    string code;
    string name;
    string responsible;
    int targetCredits;
    string degree;
    int numDisciplines;
    int totalCredits;
    string state;

public:
    // Конструктор по умолчанию
    Curriculum() : code(""), name(""), responsible(""), targetCredits(0), degree(""), numDisciplines(0), totalCredits(0), state("editable") {}

    // Конструктор с параметрами (для инициализации основных свойств)
    Curriculum(string code, string name, string responsible, int targetCredits, string degree)
        : code(code), name(name), responsible(responsible), targetCredits(targetCredits), degree(degree), numDisciplines(0), totalCredits(0), state("editable") {}

    // Конструктор копирования
    Curriculum(const Curriculum& other)
        : code(other.code), name(other.name), responsible(other.responsible), targetCredits(other.targetCredits),
        degree(other.degree), numDisciplines(other.numDisciplines), totalCredits(other.totalCredits), state(other.state) {}

    // Деструктор (необязателен, так как деструктор по умолчанию работает корректно)
    ~Curriculum() {}

    // Методы доступа к свойствам (геттеры и сеттеры)
    void setCode(string code) { this->code = code; }
    string getCode() { return code; }

    void setName(string name) { this->name = name; }
    string getName() { return name; }

    void setResponsible(string responsible) { this->responsible = responsible; }
    string getResponsible() { return responsible; }

    void setTargetCredits(int targetCredits) { this->targetCredits = targetCredits; }
    int getTargetCredits() { return targetCredits; }

    void setDegree(string degree) { this->degree = degree; }
    string getDegree() { return degree; }

    void setNumDisciplines(int numDisciplines) { this->numDisciplines = numDisciplines; }
    int getNumDisciplines() { return numDisciplines; }

    void setTotalCredits(int totalCredits) { this->totalCredits = totalCredits; }
    int getTotalCredits() { return totalCredits; }

    string getState() { return state; }

    // Метод для активации учебного плана
    void activatePlan() {
        if (totalCredits == targetCredits && !code.empty() && !name.empty() && !responsible.empty() && !degree.empty()) {
            state = "activated";
            cout << "Curriculum " << name << " activated." << endl;
        }
        else {
            cout << "Error: Curriculum cannot be activated. Please check the data." << endl;
        }
    }

    // Метод для ввода данных о учебном плане
    void inputData() {
        // Ввод кода учебного плана (до 10 цифр)
        do {
            cout << "Enter curriculum code (up to 10 digits): ";
            getline(cin, code);
            if (!all_of(code.begin(), code.end(), ::isdigit) || code.empty() || code.length() > 10) {
                cout << "Error: Code must contain only digits, be non-empty and not exceed 10 characters." << endl;
            }
        } while (!all_of(code.begin(), code.end(), ::isdigit) || code.empty() || code.length() > 10);

        // Ввод названия учебного плана (до 50 букв)
        do {
            cout << "Enter curriculum name (up to 50 letters): ";
            getline(cin, name);
            if (!all_of(name.begin(), name.end(), ::isalpha) || name.empty() || name.length() > 50) {
                cout << "Error: Name must contain only letters, be non-empty and not exceed 50 characters." << endl;
            }
        } while (!all_of(name.begin(), name.end(), ::isalpha) || name.empty() || name.length() > 50);

        // Ввод ФИО ответственного лица (до 100 букв и пробелов)
        bool isValidFullName = false;
        do {
            cout << "Enter responsible person's full name (up to 100 letters and spaces): ";
            getline(cin, responsible);

            // Проверка на пустоту
            if (responsible.empty()) {
                cout << "Error: Full name cannot be empty." << endl;
                continue;
            }

            // Проверка на длину
            if (responsible.length() > 100) {
                cout << "Error: Full name must not exceed 100 characters." << endl;
                continue;
            }

            // Проверка на наличие букв и пробелов
            bool hasNonAlphaSpace = false;
            for (char c : responsible) {
                if (!isalpha(c) && !isspace(c)) {
                    hasNonAlphaSpace = true;
                    break;
                }
            }
            if (hasNonAlphaSpace) {
                cout << "Error: Full name must contain only letters and spaces." << endl;
                continue;
            }

            // Проверка на количество пробелов (для ФИО)
            int countSpaces = std::count(responsible.begin(), responsible.end(), ' ');
            if (countSpaces != 2) {
                cout << "Error: Please enter the full name in the format 'FIO'." << endl;
                continue;
            }

            // Если все проверки пройдены, устанавливаем isValidFullName в true
            isValidFullName = true;

        } while (!isValidFullName);

        // Ввод целевого количества кредитов (от 1 до 150)
        do {
            cout << "Enter target number of credits (between 1 and 150): ";
            while (!(cin >> targetCredits)) {
                cout << "Error: Enter an integer number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (targetCredits <= 0 || targetCredits > 150) {
                cout << "Error: Target number of credits must be between 1 and 150." << endl;
            }
        } while (targetCredits <= 0 || targetCredits > 150);

        // Ввод уровня образования
        while (true) {
            cout << "Enter degree level (bachelor, master, postgraduate): ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, degree);

            transform(degree.begin(), degree.end(), degree.begin(), ::tolower);

            if (degree == "bachelor" || degree == "master" || degree == "postgraduate") {
                break;
            }
            cout << "Invalid degree level. Please enter 'bachelor', 'master', or 'postgraduate'." << endl;
        }

        // Ввод количества дисциплин (от 1 до 50)
        do {
            cout << "Enter number of disciplines (between 1 and 50): ";
            while (!(cin >> numDisciplines)) {
                cout << "Error: Enter an integer number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (numDisciplines <= 0 || numDisciplines > 50) {
                cout << "Error: Number of disciplines must be between 1 and 50." << endl;
            }
        } while (numDisciplines <= 0 || numDisciplines > 50);

        // Ввод общего количества кредитов по дисциплинам (от 1 до 200)
        do {
            cout << "Enter total number of credits for disciplines (between 1 and 200): ";
            while (!(cin >> totalCredits)) {
                cout << "Error: Enter an integer number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (totalCredits <= 0 || totalCredits > 200) {
                cout << "Error: Total number of credits must be between 1 and 200." << endl;
            }
        } while (totalCredits <= 0 || totalCredits > 200);
    }
};

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