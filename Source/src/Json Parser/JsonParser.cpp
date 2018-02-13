#include "JsonParser.h"
#include <typeinfo>

void JsonReader::JsonDocument::LoadDocument(std::string fileName)
{
	std::ifstream file("Resource/" + fileName, std::ios::in);

	char ch;
	while (file.get(ch))
	{
		if (ch != ' ' && ch != '\t' && ch != '\n' && ch != '"') //make the json format to compact
			m_docString.push_back(ch);
	}
	m_docString.shrink_to_fit();

	bool Validity_Check = (m_docString.back() == ((char)(m_docString.front() + 2)));
	//custom assert
	if (!Validity_Check)
	{
		std::cerr << "\nAssertion Failed....\nInvalid Json\nBracket Mismatch!";
		abort();
	}
}

//returns root of JsonItem*
JsonReader::JsonItem* JsonReader::JsonDocument::Parse()
{
	JsonItem* root;

	if (m_docString[0] == '{')
		root = new JsonObjectItem();
	else
		root = new JsonArrayItem();

	root = Value();

	return root;
}

JsonReader::JsonItem* JsonReader::JsonDocument::Object()
{

	JsonItem* parentObject = new JsonObjectItem();
	JsonItem* tempObj = new JsonObjectItem();

	while (!m_docString.empty())
	{
		char ch = m_docString[0];
		m_docString.erase(0, 1);

		switch (ch)
		{
			case '{':
			{
				if (m_docString[0] == '}')
					return nullptr;
				tempObj = new JsonObjectItem();
				m_paranthesis.push(ch);
				tempObj = Pair();
				break;
			}
			case '}':
			{
				if (m_paranthesis.top() == '{')
				{
					m_paranthesis.pop();
					parentObject = tempObj;	//fixed from parentobject.addchild();
					return parentObject;
				}
				else
				{
					std::cerr << "\nAssertion Failed....\nInvalid Json\n' { ' or ' } ' Expected.";
					abort();
				}
				break;
			}
			case ',':	//store object 
			{
				tempObj = Object();
				parentObject->AddChild(tempObj);
				break;
			}
			default:
			{
				std::cerr << "\nAssertion Failed....\nInvalid Json\n' { ' or ' } ' Expected.";
				abort();
				break;
			}
		}
	}
}

JsonReader::JsonItem* JsonReader::JsonDocument::Pair()
{
	JsonItem* parentPairList = new JsonObjectItem();

	std::string keystr;

	while (!m_docString.empty())
	{
		char ch = m_docString[0];
		switch (ch)
		{
			case ':': //store key
			{
				m_docString.erase(0, 1);
				JsonItem* tempPair = Value(); //define tempPair
				tempPair->m_key = keystr;
				parentPairList->AddChild(tempPair);

				keystr.clear(); //clear key after return from value and push to pair list
				break;
			}
			case '}':
			{
				return parentPairList;
				break;
			}
			case',':
			{
				m_docString.erase(0, 1);
				break;
			}
			default:
			{
				m_docString.erase(0, 1);
				keystr.push_back(ch);
				break;
			}
		}
	}
}

JsonReader::JsonItem* JsonReader::JsonDocument::Array()
{
	JsonItem* arrayItem = new JsonArrayItem();
	JsonItem* tempItem = new JsonArrayItem();
	while (!m_docString.empty())
	{
		char ch = m_docString[0];

		switch (ch)
		{
			case '[':
			{
				m_docString.erase(0, 1);
				if (m_docString[0] == ']')
					return nullptr;

				m_bracket.push(ch);

				if (m_docString[0] == '{')
				{
					tempItem = new JsonObjectItem();
					tempItem = Object();
					return tempItem;
				}
				else if (m_docString[0] == '[')
				{
					//JsonItem *tempArray = new JsonArrayItem();
					tempItem = new JsonArrayItem();
					tempItem = Array();
					return tempItem;
				}
				else
				{
					tempItem->AddChild(Value());
				}
				break;
			}
			case ']':
			{
				m_docString.erase(0, 1);
				if (m_bracket.top() == '[')
				{
					m_bracket.pop();
					arrayItem = tempItem;
					return arrayItem;
				}
				else
				{
					std::cerr << "\nAssertion Failed....\nInvalid Json\n' [ ' or ' ] ' Expected.";
					abort();
				}
				break;
			}
			default:
				tempItem->AddChild(Value());
				break;
		}
	}
}


JsonReader::JsonItem* JsonReader::JsonDocument::Value()
{
	JsonItem *parentVal;
	std::string valuestr;

	while (!m_docString.empty())
	{
		char ch = m_docString[0];
		switch (ch)
		{
			case '{':
			{
				parentVal = Object();
				return parentVal;
				break;
			}
			case '[':
			{
				parentVal = Array();
				return parentVal;
				break;
			}
			case ',':
			{
				m_docString.erase(0, 1);
				std::string tempstr;
				tempstr = type.typeof(valuestr);

				if (tempstr == "String")
				{
					JsonItem* item = new JsonStringItem(valuestr);
					return item;
				}
				else if (tempstr == "Integer")
				{
					JsonItem* item = new JsonIntItem(valuestr);
					return item;
				}
				else if (tempstr == "Double")
				{
					JsonItem* item = new JsonDoubleItem(valuestr);
					return item;
				}
				else if (tempstr == "Bool")
				{
					JsonItem* item = new JsonBoolItem(valuestr);
					return item;
				}
				break;
			}
			case '}':
			{
				std::string tempstr;
				tempstr = type.typeof(valuestr);

				if (tempstr == "String")
				{
					JsonItem* item = new JsonStringItem(valuestr);
					return item;
				}
				else if (tempstr == "Integer")
				{
					JsonItem* item = new JsonIntItem(valuestr);
					return item;
				}
				else if (tempstr == "Double")
				{
					JsonItem* item = new JsonDoubleItem(valuestr);
					return item;
				}
				else if (tempstr == "Bool")
				{
					JsonItem* item = new JsonBoolItem(valuestr);
					return item;
				}

				break;
			}
			case ']':
			{
				std::string tempstr;
				tempstr = type.typeof(valuestr);

				if (tempstr == "String")
				{
					JsonItem* item = new JsonStringItem(valuestr);
					return item;
				}
				else if (tempstr == "Integer")
				{
					JsonItem* item = new JsonIntItem(valuestr);
					return item;
				}
				else if (tempstr == "Double")
				{
					JsonItem* item = new JsonDoubleItem(valuestr);
					return item;
				}
				else if (tempstr == "Bool")
				{
					JsonItem* item = new JsonBoolItem(valuestr);
					return item;
				}

				break;
			}
			default:
			{
				m_docString.erase(0, 1);
				valuestr.push_back(ch);
				break;
			}
		}
	}
}
