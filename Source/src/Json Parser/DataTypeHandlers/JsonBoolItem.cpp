#include "JsonBoolItem.h"

JsonReader::JsonBoolItem::JsonBoolItem(std::string v)
{
	if (typeCheck.typeof(v) == "Boolean")
	{
		if (v == "true" || v == "True")
			m_value = true;
		else
			m_value = false;
	}
	else
		m_value = false;
}

JsonReader::JsonItem * JsonReader::JsonBoolItem::GetValue()
{
	return this;
}

JsonReader::JsonItem * JsonReader::JsonBoolItem::GetFirstChild()
{
	return nullptr;
}

JsonReader::JsonItem * JsonReader::JsonBoolItem::GetNextChild()
{
	return nullptr;
}

JsonReader::JsonItem * JsonReader::JsonBoolItem::AddChild(JsonItem* jsonItem)
{
	return nullptr;
}

JsonReader::JsonItem * JsonReader::JsonBoolItem::GetChildAt(int index)
{
	return nullptr;
}

int JsonReader::JsonBoolItem::asInt()
{
	if (m_value)
		return 1;
	else
		return 0;
}

double JsonReader::JsonBoolItem::asDouble()
{
	if (m_value)
		return 1;
	else
		return 0;
}

bool JsonReader::JsonBoolItem::asBool()
{
	return m_value;
}

std::string JsonReader::JsonBoolItem::asString()
{
	if (m_value)
		return "true";
	else
		return "false";
}

int JsonReader::JsonBoolItem::size()
{
	return 0;
}
