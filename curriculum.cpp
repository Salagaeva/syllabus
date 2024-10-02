#include "curriculum.h"

Curriculum::Curriculum() : code(""), name(""), responsible(""), targetCredits(0), degree(""), numDisciplines(0), totalCredits(0), state("editable") {}

Curriculum::Curriculum(string code, string name, string responsible, int targetCredits, string degree)
        : code(code), name(name), responsible(responsible), targetCredits(targetCredits), degree(degree), numDisciplines(0), totalCredits(0), state("editable") {}

Curriculum::Curriculum(const Curriculum& other)
        : code(other.code), name(other.name), responsible(other.responsible), targetCredits(other.targetCredits),
        degree(other.degree), numDisciplines(other.numDisciplines), totalCredits(other.totalCredits), state(other.state) {}

Curriculum::~Curriculum() {}

void Curriculum::setCode(string code) { this->code = code; }
string Curriculum::getCode() { return code; }

void Curriculum::setName(string name) { this->name = name; }
string Curriculum::getName() { return name; }

void Curriculum::setResponsible(string responsible) { this->responsible = responsible; }
string Curriculum::getResponsible() { return responsible; }

void Curriculum::setTargetCredits(int targetCredits) { this->targetCredits = targetCredits; }
int Curriculum::getTargetCredits() { return targetCredits; }

void Curriculum::setDegree(string degree) { this->degree = degree; }
string Curriculum::getDegree() { return degree; }

void Curriculum::setNumDisciplines(int numDisciplines) { this->numDisciplines = numDisciplines; }
int Curriculum::getNumDisciplines() { return numDisciplines; }

void Curriculum::setTotalCredits(int totalCredits) { this->totalCredits = totalCredits; }
int Curriculum::getTotalCredits() { return totalCredits; }

string Curriculum::getState() { return state; }

void Curriculum::activatePlan() {
    if (totalCredits == targetCredits && !code.empty() && !name.empty() && !responsible.empty() && !degree.empty()) {
        state = "activated";
        cout << "Curriculum " << name << " activated." << endl;
    }
    else {
        cout << "Error: Curriculum cannot be activated. Please check the data." << endl;
    }
}

void Curriculum::inputData() {
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