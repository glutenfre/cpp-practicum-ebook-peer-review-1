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

    double CommandCheer(int user_id, std::ostream& out) {
        if (readers_.count(user_id) == 0) {
            return 0;
        }
        else {
            if (readers_.size() == 1) {
                return 1;
            }
            else {
                int num_pages = readers_.at(user_id);
                double less_then_user_num =  readers_to_pages.at(1) - readers_to_pages.at(num_pages);

                return (less_then_user_num / (readers_.size() - 1));
            }
        }
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

    input >> num;
    for (int i = 0; i < num; i++) {
        input >> s;
        input >> id_size;
        if (s == "READ") {
            input >> page_num;
            book_checker.CommandRead(id_size, page_num);
        }
        else {
            double res = book_checker.CommandCheer(id_size, std::cout);
            std::cout << std::setprecision(6) << res << std::endl;
        }
    }
}
