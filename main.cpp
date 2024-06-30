#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <list>


using namespace std;

class TodoItem
{
	private:
		static int id;
		int current_id;
		string description;
		bool completion;
	public:
		//instructor
		TodoItem() : current_id{0},description{""}, completion{false}{}
		
		//Destructor
		~TodoItem() = default;
		
		//getters
		int getId(void){
			return current_id;
			}
		string getDescription(void){return description;};
		bool isCompleted(void){return completion;}
		
		//setters
		void createTask(string new_description)
		{
			id++;
			current_id = id;
			description = new_description;
		}
		
		void setCompleted()
		{
			completion= true;
		}
		
		void setId(int id)
		{
			current_id = id;
		}
		
		void decId(void)
		{
			id--;
		}
};

int TodoItem::id=0;

int main()
{
	char query;
	int task_id;
	string task_description;
	list<TodoItem>Todolist;
	list<TodoItem>::iterator it;
	list<TodoItem>::iterator it2;
	
	Todolist.clear();
	
	while(1)
	{
		system("cls");
		if(Todolist.empty())
		{
			cout<<"Create your TODO list"<<endl;
		}
		else
		{
			/*Do Nothing*/
		}
		
		for(it=Todolist.begin() ; it!=Todolist.end() ; it++)
		{
			cout<<"Task ("<<it->getId()<<"): "<<it->getDescription()<<" | "
			<<(it->isCompleted()? "Done" : "In progress")<<endl;
		}
		
		cout<<"Press [a] to Add a new task"<<endl;
		cout<<"Press [c] to Mark task as completed"<<endl;
		cout<<"Press [d] to Delete task"<<endl;
		cout<<"Press [q] to Close your TODO list"<<endl;
		
		cin>>query;
		
		if(query == 'a')
		{
			TodoItem newItem;
			cout<<"Task Description: ";
			cin.ignore();
			getline(cin, task_description);
			newItem.createTask(task_description);
			Todolist.push_back(newItem);
			cout<<"Task("<<newItem.getId()<<") : "<<newItem.getDescription()<<" added successfully"<<endl;
			
		}
		else if(query == 'c')
		{
			cout<<"Task id: ";
			cin>>task_id;
			for(it=Todolist.begin() ; it!=Todolist.end() ; it++)
			{
				if(it->getId() == task_id)
				{
					it->setCompleted();
					cout<<"Task ("<<it->getId()<<") marked as done"<<endl;
				}
			}
		}
		else if(query == 'd')
		{
			cout<<"Task id: ";
			cin>>task_id;
			for(it=Todolist.begin() ; it!=Todolist.end() ; it++)
			{
				if(it->getId() == task_id)
				{
					cout<<"Task ("<<it->getId()<<") has been deleted"<<endl;
					Todolist.erase(it);
					for(it2=it ; it2!=Todolist.end() ; it2++)
					{
						it2->setId((it2->getId()) - 1);
					}
					it->decId();
					break;
				}
			}
		}
		else if(query == 'q')
		{
			cout<<"Thank you for using TODO list Program"<<endl;
			break;
		}
		// Waiting for 1 second
		this_thread::sleep_for(chrono::seconds(2));
	}
	

	return 0;
}
