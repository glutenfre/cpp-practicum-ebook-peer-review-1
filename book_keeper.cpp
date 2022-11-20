#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <iomanip>

class BookChecker {
public:

    void CommandRead(int user_id, int page_num) {
        int cur_pages = 0;
        if (readers_.count(user_id) > 0) {
            cur_pages = readers_.at(user_id);
        }
        for (int i = cur_pages +1; i <= page_num; i++) {
            readers_to_pages[i]++;
        }
        readers_[user_id] = page_num;
    }

    void CommandCheer(int user_id, std::ostream& out) {
        if (readers_.count(user_id) == 0) {
            out << 0;
        }
        else {
            if (readers_.size() == 1) {
                out << 1;
            }
            else {
                int num_pages = readers_.at(user_id);
                double less_then_user_num =  readers_to_pages.at(1) - readers_to_pages.at(num_pages);
                out << std::setprecision(6) << (less_then_user_num/( readers_.size()-1));
            }
        }
        out << std::endl;
    }

private:
    std::unordered_map<int, int> readers_;
    std::vector<int> readers_to_pages = std::vector(1001, 0);
};

int main()
{
    BookChecker book_checker;

    int num;

    int id_size;
    int page_num;
    std::string s;

    /*input >> num;
    for (int i = 0; i < num; i++) {
        input >> s;
        input >> id_size;
        if (s == "READ") {
            input >> page_num;
            book_checker.CommandRead(id_size, page_num);
        }
        else {
            book_checker.CommandCheer(id_size, std::cout);
        }
    }*/

    std::cin >> num;
    for (int i = 0; i < num; i++) {
        std::cin >> s;
        std::cin >> id_size;
        if (s == "READ") {
            std::cin >> page_num;
            book_checker.CommandRead(id_size, page_num);
        }
        else {
            book_checker.CommandCheer(id_size, std::cout);
        }
    }
}
