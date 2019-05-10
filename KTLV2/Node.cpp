#include "Node.h"


void Node::setDegree(int sequenceLenght, vector<vector<int>>& hypergraph )
{
	//pewnie to zmienie jeszcze
	vector<vector<int>> h = hypergraph;
	int n = sequenceLenght;
	//int m = 0;
	for (int i = 0; i < h.size(); i++)
	{
		int m = h.size() - sequenceLenght;
		while (m > 0)
		{
			for (int j = m; j < n; j++)
			{
				if (h[i][j] == value) degree++;
			}
			m--;
		}
	}
}

void Node::setPotential(int p)
{
	if (potential == 0)
	{
		potential = (double)(degree / pow(2, p));
		return;
	}
	potential = p;
}

