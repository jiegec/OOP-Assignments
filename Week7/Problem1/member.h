#ifndef __MEMBER_H__
#define __MEMBER_H__

#include <string>

class Member {
    private:
        const std::string name;
        const int age;
    public:
        Member(const char *name, int age);
        Member();

        void printInfo() const;
};

#endif
