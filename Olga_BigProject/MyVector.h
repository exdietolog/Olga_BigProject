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

        std::cout << "������� ������. "
            << "�� ��������� ����� ������� ������ ������" << std::endl;

        do {
            std::getline(std::cin, buffer);
            if (buffer.size() > 0) {
                // ���������� �������� � ����� �������
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
        // ����� ������������ ������� �� �����
        std::cout << "��������� ������:" << std::endl;
        for (int i = 0; i < VectorSize(); i++) {
            std::cout << MyVector[i] << std::endl;
        }
    }

};