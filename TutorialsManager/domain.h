//
// Created by lazab on 3/22/2024.
//

#ifndef OOP_A4_5_BOGDY09_DOMAIN_H
#define OOP_A4_5_BOGDY09_DOMAIN_H
#include <string>
#include <iostream>

namespace domain {
    struct time {
        int minutes;
        int seconds;

        bool operator==(const time other) const {
            return (this->minutes == other.minutes && this->seconds == other.seconds);
        }
    };

    class Tutorial {
    private:
        std::string title;
        std::string presenter;
        time duration{};
        int nr_likes;
        std::string link;  //unique element
        bool watched=false;

    public:
        Tutorial();

        Tutorial(
                const std::string &title,
                const std::string &presenter,
                time duration,
                int nr_likes,
                const std::string &link
        );

        std::string get_title() const;

        std::string get_presenter() const;

        time get_duration();

        int get_nr_likes();

        std::string get_link();

        bool operator==(const Tutorial &compare);

        domain::Tutorial &operator=(const domain::Tutorial &movie);

        void set_title(const std::string &new_title);

        void set_presenter(const std::string &new_presenter);

        void set_duration(int new_minutes, int new_seconds);

        void set_nr_likes(int new_nr_likes);

        void set_link(const std::string &new_link);
        void set_watched();
        bool get_watched() const;

        std::string to_string() const;

    };
}


#endif //OOP_A4_5_BOGDY09_DOMAIN_H
