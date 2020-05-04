#include "Log.h"

namespace Flipper {

	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;


	void Log::Init() {

		spdlog::set_pattern("[%T] %^%n: %v %$ ");
		try {
			s_ClientLogger = spdlog::stdout_color_mt("FLIPPER_APP");
			s_ClientLogger->set_level(spdlog::level::trace);
			s_CoreLogger = spdlog::stdout_color_mt("FLIPPER");
			s_CoreLogger->set_level(spdlog::level::trace);
		}
		catch (const spdlog::spdlog_ex & ex) {
			std::cout << "Couldn't intialize log: " << ex.what() << std::endl;
		}
	}



}