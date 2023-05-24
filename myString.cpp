#include "myString.h"

    myString::myString() {
        length = 0;
        data = new char[1];
        data[0] = '\0';
    }

    myString::myString(const char* str) {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }

    myString::myString(const myString& other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    myString::~myString() {
        delete[] data;
    }

    myString& myString::operator=(const myString& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    char& myString::operator[](int index) {
        return data[index];
    }

    const char& myString::operator[](int index) const {
        return data[index];
    }

    int myString::size() const {
        return length;
    }

    bool myString::operator==(const myString& other) const {
        return strcmp(data, other.data) == 0;
    }

    bool myString::operator!=(const myString& other) const {
        return !(*this == other);
    }

    myString myString::operator+(const myString& other) const {
        int newLength = length + other.length;
        char* newData = new char[newLength + 1];
        strcpy(newData, data);
        strcat(newData, other.data);
        myString result(newData);
        delete[] newData;
        return result;
    }

    myString& myString::operator+=(const myString& other) {
        *this = *this + other;
        return *this;
    }

    myString myString::operator+(const char& c) const {
        char str[2] = { c, '\0' };
        myString temp(str);
        myString result(*this);
        result += temp;
        return result;
    }

    std::ostream& operator<<(std::ostream& out, const myString& str) {
        out << str.data;
        return out;
    }

    std::istream& operator>>(std::istream& in, myString& str) {
        const int bufferSize = 1024;
        char buffer[bufferSize];
        in >> std::ws;//white space
        in.getline(buffer, bufferSize, ' ');
        myString temp(buffer);
        str = temp;
        return in;
    }

