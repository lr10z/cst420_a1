//
// CST 420 - Assignment # 1
//
// Author: Leander Rodriguez
//
// File: dictionary.h
//
// Due date:  Sunday, July 7th by 11:59pm
//


#ifndef  dictionary_H
#define  dictionary_H

#include  <string>
#include  <vector>

using namespace std;


//
// Dictionary class declaration
//
class Dictionary
{

  public:
	  
	  //
	  // Constructor
	  //
	  Dictionary( const string  &filename, const string word );

	
  private:

	  //
	  // Member variables
	  //
	  string m_userWord;
	  string m_anagram;

	  vector<string> m_dictionary;
	  vector<string> m_storedAnagrams;


	  //
	  // Methods
	  //
	  const void permuteUSERword();
	  const void findAnagrams();
	  const void displayAnagrams() const;

};


#endif




