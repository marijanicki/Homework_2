#include <string>
#include <vector>
#include <utility>
using namespace std;

class estudiante{
    private:
        string name;
        int id;
        vector <pair<string, int> > marks;
    public:
        estudiante(string name, int id, string curso, int marks);
        //SETTERS
        void setname(string name);
        void setid(int id);
        void setmarks(string curso, int mark);

        //GETTERS
        string getname();
        int getid();
        float getmarks();

};