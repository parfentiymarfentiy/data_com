#include <iostream>

class MyString {
private:
    char* data;
    size_t length;

public:
    MyString() : data(nullptr), length(0) {}

    MyString(const char* str) {
        if (str) {
            length = 0;
            while (str[length] != '\0') {
                length++;
            }
            
            data = new char[length + 1];
            for (size_t i = 0; i < length; i++) {
                data[i] = str[i];
            }
            data[length] = '\0';
        } else {
            data = nullptr;
            length = 0;
        }
    }

    MyString(const MyString& other) {
        length = other.length;
        if (length > 0) {
            data = new char[length + 1];
            for (size_t i = 0; i < length; i++) {
                data[i] = other.data[i];
            }
            data[length] = '\0';
        } else {
            data = nullptr;
        }
    }
    
    ~MyString() {
        delete[] data;
    }

    size_t size() const {
        return length;
    }

    bool empty() const {
        return length == 0;
    }

    const char* c_str() const {
        return data ? data : "";
    }

    char at(size_t index) const {
        if (index < length) {
            return data[index];
        }
        return '\0';
    }

    void push_back(char c) {
        char* new_data = new char[length + 2];
        
        if (data) {
            for (size_t i = 0; i < length; i++) {
                new_data[i] = data[i];
            }
        }
        
        new_data[length] = c;
        new_data[length + 1] = '\0';
        
        delete[] data;
        data = new_data;
        length++;
    }

    void pop_back() {
        if (length > 0) {
            char* new_data = new char[length];
            
            for (size_t i = 0; i < length - 1; i++) {
                new_data[i] = data[i];
            }
            new_data[length - 1] = '\0';
            
            delete[] data;
            data = new_data;
            length--;
        }
    }


    void clear() {
        delete[] data;
        data = nullptr;
        length = 0;
    }

    void append(const char* str) {
        if (!str) return;
        
        size_t str_len = 0;
        while (str[str_len] != '\0') {
            str_len++;
        }
        
        if (str_len == 0) return;
        
        char* new_data = new char[length + str_len + 1];

        if (data) {
            for (size_t i = 0; i < length; i++) {
                new_data[i] = data[i];
            }
        }

        for (size_t i = 0; i < str_len; i++) {
            new_data[length + i] = str[i];
        }
        
        new_data[length + str_len] = '\0';
        
        delete[] data;
        data = new_data;
        length += str_len;
    }
    
// Дальше без понятия как делать.
