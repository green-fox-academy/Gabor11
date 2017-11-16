#include <string>

using namespace std;

#ifndef TASK_H
#define TASK_H



class Task
{
    public:
        Task(int num, int progress, string text, int prio);
        Task(int num, string text);
        virtual ~Task();
        // getters
        int get_num();
        int get_progress();
        string get_text();
        int get_prio();
        // setters
        int set_progress(int progress);
        int set_prio(int prio);

    protected:

    private:
        int num;
        int progress;
        string text;
        int prio;
};

#endif // TASK_H
