#include <bits/stdc++.h> 
using namespace std; 
#define Size 1000
struct Point 
{ 
	int x; 
	int y; 
}; 
struct queueNode 
{ 
	Point pt; 
	int dist;
}; 
 
bool isValid(int row, int col, int ROW, int COL) 
{ 
	return (row >= 0) && (row < ROW) && 
		(col >= 0) && (col < COL); 
} 

int rowNum[] = {-1, 0, 0, 1}; 
int colNum[] = {0, -1, 1, 0}; 
 
int BFS(int mat[Size][Size], Point src, Point dest, int ROW, int COL) 
{ 
	if (!mat[src.x][src.y] || !mat[dest.x][dest.y]) 
		return -1; 

	bool visited[ROW][COL]; 
	memset(visited, false, sizeof visited); 
	
	visited[src.x][src.y] = true; 

	queue<queueNode> q; 
	
	queueNode s = {src, 0}; 
	q.push(s); 

	while (!q.empty()) 
	{ 
		queueNode curr = q.front(); 
		Point pt = curr.pt; 

		if (pt.x == dest.x && pt.y == dest.y) 
			return curr.dist; 

		q.pop(); 

		for (int i = 0; i < 4; i++) 
		{ 
			int row = pt.x + rowNum[i]; 
			int col = pt.y + colNum[i]; 
			
			if (isValid(row, col,ROW,COL) && mat[row][col] && 
			!visited[row][col]) 
			{ 
				visited[row][col] = true; 
				queueNode Adjcell = { {row, col}, 
									curr.dist + 1 }; 
				q.push(Adjcell); 
			} 
		} 
	} 

	return -1; 
} 

int main() 
{ 
    int maze[Size][Size];
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> maze[i][j];
        }
    }
	int x,y;
	cin >> x >> y;
	Point source = {0, 0}; 
	Point dest = {x, y}; 

	int dist = BFS(maze, source, dest, n, m); 

	if (dist != INT_MAX) 
		cout  << dist ; 
	else
		cout <<-1; 

	return 0; 
} 
