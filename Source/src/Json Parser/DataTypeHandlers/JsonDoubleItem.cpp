#include "JsonDoubleItem.h"

JsonReader::JsonDoubleItem::JsonDoubleItem(std::string v)
{
	if (typeCheck.typeof(v) == "Double" || typeCheck.typeof(v) == "Integer")
		m_value = std::stod(v);
	else
		m_value = 0;
}

JsonReader::JsonItem * JsonReader::JsonDoubleItem::GetValue()
{
	return this;
}

JsonReader::JsonItem * JsonReader::JsonDoubleItem::GetFirstChild()
{
	return nullptr;
}

JsonReader::JsonItem * JsonReader::JsonDoubleItem::GetNextChild()
{
	return nullptr;
}

JsonReader::JsonItem * JsonReader::JsonDoubleItem::AddChild(JsonItem* jsonItem)
{
	return nullptr;
}

JsonReader::JsonItem * JsonReader::JsonDoubleItem::GetChildAt(int index)
{
	return nullptr;
}

int JsonReader::JsonDoubleItem::asInt()
{
	return m_value;
}

double JsonReader::JsonDoubleItem::asDouble()
{
	return m_value;
}

bool JsonReader::JsonDoubleItem::asBool()
{
	if (m_value == 1)
		return true;
	else
		return false;
}

std::string JsonReader::JsonDoubleItem::asString()
{
	return std::to_string(m_value);
}

int JsonReader::JsonDoubleItem::size()
{
	return 0;
}
