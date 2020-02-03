/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    unordered_map<int, unordered_map<int, int>> data;
    int dx[4]={1, 0, -1, 0};
    int dy[4]={0, 1, 0, -1};
    int dir=0;
    void cleanRoom(Robot& robot) {
        dfs(robot, 0, 0, 0);
    }
    
    void dfs(Robot &robot, int x, int y, int dir) {
        if(data[x][y] == 1) {
            return;
        }
        
        data[x][y] = 1;
        // clean 
        robot.clean();
        // find next
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if(robot.move()) {
                // already move to next
                dfs(robot, nx, ny, dir);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
            
            dir = (dir + 1) % 4;
            robot.turnRight();
        }
    }
};