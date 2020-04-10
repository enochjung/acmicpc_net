#include <iostream>
#include <string>

using namespace std;

string str;

string sentence();
string noun_phrase();
string modified_noun();
string modifier();
string present_rel();
string past_rel();
string present_person();
string past_person();
string noun();
string present_verb();
string past_verb();
string article();
string adjective();
string adverb();

char a_to_A(char x)
{
	return x-'a'+'A';
}

void print(string sentence)
{
	cout << a_to_A(sentence.at(0));
	cout << sentence.substr(1, sentence.length()-1).c_str();
}

int taunt()
{
	static int x = -1;
	++x;
	if(x%4 == 0)
		print(sentence());
	else if(x%4 == 1)
	{
		taunt();
		printf(" ");
		print(sentence());
		return 2;
	}
	else if(x%4 == 2)
		print(noun()+"!");
	else
		print(sentence());
	return 1;
}

string sentence()
{
	static int x = -1;
	++x;
	if(x%3 == 0)
		return past_rel()+" "+noun_phrase();
	else if(x%3 == 1)
		return present_rel()+" "+noun_phrase();
	else
		return past_rel()+" "+article()+" "+noun();
}

string noun_phrase()
{
	return article()+" "+modified_noun();
}

string modified_noun()
{
	static int x = -1;
	++x;
	if(x%2 == 0)
		return noun();
	else
		return modifier()+" "+noun();
}

string modifier()
{
	static int x = -1;
	++x;
	if(x%2 == 0)
		return adjective();
	else
		return adverb()+" "+adjective();
}

string present_rel()
{
	return "your "+present_person()+" "+present_verb();
}

string past_rel()
{
	return "your "+past_person()+" "+past_verb();
}

string present_person()
{
	static int x = -1;
	++x;
	if(x%3 == 0)
		return "steed";
	else if(x%3 == 1)
		return "king";
	else
		return "first-born";
}

string past_person()
{
	static int x = -1;
	++x;
	if(x%5 == 0)
		return "mother";
	else if(x%5 == 1)
		return "father";
	else if(x%5 == 2)
		return "grandmother";
	else if(x%5 == 3)
		return "grandfather";
	else
		return "godfather";
}

string noun()
{
	static int x = -1;
	++x;
	if(x%11 == 0)
		return "hamster";
	else if(x%11 == 1)
		return "coconut";
	else if(x%11 == 2)
		return "duck";
	else if(x%11 == 3)
		return "herring";
	else if(x%11 == 4)
		return "newt";
	else if(x%11 == 5)
		return "peril";
	else if(x%11 == 6)
		return "chicken";
	else if(x%11 == 7)
		return "vole";
	else if(x%11 == 8)
		return "parrot";
	else if(x%11 == 9)
		return "mouse";
	else
		return "twit";
}

string present_verb()
{
	static int x = -1;
	++x;
	if(x%2 == 0)
		return "is";
	else
		return "masquerades as";
}

string past_verb()
{
	static int x = -1;
	++x;
	if(x%2 == 0)
		return "was";
	else
		return "personified";
}

string article()
{
	static int x = -1;
	++x;
	return "a";
}

string adjective()
{
	static int x = -1;
	++x;
	if(x%7 == 0)
		return "silly";
	else if(x%7 == 1)
		return "wicked";
	else if(x%7 == 2)
		return "sordid";
	else if(x%7 == 3)
		return "naughty";
	else if(x%7 == 4)
		return "repulsive";
	else if(x%7 == 5)
		return "malodorous";
	else
		return "ill-tempered";
}

string adverb()
{
	static int x = -1;
	++x;
	if(x%5 == 0)
		return "conspicuosly";
	else if(x%5 == 1)
		return "categorically";
	else if(x%5 == 2)
		return "positively";
	else if(x%5 == 3)
		return "cruelly";
	else
		return "incontrovertibly";
}

int main()
{
	while(1)
	{
		getline(cin, str);
		while(1)
		{
			size_t found = str.find("  ");
			if(found == str.npos)
				break;
			str.replace(found, 2, " ");
		}
		cout << "Knight: " << str << endl;
		cout << "Taunter: ";
		taunt();
		cout << "." << endl << endl;
	}
	return 0;
}
