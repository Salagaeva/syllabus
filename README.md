# Проект "Реализация класса"
### Задача: Реализовать класс, моделирующий заданный тип объектов предметной области.
## Цель
разработать класс Учебный план.
## Задачи
1. Определить структуру данных для хранения информации об учебном плане.
    - Создать класс.
    - Добавить конструкторы.
    - Добавить геттеры и сеттеры для доступа к членам данных.
2. Реализовать функцию ввода данных для учебного плана.
    -  Добавить метод *inputData()* в класс *Curriculum*, который будет запрашивать у пользователя информацию об учебном плане и инициализировать соответствующие члены данных.
    -  Реализовать ввод данных с проверкой на корректность введенных значений.
3. Реализовать активацию учебного плана.
    -  Добавить метод *activatePlan()* в класс *Curriculum*, который будет проверять, можно ли активировать учебный план на основе текущих значений членов данных.
4. Реализовать отображение информации об учебном плане.
    - Добавить метод для отображения информации об учебном плане в классе *Curriculum*.
5. Создать пользовательский интерфейс для работы с учебным планом.
    - В функции *main()* создать объект класса *Curriculum* и реализовать пользовательский интерфейс для работы с ним.
    - добавить меню.
    - Использовать цикл *do-while* для отображения меню и обработки выбранных пользователем вариантов до тех пор, пока пользователь не выберет вариант выхода из программы.

## Выбор области
### Учебный план
Необходимо разработать класс **Учебный план** для автоматизирующей 
разработку учебных планов подсистемы информационной системы 
университета. 

Учебный план **состоит из дисциплин**. За прохождение каждой 
дисциплины даётся некоторое количество зачётных единиц. Сумма зачётных 
единиц за все дисциплины, включенные в учебный план, должна совпадать с 
целевым количеством зачётных единиц учебного плана. Количество 
дисциплин и суммарное количество зачётных единиц за них могут быть 
равны 0 только одновременно. План может быть введён в действие, только 
если сумма зачётных единиц за дисциплины совпадает с целевый 
количеством зачётных единиц, а также все поля заполнены. Введённый в 
действие учебный план нельзя редактировать.

**Поля:** шифр, название, ФИО ответственного за план, целевое количество 
зачётных единиц, ступень высшего образования (бакалавриат, магистратура, 
аспирантура), количество дисциплин, суммарное количество зачётных 
единиц за дисциплины, состояние (редактируется, введён в действие).

**Методы:** конструктор с шифром, названием, ФИО ответственного за план, 
целевым количеством зачётных единиц, ступенью высшего образования; 
установить и вернуть шифр; установить и вернуть название; установить и 
вернуть ФИО ответственного, установить и вернуть целевое количество 
зачётных единиц, установить и вернуть ступень высшего образования, 
установить количество дисциплин и суммарное количество зачётных единиц 
за них, вернуть состояние, ввести план в действие.

## Тестовые данные и ожидаемые результаты 
|Ввод|Ожидаемый результат|Фактический результат|Вывод|
|--------|--------|--------|--------|
|Enter your choice: 1<br>Enter curriculum code: 67890<br>Enter curriculum name: Computer<br>Enter responsible person's full name: Smith John Doe<br>Enter target number of credits (greater than 0): 128<br>Enter degree level (bachelor, master, postgraduate): bachelor<br>Enter number of disciplines: 12<br>Enter total number of credits for disciplines: 128|-|-|После ввода данных, программа не должна выводить никаких сообщений об ошибках.|
|Enter curriculum code: ABCDE| Code must contain only digits and cannot be empty.| Code must contain only digits and cannot be empty.|УСПЕШНО!|
|Enter curriculum name: 34234|Error: Name must contain only letters and cannot be empty.|Error: Name must contain only letters and cannot be empty.|УСПЕШНО!|
|Enter responsible person's full name: 34234|Error: Full name must contain only letters and spaces.|Error: Full name must contain only letters and spaces.|УСПЕШНО!|
|Enter target number of credits (greater than 0): sadad|Error: Enter an integer number:|Error: Enter an integer number:|УСПЕШНО!|
|Enter degree level (bachelor, master, postgraduate): sdaf|Invalid degree level. Please enter 'bachelor', 'master', or 'postgraduate'.|Invalid degree level. Please enter 'bachelor', 'master', or 'postgraduate'.|УСПЕШНО!|
|Enter number of disciplines: sdasd|Error: Enter an integer number:|Error: Enter an integer number:|УСПЕШНО!|
|Enter total number of credits for disciplines: sadasd|Error: Enter an integer number:|Error: Enter an integer number:|УСПЕШНО!|
|Enter your choice: 1<br>Enter curriculum code: 35<br>Enter curriculum name: Info<br>Enter responsible person's full name: Salagaeva Dasha Alex<br>Enter target<br>number of credits (greater than 0): 5<br>Enter degree level (bachelor, master, postgraduate): master<br>Enter number of disciplines: 5<br>Enter total number of credits for disciplines: 5<br>Enter your choice: 2|Curriculum Info activated.|Curriculum Info activated.|УСПЕШНО!|
|Enter your choice: 1<br>Enter curriculum code: 34234<br>Enter curriculum name: Imba<br>Enter responsible person's full name: Das SDs sad<br>Enter target number of credits (greater than 0): 5<br>Enter degree level (bachelor, master, postgraduate): master<br>Enter number of disciplines: 4<br>Enter total number of credits for disciplines: 4<br>Enter your choice: 2|Error: Curriculum cannot be activated. Please check the data.|Error: Curriculum cannot be activated. Please check the data.|УСПЕШНО!|
|Enter your choice: 1<br>Enter curriculum code: 3423<br>Enter curriculum name: dfsfds<br>Enter responsible person's full name: dsfds dfsdfsd dfsdf<br>Enter target number of credits (greater than 0): 4<br>Enter degree level (bachelor, master, postgraduate): master<br>Enter number of disciplines: 4<br>Enter total number of credits for disciplines: 4<br>Enter your choice: 2|Curriculum dfsfds activated.|Curriculum dfsfds activated.|УСПЕШНО!|

## Проектирование свойств класса
