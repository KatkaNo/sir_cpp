#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#ifndef CLASS_LIST_H
#define CLASS_LIST_H
namespace name {
    enum class IOErrors {NoInputFile, IncorrectData, NoFileName, NoErrors, IncorrectDataCMD, OutOfRange};

    std::string errors(const IOErrors &err);

    class MOPS {

    private:
        struct Node 
        {
        int value = 0;
        Node* next = nullptr;
        };
        Node *first;

    public:
        ~MOPS();

        MOPS(const std::vector<int> &vec);

        void displays_list() const;

        void add_item(int position, int data);

        void delete_item(int position);

        MOPS(const MOPS &) = delete;

        MOPS &operator=(const MOPS &) = delete;

    };
}

#endif