#include "Utils.h"

/*!
 * @brief Convert ASCII to char
 *
 * Function for convert a byte ASCII value to a character.
 *
 * @param[in] ascii : ASCII value
 * @return character converted
 */
char ToChar(BYTE ascii)
{
	return (char)ascii;
}

/*!
 * @brief Convert char to ASCII
 *
 * Function for convert a character to a byte ASCII value, is invert to ToChar().
 *
 * @param[in] c : character to convert
 * @return ASCII byte value
 */
BYTE ToAscii(char c)
{
	return (BYTE)c;
}

/*!
 * @brief Complete int in [0-9]
 *
 * Function to complete 0-9 integers (1 => 01).
 *
 * @param[in] Nbr : int to complete
 * @return string completed
 */
std::string CompleteInt(int Nbr)
{
    std::string complete = "";

	if(Nbr < 10) complete = "0" + toStr<int>(Nbr);
	else         complete = toStr<int>(Nbr);

	return complete;
}

/*!
 * @brief Convert time to string
 *
 * Function for convert tm struct to string represent(fr format)(prefer to use StrTime: fr/en format)
 *
 * @param[in] data : pointer to time
 * @return string formated ([--DD/MM/YYYY hh:mm:ss--]: )
 */
std::string TmToStr(const struct tm *date)
{
    std::string Date = "";

  	Date = "[--" + CompleteInt(date->tm_mday);
  	Date += "/"  + CompleteInt(date->tm_mon + 1);
  	Date += "/"  + CompleteInt(date->tm_year + 1900);
  	Date += " "  + CompleteInt(date->tm_hour);
  	Date += ":"  + CompleteInt(date->tm_min);

  	if(date->tm_sec == 60)
  	{
  		Date += ":" + CompleteInt(0) + "--]: ";
  	}
  	else
  	{
  		Date += ":" + CompleteInt(date->tm_sec) + "--]: ";
  	}

  	return Date;
}

/*!
 * @brief Convert day to string
 *
 * Function for convert day to a string formated (fr/en format).
 *
 * @param[in] day  : day to convert
 * @param[in] type : format type (0 for en / 1 for fr)
 * @return string format converted
 */
std::string DayToStr(int day, bool type)
{
	if(type == 0)
	{
		switch(day)
		{
			case 1:
				return "Mon";
		 		break;
			case 2:
		 		return "Tue";
				break;
			case 3:
		 		return "Wed";
				break;
			case 4:
		 		return "Thu";
				break;
			case 5:
		 		return "Fri";
				break;
			case 6:
		 		return "Sat";
				break;
			case 7:
		 		return "Sun";
				break;
			default:
				return "Mon";
		 		break;
		}
	}
	else
	{
		switch(day)
		{
			case 1:
		 		return "Lun";
				break;
			case 2:
		 		return "Mar";
				break;
			case 3:
				return "Mer";
		 		break;
			case 4:
		 		return "Jeu";
				break;
			case 5:
		 		return "Ven";
				break;
			case 6:
		 		return "Sam";
				break;
			case 7:
		 		return "Dim";
				break;
			default:
				return "Lun";
				break;
        }
    }
}


/*!
 * @brief Get size of file
 *
 * Function to get the size of a file in bytes.
 *
 * @param[in] file : ifstream reference
 * @return size of file
 */
DWORD GetFileSize(std::ifstream& file)
{
    DWORD pos, size;

    pos  = file.tellg();
    file.seekg(0,   std::ios_base::end);

    size = file.tellg();
    file.seekg(pos, std::ios_base::beg);

    return size;
}

