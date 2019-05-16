//Programming Assignment 5
//by Ujwal Madhavapeddi

//Graph with a cycle


#include <iostream>
#include <vector>
using namespace std;

void topologicalSort(int vertex, int matrix[10][10], int visited[10], int topoIndex, int level, int levelvector[10]) {
	int i = 0;
	int flag = 0;
	levelvector[level] = vertex;
	//cout << "level: " << level << " " << "levelvector: " << levelvector[level] << endl;
	if (level == 20) {
		cout << "There is a cycle with edges which pass through these vertices: " << endl;
		int k = 19;
		while (levelvector[20] != levelvector[k]) {
			k--;
		}
		while (k < 20) {
			cout << levelvector[k] << "->";
			k++;
		}
		cout << levelvector[20];
	}
	else {
		while (i <= 9 && flag == 0) {
			if (matrix[vertex][i] == 1) {
				int j = 0;
				int count = 0;
				while (j <= 9) {
					if (i != visited[j]) {
						count = count + 1;
					}
					j++;
				}
				if (count == 10) { //i is not visited
					flag = 1;
					topologicalSort(i, matrix, visited, topoIndex, level + 1, levelvector);
				}
			}
			i++;
		}
		if (flag == 0) {
			visited[topoIndex] = vertex;
			//cout << "topoindex: " << topoIndex << " " << "value: " << visited[topoIndex] << endl;
			if (topoIndex != 0) {
				topologicalSort(levelvector[level - 1], matrix, visited, topoIndex - 1, level - 1, levelvector);
			}
			else {
				cout << "Topological order" << endl;
				for (int i = 0; i <= 9; i++) {
					cout << visited[i] << " ";
				}
			}
		}
	}
	return;
}

int main() {
	int matrix[10][10];

	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			matrix[i][j] = 0;
		}
	}

	matrix[0][1] = 1;
	matrix[0][2] = 1;
	matrix[1][3] = 1;
	matrix[1][4] = 1;
	matrix[2][4] = 1;
	matrix[2][5] = 1;
	matrix[3][4] = 1;
	matrix[4][5] = 1;
	matrix[3][6] = 1;
	matrix[6][7] = 1;
	matrix[7][9] = 1;
	matrix[3][8] = 1;
	matrix[8][9] = 1;
	matrix[5][7] = 1;
	matrix[5][9] = 1;
	matrix[9][0] = 1;

	cout << "There are 10 vertices: 0-9" << endl;
	int count = 0;
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			if (matrix[i][j] == 1) {
				count++;
			}
		}
	}

	cout << "There are " << count << " edges" << endl;

	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			if (matrix[i][j] == 1) {
				cout << "Edge from " << i << " to " << j << endl;
			}
		}
	}

	cout << endl;

	//find starting point
	int j = 0;
	count = 1;
	int start;
	while (j <= 9 && count != 0) {
		count = 0;
		for (int i = 0; i <= 9; i++) {
			if (matrix[i][j] == 1) {
				count = count + 1;
			}
		}
		if (count == 0)
		{
			start = j;
		}
		j++;
	}

	int visited[10];
	int levelvector[10];
	for (int i = 0; i <= 9; i++) {
		visited[i] = -1;
		levelvector[i] = -1;
	}

	topologicalSort(start, matrix, visited, 9, 0, levelvector);

	int n;
	cin >> n;
}