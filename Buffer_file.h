#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <deque>

using namespace std;

class Buffer_file : public fstream
{
 private:
	fstream infile;
	string file;
	int getter;
	int putter;
	bool eof_flag;
	const char* file_name;
	deque<char> que;
 public:
	Buffer_file();
	Buffer_file(const char*);
	~Buffer_file();
	void do_over(char& ch);
	void put(char ch);
	Buffer_file &get(char &ch);
	bool eof();
};
