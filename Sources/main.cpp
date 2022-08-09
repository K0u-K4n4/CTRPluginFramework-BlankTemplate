#include <3ds.h>
#include "csvc.h"
#include <CTRPluginFramework.hpp>

#include <vector>

namespace CTRPluginFramework
{
    // This patch the NFC disabling the touchscreen when scanning an amiibo, which prevents ctrpf to be used
    static void    ToggleTouchscreenForceOn(void)
    {
        static u32 original = 0;
        static u32 *patchAddress = nullptr;

        if (patchAddress && original)
        {
            *patchAddress = original;
            return;
        }

        static const std::vector<u32> pattern =
        {
            0xE59F10C0, 0xE5840004, 0xE5841000, 0xE5DD0000,
            0xE5C40008, 0xE28DD03C, 0xE8BD80F0, 0xE5D51001,
            0xE1D400D4, 0xE3510003, 0x159F0034, 0x1A000003
        };

        Result  res;
        Handle  processHandle;
        s64     textTotalSize = 0;
        s64     startAddress = 0;
        u32 *   found;

        if (R_FAILED(svcOpenProcess(&processHandle, 16)))
            return;

        svcGetProcessInfo(&textTotalSize, processHandle, 0x10002);
        svcGetProcessInfo(&startAddress, processHandle, 0x10005);
        if(R_FAILED(svcMapProcessMemoryEx(CUR_PROCESS_HANDLE, 0x14000000, processHandle, (u32)startAddress, textTotalSize)))
            goto exit;

        found = (u32 *)Utils::Search<u32>(0x14000000, (u32)textTotalSize, pattern);

        if (found != nullptr)
        {
            original = found[13];
            patchAddress = (u32 *)PA_FROM_VA((found + 13));
            found[13] = 0xE1A00000;
        }

        svcUnmapProcessMemoryEx(CUR_PROCESS_HANDLE, 0x14000000, textTotalSize);
exit:
        svcCloseHandle(processHandle);
    }

    // This function is called before main and before the game starts
    // Useful to do code edits safely
    void    PatchProcess(FwkSettings &settings)
    {
        ToggleTouchscreenForceOn();
    }

    // This function is called when the process exits
    // Useful to save settings, undo patchs or clean up things
    void    OnProcessExit(void)
    {
        ToggleTouchscreenForceOn();
    }

    void    InitMenu(PluginMenu &menu)
    {
        menu += new MenuEntry("お守り生成", nullptr, Gene, "お守りを生成できます。");
        menu += new MenuEntry("機能ID_1設定", nullptr, bh3, "機能ID_1を設定できます（匠など）");
        menu += new MenuEntry("機能ID_2設定", nullptr, bh4, "機能ID_2を設定できます（匠など）");
        menu += new MenuEntry("バフレベル設定（バフ欄1）", nullptr, bh1, "バフの設定をできます");
        menu += new MenuEntry("バフレベル設定（バフ欄1）", nullptr, bh2, "バフの設定をできます");
        
        menu += new MenuEntry("お守りレベル設定", nullptr, omam, "お守りのレベルを設定できます（兵士や闘士など）");
        menu += new MenuEntry("装飾品設定1", nullptr,sous1, "装飾品スロット1を設定できます");
        menu += new MenuEntry("装飾品設定2", nullptr, sous2, "装飾品スロット2を設定できます");
        menu += new MenuEntry("装飾品設定3", nullptr, sous3, "装飾品スロット3を設定できます");
    }

    int     main(void)
    {
        PluginMenu *menu = new PluginMenu("Action Replay", 0, 7, 1,
                                            "A blank template plugin.\nGives you access to the ActionReplay and others tools.");

        // Synnchronize the menu with frame event
        menu->SynchronizeWithFrame(true);

        // Init our menu entries & folders
        InitMenu(*menu);

        // Launch menu and mainloop
        menu->Run();

        delete menu;

        // Exit plugin
        return (0);
    }
}
