//
// Created by Yuting Lou on 2019-04-29.
//

#ifndef CPP_STUDY_UTIL_H
#define CPP_STUDY_UTIL_H

#include <iostream>
#include <chrono>
#include <time.h>
using namespace std;
using namespace std::chrono;

/**
 * 获取时间戳，微秒 us
 * @return
 */
long long get_timestamp_micros() {
    system_clock::time_point start = system_clock::now();
//    time_t start_t = system_clock::to_time_t(start);
//    cout << start_t << endl;
    long long time = duration_cast<microseconds>(start.time_since_epoch()).count();
    return time;
}

#endif //CPP_STUDY_UTIL_H
