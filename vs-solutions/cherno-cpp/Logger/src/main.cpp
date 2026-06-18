#include <iostream>

class Log
{
public:
	const int LOG_LEVEL_ERROR = 0;
	const int LOG_LEVEL_WARNING = 1;
	const int LOG_LEVEL_INFO = 2;

private:
	int log_level = LOG_LEVEL_INFO;

public:
	void set_level(int level)
	{
		log_level = level;
	}

	void warn(const char* message)
	{
		if (log_level >= LOG_LEVEL_WARNING)
			std::cout << "[WARNING]: " << message << std::endl;
	}

	void error(const char* message)
	{
		if (log_level >= LOG_LEVEL_ERROR)
			std::cout << "[ERROR]: " << message << std::endl;
	}

	void info(const char* message)
	{
		if (log_level >= LOG_LEVEL_INFO)
			std::cout << "[INFO]: " << message << std::endl;
	}
};

int main()
{
	Log log{};
	log.set_level(log.LOG_LEVEL_INFO);

	log.warn("This is a warning!");
	log.error("This is an error!");
	log.info("This is an info!");

	std::cin.get();
}