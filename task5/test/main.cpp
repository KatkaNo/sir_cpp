#include "list_class.h"
#include <iostream>
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

        std::vector<int> vector;
        int vec;
        while (datafile >> vec) {
            vector.push_back(vec);
        }
        datafile.close();

        MOPS what(vector);
        cout << "Cписок из std::vector: ";
        what.displays_list();
        int position;
        cout << "Введите положение узла, который нужно удалить: ";
        cin >> position;
        position = position - 1;
        if (position < 0)
            cout << "Ошибка, такой позиции быть не может!" << endl;
        else{
            what.delete_item(position);
            cout << "После удаления элемента на позиции #" << position + 1 << ":" << " ";
            what.displays_list();
        }

        int num;
        cout << "Введите значение для вставки: ";
        cin >> num;
        cout << "Введите позицию для вставки после: ";
        cin >> position;
        position = position + 1;

        what.add_item(position, num);
        what.displays_list();

        cout << "После удаления: ";
        what.~MOPS();
        what.displays_list();

    }
    catch(const name::IOErrors& err)
    {
        cerr << errors(err) << endl;
        return -1;
    }
    return 0;
}

