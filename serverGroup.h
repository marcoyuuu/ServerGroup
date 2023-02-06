//Archivo "header" serverGroup.h
using namespace std;

template <class DataType>
class ServerGroup
{
public:
    // Constructor (parte a)
    ServerGroup(int size);
    // Función miembro (parte b)
    bool spServerFree();
    // Función miembro (parte c)
    bool serverFree();
    // Función miembro (parte d)
    void useServer(int avTransTime);
    // Función miembro (parte e)
    void usespServer(int avTransTime);
    // Función miembro (parte f)
    void decServers();
    // Destructor (a4)
    ~ServerGroup();
    // Copy constructor (a4)
    ServerGroup(const ServerGroup &ap);
    // Overloaded assignment operator (a4)
    ServerGroup<DataType> &operator=(const ServerGroup<DataType> &s2);
    // Función para probar destructor, copy constructor y overloaded assignment operator (a4)
    void testServer(ServerGroup<DataType> obj);
    // Función para cambiar valores del servidor
    void changeValues();

private:
    int spServer, freeServer = 5, size = 0;
    int *servers = new int(size);
// deepCopy (a4)
    inline void deepCopy(const ServerGroup<DataType> &og);
};
