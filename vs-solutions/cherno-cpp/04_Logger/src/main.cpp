#include <iostream>

class Log
{
public:
	enum Level
	{
		ERROR	= 0,
		WARNING = 1,
		INFO	= 2,
	};

private:
	Level log_level = Log::INFO;

public:
	void set_level(Level level)
	{
		log_level = level;
	}

	void warn(const char* message)
	{
		if (log_level >= Log::WARNING)
			std::cout << "[WARNING]: " << message << std::endl;
	}

	void error(const char* message)
	{
		if (log_level >= Log::ERROR)
			std::cout << "[ERROR]: " << message << std::endl;
	}

	void info(const char* message)
	{
		if (log_level >= Log::INFO)
			std::cout << "[INFO]: " << message << std::endl;
	}
};

int main()
{
	Log log{};
	log.set_level(Log::INFO);

	log.warn("This is a warning!");
	log.error("This is an error!");
	log.info("This is an info!");

	std::cin.get();
}