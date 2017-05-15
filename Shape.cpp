//
// Created by Dimitar on 6.5.2017 г..
//

#include "Shape.h"

std::ostream &operator<<(std::ostream &os, const Shape &shape) {
    return shape.Print(os);
}

std::ostream &Shape::Print(std::ostream &os)const  {
    return os;
}

Shape::~Shape() {

}


