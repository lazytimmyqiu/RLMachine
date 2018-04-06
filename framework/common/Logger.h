#pragma once

#include <fstream>
#include <iostream>
#include <string>

#include "common.h"

using namespce std;

namespace TLib {    // 自己的轮子库


// 一个具有通用性的Logger
// 能够设置输入输出流
// 能够设置LogLevel
// 能够强制flush
// 打印出一般的额外信息


// log level 
enum LogLevel {INFO, WARN, ERROR, FATAL};


// This class is largely imitating the logging class in xLearn: 
// https://github.com/aksnzhy/xlearn/blob/master/src/base/logging.h
class Logger
{
public:
  // create a logger object with specific log level, INFO would be the default
  Logger(LogLevel level = INFO) : level_(level) {}
  
  // invoke abort() if level_ is FATAL for debugging purposes
  ~Logger();

  // static method that intialize the log output stream
  static void InitLogger(const string& info_log_file,
                         const string& warn_log_file,
                         const string& erro_log_file);

  // Get output stream for specific log level
  static ofstream& GetStream(LogLevel level);

  // Output regular information and ready to receive log infos
  static ofstream& Start(LogLevel level, 
                         const string& file, 
                         int32_t line, 
                         const string& func);
  
private:
  // static member of output stream
  static ofstream  info_log_stream_;
  static ofstream  warn_log_stream_;
  static ofstream  erro_log_stream_;

  // Log level
  LogLevel level_;    
};

// Macro for easy to use
#define TLOG(level)                 \
  Logger(level).Start(level, __FILE__, __LINE__, __FUNCTION__) 
}
