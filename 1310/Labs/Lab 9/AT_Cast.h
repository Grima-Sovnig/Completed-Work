#ifndef AT_CAST_H
#define AT_CAST_H

#include <iostream>
#include <string>
using namespace std;

class AT_Cast
{
    private:
        int CastID;
        string CastName;
    
    public:
        AT_Cast()
        {
            CastID = 0;
            CastName = "None";
        }
        AT_Cast(int ID, string name)
        {
            CastID = ID;
            CastName = name;
        }
        void setID(int ID)
        {
            CastID = ID;
        }
        void setName(string name)
        {
            CastName = name;
        }
        int getID()
        {
            return CastID;
        }
        string getName()
        {
            return CastName;
        }

        bool operator < (const AT_Cast& member)
        {
            return this->CastID < member.CastID;
        }
        friend ostream &operator << (ostream &strm, AT_Cast &member)
        {
            strm << "Cast ID Number: " << member.CastID;
            strm << "\tName: " << member.CastName << endl;
            return strm;
        }


};

#endif