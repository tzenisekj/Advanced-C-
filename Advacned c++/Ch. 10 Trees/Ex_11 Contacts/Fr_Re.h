#ifndef FR_RE_H
#define FR_RE_H

#include <string>
#include <cstdlib>

namespace tz {
	class Contact {
	public: 
		int phone_number = 0; ;
		std::string email = ""; 

		Contact() {
			phone_number = 0; 
			email = "";
		}
	};
}
#endif

