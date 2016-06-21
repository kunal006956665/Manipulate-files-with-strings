#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <queue>
#include "Buffer_file.h"

using namespace std;

class StreamSource
{
 private:
	Buffer_file buffer;
	string repl, search;
	int rep_count;
	int search_origin;
	int search_count;
	int string_length;
	bool search_get;
	bool rep_get;
 public:
	StreamSource(string search, string rep, const char* file);
	~StreamSource();
	bool currently_replacing();
	void matched_search_string();
	bool eof();
	StreamSource &get(char &ch);
	void put(char &ch);
	void found_partial_match(int c, char ch);
};
