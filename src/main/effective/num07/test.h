//
// Created by 娄宇庭 on 2018/11/6.
//

#ifndef DEMO_TEST_H
#define DEMO_TEST_H

#include <iostream>

using namespace std;

class TimeKeeper {
public:
    TimeKeeper(){
        cout<< "TimeKeeper constructor"<<endl;
    }
    virtual ~TimeKeeper(){
        cout<< "TimeKeeper destructor"<<endl;
    }

public:
    virtual TimeKeeper* getTimeKeeper() {};
};


class WaterClock: public TimeKeeper{
public:
    WaterClock(){
        cout<< "WaterClock constructor"<<endl;
    }
    virtual ~WaterClock(){
        cout<< "WaterClock destructor"<<endl;
    }

    TimeKeeper* getTimeKeeper(){
        return new WaterClock;
    }
};

class AtomicClock: public TimeKeeper{
public:
    TimeKeeper* getTimeKeeper() const {
        return new AtomicClock;
    }
};

class WristWatch: public TimeKeeper{
public:
    TimeKeeper* getTimeKeeper() const{
        return new WristWatch;
    }
};

#endif //DEMO_TEST_H
