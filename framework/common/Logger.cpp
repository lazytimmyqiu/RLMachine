#include <ctime>
#include <cstdlib>
#include <string>
#include "Logger.h"

using namespace std;
using namespace TLib;


ofstream  Logger::info_log_stream_;
ofstream  Logger::warn_log_stream_;
ofstream  Logger::erro_log_stream_;

// flush the stream
// if level is FATAL, abort() to trigger a coredump
Logger::~Logger()
{
  GetStream(level_) << "\n" << flush;
  if (level_ == FATAL) {
    info_log_stream_.close();
    warn_log_stream_.close();
    erro_log_stream_.close();
    abort();
  }
}


ostream& Logger::GetStream(LogLevel level)
{
  if (level == INFO)
    return info_log_stream_.is_open() ? info_log_stream_ : cout;
  else if (level == WARN)
    return warn_log_stream_.is_open() ? warn_log_stream_ : cerr;
  else if (level == ERROR || level == FATAL)
    return erro_log_stream_.is_open() ? erro_log_stream_ : cerr;
  else
    return cout;
}

// log header info:
// + time
// + file
// + line
// + func
ostream& Logger::Start(LogLevel level, 
                       const string& file,
                       int32_t line,
                       const string& func)
{
  time_t tm;
  time(&tm);
  char s_time[32];
  ctime_r(&tm, s_time);

  GetStream(level) << s_time
                   << "[" << file << ": "
                   << line << "]"
                   << "(" << func << ") " << flush;
}


void Logger::InitLogger(const string& info_log_file,
                        const string& warn_log_file,
                        const string& erro_log_file)
{
  Logger::info_log_stream_.open(info_log_file.c_str());
  Logger::warn_log_stream_.open(warn_log_file.c_str());
  Logger::erro_log_stream_.open(erro_log_file.c_str());

  bool b_fail = false;
  if (!info_log_stream_.is_open()) {
    cerr << "Create info log file failed: " << info_log_file << endl;
    b_fail = true;
  }

  if (!warn_log_stream_.is_open()) {
    cerr << "Create warn log file failed: " << warn_log_file << endl;
    b_fail = true;

  }

  if (!warn_log_stream_.is_open()) {
    cerr << "Create erro log file failed: " << erro_log_file << endl;
    b_fail = true;
  }

  if (b_fail) {
    exit(0);
  }
}
              
