
#include "delay.h"
#include "key.h"
#include "led.h"
#include "main.h"
#include "timer.h"

// IDR是查看引脚电平状态用的寄存器，ODR是引脚电平输出的寄存器

u8 counter; //计数器

u8 state;    //当前电梯状态
u8 statepre; //之前电梯状态
u8 flag;     //电梯上下标志，  0下，1上

u8 i;

char key[24] = {0};

void keyscan(void);
void elvator(void);

void display()
{

  GPIOA->ODR &= 0xFFFF0FFF;
  set_DigitalNum(state); //楼乘标号
  GPIOA->ODR |= 0x00002000;
  Delay_ms(2);

  GPIOA->ODR &= 0xFFFF0FFF;
  set_DigitalNum(flag);
  GPIOA->ODR |= 0x00008000;
  Delay_ms(2);
}

void run()
{
  for (i = 0; i < 50; i++) // 100ms
  {
    keyscan();
    display();
  }
}

int main()
{
  Delay_Init();          // 延时程序初始化
  MultDigitalNum_Init(); // 数码管初始化
  KEY_Init();            // 按键初始化
                         // TIM3_Int_Init(499,7199);//50ms进入一次中断
                         //电梯在一楼
  state = 1;
  statepre = 1;
  flag = 1; //上

  //电梯程序持续工作
  while (1)
  {
    // keyscan();
    elvator();
  }
}

void keyscan(void)
{
  //扫描
  for (int i = 0; i < 14; i++)
  {
    //扫描GPIOC
    if (i < 8)
    {
      if (GPIO_ReadInputDataBit(GPIOC, 1 << i) == Bit_RESET)
      {
        // Delay_ms(1);
        if (GPIO_ReadInputDataBit(GPIOC, 1 << i) == Bit_RESET)
          key[i + 14] = 1;
      }
    }
    //扫描GPIOB
    if (GPIO_ReadInputDataBit(GPIOB, 1 << i) == Bit_RESET)
    {
      // Delay_ms(1);
      if (GPIO_ReadInputDataBit(GPIOB, 1 << i) == Bit_RESET)
        key[i] = 1;
    }
  }
}

