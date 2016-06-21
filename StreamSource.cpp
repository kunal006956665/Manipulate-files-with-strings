#include "StreamSource.h"

StreamSource:: StreamSource(string s, string rep, const char* file):buffer(file), search(s), repl(rep), rep_count(0), search_origin(0), search_count(0), string_length(0), search_get(false), rep_get(false)
{}

StreamSource:: ~StreamSource()
{}

bool StreamSource:: currently_replacing()
{
	return rep_get;
}

void StreamSource:: matched_search_string()
{
	string_length = repl.length();
	rep_count = repl.length();
}

bool StreamSource:: eof()
{
	if(search_get == true || rep_get == true)
	return false;
	
	else	
	return buffer.eof();
}

StreamSource& StreamSource :: get(char &ch)
{
	if(search_count > 0)
	{
		ch = search[string_length - search_count --];
		search_get = true;
	}
	else if(rep_count > 0)
	{
		ch = repl[string_length - rep_count --];
		rep_get = true;
	}
	else
	{
		search_get = rep_get = false;
		buffer.get(ch);
	}
	return *this;
}

void StreamSource:: put(char &ch)
{	
	buffer.put(ch);
}
void StreamSource:: found_partial_match(int match_count, char ch)
{
	if(search_get)
	{
		++search_origin;
	}
	else
	{
		search_origin = 0;
		string_length = match_count;
		buffer.do_over(ch);
	}
	put(search[search_origin]);
	search_count = string_length - 1 - search_origin;
}










