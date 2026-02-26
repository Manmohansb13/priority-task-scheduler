#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

#include "ThreadPool.cpp"

int main() {
    ThreadPool pool(3);
    pool.addTask(1,"Critical Backup",[]{
        this_thread::sleep_for(chrono::milliseconds(300));
    });

    pool.addTask(2, "Send Email",[]{
        this_thread::sleep_for(chrono::milliseconds(200));
    });

    pool.addTask(3, "Generate Report",[]{
        this_thread::sleep_for(chrono::milliseconds(250));
    });

    pool.addTask(2, "Process Payment",[]{
        this_thread::sleep_for(chrono::milliseconds(250));
    });

    this_thread::sleep_for(chrono::seconds(2));
    return 0;
}