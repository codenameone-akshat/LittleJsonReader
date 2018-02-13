#include "JsonObjectItem.h"

JsonReader::JsonItem * JsonReader::JsonObjectItem::GetValue()
{
	return this;
}

JsonReader::JsonItem * JsonReader::JsonObjectItem::GetFirstChild()
{
	it = m_value.begin();
	return *it;
}

JsonReader::JsonItem * JsonReader::JsonObjectItem::GetNextChild()
{
	std::vector<JsonItem*>::iterator end = m_value.end()-1;
	if (it != end)
	{
		++it;
		return *it;
	}
	else
		return *it;
}

JsonReader::JsonItem * JsonReader::JsonObjectItem::AddChild(JsonItem* jsonItem)
{
	m_value.push_back(jsonItem);
	return jsonItem;
}

JsonReader::JsonItem * JsonReader::JsonObjectItem::GetChildAt(int index)
{
	if (index <= m_value.size() - 1)
	{
		return m_value.at(index);
	}
	else
		return nullptr;
}

int JsonReader::JsonObjectItem::asInt()
{
	return 0;
}

double JsonReader::JsonObjectItem::asDouble()
{
	return 0.0;
}

bool JsonReader::JsonObjectItem::asBool()
{
	return false;
}

std::string JsonReader::JsonObjectItem::asString()
{
	return std::string();
}

int JsonReader::JsonObjectItem::size()
{
	return m_value.size();
}
