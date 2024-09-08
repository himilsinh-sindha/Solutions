class Solution {
public:
    // Function to simulate the robot's movement based on the given commands and obstacles
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Robot's current position (start at origin)
        int endX = 0;
        int endY = 0;

        // Initial direction (facing north, i.e., up the y-axis)
        int dirX = 0;
        int dirY = 1;

        // Variable to store the maximum Euclidean distance squared
        int maxDist = 0;

        // Use an unordered_map to store obstacles for quick lookup
        // Each key is the x-coordinate, and the value is a set of y-coordinates where obstacles exist
        unordered_map<int, unordered_set<int>> m;
        for (auto i : obstacles) {
            m[i[0]].insert(i[1]);  // Store each obstacle's position
        }

        // Iterate over each command in the commands array
        for (auto i : commands) {
            if (i > 0) {
                // For a positive command (i > 0), move forward in the current direction
                if (dirX == 0 && dirY == 1) {  // Moving north (up the y-axis)
                    for (int j = 1; j <= i; j++) {
                        endY++;  // Move the robot up by one unit
                        // If the new position is an obstacle, revert the move and stop
                        if (m.find(endX) != m.end() && m[endX].find(endY) != m[endX].end()) {
                            endY--;  // Step back to avoid the obstacle
                            break;
                        }
                    }
                } else if (dirX == 1 && dirY == 0) {  // Moving east (right on the x-axis)
                    for (int j = 1; j <= i; j++) {
                        endX++;  // Move the robot right by one unit
                        if (m.find(endX) != m.end() && m[endX].find(endY) != m[endX].end()) {
                            endX--;  // Step back to avoid the obstacle
                            break;
                        }
                    }
                } else if (dirX == -1 && dirY == 0) {  // Moving west (left on the x-axis)
                    for (int j = 1; j <= i; j++) {
                        endX--;  // Move the robot left by one unit
                        if (m.find(endX) != m.end() && m[endX].find(endY) != m[endX].end()) {
                            endX++;  // Step back to avoid the obstacle
                            break;
                        }
                    }
                } else if (dirX == 0 && dirY == -1) {  // Moving south (down the y-axis)
                    for (int j = 1; j <= i; j++) {
                        endY--;  // Move the robot down by one unit
                        if (m.find(endX) != m.end() && m[endX].find(endY) != m[endX].end()) {
                            endY++;  // Step back to avoid the obstacle
                            break;
                        }
                    }
                }

                // Calculate the Euclidean distance squared from the origin
                int t = endX * endX + endY * endY;
                // Update the maximum distance if the current distance is greater
                maxDist = max(t, maxDist);

            } else {
                // For a negative command, change the robot's direction
                // -1: Turn 90 degrees to the right
                // -2: Turn 90 degrees to the left

                if (dirX == 0 && dirY == 1) {  // Currently facing north
                    if (i == -1) {  // Turn right (east)
                        dirX = 1;
                        dirY = 0;
                    } else if (i == -2) {  // Turn left (west)
                        dirX = -1;
                        dirY = 0;
                    }
                } else if (dirX == 0 && dirY == -1) {  // Currently facing south
                    if (i == -1) {  // Turn right (west)
                        dirX = -1;
                        dirY = 0;
                    } else if (i == -2) {  // Turn left (east)
                        dirX = 1;
                        dirY = 0;
                    }
                } else if (dirX == 1 && dirY == 0) {  // Currently facing east
                    if (i == -1) {  // Turn right (south)
                        dirX = 0;
                        dirY = -1;
                    } else if (i == -2) {  // Turn left (north)
                        dirX = 0;
                        dirY = 1;
                    }
                } else if (dirX == -1 && dirY == 0) {  // Currently facing west
                    if (i == -1) {  // Turn right (north)
                        dirX = 0;
                        dirY = 1;
                    } else if (i == -2) {  // Turn left (south)
                        dirX = 0;
                        dirY = -1;
                    }
                }
            }
        }

        // Return the maximum distance squared the robot was from the origin
        return maxDist;
    }
};
