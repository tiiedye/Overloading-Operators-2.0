#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring {
	// Friends :3
	
	friend Mystring operator-(const Mysting &obj);
    friend bool operator==(const Mystring &lhs, const Mystring &rhs) const;
    friend bool operator!=(const Mystring &lhs, const Mystring &rhs) const;
    friend bool operator<(const Mystring &lhs, const Mystring &rhs) const;
    friend bool operator>(const Mystring &lhs, const Mystring &rhs) const;
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs) const;
    friend Mystring operator+=(const Mystring &lhs, const Mystring &rhs);
    friend Mystring operator*(const Mystring &lhs, int n) const;
    friend Mystring operator*=(Mystring &lhs, int n);
    friend Mystring operator++(Mystring &obj);
    friend Mystring operator++(Mystring &obj, int);
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str;  // pointer to a char[] that holds a C-style string
public:
    Mystring(); // No-args constructor
    Mystring(const char *s);    // Overloaded constructor
    Mystring(const Mystring &source);   // Copy constructor
    Mystring(Mystring &&source);   // Move constructor
    ~Mystring();    // Destructor
    
    Mystring &operator=(const Mystring &rhs);   // Copy assignment
    Mystring &operator=(Mystring &&rhs);    // Move assignment
    
    void display() const;
    
    int get_length() const; // getters
    const char *get_str() const;
};

#endif // _MYSTRING_H_