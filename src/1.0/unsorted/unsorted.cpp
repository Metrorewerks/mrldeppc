#include <unsorted/unsorted.hpp>

#include <memory/memory.hpp>

auto unsorted::do_exit(std::uint32_t exit_code) -> void
{
	if (!memory::get<int>(0x004D5774))
	{
		memory::call<void __cdecl()>(0x00404FA0)();
	}

	memory::call<void __cdecl(std::uint32_t)>(0x00402080)(exit_code);
}

auto unsorted::start() -> void
{
	memory::call<void __cdecl(std::uint32_t(__cdecl**)(int, int, int, int))>(0x004014E0)
		(reinterpret_cast<std::uint32_t(__cdecl**)(int, int, int, int)>(0x0048A020));

	if (!memory::call<int __cdecl()>(0x00401E60)())
	{
		unsorted::do_exit(0xFFFFFFFF);
	}

	memory::call<void __cdecl(std::uint32_t*)>(0x004020B0)(reinterpret_cast<std::uint32_t*>(0x004B0000));

	auto v0 = memory::call<std::uint32_t __cdecl(std::uint32_t, std::uint32_t)>(0x00402AB0)
		(memory::get<std::uint32_t>(0x004D5794), memory::get<std::uint32_t>(0x004D579C));

	unsorted::do_exit(v0);
}