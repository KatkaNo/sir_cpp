#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list_class.h>
using namespace std;

namespace name
{
    std::string errors(const IOErrors &err){
        switch (err)
        {
        case IOErrors::NoFileName:
            return "You didn't print any filename";
            break;
        case IOErrors::NoInputFile:
            return "Cannot open input file";
            break;
        case IOErrors::IncorrectData:
            return "Incorrect data in cmd";
            break;
        case IOErrors::IncorrectDataCMD:
            return "Incorrect data in CMD";
            break;
        case IOErrors::NoErrors:
            break;
        case IOErrors::OutOfRange:
            return "List index out of range";
            break;
        default:
            return "Unknown error";
            break;
        }
    }

    MOPS::MOPS(const std::vector<int> &vec){

            first = new Node;
            first -> value = vec[0];
            Node* current = first;
            for(int i = 1; i < vec.size(); i++){
                Node* new_ = new Node;
                new_ -> value = vec[i];
                current -> next = new_;
                current = current -> next;
            }
            current -> next = nullptr;
        }

    void MOPS::displays_list() const {
            Node *current = first;
            while (current) {
                cout << current -> value << " ";
                current = current -> next;
            }
            cout << endl;
        }

    void MOPS::add_item(int value, int position){
            Node* current = first;
            for(int i = 0; i < position; i++){
                if(current -> next == nullptr)
                    break;
                current = current -> next;
            }
            Node* next_ = current->next;
            Node* new_ = new Node;
            new_ -> value = value;
            new_ -> next = next_;
            current -> next = new_;
        }

    void MOPS::delete_item(int position){ 
            Node* current = first;
            int del;
            for(int i = 0; i < position; i++){
                if(current -> next == nullptr)
                    throw IOErrors::OutOfRange;
                current = current -> next;
            }
            Node* del_n = current -> next;
            del = del_n -> value;
            current -> next = del_n -> next;
            delete del_n;
        }

    MOPS::~MOPS(){
        while (first) {
            Node *next = first -> next;
            delete first;
            first = next;
        }
    }

}
