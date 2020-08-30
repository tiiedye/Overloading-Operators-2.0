#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
    
    cout << boolalpha << endl;
    Mystring a {"jace"};
    Mystring b {"jace"};

    cout << "Should print true: " << (a==b) << endl;
    cout << "Should print false: " << (a!=b) << endl;
    
    b = "george";
    cout << "Should print false: " << (a==b) << endl;
    cout << "Should print true: " << (a!=b) << endl;
	cout << "Should print false: " << (a<b) << endl;
    cout << "Should print true: " << (a>b) << endl;
    
    Mystring s1 {"JACE"};
    s1 = -s1;       
    cout << "Should print jace: " << s1 << endl;              

    s1 = s1 + "*****";
    cout << "Should print jace*****: " << s1 << endl;       
    
    s1 += "-----";
    cout << "Should print jace*****-----: " << s1 << endl;
    
    Mystring s2{"12345"};
    s1 = s2 * 3;
    cout << "Should print 123451234512345: " << s1 << endl;
    
    Mystring s3{"abcdef"};  
    s3 *= 5;
    cout << "Should print abcdefabcdefabcdefabcdefabcdef: " << s3 << endl;
    
    Mystring s = "Jace";
    ++s;
    cout << "Should print JACE: " << s << endl;
    
    s = -s; 
    cout << "Should print jace: " << s << endl;
    
    Mystring result;
    result = ++s;                           
    cout << "Should print JACE: " << s << endl;
    cout << "Should print JACE: " << result << endl;
    
    s = "Jace";
    s++;
    cout << "Should print JACE: " << s << endl;
    
    s = -s;
    cout << "Should print jace: " << s << endl;
    result = s++;
    cout << "Should print JACE: " << s << endl;
    cout << "Should print jace: " << result << endl;
    
    return 0;
}