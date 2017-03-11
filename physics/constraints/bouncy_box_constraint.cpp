//
// Created by Brennan on 3/7/2017.
//

#include "bouncy_box_constraint.hpp"
#include <string>

std::string BouncyBoxConstraint::TYPE = "bouncy_box_constraint";

BouncyBoxConstraint::BouncyBoxConstraint(double x, double y, double width, double height, double loose) : SingleConstraint() {
    addType(BouncyBoxConstraint::TYPE);
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->loose = loose;
}

BouncyBoxConstraint::BouncyBoxConstraint(int *pos, double width, double height, double loose) : SingleConstraint() {
    addType(BouncyBoxConstraint::TYPE);
    if(pos != nullptr) {
        x = pos[0];
        y = pos[1];
    } else {
        x = 0;
        y = 0;
    }
    this->width = width;
    this->height = height;
    this->loose = loose;
}

void BouncyBoxConstraint::fix(int iter, Particle * p) {
    if((*p)[0] < x) {
        (*p)[0] -= ((*p)[0] - x) * loose;
    } else if((*p)[0] > x + width) {
        (*p)[0] -= ((*p)[0] - (x + width)) * loose;
    }
    if((*p)[1] < y) {
        (*p)[1] -= ((*p)[1] - y) * loose;
    } else if((*p)[1] > y + height) {
        (*p)[1] -= ((*p)[1] - (y + height)) * loose;
    }
}