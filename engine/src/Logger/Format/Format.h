#include<string>
#include<chrono>
#include<time.h>
#include<thread>
#include<sstream>
namespace xengine{

class Format{
public:
    virtual std::string format() = 0;
};


class MessageFormat : public Format{
public:
    MessageFormat(std::string message): m_message(message){
    }

    virtual std::string format() override {return m_message;}

private:
    std::string m_message;
};


class TimeFormat : public Format{
public:
    virtual std::string format() override{
       time_t t;
       time(&t);
       return std::string(ctime(&t));
    }
};

class ThreadFormat: public Format{
public:
    virtual std::string format() override{
         std::stringstream ss;
         ss << std::this_thread::get_id();
         return ss.str();
    }
};

class IntFormat : public Format{
public:
    IntFormat(int id):m_value(id){}
    virtual std::string format() override{
        return std::to_string(m_value);
    }

private:
    int m_value;
};
class LineFormat : public IntFormat{};

}