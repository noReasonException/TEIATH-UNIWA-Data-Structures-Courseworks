//
// Created by stefstef on 20/5/2017.
//

#ifndef INC_2_POPNOTAVAILABLE_H
#define INC_2_POPNOTAVAILABLE_H

#include <exception>
#include <stdexcept>

class PopNotAvailable: public std::out_of_range{
public:
    PopNotAvailable():std::out_of_range("No elements to pop"){}
};
#endif //INC_2_POPNOTAVAILABLE_H
