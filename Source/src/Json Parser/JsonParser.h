#pragma once
#include"DataTypeHandlers\TypeCheck.hpp"
#include"DataTypeHandlers\JsonStringItem.h"
#include"DataTypeHandlers\JsonDoubleItem.h"
#include"DataTypeHandlers\JsonBoolItem.h"
#include"DataTypeHandlers\JsonIntegerItem.h"
#include"DataTypeHandlers\JsonArrayItem.h"
#include"DataTypeHandlers\JsonObjectItem.h"

namespace JsonReader
{
	/*!
	\brief JsonDocumentClass
	*/
	class JsonDocument
	{
	public:
		/*!
		\brief Opens the json 
		\param Json Name
		*/
		void			LoadDocument(std::string fileName);
		
		/*!
		\brief Parses Json and stores it every
		*/
		JsonItem*		Parse();
		
		/*
		\brief Object Operations
		*/
		JsonItem*		Object();
		
		/*!
		\brief Pair Operations
		*/
		JsonItem*		Pair();
		
		/*
		\brief Array Operations
		*/
		JsonItem*		Array();
		
		/*!
		\brief Value Operations
		*/
		JsonItem*		Value();
		
	private:
		std::string				m_docString; //!<string that stores the json
		std::stack<char>		m_paranthesis;	//!<stack that stores { 
		std::stack<char>		m_bracket;	//!<stack that stores [
		
		TypeCheck type;	//!<type check var
	};
}