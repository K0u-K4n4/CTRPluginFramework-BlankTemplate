#include "cheats.hpp"

u32 offset = 0, offset2 = 0, data32 = 0, cmp32 = 0;
u16 data16 = 0, cmp16 = 0;
u8 data8 = 0, cmp8 = 0;
float dataf = 0;

namespace CTRPluginFramework
{
  void KeyStrokesButtom(MenuEntry* entry) {
    const Screen &KSTSC = OSD::GetTopScreen();
    std::string IsK = "";
    u32 KSTX = 10;
    u32 KSTY = 50;
    Color foreground = Color::White;
    Color background = Color::Black;
    if(Controller::IsKeysDown(A)) {
      IsK += "A  ";
      KSTSC.Draw(IsK, KSTX, KSTY, foreground, background);
    }
    if(Controller::IsKeysDown(B)) {
      IsK += "B  ";
      KSTSC.Draw(IsK, KSTX, KSTY, foreground, background);
    }
    if(Controller::IsKeysDown(X)) {
      IsK += "X  ";
      KSTSC.Draw(IsK, KSTX, KSTY, foreground, background);
    }
    if(Controller::IsKeysDown(Y)) {
      IsK += "Y  ";
      KSTSC.Draw(IsK, KSTX, KSTY, foreground, background);
    }
    if(Controller::IsKeysDown(R)) {
      IsK += "R  ";
      KSTSC.Draw(IsK, KSTX, KSTY, foreground, background);
    }
    if(Controller::IsKeysDown(L)) {
      IsK += "L  ";
      KSTSC.Draw(IsK, KSTX, KSTY, foreground, background);
    }
    if(Controller::IsKeysDown(ZR)) {
      IsK += "ZR  ";
      KSTSC.Draw(IsK, KSTX, KSTY, foreground, background);
    }
    if(Controller::IsKeysDown(ZL)) {
      IsK += "ZL  ";
      KSTSC.Draw(IsK, KSTX, KSTY, foreground, background);
    }
    if(Controller::IsKeysDown(Start)) {
      IsK += "Start  ";
      KSTSC.Draw(IsK, KSTX, KSTY, foreground, background);
    }
    if(Controller::IsKeysDown(Select)) {
      IsK += "Select  ";
      KSTSC.Draw(IsK, KSTX, KSTY, foreground, background);
    }
  }
  void KeyStrokesPad(MenuEntry* entry) {
    if(Controller::IsKeysDown(CPadUp) || Controller::IsKeysDown(CPadDown) || Controller::IsKeysDown(CPadRight) || Controller::IsKeysDown(CPadLeft)) {
    const Screen &Pad = OSD::GetTopScreen();
    const Screen &Pat = OSD::GetTopScreen();
    u32 KSTX = 360;
    u32 KSTY = 5;
    Color foreground = Color::White;
    Color background = Color::Black;
    std::string Pad1 = "_";
    std::string Pad2 = "_ _ _";
    if(Controller::IsKeysDown(CPadUp)) {
      Pad1 = "X";
      if(Controller::IsKeysDown(CPadRight)) {
        Pad2 = "_ _ X";
      }
      if(Controller::IsKeysDown(CPadLeft)) {
        Pad2 = "X _ _";
      }
    }
    if(Controller::IsKeysDown(CPadDown)) {
      if(Controller::IsKeysDown(CPadRight)) {
        Pad2 = "_ X X";
      }else{
      if(Controller::IsKeysDown(CPadLeft)) {
        Pad2 = "X X _";
      }else{
        Pad2 = "_ X _";
      }
      }
    }else{
    if(Controller::IsKeysDown(CPadRight)) {
        Pad2 = "_ _ X";
      }
    if(Controller::IsKeysDown(CPadLeft)) {
        Pad2 = "X _ _";
      }
    }
  Pad.Draw(Pad1, KSTX+12, KSTY, foreground, background);
  Pat.Draw(Pad2, KSTX, KSTY+13, foreground, background);
  }
  }
  void KeyStrokesDPad(MenuEntry* entry) {
    if(Controller::IsKeysDown(DPadUp) || Controller::IsKeysDown(DPadDown) || Controller::IsKeysDown(DPadRight) || Controller::IsKeysDown(DPadLeft)) {
    const Screen &Pad = OSD::GetTopScreen();
    const Screen &Pat = OSD::GetTopScreen();
    u32 KSTX = 5;
    u32 KSTY = 210;
    Color foreground = Color::White;
    Color background = Color::Black;
    std::string Pad1 = "_";
    std::string Pad2 = "_ _ _";
    if(Controller::IsKeysDown(DPadUp)) {
      Pad1 = "X";
      if(Controller::IsKeysDown(DPadRight)) {
        Pad2 = "_ _ X";
      }
      if(Controller::IsKeysDown(DPadLeft)) {
        Pad2 = "X _ _";
      }
    }
    if(Controller::IsKeysDown(DPadDown)) {
      if(Controller::IsKeysDown(DPadRight)) {
        Pad2 = "_ X X";
      }else{
      if(Controller::IsKeysDown(DPadLeft)) {
        Pad2 = "X X _";
      }else{
        Pad2 = "_ X _";
      }
      }
    }else{
    if(Controller::IsKeysDown(DPadRight)) {
        Pad2 = "_ _ X";
      }
    if(Controller::IsKeysDown(DPadLeft)) {
        Pad2 = "X _ _";
      }
    }
  Pad.Draw(Pad1, KSTX+12, KSTY, foreground, background);
  Pat.Draw(Pad2, KSTX, KSTY+13, foreground, background);
  }
  }
  void Readanim(MenuEntry* entry) {
    if(Controller::IsKeysDown(R + L + DPadRight)) {
  u8 HP;
  u8 Sutam;
  u16 sharp;
  u8 field;
  const Screen &HPi = OSD::GetTopScreen();
  const Screen &Sutami = OSD::GetTopScreen();
  const Screen &sharpi = OSD::GetTopScreen();
  const Screen &fieldi = OSD::GetTopScreen();
  u32 x4= 10;
  u32 y4 = 120;
  Color foreground = Color::SkyBlue;
  Color background = Color::Black;
  Process::Read32(0x08195350 , offset);
  Process::Read8(offset + 0x0F52 , HP);
  Process::Read8(offset + 0x0F5E , Sutam);
  Process::Read16(offset + 0x2214 , sharp);
  Process::Read8(offset + 0x0CF4 , field);
  HPi.Draw("HP : " + Utils::Format("%d" , HP), x4, y4, foreground, background);
  Sutami.Draw("Moving : " + Utils::Format("%d" , Sutam), x4, y4+10, foreground, background);
  sharpi.Draw("Sharpness : " + Utils::Format("%d" , sharp), x4, y4+20, foreground, background);
  fieldi.Draw("Field : " + Utils::Format("%d" , field), x4, y4+30, foreground, background);
    }
}
  void Readanim2(MenuEntry* entry) {
    if(Controller::IsKeysDown(R + L + DPadLeft)) {
      const Screen &HRi = OSD::GetTopScreen();
      const Screen &atki = OSD::GetTopScreen();
      const Screen &dfci = OSD::GetTopScreen();
      const Screen &abli = OSD::GetTopScreen();
      const Screen &monyi = OSD::GetTopScreen();
      const Screen &pointi = OSD::GetTopScreen();
      u32 x5 = 10;
      u32 y5 = 50;
      Color foreground = Color::SkyBlue;
      Color background = Color::Black;
      u16 atk;
      u16 dfc;
      u16 abl;
      u16 HR;
      u32 Money;
      u32 point;
      Process::Read16(0x831B450 , atk);
      Process::Read16(0x831B45E , dfc);
      Process::Read16(0x831B45A , abl);
      Process::Read16(0x831B76A , HR);
      Process::Read32(0x83B3818 , Money);
      Process::Read32(0x83B3820 , point);
      dfc += 1;
      atki.Draw("attacks : " + Utils::Format("%d" , atk), x5, y5, foreground, background);
      dfci.Draw("Defenses : " + Utils::Format("%d" , dfc), x5, y5+10, foreground, background);
      abli.Draw("attributes : " + Utils::Format("%d" , abl), x5, y5+20, foreground, background);
      HRi.Draw("HR : " + Utils::Format("%d" , HR), x5, y5+30, foreground, background);
      monyi.Draw("Money : " + Utils::Format("%d" , Money), x5, y5+40, foreground, background);
      pointi.Draw("RRI Point : " + Utils::Format("%d" , point), x5, y5+50, foreground, background);
    }
}
}






