#pragma once
#include"TypeCheck.hpp"

#include<stack>
#include<vector>
#include<string>
#include<fstream>
#include<iostream>
#include<algorithm>

namespace JsonReader
{
	/*!
	\brief Abstract class for different data types
	*/
	class JsonItem
	{
	public:
		std::string m_key; //!< key for the attributes
				
		/*!
		\brief returns the value of the object
		*/
		virtual JsonItem*		GetValue() = 0;
		
		/*!
		\brief returns the iterator pointer of the first child
		*/
		virtual JsonItem*		GetFirstChild() = 0;

		/*!
		\brief returns the iterator pointer of the next child if there, else returns the same
		*/
		virtual JsonItem*		GetNextChild() = 0;

		/*!
		\brief adds val to the root vector and returns
		\param jsonItem to be added
		*/
		virtual JsonItem*		AddChild(JsonItem* jsonItem) = 0;

		/*!
		\brief returns the child at the index given if there, else null
		\param index
		*/
		virtual JsonItem*		GetChildAt(int index) = 0;

		/*!
		\brief returns the value as an integer
		*/
		virtual int				asInt() = 0;

		/*!
		\brief returns the value as an double
		*/
		virtual double			asDouble() = 0;

		/*!
		\brief returns the value as an boolean
		*/
		virtual bool			asBool() = 0;

		/*!
		\brief returns the value as an string
		*/
		virtual std::string		asString() = 0;

		/*!
		\brief returns the size of the m_val vector
		*/
		virtual int				size() = 0;
	};	
}