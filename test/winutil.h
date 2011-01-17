#ifndef _H_WINUTIL
#define _H_WINUTIL

#include <string>

void MarshalString(System::String ^ s, std::string& os);
std::string randomString(System::Random^ random, int len);

#endif