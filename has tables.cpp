#include <vector>
#include <iostream>
#include <string>

std::vector<std::string>table(1000000);


int hash(int key)
{
    return key % 1000000;
}

void insert(int key) {
    int index = hash(key);

    // Линейное зондирование для поиска пустой ячейки
    while (table[index] != "") {
        index++;
        index %= 1000000;  // Циклическое индексирование
    }

    table[index] = std::to_string(key);
}

void remove(int key) {
    int index = hash(key);

    // Линейное зондирование для поиска элемента
    while (table[index] != std::to_string(key)) {
        index++;
        index %= 1000000;  // Циклическое индексирование
    }

    // Помечаем ячейку как пустую
    table[index] = "";
}

bool search(int key) {
    int index = hash(key);

    // Линейное зондирование для поиска элемента
    while (table[index] != std::to_string(key)) {
        index++;
        index %= 1000000;  // Циклическое индексирование

        if (table[index] == "") {
            return false;
        }
    }

    return true;
}

int main() {
  


    insert(12);
    insert(12);
    insert(12);
    insert(12);
    insert(12);
    std::cout << search(12) << std::endl;  // true
    std::cout << search(98) << std::endl;  //false

    remove(12);
    std::cout << search(12) << std::endl;  // false

    return 0;
}