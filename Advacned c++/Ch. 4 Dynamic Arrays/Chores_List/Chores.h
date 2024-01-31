#include <cstdlib>
#include <string>

namespace main_savitch_tz {
	class Chores_List {
	public:
		Chores_List(); 
		~Chores_List(); 
		void add_chore(std::string&); 
		int num_chores() const; 
		std::string* chores_list() const; 
		void display_chores(); 
		void delete_chore(); 
		void reallocate(); 

	private:
		std::string* chores_arr; 
		std::size_t allocated; 
		std::size_t current_size; 
	};
}
