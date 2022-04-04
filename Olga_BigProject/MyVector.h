#include <iostream>
#include <vector>
#include <string>

class VectorClass {

public:
    std::vector<std::string> MyVector;

    VectorClass() {
        CreateVector();
        PrintVector();
    }

    void CreateVector() {


        std::string buffer = "";

        std::cout << "Вводите данные. "
            << "По окончание ввода введите пустую строку" << std::endl;

        do {
            std::getline(std::cin, buffer);
            if (buffer.size() > 0) {
                // Добавление элемента в конец вектора
                MyVector.push_back(buffer);
            }
        } while (buffer != "");


        unsigned int vector_size = MyVector.size();

            

    }

   int VectorSize() {
        unsigned int vector_size = MyVector.size();
        return vector_size;
    }

    void PrintVector() {
        // Вывод заполненного вектора на экран
        std::cout << "Введенные данные:" << std::endl;
        for (int i = 0; i < VectorSize(); i++) {
            std::cout << MyVector[i] << std::endl;
        }
    }

};