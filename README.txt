no esta terminado.

para ejecutar solo hay que descargar todo en una carpeta y desde la terminal usar los comandos.

make prepare
cd build
cmake ..
cmake --build .
./src/mq_server

el main esta vacio, lo vacie justo antes de subirlo, en el se puede ahcer pruebas de como funciona, actualmente deberia de estar todo perfectamente funcional.

message contiene la estructura basica de un mensaje.
messagequeue es la implementacion de colas para manejar mensajes.
queuemanager es la implementacion de un map para manejar colas con id/nombres unicos como un diccionario.

desde la llamada de queuemanager se pueden crear colas, borrar colas, buscar colas, y listarlas a ellas desde una funcion de queuemanager que devulve una lista de las keys/nombres_de_las_colas, es un vector de string, no sirven para modificar colas ni consumir mensajes, es una funcion constante. para acceder se ocupa la funcion get_queue que devuelve un puntero a la cola con la key==argumento_de_la_funcion y desde ahi hacer pop o push.
