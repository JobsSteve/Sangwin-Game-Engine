#ifndef TESTEVENTONE_H
#define	TESTEVENTONE_H

#include "Event.h"
#include <iostream>

using namespace std;

class TestEventOne: public Event {

public:

    int count;
    const char* name;

    TestEventOne(const char* cName)
    :count(0),
     name(cName)
    {}

    void actionPerformed() {

        cout << "Action Performed on TestEventOne: " << name << "\n";
    }
};


#endif	/* TESTEVENTONE_H */

