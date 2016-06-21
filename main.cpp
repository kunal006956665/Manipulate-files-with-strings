#include <iostream>
#include <fstream>
#include <string>
#include "StreamSource.h"

using namespace std;

int main(int argc, char** argv)
{
	
	string search = argv[1];
	string repl = argv[2];
	const char* file = argv[3];	
	StreamSource ss(search, repl, file);

	int match_count=0; 
	char ch;
	while(!ss.get(ch).eof())
	{
		if(!ss.currently_replacing() && ch==search[match_count])
  		{
    			++match_count;
    			if(match_count < search.length())
      			continue;
  		}
  		if(match_count == search.length())
		{
    			ss.matched_search_string();
			match_count=0;
		}
  		else if(match_count > 0)
    		{	
    			ss.found_partial_match(match_count, ch);
			match_count=0;
		}
  		else
		{
    			ss.put(ch);
			match_count=0;
		}
	}
	return 0;
}


