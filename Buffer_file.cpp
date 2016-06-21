#include "Buffer_file.h"

Buffer_file:: Buffer_file(const char* file):infile(file,ios::in|ios::out), eof_flag(false), getter(0), putter(0)
{
	file_name = file;
}

Buffer_file:: ~Buffer_file()
{
	infile.close();
	truncate(file_name, putter);
} 

void Buffer_file:: do_over(char& ch)
{
	que.push_front(ch);
}

Buffer_file& Buffer_file:: get(char &ch)
{
	if(!que.empty())
	{
		ch = que.front();
		que.pop_front();
	}
	else
	{
		infile.seekg(getter);
		infile.get(ch);
		if(infile.eof())
		{
			eof_flag = true;
			infile.clear();
		}	
		++getter;	
	}
	
}

void Buffer_file:: put(char ch)
{
        char c;
	if(getter == putter && !eof_flag)
	{
		infile.seekg(getter);
		infile.get(c); 
		if(infile.eof())
		{
			eof_flag = true;
			infile.clear();
		}

		if(eof_flag==false)
		{
			que.push_back(c);
			++getter;
		}
	}	
	infile.seekp(putter);	
	infile.put(ch);
	++putter;
}

bool Buffer_file:: eof()
{
	if(!que.empty())
	{
		return false;
	}
	
	else
	return eof_flag;
}






















