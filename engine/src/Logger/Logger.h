#include<string>
#include<vector>
#include<memory>
#include<string>
#include"Format/format.h"
#include"Writer/LogWriter.h"

namespace xengine{

enum LOG_LEVEL: int{
    LOG_INFO = 0,
    LOG_WARN ,
    LOG_ERROR,
    LOG_FATAL
};




class Logger{
public:
    template<typename Wt = FileLogWriter> // 默认使用FileWriter
    Logger(std::string name, LOG_LEVEL level = LOG_INFO, std::initializer_list<Format&&> format_list)
        : m_name(name), m_writer(std::make_shared<Wt>()) {
            for(auto pFormat : format_list){
                m_formats.emplace_back(pFormat);
            }
        }

    template<typename T, typename... Args>
    void log(LOG_LEVEL level, std::string module_name, int line, const T* format, Args... args){
        if(level >= m_level){
            std::stringstream ss;
            ss << module_name << ": " << line<<" ";
            char message[100] = {0};
            vnsprintf(mesage, sizeof(message), format, args...);
            ss<< message;
            m_writer->write(ss.str());
        }
    }

protected:
    LOG_LEVEL m_level;
    std::string m_name;
    std::vector<Format&&> m_formats; // 不知道这样写会不会出错
    std::shared_ptr<LogWriter> m_writer;
}

}