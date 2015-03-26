//
// CST 420 - Assignment # 1
//
// Author: Leander Rodriguez
//
// File: dictionary.cpp
//
// Due date:  Sunday, July 7th by 11:59pm
//



#include  <iostream>
#include  <fstream>
#include  <algorithm>
#include  "dictionary.h"



//
// Constructor
//
Dictionary::Dictionary( const string  &filename, const string word ) :
	m_userWord( word )
{

	//
	// File is opened
	//
	ifstream in( filename );

	
	//
	// Check to see if file opened
	//
	if( !in )
	{

		cout  <<  "Error opening file '"
			  <<  filename
			  <<  "'"
			  <<  endl; 

		exit( EXIT_FAILURE );

	}
	else
	{

		//
		// Dictionary entries from file are read in and stored
		// 
		string entry;


		while( getline(in, entry) )
		{
			m_dictionary.push_back( entry );
		}



		//
		// Checks if user's word exists in the dictionary; if it does exist, 
		// program will look for anagrams of the user's word
		//
		if( !binary_search( m_dictionary.begin(), m_dictionary.end(), m_userWord ) )
		{

			cout  <<  "  "  
				  <<  m_userWord  
				  <<  " is not a valid word"  
				  <<  endl  
				  <<  endl;  

		}
		else
		{

			permuteUSERword();

			//
			// File is closed
			//
			in.close();

		}

	}

}


const void Dictionary::permuteUSERword()
{

	//
	// pWord will be the string that is "permuted".
	//
	string  pWord( m_userWord );


	//
	// Loop through all the permutations. The loop ends when the
	// pword is same as user's word.
	//
	// NOTE: there is an "issue" in this program in that all the permutations
	// will not be generated if the word contains the same character
	// more than once. For example, try the word "pool".
	//
	do
	{

		m_anagram = pWord;
		
		findAnagrams();

		prev_permutation( pWord.begin(), pWord.end() );


	}  while( pWord != m_userWord );


	displayAnagrams();

}



//
// Checks if permutations of user's word are anagrams in the dictionary,
// and stores them
//
const void Dictionary::findAnagrams() 
{
	
	if( binary_search( m_dictionary.begin(), m_dictionary.end(), m_anagram ) )
	{

		if( m_userWord != m_anagram )
		{
				m_storedAnagrams.push_back( m_anagram );
		}

	}

}



//
// Displays existing anagrams of the user's word
//
const void Dictionary::displayAnagrams() const
{
	
	if( m_storedAnagrams.empty() )
	{

		cout  <<  "  "  <<  m_userWord  <<  " does not have any anagrams";

	}
	else
	{

		cout <<  "  "  <<  "Anagram: ";

	
		for (size_t n = 0; n < m_storedAnagrams.size(); n++)
		{
			cout << m_storedAnagrams[ n ] << " ";
		}
		
	}

	cout  <<  endl  <<  endl;

}
