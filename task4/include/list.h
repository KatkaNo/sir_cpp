#ifndef LIST_H
#define LIST_H

#include <vector>
#include <string>
#include <sstream>

namespace name{

    enum class IOErrors {NoInputFile, IncorrectData, NoFileName, NoErrors, IncorrectDataCMD, OutOfRange};

    std::string errors(const IOErrors &err);

    struct Node
    {
        int value = 0;
        Node* next = nullptr;
    };

    struct List
    {
        Node* first = nullptr;
    };

    // Создание списка из `std::vector`;
    void make_list(const std::vector<int> &v, List &list);

    // Вывод на экран всех элементов списка;
    void displays_list(const List& list);

    // Добавление элемента с заданным значением в указанную позицию;
    void add_item(int value, int position, List &list);

    // Удаление элемента с заданным номером;
    void delete_item(int position, List &list);

    // Очистка списка.
    void cleaning(List &list);

}

#endif
