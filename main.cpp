//
// CST 420 - Assignment # 1
//
// Author: Leander Rodriguez
//
// File: main.cpp
//
// Due date:  Sunday, July 7th by 11:59pm
//



#include  <iostream>
#include  "dictionary.h"


//
// Main program
//
int  main()
{
	string  filename, 
			word;
	
	
	//
	// Prompt user to enter filename
	//
	cout  <<  "Enter dictionary file name: ";

	getline( cin, filename );

	cout <<  endl;


	//
	// Continously prompts user for a word, and creates 
	// a Dictionary object until user enters the word "quit"
	//
	for( ; ; )
	{

		cout  <<  "Enter a word: ";
		getline( cin, word );


		if( word == "quit" )
		{
			exit( EXIT_SUCCESS );
		}


		Dictionary dict( filename, word );
	  
	}


  return  0;

}