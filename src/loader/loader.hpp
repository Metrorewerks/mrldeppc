#pragma once

#include <windows.h>

#include <fstream>
#include <vector>
#include <algorithm>

#define BINARY_PAYLOAD_SIZE 0x300000

namespace loader
{
	auto load(const char* bin_name) -> void;
	auto load_imports(const HMODULE target, const HMODULE source) -> void;
	auto find_library(LPCSTR library)->HMODULE;
	auto load_sections(const HMODULE target, const HMODULE source) -> void;
	auto load_section(const HMODULE target, const HMODULE source, IMAGE_SECTION_HEADER* section) -> void;
};