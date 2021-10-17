#include <loader/loader.hpp>
#include <memory.hpp>

int __cdecl main(int argc, char* argv[])
{
	loader::load("mwldeppc.exe");
	memory::call<void __cdecl()>(0x00401000)();
	return 0;
}