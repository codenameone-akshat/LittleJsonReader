#include"src\Json Parser\JsonParser.h"
#include<iostream>

int main()
{
	JsonReader::JsonDocument doc;
	JsonReader::JsonItem* root;
	doc.LoadDocument("File2.json");

	root = doc.Parse();

	JsonReader::JsonItem* item = root->GetFirstChild();

	int i = 0;

	while (i < root->size())
	{
		std::cout << item->GetValue()->asString() << std::endl;
		item = root->GetNextChild();
		++i;
	}

	system("pause");
}