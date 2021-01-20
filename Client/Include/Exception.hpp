#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <string>

class Exception : public std::exception
{
public:
    Exception(std::string msg, const char *file, int line);
    virtual ~Exception() = default;
    virtual const char *What() const noexcept;

private:
    std::string msg, file;
    int line;
    mutable std::string whatbuffer;
};

#endif