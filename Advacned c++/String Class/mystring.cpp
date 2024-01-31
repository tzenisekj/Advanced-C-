#include "mystring.h"
#include <string>
#include <iostream>

namespace main_savitch_4 {
    // constructors and deconstructor
    mystring::mystring(const char str[] = "") {
        current_length = 0;
        allocated = 1; 
        sequence = new char[allocated]; 
    }

    mystring::mystring(const mystring& source) {
        while (length() + source.length() > allocated + 1) { reserve(allocated + 1); }
        while (length() + source.length() < allocated + 1) { reserve(allocated - 1);  }
        for (unsigned int i = 0; i < source.length(); ++i) {
            sequence[current_length] = source[i];
            ++current_length;
        }      
    }

    mystring::~mystring() {
        delete[] sequence; 
    }

    // MODIFICATION MEMBER FUNCTIONS
    void mystring::reserve(size_t n) {
        char* new_arr = new char[n]; 
        for (unsigned int i = 0; i < length(); ++i) {
            new_arr[i] = sequence[i]; 
        }
        delete[] sequence; 
        sequence = new_arr; 
        allocated = n;  
    }

    void mystring::operator+=(const mystring& addend) {
        while (length() + addend.length() > allocated + 1) { reserve(allocated + 1); }
        while (length() + addend.length() < allocated + 1) { reserve(allocated - 1); }
        for (unsigned int i = 0; i < addend.length(); ++i) {
            sequence[current_length] = addend[i];
            ++current_length; 
        }
    }

    void mystring::operator +=(const char addend[]) {

    }

    void mystring::operator +=(char addend) {
        while (length() + 1 > allocated + 1) { reserve(allocated + 1); }
        while (length() + 1 < allocated + 1) { reserve(allocated - 1); }
        sequence[current_length] = addend; 
        ++current_length; 
    }

    void mystring::operator =(const mystring& source) {
        while (source.length() > allocated + 1) { reserve(allocated + 1); }
        while (source.length() < allocated + 1) { reserve(allocated - 1); }
        sequence = source.sequence; 
        current_length = source.current_length; 
    }

    // CONSTANT MEMBER FUNCTIONS
    char mystring::operator [ ](size_t position) const {
        if (position > length()) return; 
        else {
            return sequence[position];
        }
    }

    // FRIEND FUNCTIONS
    std::ostream& operator <<(std::ostream& outs, const mystring& source) {
        for (unsigned int i = 0; i < source.length(); ++i) {
            outs << source.sequence[i]; 
        }
        return outs; 
    }

    bool operator ==(const mystring& s1, const mystring& s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        size_t counter = 0; 
        for (unsigned int i = 0; i < s1.length(); ++i) { 
            if (s1.sequence[i] == s2.sequence[i]) {
                counter++; 
            }
        }
        if (counter == s1.length()) {
            return true; 
        }
        else {
            return false; 
        }
    }

    bool operator !=(const mystring& s1, const mystring& s2) {
        if (s1.length() == s2.length()) {
            int counter; 
            for (unsigned int i = 0; i < s1.length(); ++i) {
                if (s1.sequence[i] == s2.sequence[i]) {
                    ++counter;
                }
            }
            if (counter == s1.length()) {
                return false;
            }
            else {
                return true;
            }
        }
        else {
            return true;
        }
    }

    bool operator >=(const mystring& s1, const mystring& s2) {
        if (s1 == s2) {
            return true;
        }
        size_t size; 
        if (s1.allocated > s2.allocated)
            size = s1.allocated;
        else
            size = s2.allocated; 
        for (unsigned int i = 0; i < size; ++i) {
            if (s1.sequence[i] > s2.sequence[i]) {
                return true;
                break; 
            }
            else if(s1.sequence[i] < s2.sequence[i]) {
                return false;
                break;
            }
        }
    }

    bool operator <=(const mystring& s1, const mystring& s2) {
        if (s1 == s2) {
            return true;
        }
        size_t size;
        if (s1.allocated > s2.allocated)
            size = s1.allocated;
        else
            size = s2.allocated;
        for (unsigned int i = 0; i < size; ++i) {
            if (s1.sequence[i] > s2.sequence[i]) {
                return false;
                break;
            }
            else if (s1.sequence[i] < s2.sequence[i]) {
                return true;
                break;
            }
        }
    }

    bool operator > (const mystring& s1, const mystring& s2) {
        if (s1 == s2) { return false; }
        size_t size;
        if (s1.allocated > s2.allocated)
            size = s1.allocated;
        else
            size = s2.allocated;
        for (unsigned int i = 0; i < size; ++i) {
            if (s1.sequence[i] > s2.sequence[i]) {
                return true;
            }
            else if (s1.sequence[i] < s2.sequence[i]) {
                return false;
            }
        }
    }

    bool operator < (const mystring& s1, const mystring& s2) {
        if (s1 == s2) { return false; }
        size_t size;
        if (s1.allocated > s2.allocated)
            size = s1.allocated;
        else
            size = s2.allocated;
        for (unsigned int i = 0; i < size; ++i) {
            if (s1.sequence[i] > s2.sequence[i]) {
                return false;
            }
            else if (s1.sequence[i] < s2.sequence[i]) {
                return true;
            }
        }
    }

    mystring operator +(const mystring& s1, const mystring& s2) {
        mystring s3;
        s3 += s1;
        s3 += s2; 
        return s3; 
    }

    std::istream& operator >>(std::istream& ins, mystring& target) {
        ins >> target. 
    }

    std::istream& getline(std::istream& ins, mystring& target);
}

 