class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    
    queue<pair<int,int>> body;
    set<pair<int,int>> hist;
    int pos = 0;
    int m,n;
    vector<pair<int, int>> food;
    
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        body.push({0,0});
        hist.insert({0,0});
        m = height;
        n = width;
        this->food = food;
        
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
	    int x = body.back().first;
        int y = body.back().second;
        
        //shrink tail
	    pair<int, int> old = body.front(); 
	    hist.erase(old);

	    if (direction == "U")
		    x--;
	    else if (direction == "D")
		    x++;
	    else if (direction == "L")
		    y--;
	    else if (direction == "R")
		    y++;
        
        if (x < 0 || y < 0 || x >= m || y >= n || hist.count({x,y}))
		    return -1;
        
        // move to next
        hist.insert({x,y});
        body.push({x,y});
        
        
	    if (pos < food.size() && x == food[pos].first && y == food[pos].second) {
		    pos++;
		    hist.insert(old);
	    } else {
            body.pop();
        }

	    return body.size() - 1;
        
    }
    

};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */