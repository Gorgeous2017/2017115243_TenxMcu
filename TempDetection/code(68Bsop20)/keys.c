#define __keys_c
#include "includeAll.h"
//=============================================================================
void GetKeys()
{
	static uint8_t tmpKeyValue[4] = {D_keyNull, D_keyNull, D_keyNull, D_keyNull}; //静态局部变量初始化为0，每次执行函数保持上一次的执行时的值
	KeyInit();																	  /* 设置按键为输入端口*/
	P_led_com = 1;																  /* led 失能 */
	delayMs(1);
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	P_key_1 = 1; /* SFG置一，数位输入，下同 */
	P_key_2 = 1;
	P_key_3 = 1;
	P_key_4 = 1;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	//临时键值为0
	//-------------------------------------------------------------
	if (P_key_1 == 0)
	{ //按键真的按下，为低电平
		tmpKeyValue[0] = D_keyValue1;
	}
	else
	{ //按键没有被按下，为高电平
		keyValue[0] = tmpKeyValue[0];
		tmpKeyValue[0] = D_keyNull;
	}
	//-------------------------------------------------------------
	if (P_key_2 == 0)
	{ //按键真的按下，为低电平
		tmpKeyValue[1] = D_keyValue1;
	}
	else
	{ //按键没有被按下，为高电平
		keyValue[1] = tmpKeyValue[1];
		tmpKeyValue[1] = D_keyNull;
	}
	//-------------------------------------------------------------
	if (P_key_3 == 0)
	{ //按键真的按下，为低电平
		tmpKeyValue[2] = D_keyValue1;
	}
	else
	{ //按键没有被按下，为高电平
		keyValue[2] = tmpKeyValue[2];
		tmpKeyValue[2] = D_keyNull;
	}
	//-------------------------------------------------------------
	if (P_key_4 == 0)
	{ //按键真的按下，为低电平
		tmpKeyValue[3] = D_keyValue1;
	}
	else
	{ //按键没有被按下，为高电平
		keyValue[3] = tmpKeyValue[3];
		tmpKeyValue[3] = D_keyNull;
	}

	LEDInit();	 /* 端口置为输出，显示 led */
	P_led_com = 0; /* led 使能 */
}