#include <iostream>
#include <fstream>
#include <vector>
#include <list>
using namespace std;

//Mendeklarasikan class dari edge
class edge
{
    private:
        int vertex, weight;         //inisialisasi variable yang terdapat didalam edge
    public:
        edge (int v, int w)
        {
            vertex = v;
            weight = w;
        }
        int Vertex ()
        {
            return vertex;
        }
        int Weight ()
        {
            return weight;
        }

};


int main ()
{
    //inisialisasi variabel
    int totalvertex, vertex1, vertex2, weight;
    
    ifstream input ("input.txt");          //menyalakan fungsi inputan dari file input.txt yang telah dibuat
    //ofstream output ("input.txt");     //mematikan inputan dari file input.txt
    input >> totalvertex;
    vector < list <edge> > adjacencylist (totalvertex);
    while (input >> vertex1 >> vertex2 >> weight)
    {
        adjacencylist [vertex1-1] .push_back (edge (vertex2, weight));
    }

    //inisialiasi variable
    int banyak_vertex = 1;
    vector < list <edge> > :: iterator i;

    //Perulangan untuk menampilkan hasil dari inputan pada file input.txt
    for (i = adjacencylist.begin(); i != adjacencylist.end(); i++)
    {
        cout << banyak_vertex << " -> ";
        list <edge> li = *i;
        list <edge> :: iterator iter;
        for (iter = li.begin(); iter != li.end(); iter++)
        {
            cout << " [" << (*iter) .Vertex() << ", " << (*iter) .Weight() << "] -> ";
        }
        cout << endl;
        banyak_vertex++;

    }


    return 0;
}