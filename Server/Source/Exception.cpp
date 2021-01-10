#include "Exception.hpp"
#include <iostream>
#include <sstream>

Exception::Exception(std::string msg, const char *file, int line)
    : msg(std::move(msg)), file(file), line(line)
{
}

Exception::~Exception()
{
}

const char *Exception::Exception::what() const noexcept
{
    std::ostringstream os;
    os << "[EXCEPTION] Threw an exception in file " << this->file << " at line " << this->line << '\n';
    os << "[ERROR] Exception caught: " << msg << '\n';
    this->whatbuffer = os.str();
    return whatbuffer.c_str();
}