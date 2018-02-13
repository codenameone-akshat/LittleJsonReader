#pragma once
#include"JsonItem.h"
#include"TypeCheck.hpp"

namespace JsonReader
{
	/*!
	\brief JsonIntItem class
	*/
	class JsonIntItem : public JsonReader::JsonItem
	{
		int m_value;		//!< value of the key of Json
	public:
		/*!
		\brief parameterized constructor that sets the value
		*/
		JsonIntItem(std::string v);


		/*!
		\brief returns the value of the object
		*/
		JsonItem*		GetValue()	override;

		/*!
		\brief returns the iterator pointer of the first child
		*/
		JsonItem*		GetFirstChild() override;

		/*!
		\brief returns the iterator pointer of the next child if there, else returns the same
		*/
		JsonItem*		GetNextChild() override;

		/*!
		\brief adds val to the root vector and returns
		\param jsonItem to be added
		*/
		JsonItem*		AddChild(JsonItem* jsonItem) override;

		/*!
		\brief returns the child at the index given if there, else null
		\param index
		*/
		JsonItem*		GetChildAt(int index) override;

		/*!
		\brief returns the value as an integer
		*/
		int				asInt()		override;

		/*!
		\brief returns the value as an double
		*/
		double			asDouble()	override;

		/*!
		\brief returns the value as an boolean
		*/
		bool			asBool()	override;

		/*!
		\brief returns the value as an string
		*/
		std::string		asString()	override;

		/*!
		\brief returns the size of the m_val vector
		*/
		int				size() override;

		JsonReader::TypeCheck typeCheck; //!< typecheck variable to check the data type of the passed string
	};
}