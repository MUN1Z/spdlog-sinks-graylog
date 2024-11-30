#pragma once
#include <iostream>

struct GrayLogSinkOptions {
	const std::string hostNameOrAddress;
	const std::string source;
	const std::string level;
	short port;
};
