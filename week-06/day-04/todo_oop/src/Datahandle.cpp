#include "../include/Datahandle.h"
#include <vector>
#include <string.h>



Datahandle::Datahandle()
{
    filename = "todo_log.txt";
    //string file_name = "todo_log.txt";
    //copy(&file_name[0], &file_name[0] + file_name.size(), filename);
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

int Datahandle::write_to_file()
{
    ofstream out_file;
    out_file.open(filename.c_str(), ios::out | ios::trunc);
    for (int i = 0; i < task_list.size(); i++) {
        out_file << task_list[i].get_num() << "\t" << task_list[i].get_progress() << "\t" << task_list[i].get_text() << "\t" << task_list[i].get_prio() << endl;
    }
    out_file.close();

}
int Datahandle::read_from_file()
{
    ifstream in_file;
    char content[500];
    in_file.open(filename.c_str(), ios::in);
    empty_list();
    in_file >> content;
	for( int i = 0 ; i < strlen(content); i ++ ){
		//cout << names[i];
	};
    in_file.close();

}
int Datahandle::empty_list()
{
    task_list.clear();
}
int Datahandle::remove_task()
{

}
int Datahandle::set_progress()
{

}
int Datahandle::add_priority()
{

}
int Datahandle::list_by_priority()
{

}

Datahandle::~Datahandle()
{
    //dtor
}
