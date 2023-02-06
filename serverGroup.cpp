// Definiciones de funciones miembros de la clase ServerGroup

// Constructor (parte a)
template <class DataType>
ServerGroup<DataType>::ServerGroup(int s)
{
    size = s;
    for (int i = 0; i < size; i++)
        servers[i] = 0;
    spServer = 0;
}

// Función miembro (parte b)
template <class DataType>
bool ServerGroup<DataType>::spServerFree()
{
    if (spServer == 0)
        return true;
    else
        return false;
}

// Función miembro (parte c)
template <class DataType>
bool ServerGroup<DataType>::serverFree()
{
    for (int i = 0; i < size; i++)
    {
        if (servers[i] == 0)
        {
            freeServer = i;
            return true;
        }
    }
    return false;
}

// Función miembro (parte d)
template <class DataType>
void ServerGroup<DataType>::useServer(int avTransTime)
{
    servers[freeServer] = avTransTime;
}

// Función miembro (parte e)
template <class DataType>
void ServerGroup<DataType>::usespServer(int avTransTime)
{
    spServer = avTransTime;
}

// Función miembro (parte f)
template <class DataType>
void ServerGroup<DataType>::decServers()
{
    if (spServer != 0)
        spServer--;
    for (int i = 0; i < size; i++)
    {
        if (servers[i] != 0)
        {
            servers[i]--;
        }
    }
}

// Destructor (a4)
template <class DataType>
ServerGroup<DataType>::~ServerGroup()
{
    delete[] servers;
}

// Copy constructor (a4)
template <class DataType>
ServerGroup<DataType>::ServerGroup(const ServerGroup &ap)
{
    deepCopy(ap);
}

// Overloaded assignment operator (a4)
template <class DataType>
ServerGroup<DataType> &ServerGroup<DataType>::operator=(const ServerGroup &right)
{
    if (this == &right)
        return *this;
    delete[] servers;
    deepCopy(right);
    return *this;
}

// deepCopy (a4)
template <class DataType>
inline void ServerGroup<DataType>::deepCopy(const ServerGroup<DataType> &og)
{
    size = og.size;
    servers = new DataType[size];
    for (int i = 0; i < og.size; i++)
        servers[i] = og.servers[i];
}

// Función para probar destructor, copy constructor y overloaded assignment operator (a4)
template <class DataType>
void ServerGroup<DataType>::testServer(ServerGroup<DataType> obj)
{
    cout << "Funcion para probar si cambio arreglo fue ejecutado\n";
    cout << "Datos de los servidores originales son: \n";
    for (int i = 0; i < size; i++)
        cout << "server " << i << ": " << servers[i] << endl;
    cout << "Datos de los servidores nuevos son: \n";
    for (int i = 0; i < size; i++)
        cout << "server " << i << ": " << obj.servers[i] << endl;
}

// Función para cambiar valores del servidor
template <class DataType>
void ServerGroup<DataType>::changeValues()
{
    servers[0] = 1;
    servers[1] = 2;
    servers[2] = 3;
    servers[3] = 4;
}
