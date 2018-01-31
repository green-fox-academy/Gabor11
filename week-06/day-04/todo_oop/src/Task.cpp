#include "../include/Task.h"
#define MAX 2147483647

Task::Task(int num, int progress, string text, int prio)
{
    this->num = num;
    this->progress = progress;
    this->text = text;
    this->prio = prio;
    //ctor
}
Task::Task(int num, string text)
{
    this->num = num;
    this->text = text;
    this->progress = 0;
    this->prio = MAX;
}

// Task::getters
int Task::get_num()
{
    return num;
}
int Task::get_progress()
{
    return progress;
}
string Task::get_text()
{
    return text;
}
int Task::get_prio()
{
    return prio;
}
// Task::setters
int Task::set_progress(int progress)
{
    if (progress <= 100, progress >= 0) {
        this->progress = progress;
        return 0;
    } else {
        return 1;
    }
}
int Task::set_prio(int prio)
{
    if (prio > 0) {
        this->prio = prio;
        return 0;
    } else {
        return 1;
    }
}


Task::~Task()
{
    //dtor
}
