#include "cheats.hpp"

namespace CTRPluginFramework
{
void Gene(MenuEntry*) {
  Process::Write16(0x833BDAA, 0x0306);
  Process::Write16(0x833BDAC, 0x10);
}
void bh1(MenuEntry*) {
  std::stringstream msg;
  u8 bahh;
  msg << "バフレベルを入力してください(機能IDを先に設定しないと空欄のままです)"<< ;
  if (!GetInput(bahh)) {
    return;
  }
  Process::Write16(0x833BDB8, bahh);
}
void  bh2(MenuEntry*) {
  std::stringstream msg;
  u8 bahh2;
  msg2 << "バフレベルを入力してください(機能IDを先に設定しないと空欄のままです)"<< ;
  if (!GetInput(bahh2)) {
    return;
  }
  Process::Write16(0x833BDBC, bahh2);
}
void  omam(MenuEntry*) {
  std::stringstream msg;
  u8 oma;
  msg << "お守りのレベル（兵士や闘士など）を入力してください"<< ;
  if (!GetInput(oma)) {
    return;
  }
  if(oma>=12||oma<1){
    oma=1;
  }
  Process::Write16(0x833BDBC, oma);
}
void bh3(MenuEntry*) {
  std::stringstream msg3;
  u8 bahh3;
  msg3 << "機能ID_1を設定してください（匠など）"<< ;
  if (!GetInput(bahh3)) {
    return;
  }
  Process::Write16(0x833BDB6, bahh3);
}
void  bh4(MenuEntry*) {
  std::stringstream msg4;
  u8 bahh4;
  msg4 << "機能ID_2を設定してください（匠など）"<< ;
  if (!GetInput(bahh4)) {
    return;
  }
  Process::Write16(0x833BDBA, bahh4);
}


void  sous1(MenuEntry*) {
  std::stringstream msg5;
  u8 sou;
  msg5 << "装飾品の設定_1"<< ;
  if (!GetInput(sou)) {
    return;
  }
  Process::Write16(0x833BDB0, sou);
}
void sous2(MenuEntry*) {
  std::stringstream msg6;
  u8 sou2;
  msg6 << "装飾品の設定_2"<< ;
  if (!GetInput(sou2)) {
    return;
  }
  Process::Write16(0x833BDB2, sou2);
}
void  sous3(MenuEntry*) {
  std::stringstream msg7;
  u8 sou3;
  msg7<< "装飾品の設定_3"<< ;
  if (!GetInput(sou3)) {
    return;
  }
  Process::Write16(0x833BDB4, sou3);
}
}
