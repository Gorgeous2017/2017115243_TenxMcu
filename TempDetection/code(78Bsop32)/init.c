#define __init_c
#include "includeAll.h"
//=============================================================================
void SysInit() {
  F_clearWDT();
  //时钟初始化
  CLKCON = 0x03; // Clock div 1  7.3728Mhz
  STPPCK = 0;
  STPFCK = 0;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  SELFCK = 1;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  // IO 模式初始化
  P1MODL = 0xaa;
  P1MODH = P14MOD_2 | P15MOD_2;
  P_led_com = 0; /* 根据电路图，con 口应恒为低 */
  P_led_1 = 0;

  // IO 状态初始化
  //F_ledOff();
  P_bell = 0;
}
//=============================================================================
void VarsInit() {}