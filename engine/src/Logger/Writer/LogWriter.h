#include<string>
#include<fstream>
namespace xengine{

class LogWriter{
public:
    /**
     * 每次写一行数据到Writer目标
     * **/
    virtual bool write(std::string)  = 0;
};


class FileLogWriter: LogWriter{
public:
    FileLogWriter(std::string filename) : m_fileName(filename){
        m_fileStream.open(filename);
    }

    virtual bool write(std::string message) override{
        m_fileStream << message<<std::endl; // 自动换行
    }
    ~FileLogWriter(){
        if(m_fileStream.is_open()){
            m_fileStream.close();
        }
    }

private:
    std::string m_fileName;
    std::fstream m_fileStream;
};

}