#ifndef CURRICULUM_H
#define CURRICULUM_H

#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <cctype>

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
    Curriculum();

    // Конструктор с параметрами (для инициализации основных свойств)
    Curriculum(string code, string name, string responsible, int targetCredits, string degree);

    // Конструктор копирования
    Curriculum(const Curriculum& other);

    // Деструктор (необязателен, так как деструктор по умолчанию работает корректно)
    ~Curriculum();

    // Методы доступа к свойствам (геттеры и сеттеры)
    void setCode(string code);
    string getCode();

    void setName(string name);
    string getName();

    void setResponsible(string responsible);
    string getResponsible();

    void setTargetCredits(int targetCredits);
    int getTargetCredits();

    void setDegree(string degree);
    string getDegree();

    void setNumDisciplines(int numDisciplines);
    int getNumDisciplines();

    void setTotalCredits(int totalCredits);
    int getTotalCredits();

    string getState();

    // Метод для активации учебного плана
    void activatePlan();

    // Метод для ввода данных о учебном плане
    void inputData();
};

#endif