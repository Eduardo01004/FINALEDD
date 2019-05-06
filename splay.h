
#ifndef __SPLAY_H__
#define __SPLAY_H__
typedef int KEY_TYPE;
typedef struct splay{
	KEY_TYPE key;
	struct splay* lchild;//izquierda
	struct splay* rchild;//derecha 
}splay;
splay* New_Node(KEY_TYPE key);//nuevp nodo del splay
inline splay* Rotacion_Derecha(splay* k2);
inline splay* Rotacion_Izquierda(splay* k2);
splay* Splay(int key, splay* root);
splay* Insertar(KEY_TYPE key, splay* root);
splay* Borrar(KEY_TYPE key, splay* root);
splay* Buscar(KEY_TYPE key, splay* root);
void InOrder(splay* root);



#endif