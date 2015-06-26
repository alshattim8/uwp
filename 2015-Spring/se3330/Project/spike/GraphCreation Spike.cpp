string locations[MAX_LOCS];
Node graph[MAX_LOCS];

int findIndex(string location)
{
   for(int i = 0; i < numLocs; i++)
   {
      if(locations[i].compare(location) == 0)
      {
         return i;
      }
   }
   return -1;
}

Node(int adjVertIndex, int fID, decimal duration, tm startDate, tm endDate, Node *next)
{

}

void populateFlightGraph()
{
	decimal duration;
	for(/*All flights using iter*/)
	{
		if(findIndex(iter->getDepLoc) == -1)
		{
			locations[count] = getDepLoc;
			count++;
		}
		Node * ptr = graph[findIndex(iter->getDepLoc)];
		While(ptr->next != null)
		{
			 ptr = ptr->next;
		}
		if(FindIndex(iter.getArrLoc) == -1)
		{
			locations[count] = getArrLoc;
			count++;
		}
		ptr-> next = new Node(FindIndex(iter.getArrLoc), whateverTheIterIsPointingAt, NULL);
	}
}