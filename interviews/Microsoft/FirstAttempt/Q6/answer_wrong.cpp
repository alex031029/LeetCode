// implement a lock

class Lock
{

	string state;
	// int readers = 0;
	set<thread::pid> readers;
	thread::pid writer;
	public:
	bool readLock()
	{
		sleep();
		if(state=="UNLOCKED"||state=="READLOCKED")
		{
			state = "READLOCKED";
			readers++;
			return true;
		}
		return 
			false;

	}
	bool writeLock()
	{
		if(state=="UNLOCKED")
		{
			state = "WRITELOCKED";
			return true;
		}
		return false;
	}
	string whatState()
	{
		return state;
	}
	bool readUnlock()
	{
		if(state=="WRITELOCKED")
			return false;
		if(readers==0)
			return true;
		if(--readers==0)
		{
			state = "UNLOCKED";
		}
		return true;
	}
	bool writeUnlock()
	{
		// if(reader>0)
		// 	state = "READLOCKED";
		// else
		state = "UNLOCKED";
		return true;
	}
}

guard_lock<mutex> 
unique_lock<mutex>
