#include "JsonStringItem.h"

JsonReader::JsonStringItem::JsonStringItem(std::string v): m_value(v) {}

inline JsonReader::JsonItem* JsonReader::JsonStringItem::GetValue()
{
	return this;
}

JsonReader::JsonItem * JsonReader::JsonStringItem::GetFirstChild()
{
	return nullptr;
}

JsonReader::JsonItem * JsonReader::JsonStringItem::GetNextChild()
{
	return nullptr;
}

JsonReader::JsonItem * JsonReader::JsonStringItem::AddChild(JsonItem* jsonItem)
{
	return nullptr;
}

JsonReader::JsonItem * JsonReader::JsonStringItem::GetChildAt(int index)
{
	return nullptr;
}

int JsonReader::JsonStringItem::asInt()
{
	if (m_value.find_first_not_of(".0123456789") == std::string::npos)
		return std::stoi(m_value);
	else
		return 0;
}

double JsonReader::JsonStringItem::asDouble()
{
	if (m_value.find_first_not_of(".0123456789") == std::string::npos)
		return std::stod(m_value);

	else
		return 0.0f;
}

bool JsonReader::JsonStringItem::asBool()
{
	if (m_value == "true")
		return true;
	else if (m_value == "false")
		return false;
	else
		return false;
}

inline std::string JsonReader::JsonStringItem::asString() {return(m_value);}

int JsonReader::JsonStringItem::size()
{
	return 0;
}
