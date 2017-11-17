#include "Datahandle.h"
#include <vector>

Datahandle::Datahandle()
{
    //ctor
}

int Datahandle::add_to_list(int num, int progress, string text, int prio)
{
    Task task(num, progress, text, prio);
    task_list.push_back(task);
    cout << "new task added" << endl;
    return 0;

}
int Datahandle::add_to_list(int num, string text)
{
    Task task(num, text);
    task_list.push_back(task);
    cout << "new task added" << endl;
    return 0;
}

int Datahandle::print_list()
{
    for (int i = 0; i < task_list.size(); i++) {
        cout << task_list[i].get_num()<< "\t[" << task_list[i].get_progress() << "]\t" << task_list[i].get_text() << "\t" << task_list[i].get_prio() << endl;
    }
    return 0;
}

Datahandle::~Datahandle()
{
    //dtor
}
