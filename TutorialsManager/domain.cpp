//
// Created by lazab on 3/22/2024.
//

#include "domain.h"
#include <iostream>
using namespace std;
domain::Tutorial::Tutorial() {
    this->title="";
    this->presenter="";
    this->duration=time{0,0};
    this->nr_likes=0;
    this->link="";
}

domain::Tutorial::Tutorial(
        const std::string &title,
        const std::string &presenter,
        time duration,
        int nr_likes,
        const std::string &link
):title(title), presenter(presenter), duration(duration), nr_likes(nr_likes), link(link){
    this->title=title;
    this->presenter=presenter;
    this->duration=duration;
    this->nr_likes=nr_likes;
    this->link=link;
}

std::string domain::Tutorial::get_title() const{
    return this->title;
}

std::string domain::Tutorial::get_presenter() const{
    return this->presenter;
}

domain::time domain::Tutorial::get_duration(){
    return this->duration;
}

int domain::Tutorial::get_nr_likes(){
    return this->nr_likes;
}

std::string domain::Tutorial::get_link(){
    return this->link;
}

bool domain::Tutorial::operator==(const domain::Tutorial &compare){
    if(this->title==compare.title && this->presenter==compare.presenter && this->duration==compare.duration&&
    this->nr_likes==compare.nr_likes && this->link==compare.link)
        return true;
    else
        return false;
}

domain::Tutorial &domain::Tutorial::operator=(const domain::Tutorial &tutorial)
{
    if (this == &tutorial)
        return *this;

    this->title = tutorial.title;
    this->presenter = tutorial.presenter;
    this->duration = tutorial.duration;
    this->nr_likes = tutorial.nr_likes;
    this->link = tutorial.link;

    return *this;
}

void domain::Tutorial::set_title(const std::string &new_title){
    this->title=new_title;
}

void domain::Tutorial::set_presenter(const std::string &new_presenter){
    this->presenter=new_presenter;
}

void domain::Tutorial::set_duration(int new_minutes, int new_seconds){
    this->duration.minutes=new_minutes;
    this->duration.seconds=new_seconds;
}

void domain::Tutorial::set_nr_likes(int new_nr_likes){
    this->nr_likes=new_nr_likes;
}

void domain::Tutorial::set_link(const std::string &new_link){
    this->link=new_link;
}

void domain::Tutorial::set_watched(){
    this->watched=true;
}

bool domain::Tutorial::get_watched() const{
    return this->watched;
}

std::string domain::Tutorial::to_string() const{
    auto minutes=std::to_string(this->duration.minutes);
    auto seconds=std::to_string(this->duration.seconds);
    auto nr_of_likes=std::to_string (this->nr_likes);
    return "Title: "+this->title+" Presenter: "+this->presenter+" Duration: "+minutes+" "+seconds+" Likes: "
    +nr_of_likes+" Link: "+this->link;
}