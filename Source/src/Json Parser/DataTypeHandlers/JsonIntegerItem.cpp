#include "JsonIntegerItem.h"

JsonReader::JsonIntItem::JsonIntItem(std::string v)
{
	if (typeCheck.typeof(v) == "Integer")
		m_value = std::stoi(v);
	else
		m_value = 0;
}

JsonReader::JsonItem * JsonReader::JsonIntItem::GetValue()
{
	return this;
}

JsonReader::JsonItem * JsonReader::JsonIntItem::GetFirstChild()
{
	return nullptr;
}

JsonReader::JsonItem * JsonReader::JsonIntItem::GetNextChild()
{
	return nullptr;
}

JsonReader::JsonItem * JsonReader::JsonIntItem::AddChild(JsonItem* jsonItem)
{
	return nullptr;
}

JsonReader::JsonItem * JsonReader::JsonIntItem::GetChildAt(int index)
{
	return nullptr;
}

int JsonReader::JsonIntItem::asInt()
{
	return m_value;
}

double JsonReader::JsonIntItem::asDouble()
{
	return m_value;
}

bool JsonReader::JsonIntItem::asBool()
{
	if (m_value == 1)
		return true;
	else
		return false;
}

std::string JsonReader::JsonIntItem::asString()
{
	return std::to_string(m_value);
}

int JsonReader::JsonIntItem::size()
{
	return 0;
}
