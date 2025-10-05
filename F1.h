#ifndef F1_h
#define F1_h

#include <string>
using namespace std;

struct Task {
    string name;
    string assignee;
    string status;
    int priority;
};

void addTask();
void showAllTasks();

#endif
