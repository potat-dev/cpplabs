# SUAI Labs - Tasks

Оригинальный файл с заданиями: [Google Docs](https://docs.google.com/document/d/1xrpJrEPfF8pt5H5FsIfXumKFvwkoEy_wYpgZskR7_lA/)

## Semester 1

> Здесь приведены задания для варианта №7

### Lab 0

**Задание:** Ввести три целых числа. Вычислить и вывести произведение первого и второго числа

**Доп:** Третье число умножить на второе и поделить на первое. Вывести результат как float

### Lab 1

**Задание:** Ввести 10 действительных чисел. Вывести максимальное по абсолютной величине число

**Доп:** Вывести все локальные максимумы введенного массива

### Lab 2

**Задание:** Ввести строку, выяснить, нет ли повторяющихся слов, и вывести их, если они есть. Можно считать, что все слова имеют длину ровно 3 символа

**Доп:** Вывести исходную строку без тех слов, которые встречались больше 1 раза

### Lab 3

> Необходимо написать функцию и тестирующую программу, которая вводит исходные данные, вызывает функцию и выводит результат её работы

**Задание:** Написать функцию, которая вставляет в массив элемент с заданным индексом и заданным значением. Лишний элемент должен пропасть

**Доп:** Написать функцию, которая вставляет в массив 0 после максимального элемента. Размер массива должен увеличиться

### Lab 4

**Задание:** Ввести строку. Вывести различные слова вместе с количеством их появления в строке

**Доп:** Вывести различные слова с сортировкой по алфавиту

### Lab 5

**Задание:** Ввести строку. Заменить знаки препинания на сокращения (пример: тчк, зпт, впр, дтч) (можно использовать английские аналоги)

**Доп:** Обратное задание: сокращения заменить на символы (регистр не учитывать) (можно использовать только английские слова)

### Lab 6

> Во всех заданиях располагать узлы списка/дерева в динамической памяти
> Предусмотреть функции вывода на экран списка/дерева

**Задание:** По символьному файлу составить два линейных списка слов, упорядоченных по алфавиту и по количеству гласных букв. Вывести оба списка

**Доп:** Сделать управление функциями (0 - выход из цикла, 1 - удаление элемента, 2 - вставка элемента, и т.д)

## Semester 2

> В лабораторных работах второго семестра настоятельно рекомендуется использовать функции стандартной библиотеки вместо собственного кода, если это не противоречит заданию
>
> Во всех последующих лабораторных работах необходимо разделять исходный код на 3 файла: в файле **main.cpp** располагается управляющая функция main, в файле **my_lab.cpp** (название может отличаться) ― функции в соответствии с заданием (ввод/вывод исходных данных, основная логика задания и т.п.), а в файле **my_lab.h** ― прототипы функций из my_lab.cpp
>
> Далее приведены задания для варианта №6

### Lab 7

**Задание:** Написать генератор псевдослучайных чисел по алгоритму `f(n) = f(n-1) + f(n-2) + f(n-3) mod 211` (начальные условия: `f(0) = f(1) = f(2) = 1`). Подсчитать частоту каждого числа при выборке 100000

> Линский: рекурсивная реализация неэффективна! Для лабы нужно уменьшить сложность (через глобальные переменные или параметры)

### Lab 8

**Задание:** Сортировка вставками: пусть первые k элементов упорядочены по возрастанию. Берется (k+1)-ый элемент и размещается среди первых k так, чтобы упорядоченными оказались k+1 элементов. Этот метод применяется при k от 1 до n-1

### Lab 9

**Задание:** Ввести n и числа a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub>. Вычислить и вывести коэффициенты многочлена p(x) = (x - a<sub>1</sub>) _(x - a<sub>2</sub>)_ ... \* (x - a<sub>n</sub>) (Для этого написать вспомогательную функцию для умножения двух многочленов)

### Lab 10

> Использовать функции **fopen**, **fclose**, **fgets**

**Задание:** По символьному файлу с текстом создать новый файл с форматированным текстом, в котором в каждой строке первое слово начинается с 3-ей позиции, а последнее заканчивается в 60-ой позиции

### Lab 11

**Задание:** Написать функцию `const char* strpbrk(const char *string, const char *strCharSet)` работающую так же, как библиотечная и тестирующую программу к ней

### Lab 12

> Используйте приватные поля для данных, определите конструктор, который должен содержать значения по умолчанию, напишите методы установки и извлечения значений (set, get), выполнения операций ввода и вывода значения объекта созданного класса. Напишите конструктор копий, оператор присваивания, деструктор. Напишите программу для тестирования вашего класса

**Задание:** Создайте класс `HugeInt`, который хранит в 40-элементном массиве цифр целые числа разрядностью до 40 знаков. Разрядность указать в конструкторе. Предусмотреть функции сложения, вычитания, сравнения и проверки на 0

### Lab 13

> Для всех заданий используйте приватные поля для данных, определите конструктор, который должен содержать значения по умолчанию, напишите функции-элементы установки и извлечения значений, перегруженные операторы ввода и вывода значения объекта созданного класса и указанные в задании перегруженные операции. Напишите конструктор копий, оператор присваивания, деструктор, если требуется. Напишите программу для тестирования вашего класса и всех операций

**Задание:** Создайте класс `Rational` (рациональная дробь) с операциями `+, +=, -, -=, =, ==, !=, >, <, >=, <=, *, *=, /, /=`

### Lab 14

> Номера заданий выдаются индивидуально по запросу  
> Здесь приведено задание для варианта 2

**Задание:** Графический редактор

Программа должна хранить схему в виде заданной в задании структуры данных, где хранятся геометрические фигуры. Каждая фигура характеризуется уникальным идентификатором `(int) id`, координатами на экране `(x, y)`, а также своими параметрами.

Программа должна уметь работать с фигурами, указанными в задании. Каждая фигуру должна уметь выводить на экран свои параметры **в текстовом режиме** с помощью метода print(). Возможно, в будущем будут добавлены новые фигуры.

Класс FigureList должен быть основан на связном списке. Связаный список должен быть реализован с помощью двух классов Node (элемент списка) и List (сам список).

```c++
class FigureList
{
  // добавить фигуру в голову списка
  void addToHead(Shape &shape);

  // найти фигуру всписке по идентификатору
  int findFigure(int id);

  // удалить фигуру из списка
  void erase(int id);

  // вывести на экран в текстовом режиме информацию о всех фигурах в списке
  void printAll();
}
```

Программа должна работать с фигурами:

- Circle (параметры: радиус, надпись произвольной длины)
- Segment (параметры: координаты начала и коодинаты конца)

## Educational Practice

> Требования к заданиям:
>
> - указывать имена файлов исходных и результирующих файлов в командной строке
> - файлы, после обработки заголовков, читать целиком в динамически заказанную память
> - использовать в работе информацию из папки [Форматы](https://drive.google.com/drive/folders/12bxUiI0kUxZr93gR5xvFAoCZyQIY1Lz_?usp=sharing)

### Lab 15

**Задание:** Написать программу, формирующую по исходному BMP файлу новый BMP файл, повернутый по часовой стрелке на 90 градусов

### Lab 16

**Задание:** Написать программу, формирующую по исходному WAV (16 бит на отсчет) файлу новый WAV файл (8 бит на отсчет)

## Semester 3

> Для 17 и 18 лаб приведены задания для варианта №4

### Lab 17

> Шаблоны и исключения
>
> Во всех задачах требуется реализовать конструктор копий и оператор присваивания. Если в задании не оговорено ограничение на максимальный размер, то считается, что контейнер динамически растет
>
> Во всех заданиях стоит избегать избыточного копирования параметров
> В main должно быть продемонстрировано, что шаблонный класс работает:
>
> - для любого примитивного типа
> - для struct `Point { int x; int y; int z; }`

**Задание:** Сделать реализацию матрицы на шаблонах. Методы set, get, sum бросают исключения

**Доп:** Сохранение в файл и загрузка из файла, с исключениями, причем сохранять в json

```c++
Matrix(size_t row, size_t column) // конструктор
set() // устанавливает значение в ячейку
get() // возвращает значение по индексу
rows() // количество строк
сolumns() // количество столбцов
Matrix sum(const Matrix& m) // сумма матриц
```

## Lab 18

**Задание:** Реализовать LFU кэш фиксированного размера (количество записей задается в конструкторе) для адресов (адресом является строка, например, “AFFB”). Согласно алгоритму LFU после исчерпания размера кэша в начале удаляются записи, которые запрашивались реже всего. Удобной реализацией такого кэша является map<адрес, число запросов адреса>. При реализации использовать дополнительный multimap или priority_queue (т.е. всего 2 map) для быстрого поиска адреса, который встречался наименьшее число раз.

```c++
LfuCache(size_t size) // конструктор
bool find_and_add(const std::string &address);
// возвращает true, если адрес найден в кэше
operator<< // для вывода на экран
```

**Доп:** Связный список со всеми словами для перевода, текст переводится с помощью этих слов, причем слово сначала ищем в кеше а потом в списке, если не нашли, то добавляем в кеш, если кеш заполнен, то удаляем из него слово, которое встречалось реже всего

## Lab 19

> Эта лабораторная работа выдается если у ученика недостаточно баллов

## Lab 20

**Задание:** Ориентированный граф задан и хранится матрицей смежности. В файле также задается вершина, с которой начинается обход. Построить дерево обхода с помощью bfs. Определить типы ребер графа и вывести их на экран

**Доп:** Сгенерировать изображение графа с помощью graphviz, раскрасить вершины в зависимости от типа ребер
