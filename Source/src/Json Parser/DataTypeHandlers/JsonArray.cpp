#include "JsonArrayItem.h"

JsonReader::JsonItem * JsonReader::JsonArrayItem::GetValue()
{
	return this;
}

JsonReader::JsonItem * JsonReader::JsonArrayItem::GetFirstChild()
{
	it = m_value.begin();
	return *it;
}

JsonReader::JsonItem * JsonReader::JsonArrayItem::GetNextChild()
{
	std::vector<JsonItem*>::iterator end = m_value.end() - 1;
	if (it != end)
	{
		++it;
		return *it;
	}
	else
		return *it;
}

JsonReader::JsonItem * JsonReader::JsonArrayItem::AddChild(JsonItem* jsonItem)
{
	m_value.push_back(jsonItem);
	return jsonItem;
}

JsonReader::JsonItem * JsonReader::JsonArrayItem::GetChildAt(int index)
{
	if (index <= m_value.size() - 1)
	{
		return m_value.at(index);
	}
	else
		return nullptr;
}

int JsonReader::JsonArrayItem::asInt()
{
	return 0;
}

double JsonReader::JsonArrayItem::asDouble()
{
	return 0.0;
}

bool JsonReader::JsonArrayItem::asBool()
{
	return false;
}

std::string JsonReader::JsonArrayItem::asString()
{
	return std::string();
}

int JsonReader::JsonArrayItem::size()
{
	return m_value.size();
}
