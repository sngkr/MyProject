#include <iomanip>
#include <iostream>
using namespace std;
/*信息：
 AB_Distance：AB两点距离
 Capacity：邮箱容量
 Oil_Distance_L： 每升汽油可以跑多远
 Num_Of_Station：加油站数量
 Distance_Of_Station[]： 加油站距起始位置距离
 OilPrice_Of_Station[]: 加油站油价
 */
float AB_Distance;
float Capacity;
int Oil_Distance_L;
int Num_Of_Station;
float Distance_Of_Station[200];
float OilPrice_Of_Station[200];

/* 汽车：
Oil：汽车总共加油量
Oil_Now：到达加油站时还剩油量
CanRun_Now：到达加油站还可以跑多远
 */
float Oil;
float Oil_Now;
float CanRun_Now;
/* 结果：
Sum：总花费
*/
float Sum = 0;

/*功能：返回当前加油站以及后面加油站最低油价的那一个
参数：
 x： 加油站号
 flag： 0返回最小 1只要小于成立就返回
*/
int lowest_price(int x, int flag) {
  int lowest = x;
  for (int i = x + 1; i < Num_Of_Station; i++) {
    if (OilPrice_Of_Station[i] < OilPrice_Of_Station[lowest]) {
      lowest = i;
      if (flag == 1) return lowest;
    }
  }
  return lowest;
}

/*功能：解决加油站问题
 */
bool Solution() {
  /* 初始：油0  能跑0 */
  Oil = 0;
  Oil_Now = 0;
  CanRun_Now = Oil_Now * Oil_Distance_L;
  for (int i = 0; i < Num_Of_Station; i++) {
    int lowPrice = lowest_price(i, 0);
    Oil_Now = Oil - Distance_Of_Station[i] / Oil_Distance_L;
    CanRun_Now = Oil_Now * Oil_Distance_L;

    /* 如果当前加油站油价最低 ，这肯定加*/
    if (lowPrice == i) {
      float OilNeed = (Capacity - Oil_Now);
      if (OilNeed > Capacity) return false;
      if ((CanRun_Now + OilNeed * Oil_Distance_L) <
          AB_Distance - Distance_Of_Station[i]) {
        /*加满都不能到终点的话： 加满 */
        Oil += OilNeed;
        Sum += OilNeed * OilPrice_Of_Station[i];
      }
      /*加满可以到终点：加所需量 */
      else {
        float OilNeed = (AB_Distance - CanRun_Now - Distance_Of_Station[i]) /
                        Oil_Distance_L;
        if (OilNeed > Capacity) return false;
        Oil += OilNeed;
        Sum += OilNeed * OilPrice_Of_Station[i];
        return true;
      }
    } else {
      /* 油价不是最低 ，需要判断加还是不加
      最后一个加油站的情况会归为上面情况，
      这种情况后面必有一个加油站比它油价低
      1、不够到比它油价低的加油站
        加
      2、够到比它油价低的加油站
        不加 --> 不管
      */
      /* 找到下一个比它油价低的加油站 */
      int nextLowStation = lowest_price(i, 1);
      /*  */
      float between =
          Distance_Of_Station[nextLowStation] - Distance_Of_Station[i];
      if (CanRun_Now < between) {
        float OilNeed = (between - CanRun_Now) / Oil_Distance_L;
        if (OilNeed > Capacity) return false;
        Oil += OilNeed;
        Sum += OilNeed * OilPrice_Of_Station[i];
      }
    }
  }
  return false;
}

int main() {
  int num = 0;
  cin >> num;
  for (int i = 0; i < num; i++) {
    cin >> AB_Distance >> Capacity >> Oil_Distance_L >> Num_Of_Station;
    for (int temp = 0; temp < Num_Of_Station; temp++)
      cin >> Distance_Of_Station[temp];
    for (int temp = 0; temp < Num_Of_Station; temp++)
      cin >> OilPrice_Of_Station[temp];
    if (Solution())
      cout << setprecision(1) << fixed << Sum << endl;
    else
      cout << "No Solution" << endl;
  }

  return 0;
}
