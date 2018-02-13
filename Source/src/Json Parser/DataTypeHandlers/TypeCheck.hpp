#pragma once
#include<string>

namespace JsonReader
{
	/*!
	\brief Structure for checking type of var
	*/
	struct TypeCheck
	{
		/*!
		\brief returns the type of string it is
		\param string to check
		*/
		std::string typeof(std::string val)
		{
			if (val.find_first_not_of("0123456789") == std::string::npos)
				return "Integer";
			else if (val.find_first_not_of(".0123456789") == std::string::npos)
				return "Double";
			else if (val == "true" || val == "false")
				return "Bool";
			else
				return "String";
		}
	};
}