// design a event_timer

event_timer e;
e.add_events(4, [](){ cout << "a" << end;});
e.add_events(1, [](){ cout << "b" << end;});
string info = "hello";
e.add_events(10, [=](){cout << info; })

e.run_events(); // nothing
sleep(3);
e.run_events()b; // print b 

class event_timer
{
	// long long timer;
	priority_queue<pair<long long, void *>> events;
	multiset<>
	// queue<void *> pendings;
	
	void add_event(long long time, void * func)
	{
		events.push(make_pair(time*1000+clock(), func));
	};
	
	void run_even()
	{
	 	long long current_time = clock();
		while(!events.empty())
		{
			if(events.front()->first()<=current_time)
			{
			    void * func(void); 
			    func = events.begin()->second();
			    func();
				// events.begin()->second()();
				events.pop();
			}
			else
				break;
		}
	};
	event_timer()
	{
	 // timer = clock();
	}
}
