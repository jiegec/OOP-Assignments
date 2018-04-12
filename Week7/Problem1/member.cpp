#include "member.h"
#include <stdio.h>

Member::Member(const char *name, int age) : name(name), age(age) {
}

Member::Member() : name("???"), age(0) {
}

void Member::printInfo() const {
    printf("Name: %s, Age: %d\n", name.c_str(), age);
}
