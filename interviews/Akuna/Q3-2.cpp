// designa pid manager


class PidManager
{
public: 
    int create(int pid); // return the new pid just been created
    vector<int> kill(int pid); // return all pids been killed
    bool exists(int pid) const;
};


PidManager m;

m.exists(0); // true

int a = m.create(0);
int b = m.create(a);
int c = m.create(a);
int d = m.create(b);

m.exists(c); // true

auto killed = m.kill(a);

// killed == {a, b, c}
// killed == {a,b,c,d}
m.exists(0) // true
// m contains only pid "0" now



class PidManager
{
    unsigned int id = 1;
    map<int, vector<int>> children;
    map<int, int> father;
    queue<int> available;
    public: 
    int create(int pid) // return the new pid just been created
    {
        if(!exists(pid))
          return -1;
        int newId = id;
        if(!available.empty())
        { 
          newId = available.front();
          available.pop();
        }
        else
          id++;


       children[pid].push_back(newId);
       children[newId].push_back(newId);
       father[newId] = pid;
       return newId;
    }
    vector<int> kill(int pid) // return all pids been killed
    {
      if(pid == 0)
             return vector<int>{};
       vector<int> ret;
       avaible.push(pid);
       ret.insert(ret.begin(), children[pid].begin(), children[pid].end());
        for(int i=1;i<children[pid].size();i++)
       {  
          auto temp = kill(children[pid][i]);
          ret.insert(ret.begin(), temp.begin()+1, temp.end());
          available.push(children[pid][i]);
        }
     children.erase(pid);
     for(int i=0;i<children[father[pid]].size();i++)
     {
         if(children[father[pid]][i]==pid)
        {
             children[father[pid]].erarse(children[father[pid]].begin()+i);
    break;
        }
    }
    father.erase(pid);
             return ret;
    }
    bool exists(int pid) const
    {
        return !children[pid].empty();
    }
    pidManager()
    {
       children[0].push_back(0);
    }
};

