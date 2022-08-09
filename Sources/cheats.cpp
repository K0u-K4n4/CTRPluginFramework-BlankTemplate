#include "cheats.hpp"
u32 offset = 0, offset2 = 0, data32 = 0, cmp32 = 0;
u16 data16 = 0, cmp16 = 0;
u8 data8 = 0, cmp8 = 0;
float dataf = 0;
namespace CTRPluginFramework
{
void Gene(MenuEntry*) {
  Process::Write16(0x833BDAA, 0x0306);
  Process::Write16(0x833BDAC, 0x10);
}
void bh1(MenuEntry*) {
  

  u8 bahh;
  
  if (!GetInput(bahh,  "バフレベルを入力してください(機能IDを先に設定しないと空欄のままです") {
    return;
  }
  Process::Write16(0x833BDB8, bahh);
}
void  bh2(MenuEntry*) {
  u8 bahh2;
  if (!GetInput(bahh2, "バフレベルを入力してください(機能IDを先に設定しないと空欄のままです") {
    return;
  }
  Process::Write16(0x833BDBC, bahh2);
}
void  omam(MenuEntry*) {
  u8 oma;
  if (!GetInput(oma,"お守りのレベル（兵士や闘士など）を入力してください") {
    return;
  }
  if(oma>=12||oma<1){
    oma=1;
  }
  Process::Write16(0x833BDBC, oma);
}
void bh3(MenuEntry*) {
  u8 bahh3;
  if (!GetInput(bahh3, "機能ID_1を設定してください（匠など）") {
    return;
  }
  Process::Write16(0x833BDB6, bahh3);
}
void  bh4(MenuEntry*) {
  u8 bahh4;
  if (!GetInput(bahh4,  "機能ID_2を設定してください（匠など）") {
    return;
  }
  Process::Write16(0x833BDBA, bahh4);
}


void  sous1(MenuEntry*) {
  u8 sou;

  if (!GetInput(sou,"装飾品の設定_1") {
    return;
  }
  Process::Write16(0x833BDB0, sou);
}
void sous2(MenuEntry*) {
  u8 sou2;

  if (!GetInput(sou2,"装飾品の設定_2") {
    return;
  }
  Process::Write16(0x833BDB2, sou2);
}
void  sous3(MenuEntry*) {
  u8 sou3;
  if (!GetInput(sou3,  "装飾品の設定_3") {
    return;
  }
  Process::Write16(0x833BDB4, sou3);
}
}