//电梯执行程序
void elvator(void)
{
  switch (state)
  { //执行
  case (1):
  {
    //电梯停
    //电梯到请求一楼,到达后电梯不动，监听请求

    //取消以前到1楼、和将要发生在本楼层的请求，
    key[up_1] = 0;
    key[in_1] = 0;
    // Delay_ms(2);
    //监听
    //目前一楼，如果上面楼层有请求，电梯上升到二楼
    if (key[up_2] || key[down_2] || key[in_2] ||
        key[up_3] || key[down_3] || key[in_3] ||
        key[up_4] || key[down_4] || key[in_4] ||
        key[up_5] || key[down_5] || key[in_5] ||
        key[up_6] || key[down_6] || key[in_6] ||
        key[up_7] || key[down_7] || key[in_7] ||
        key[down_8] || key[in_8])
    {
      flag = 1;     //上升
      run();        //扫描按键，输出状态、楼层
      state = 2;    //新状态，二楼
      statepre = 1; //旧状态，一楼
    }
    else //无上升请求，保持静止
    {
      statepre = state;
      flag = 2; //保持停止状态
      run();
    }
    break;
  }
  case (2):
  { //电梯到2楼

    //不停，不是2楼的请求
    if (((~key[up_2]) && (~key[in_2]) && (~key[down_2])) == 1)
    {
      if (flag == 1)
      {
        if (key[up_3] || key[down_3] || key[in_3] ||
            key[up_4] || key[down_4] || key[in_4] ||
            key[up_5] || key[down_5] || key[in_5] ||
            key[up_6] || key[down_6] || key[in_6] ||
            key[up_7] || key[down_7] || key[in_7] ||
            key[down_8] || key[in_8])
        {
          flag = 1;
          run();
          //上升到三楼
          state = 3;
          statepre = 2;
        }
      }
      //因为下降经过
      if (flag == 0)
      {
        if (key[up_1] || key[in_1])
        {
          flag = 0;
          run();
          state = 1;
          statepre = 2;
        }
      }
    }
    //停在2楼
    if ((key[up_2]) || (key[in_2]) || (key[down_2]) || statepre == state)
    {
      //取消以前到2楼、和将要发生在本楼层的请求，
      key[in_2] = 0;
      key[up_2] = 0;
      key[down_2] = 0;
      statepre = state;
      flag = 2; //保持停止状态
      //保持监听!
      keyscan();
      if (key[up_3] || key[down_3] || key[in_3] ||
          key[up_4] || key[down_4] || key[in_4] ||
          key[up_5] || key[down_5] || key[in_5] ||
          key[up_6] || key[down_6] || key[in_6] ||
          key[up_7] || key[down_7] || key[in_7] ||
          key[down_8] || key[in_8])
        flag = 1;
      if (key[in_1] || key[up_1])
        flag = 0;
      run();
    }
    break;
  }
  case (3):
  {
    //不停，不是3楼的请求
    if (((~key[up_3]) && (~key[in_3]) && (~key[down_3])) == 1)
    {
      if (flag == 1)
      {
        if (key[up_4] || key[down_4] || key[in_4] ||
            key[up_5] || key[down_5] || key[in_5] ||
            key[up_6] || key[down_6] || key[in_6] ||
            key[up_7] || key[down_7] || key[in_7] ||
            key[down_8] || key[in_8])
        {
          flag = 1;
          run();
          //上升到4楼
          state = 4;
          statepre = 3;
        }
      }
      //因为下降经过
      if (flag == 0)
      {
        if (key[up_1] || key[in_1] ||
            key[up_2] || key[down_2] || key[in_2])
        {
          flag = 0;
          run();
          //下降到2楼
          state = 2;
          statepre = 3;
        }
      }
    }
    //停在3楼
    if ((key[up_3]) || (key[in_3]) || (key[down_3]) || statepre == state)
    {
      //取消以前到3楼、和将要发生在本楼层的请求，
      key[in_3] = 0;
      key[up_3] = 0;
      key[down_3] = 0;
      statepre = state;
      flag = 2; //保持停止状态
      //保持监听!随时改变电梯状态
      keyscan();
      if (key[up_4] || key[down_4] || key[in_4] ||
          key[up_5] || key[down_5] || key[in_5] ||
          key[up_6] || key[down_6] || key[in_6] ||
          key[up_7] || key[down_7] || key[in_7] ||
          key[down_8] || key[in_8])
        flag = 1;

      if (key[up_1] || key[in_1] ||
          key[up_2] || key[down_2] || key[in_2])
        flag = 0;
      run();
    }
    break;
  }

  case (4):
  {
    //不停，不是4楼的请求
    if (((~key[up_4]) && (~key[in_4]) && (~key[down_4])) == 1)
    {
      if (flag == 1)
      {
        if (key[up_5] || key[down_5] || key[in_5] ||
            key[up_6] || key[down_6] || key[in_6] ||
            key[up_7] || key[down_7] || key[in_7] ||
            key[down_8] || key[in_8])
        {
          flag = 1;
          run();
          //上升到5楼
          state = 5;
          statepre = 4;
        }
      }
      //因为下降经过
      if (flag == 0)
      {
        if (key[up_1] || key[in_1] ||
            key[up_2] || key[down_2] || key[in_2] ||
            key[up_3] || key[down_3] || key[in_3])
        {
          flag = 0;
          run();
          //下降到3楼
          state = 3;
          statepre = 4;
        }
      }
    }
    //停在4楼
    if ((key[up_4]) || (key[in_4]) || (key[down_4]) || statepre == state)
    {
      //取消以前到4楼、和将要发生在本楼层的请求，
      key[in_4] = 0;
      key[up_4] = 0;
      key[down_4] = 0;
      statepre = state;
      flag = 2; //保持停止状态
      //保持监听!
      keyscan();
      if (key[up_5] || key[down_5] || key[in_5] ||
          key[up_6] || key[down_6] || key[in_6] ||
          key[up_7] || key[down_7] || key[in_7] ||
          key[down_8] || key[in_8])
        flag = 1;
      if (key[up_1] || key[in_1] ||
          key[up_2] || key[down_2] || key[in_2] ||
          key[up_3] || key[down_3] || key[in_3])
        flag = 0;
      run();
    }
    break;
  }

  case (5):
  {
    //不停，不是5楼的请求
    if (((~key[up_5]) && (~key[in_5]) && (~key[down_5])) == 1)
    {
      if (key[up_6] || key[down_6] || key[in_6] ||
          key[up_7] || key[down_7] || key[in_7] ||
          key[down_8] || key[in_8])
      {
        if (flag == 1)
        {
          flag = 1;
          run();
          //上升到6楼
          state = 6;
          statepre = 5;
        }
      }
      if (key[up_1] || key[in_1] ||
          key[up_2] || key[down_2] || key[in_2] ||
          key[up_3] || key[down_3] || key[in_3] ||
          key[up_4] || key[down_4] || key[in_4])
      {
        //因为下降经过
        if (flag == 0)
        {

          flag = 0;
          run();
          //下降到4楼
          state = 4;
          statepre = 5;
        }
      }
    }
    //停在5楼
    if ((key[up_5]) || (key[in_5]) || (key[down_5]) || statepre == state)
    {
      //取消以前到4楼、和将要发生在本楼层的请求，
      key[in_5] = 0;
      key[up_5] = 0;
      key[down_5] = 0;
      statepre = state;
      flag = 2; //保持停止状态
      //保持监听!
      keyscan();
      if (key[up_6] || key[down_6] || key[in_6] ||
          key[up_7] || key[down_7] || key[in_7] ||
          key[down_8] || key[in_8])
        flag = 1;

      if (key[up_1] || key[in_1] ||
          key[up_2] || key[down_2] || key[in_2] ||
          key[up_3] || key[down_3] || key[in_3] ||
          key[up_4] || key[down_4] || key[in_4])
        flag = 0;
      run();
    }
    break;
  }

  case (6):
  {
    //不停，不是5楼的请求
    if (((~key[up_6]) && (~key[in_6]) && (~key[down_6])) == 1)
    {
      if (key[up_7] || key[down_7] || key[in_7] ||
          key[down_8] || key[in_8])
      {
        if (flag == 1)
        {
          flag = 1;
          run();
          //上升到7楼
          state = 7;
          statepre = 6;
        }
      }
      if (key[up_1] || key[in_1] ||
          key[up_2] || key[down_2] || key[in_2] ||
          key[up_3] || key[down_3] || key[in_3] ||
          key[up_4] || key[down_4] || key[in_4] ||
          key[up_5] || key[down_5] || key[in_5])
      {
        //因为下降经过
        if (flag == 0)
        {

          flag = 0;
          run();
          //下降到5楼
          state = 5;
          statepre = 6;
        }
      }
    }
    //停在6楼
    if ((key[up_6]) || (key[in_6]) || (key[down_6]) || statepre == state)
    {
      //取消以前到4楼、和将要发生在本楼层的请求，
      key[in_6] = 0;
      key[up_6] = 0;
      key[down_6] = 0;
      statepre = state;
      flag = 2; //保持停止状态
      //保持监听!
      keyscan();
      if (key[up_7] || key[down_7] || key[in_7] ||
          key[down_8] || key[in_8])
        flag = 1;

      if (key[up_1] || key[in_1] ||
          key[up_2] || key[down_2] || key[in_2] ||
          key[up_3] || key[down_3] || key[in_3] ||
          key[up_4] || key[down_4] || key[in_4] ||
          key[up_5] || key[down_5] || key[in_5])
        flag = 0;
      run();
    }
    break;
  }

  case (7):
  {
    //不停，不是5楼的请求
    if (((~key[up_7]) && (~key[in_7]) && (~key[down_7])) == 1)
    {
      if (key[down_8] || key[in_8])
      {
        if (flag == 1)
        {
          flag = 1;
          run();
          //上升到8楼
          state = 8;
          statepre = 7;
        }
      }
      if (key[up_1] || key[in_1] ||
          key[up_2] || key[down_2] || key[in_2] ||
          key[up_3] || key[down_3] || key[in_3] ||
          key[up_4] || key[down_4] || key[in_4] ||
          key[up_5] || key[down_5] || key[in_5] ||
          key[up_6] || key[down_6] || key[in_6])
      {
        //因为下降经过
        if (flag == 0)
        {

          flag = 0;
          run();
          //下降到6楼
          state = 6;
          statepre = 7;
        }
      }
    }
    //停在7楼
    if ((key[up_7]) || (key[in_7]) || (key[down_7]) || statepre == state)
    {
      //取消以前到4楼、和将要发生在本楼层的请求，
      key[in_7] = 0;
      key[up_7] = 0;
      key[down_7] = 0;
      statepre = state;
      flag = 2; //保持停止状态
      //保持监听!
      keyscan();
      if (key[down_8] || key[in_8])
        flag = 1;

      if (key[up_1] || key[in_1] ||
          key[up_2] || key[down_2] || key[in_2] ||
          key[up_3] || key[down_3] || key[in_3] ||
          key[up_4] || key[down_4] || key[in_4] ||
          key[up_5] || key[down_5] || key[in_5] ||
          key[up_6] || key[down_6] || key[in_6])
        flag = 0;
      run();
    }
    break;
  }

  case (8):
  { // case4和case1类似
    keyscan();
    display();
    if (state != statepre)
    {
      run();
      key[in_8] = 0; //如果key[in_4]和key[down_4]被按下则无效
      key[in_8] = 0;
      key[down_8] = 0;
      key[down_8] = 0;
    }
    else
    {
      if (key[down_8])
      {
        key[down_8] = 0;
        key[down_8] = 0;
        run();
      }
    }
    key[in_8] = 0;
    key[in_8] = 0;
    if (key[up_1] || key[in_1] ||
        key[up_2] || key[down_2] || key[in_2] ||
        key[up_3] || key[down_3] || key[in_3] ||
        key[up_4] || key[down_4] || key[in_4] ||
        key[up_5] || key[down_5] || key[in_5] ||
        key[up_6] || key[down_6] || key[in_6] ||
        key[up_7] || key[down_7] || key[in_7])
    {
      flag = 0; //说明下行
      run();
      state = 7; //更新状态
      statepre = 8;
    }
    else
    {
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
