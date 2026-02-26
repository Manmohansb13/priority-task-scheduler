#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>
using namespace std;

#include "Task.cpp"

class ThreadPool {

private:
    vector<thread> workers;
    priority_queue<Task,vector<Task>,greater<Task>> taskQueue;
    mutex mtx;
    bool stop;

    void workerLoop(){
        while(true){
            mtx.lock();
            if(stop && taskQueue.empty()){
                mtx.unlock();
                return;
            }
            if(!taskQueue.empty()){
                Task t=taskQueue.top();
                taskQueue.pop();
                mtx.unlock();
                cout<<"[Running] "<<t.name<<endl;
                t.job();
                cout<<"[Done] "<<t.name<<endl;
            }
            else {
                mtx.unlock();
                this_thread::sleep_for(chrono::milliseconds(10));
            }
        }
    }
public:
    ThreadPool(int n){
        stop=false;
        for(int i=0;i<n;i++){
            workers.push_back(thread(&ThreadPool::workerLoop,this));
        }
    }

    ~ThreadPool() {
        mtx.lock();
        stop=true;
        mtx.unlock();
        for(int i=0;i<workers.size();i++){
            workers[i].join();
        }
    }

    void addTask(int priority,string name,function<void()> job){
        mtx.lock();

        Task t;
        t.priority=priority;
        t.name=name;
        t.job=job;

        taskQueue.push(t);
        mtx.unlock();
        cout<<"[Added] "<<name<<endl;
    }


};