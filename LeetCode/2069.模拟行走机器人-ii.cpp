/*
 * @lc app=leetcode.cn id=2069 lang=cpp
 *
 * [2069] 模拟行走机器人 II
 */

// @lc code=start
class Robot {
private:
    int x, y;
    int width,height;
    string Dir;
public:
    Robot(int w, int h) {
        x = y= 0;
        width = w;
        height = h ;
        Dir = "East";
    }
    
  void step(int num) {
    while (num) {
      if (Dir == "East" && x == width - 1) Dir = "North";
      if (Dir == "North" && y == height - 1) Dir = "West";
      if (Dir == "West" && x == 0) Dir = "South";
      if (Dir == "South" && y == 0) Dir = "East";

      if (Dir == "East") {
        x++;
        num--;
      }
      if (Dir == "North") {
        y++;
        num--;
      }

      if (Dir == "West") {
        x--;
        num--;
      }

      if (Dir == "South") {
        y--;
        num--;
      }
    }
  }
    
    vector<int> getPos() {
        vector<int> temp{x,y};
        return temp;
    }
    
    string getDir() {
        return Dir;
    }   
};


/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
// @lc code=end
