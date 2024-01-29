#include "list.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

using namespace name;

int main(int argc, char **argv)
{
    try {
        if (argc < 2) {
            throw IOErrors::NoFileName;
        }
        std::ifstream datafile(argv[1]);
        if (!datafile) {
            cout << "Ошибка при открытии файла" << endl;
            return 1;
        }
        List list;

        std::vector<int> vector;
        int vec;
        while (datafile >> vec) {
            vector.push_back(vec);
        }
        datafile.close();

        Node *first = nullptr;
        make_list(vector, list);
        cout << "Cписок из std::vector: ";

        displays_list(list);

        int position;
        cout << "Положение узла для удаления: ";
        cin >> position;
        position = position - 1;
        if (position < 0)
            cout << "Некорректн. позиция" << endl;
        else{
            delete_item(position, list);
            cout << "Удаление на позиции " << position + 1 << ":" << " ";
            displays_list(list);
        }

        int value;
        cout << "Номер для элемента: ";
        cin >> value;
        cout << "Номер для элемента после: ";
        cin >> position;
        position = position + 1;

        add_item(value, position, list);
        displays_list(list);

        cout << "После удаления: ";
        cleaning(list);
        displays_list(list);

    }
    catch(const name::IOErrors& err)
    {
        std::cerr << errors(err) << std::endl;
        return -1;
    }
    return 0;
}
