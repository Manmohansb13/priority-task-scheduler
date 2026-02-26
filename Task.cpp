#include<string>
#include<functional>
using namespace std;

struct Task {
    int priority;
    string name;
    function<void()> job;
    bool operator>(const Task & other)const{
        return priority>other.priority;
    }
};

