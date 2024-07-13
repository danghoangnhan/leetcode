#include "bits/stdc++.h"
using namespace std;

struct Robot {
    int position;
    int health;
    char direction;
    int originalOrder;

    Robot(int p, int h, char d,int o) : position(p), health(h), direction(d), originalOrder(o) {}
};

class Solution {
public:
    
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
            int n = positions.size();
            vector<Robot> robots;

            stack<int> leftStack;
            vector<int> result;

            for (int i = 0; i < n; i++) {
                robots.emplace_back(positions[i], healths[i], directions[i],i);
            }

            sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
                return a.position < b.position;
            });
        
            for (int i = 0; i < n; i++) {
                
                if (robots[i].direction == 'R') {
                    leftStack.push(i);
                    continue;
                }

                while (!leftStack.empty() &&  robots[i].health>0) {
                    
                    if (robots[leftStack.top()].health > robots[i].health) {
                        robots[leftStack.top()].health--;
                        robots[i].health = 0;
                    } else if (robots[leftStack.top()].health < robots[i].health) {
                        robots[i].health--;
                        robots[leftStack.top()].health = 0;
                        leftStack.pop();
                    } else {
                        robots[i].health = 0;
                        robots[leftStack.top()].health = 0;
                        leftStack.pop();
                    }
                }
            }

            sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
                return a.originalOrder < b.originalOrder;
            });
            
            for (const auto& robot : robots) {
                    if (robot.health > 0) {
                        result.push_back(robot.health);
                    }
                }
            return result;
    }
};