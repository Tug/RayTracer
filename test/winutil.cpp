#include "stdafx.h"

#include "winutil.h"


void MarshalString(System::String ^ s, std::string& os) {
   using namespace System::Runtime::InteropServices;
   const char* chars = 
      (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
   os = chars;
   Marshal::FreeHGlobal(System::IntPtr((void*)chars));
}

;

std::string randomString(System::Random^ random, int len) {
	std::string str;
    static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i < len; ++i) {
        str += alphanum[random->Next(0, sizeof(alphanum) - 1)];
    }
    return str;
}
