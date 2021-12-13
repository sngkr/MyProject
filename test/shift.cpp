// #include <iostream>

// using namespace std;
// #define PGSHIFT 12
// #define PXMASK 0x1FF // 9 bits
// #define PXSHIFT(level) (PGSHIFT + (9 * (level)))
// #define PX(level, va) ((((uint64_t)(va)) >> PXSHIFT(level)) & PXMASK)
// #define hh (1 << 2)

// int main()
// {
//     uint32_t a = 0x0fff0fff;
//     char b[100];
//     cout << a << endl;
//     itoa(a, b, 2);
//     cout << b << endl;
//     itoa((a >> PGSHIFT), b, 2);

//     cout << "a>>PGSHIFT:" << b << endl;

//     itoa(PXMASK, b, 2);

//     cout << b << endl;

//     itoa(((a >> 10) << 12), b, 2);

//     cout << b << endl;
//     PX(2, a);
//     cout << a << endl;
//     return 0;
// }
void elvator(void) {
  switch (state) {  //扫描电梯所在位置
    case (1): {
      if (state != statepre) {  //上次的状态和本次不一样说明电梯 需要开门
        run();                  //按键扫描三秒钟
        in1 = 0;                //如果in1和up1被按下则无效
        key[in_1] = 0;  //---------------------------------------
        up1 = 0;
        key[up_1] = 0;  //---------------------------------------
      } else {
        if (up1) {
          if (key[up_1]) {
            up1 = 0;
            run();
          }
        }
        in1 = 0;

        if (up2 | down2 | up3 | down3 | down4 | in2 | in3 | in4) {
          flag = 1;   //说明上行
          run();      //按键扫描三秒钟
          state = 2;  //更新状态
          statepre = 1;
        } else {
          statepre = state;
          flag = 2;
          keyscan();
          display();
        }
        break;
      }
      case (2): {                 //电梯到2楼
        if (state != statepre) {  //如果前后两次状态不一样则可能需要开门
          if (!(((flag == 1) && (in3 | up3 | down3) && (~up2) &&
                 (~in2))  //去三楼
                || ((flag == 1) && (in4 | down4) && (~up2) && (~in2))  //去四楼
                || ((flag == 0) && (in1 || up1) && (~down2) && (~in2))  //去一楼
                )) {
            run();    //按键扫描三秒钟
            in2 = 0;  //如果in2被按下则无效

            if (flag == 1) {  //如果上行，电梯外上行指示灯按下无效
              up2 = 0;
            } else {  //如果下行，电梯外下行指示灯按下无效
              down2 = 0;
            }
          }
        } else {  //在二楼停
          if (down2 | up2) {
            down2 = 0;
            up2 = 0;
            run();
          }
        }
        in2 = 0;

        if (flag)
          up2 = 0;
        else
          down2 = 0;
        if (flag == 1) {
          if (down3 | in3 | up3 | down4 | in4) {
            flag = 1;
            run();
            state = 3;
            statepre = 2;
          } else if (in1 | up1) {
            flag = 0;
            run();
            state = 1;
            statepre = 2;
          } else {
            statepre = state;
            flag = 2;
            keyscan();
            display();
          }
        } else {
          if (up1 | in1) {
            flag = 0;
            run();
            state = 1;
            statepre = 2;
          } else if (in3 | down3 | up3 | in4 | down4) {
            flag = 1;
            run();
            state = 3;
            statepre = 2;
          } else {
            statepre = state;
            flag = 2;
            keyscan();
            display();
          }
        }
        break;
      }
      case (3): {  //电梯到3楼

        if (state != statepre) {  //如果前后两次状态不一样则可能需要开门
          if (!(((flag == 0) && (in2 | up2 | down2) && (~up3) &&
                 (~in3))  //去二楼
                || ((flag == 1) && (in4 | down4) && (~up3) && (~in3))  //去四楼
                || ((flag == 0) && (in1 || up1) && (~down3) && (~in2))  //去一楼
                )) {
            run();    //按键扫描三秒钟
            in3 = 0;  //如果in3被按下则无效

            if (flag == 1) {  //如果上行，电梯外上行指示灯按下无效
              up3 = 0;
            } else {  //如果下行，电梯外下行指示灯按下无效
              down3 = 0;
            }
          }
        } else {  //在三楼停
          if (down3 | up3) {
            down3 = 0;
            up3 = 0;
            run();
          }
        }
        in3 = 0;

        if (flag)
          up3 = 0;
        else
          down3 = 0;
        if (flag == 1) {
          if (down4 | in4) {
            flag = 1;
            run();
            state = 4;
            statepre = 3;
          } else if (in1 | up1 | in2 | up2 | down2) {
            flag = 0;
            run();
            state = 2;
            statepre = 3;
          } else {
            statepre = state;
            flag = 2;
            keyscan();
            display();
          }
        } else {
          if (up1 | in1 | up2 | in2 | down2) {
            flag = 0;
            run();
            state = 2;
            statepre = 3;
          } else if (in4 | down4) {
            flag = 1;
            run();
            state = 4;
            statepre = 3;
          } else {
            statepre = state;
            flag = 2;
            keyscan();
            display();
          }
        }
        break;
      }
      case (4): {  // case4和case1类似
        keyscan();
        display();
        if (state != statepre) {
          run();
          in4 = 0;  //如果in4和down4被按下则无效

          down4 = 0;
        } else {
          if (down4) {
            down4 = 0;
            run();
          }
        }
        in4 = 0;

        if (in1 | up1 | up2 | down2 | in2 | in3 | up3 | down3) {
          flag = 0;  //说明下行
          run();
          state = 3;  //更新状态
          statepre = 4;
        } else {
          statepre = state;
          flag = 2;
          keyscan();
          display();
        }
        break;
      }
      default:
        break;
    }
  }
}