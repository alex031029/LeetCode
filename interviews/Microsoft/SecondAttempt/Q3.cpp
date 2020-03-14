// write a Dijkstra's algorithm


struct Node
{
	// this->edges[i] = x, x is an index of G
	vector<int> edges;
	vector<int> weights;
}

vector<Node*> G;

int Dijkstra(int s, int t)
{
	vector<int> distance(G.size(), INT_MAX);
	distance[s] = 0;
	// comparator for min heap
	auto comparator = [](int x, int y){return distance[x]>distance[y];};

	// a min heap to find the shortest distance among all undetermined nodes from s 
	priority_queue<int, vector<int>, decltype(comparator)> heap(comparator);

	// a flag to check if a node whose shortest distance from s is determined 
	vector<bool> flag(G.size(), false);
	heap.push(s);

	// relax function 
	auto relax = [&](int in, int out)
	{
		if(G[in]->weights[out]+distance[in]<distance[G[in]->edges[out]])
			distance[G[in]->edges[out]] = G[in]->weights[out]+distance[in];
	};

	while(!heap.empty())
	{
		int temp = heap.front();
		flag[temp] = true;
		if(temp == t)
			return distance[t];
		for(int i=0;i<G[temp]->edges.size();i++)
		{
			if(!flag[G[temp]->edges[i]])
			{
				relax(temp, i);
				heap.push(G[temp]->edges[i]);
			}
		}
	}
	return distance[t];
}
