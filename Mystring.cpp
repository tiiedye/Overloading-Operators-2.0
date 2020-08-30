#include <iostream>
#include <cstring>
#include "Mystring.h"

 // No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

// Your Definitions here!!

// Unary minus, to lower
Mystring operator-(const Mystring &obj) {
    char *buff = new char[std::strlen(obj.str) +1];
    std::strcpy(buff, obj.str);
    for (size_t i=0; i < std::strlen(buff); i++) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

// check if equal
bool operator==(const Mystring &rhs) const {
    if (std::strcmp(str, rhs.str) == 0) {
        return true;
    } else{
        return false;
    }
}

// check for not equal
bool operator!=(const Mystring &rhs) const {
    if (std::strcmp(str, rhs.str) != 0) {
        return true;
    } else {
        return false;
    }
}

// check for less than
bool operator<(const Mystring &rhs) const {
    if (std::strcmp(str, rhs.str) < 0) {
        return true;
    } else {
        return false;
    }
}

// check for greater than
bool operator>(const Mystring &rhs) const {
    if (std::strcmp(str, rhs.str) > 0) {
        return true;
    } else {
        return false;
    }
}

// concatenate
Mystring operator+(const Mystring &rhs) const {
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) +1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

// concatenate and assign
Mystring operator+=(const Mystring &rhs) {
    *this = *this + rhs;
    return *this;
}

// repeat
Mystring operator*(int n) const {
    Mystring temp;
    for (int i = 1; i <= n; i++) {
        temp = temp + *this;
    }
    return temp;
}

// repeat and assign
Mystring operator*=(int n) {
    *this = *this * n;
    return *this;
}

// pre-increment - make the string uppercase
Mystring operator++() {
    for (size_t i=0; i < std::strlen(str); i++) {
        str[i] = std::toupper(str[i]);
    }
    return *this;
}

// post-increment - make string uppercase
Mystring operator++(int) {
    Mystring temp(*this);
    operator++();
    return temp;
}