#include <string>
using namespace std;

#ifndef Squirrel_H
#define Squirrel_H

class Squirrel{
    private:
    float lat_;
    float lon_;
    string ID_;
    
    public:
    // constructor, defaulted
    Squirrel(float lat = 0, float lon = 0, string ID = "ImmaSquirrel"){
        lat_ = lat;
        lon_ = lon;
        ID_ = ID;
    }



    // compare two squirrel objects based on latitude
    // param otherSquirrel: Squirrel object to be compared to
    // returns some value > 0 if this latitude is greater than otherSquirrel latitude
    // returns 0 if this latitude is equal to otherSquirrel latitude
    // returns some value < 0 if this latitude is less than otherSquirrel latitude
    float compareTo(Squirrel otherSquirrel){
        return lat_ - otherSquirrel.getLat();
    }




    // getters
    float getLat(){
        return lat_;
    }

    float getLon(){
        return lon_;
    }

    string getID(){
        return ID_;
    }

    // setters
    void setLat(float lat){
        lat_ = lat;
    }

    void setLon(float lon){
        lon_ = lon;
    }

    void setID(string ID){
        ID_ = ID;
    }
};

#endif