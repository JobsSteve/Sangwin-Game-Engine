#ifndef TESTACTIONONE_H
#define	TESTACTIONONE_H

#include "Action.h"
#include "TestEventOne.h"

class TestActionOne: public Action {

public:

    const char* name;
    
    TestActionOne(const char* cName)
    :name(cName)
    {}

    ~TestActionOne() {
        cout << "TestActionOne deleted!" << "\n";
    }

    void perform(SPtr<Queue<SPtr<Event> > > events) {

        for(int i=0; i<events->size(); i++) {

            static_cast<TestEventOne*> (events->peek().get())->count++;
            cout << "Action " << name << " performed its action\n";
        }
    }
};



#endif	/* TESTACTIONONE_H */

