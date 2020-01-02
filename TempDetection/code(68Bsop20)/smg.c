#define __SMG_C_
#include "includeAll.h"
//=============================================================================

/* 0~9 数字的数码管编码 */
/* 从左到右 依次为 dp g f e d c b a */
const uint8_t number_code[11] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

void SMG_Display(uint8_t number)
{
	uint16_t i, j;
	uint8_t num1 = number / 10;
	uint8_t num2 = number % 10;
	
	SMG_Disable();
	
	for (i = 0; i < 1; i++)
	{
		SMG_One_Display(2, num1);
		for (j = 0; j < 50; j++)
		{
			/* code */
			F_clearWDT();
			
		}
		SMG_One_Display(1, num2);
		for (j = 0; j < 50; j++)
		{
			/* code */
			F_clearWDT();
		}
		//F_clearWDT();
	}
}

static void SMG_One_Display(uint8_t position, uint8_t number)
{
	int i;
	/* 选择数码管的位置 */
	/* 根据电路图，电平为低时该位被选中 */
	if (position == 1)
	{
		SMG_COM1 = 0;
		SMG_COM2 = 1;
	}
	else if (position == 2)
	{
		SMG_COM1 = 1;
		SMG_COM2 = 0;
	}

	/* 数据显示 */
	SMG_A = 0x01 & (number_code[number] >> 0);
	for (i = 0; i < 6; i++)
		;
	SMG_B = 0x01 & (number_code[number] >> 1);
	for (i = 0; i < 6; i++)
		;
	SMG_C = 0x01 & (number_code[number] >> 2);
	for (i = 0; i < 6; i++)
		;
	SMG_D = 0x01 & (number_code[number] >> 3);
	for (i = 0; i < 6; i++)
		;
	SMG_E = 0x01 & (number_code[number] >> 4);
	for (i = 0; i < 6; i++)
		;
	SMG_F = 0x01 & (number_code[number] >> 5);
	for (i = 0; i < 6; i++)
		;
	SMG_G = 0x01 & (number_code[number] >> 6);
	for (i = 0; i < 6; i++)
		;
	SMG_DG = 0x01 & (number_code[number] >> 7);
	for (i = 0; i < 6; i++)
		;
}
void SMG_Disable(void)
{
	SMG_COM1 = 0;
	SMG_COM2 = 0;
	SMG_A = 0x00;
	SMG_B = 0x00;
	SMG_C = 0x00;
	SMG_D = 0x00;
	SMG_E = 0x00;
	SMG_F = 0x00;
	SMG_G = 0x00;
	SMG_DG = 0x00;
}