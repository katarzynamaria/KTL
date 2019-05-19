#include "Node.h"


int Node::setDegree(int n, vector<vector<int>> h)
{
	int m = 0;
	for (int i = 0; i < h.size(); i++)
	{
		int m = h.size() - n;
		while (m > 0)
		{
			for (int j = m; j < n; j++)
			{
				if (h[i][j] == value) degree++;
			}
			m--;
		}
	}
	return degree;
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

