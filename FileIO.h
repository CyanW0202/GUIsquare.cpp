#pragma once
#include "Simulator.h"
#include "UELogData.h"
#include <cstring>
#include <map> //maps are like dictionaries in C++
//C++ connector libraries
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

class DataBase{
private:
	sql::Driver *driver;
	sql::Connection *con;

public:
	DataBase();//constructor that has the IP, password, username...etc.
	sql::Connection* connect_db();//use this function to reuse connection
	~DataBase();//delete the connection at the end, 
};


class FileIO : private Simulator
{
private:
	static char	filePathSlash;
	static bool	splitLogFiles;
	static uint32_t	logCount;
	static uint32_t	logRowCount;
	static std::string programPath;
	static std::string dataRateTableFilePath;
	static std::string currentTickCSVFilePath;
	static std::string logFilePath;
	static std::string simulationSaveName;
	static uint32_t lineCounter; //used for reading line-by-line the saved CSV file
	static DataBase simDB;
	

	static void setSimSaveFromFP(const std::string& fp);
	static void setDRTBLFP(const std::string& drtblFP);
	static bool fixDRTBLFile();

	static void incrementLogCount();
	static void incrementLogRowCount();
	static void resetLogRowCount();

public:

	//For more info on these two lines, look here: https://stackoverflow.com/questions/41319180/what-does-reinterpret-castchar-st-and-1static-castint-mean
	template<typename T> inline static const char* chPtrConv(T* p) { return reinterpret_cast<const char*>(p); }
	template<typename T> inline static char* chPtrConv_m(T* p) { return reinterpret_cast<char*>(p); }

	static const uint32_t AP_MaxLogLines;
	static const std::string defaultDRTBLName;
	static const std::string defaultCurrentTickCSV;
	static const std::string defaultMachineLearningInputCSV;
	static const std::string DRTBLSignature;
	static std::map<std::int32_t, std::int64_t> dict_time2pos; //this is a dictionary for the position of time ticks in the log


	static const std::string& getDRTBLFP();
	static const std::string& getCurrentTickCSVFP();
	static const std::string& getMachineLearningInputFP();
	static const std::string& getProgramFP();
	static const std::string getSimSaveFP();
	static const std::string& getSimName();

	static void setFPSlash(const char& fpSlash);
	static void setProgramFP(const char argZero[]);
	static void setSimulationSaveName(const std::string&);

	static void resetLog();
	static bool verifyDRTBLExistence();
	static bool writeInitalSimulationState(const std::string& addendum);
	static bool readSaveFileIntoSim();
	
	static void connect_api();//intialize the db table generator
	static void insert_db(const std::string table_n);//insert log into the table


	static bool appendLog(const uint32_t& sim);
	static bool writeCurrentTick(const uint32_t& simNum);
	static bool readLog_Init(const uint32_t& sim, int &numOfVars);
	static bool readLog_NextLine(const uint32_t& simNum, std::string* varNames);
	static bool readLog_NextLine(const uint32_t& sim, float* lineData);

	// read the line starting from the given position; returns the next position after the line is read;
	// will return NULL if eof was reached
	static std::uint64_t readLog_LineAtPosition(const uint32_t& simNum, float* lineData, std::uint64_t position);
	
};
