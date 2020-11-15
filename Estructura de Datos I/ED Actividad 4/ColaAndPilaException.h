#pragma once
#include <string>
#include <exception>

class ColaAndPilaExecption : public std::exception {
private:
    std::string msg;
public:
    // constructores
    // ancii
    explicit ColaAndPilaExecption(const char* message) : msg(message) {}
    // c++
    explicit ColaAndPilaExecption(const std::string& message) : msg(message) {}
    // destructor
    virtual ~ColaAndPilaExecption() throw () {}
    // devuelve la cadena
    virtual const char* what() const throw () {
        return msg.c_str();
    }
};