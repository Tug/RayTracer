// test.cpp�: fichier projet principal.

#include "stdafx.h"
#include "Form1.h"

using namespace test;
using namespace System;
using namespace System::Runtime::InteropServices;

[DllImport("kernel32.dll", EntryPoint="AttachConsole")]
extern bool AttachConsole(int dwProcessId);
[DllImport("kernel32.dll", EntryPoint="AllocConsole")]
extern bool AllocConsole(void);

const int ATTACH_PARENT_PROCESS = -1;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Activation des effets visuels de Windows�XP avant la cr�ation de tout contr�le
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	AttachConsole(ATTACH_PARENT_PROCESS);
	AllocConsole();

	// Cr�er la fen�tre principale et l'ex�cuter
	Application::Run(gcnew Form1());
	return 0;
}
