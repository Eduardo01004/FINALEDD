#include "splay.h"
#include <iostream>
#include <fstream>
#include <iomanip>

void bst_print_dot_aux(splay* node, FILE* stream)
{
	static int nullcount = 0;

	if (node->lchild)

	{

		fprintf(stream, "%d -> %d;\n", node->key,node->lchild->key,"\"];\n");
		bst_print_dot_aux(node->lchild, stream);
	}

	if (node->rchild)
	{

		fprintf(stream, "%d -> %d;\n", node->key, node->rchild->key);
		bst_print_dot_aux(node->rchild, stream);
	}

}
	void bst_print_dot(splay *tree,FILE* stream)
{
	fprintf(stream, "digraph BINARIO {\n");

	fprintf(stream, "node [fontname=\"Arial\", color=gray30, style=	rounded];\n");

	if (!tree)
	fprintf(stream, "\n");

	else if (!tree->rchild && !tree->lchild)
	fprintf(stream, "%d;\n", tree->key);
	else
	bst_print_dot_aux(tree, stream);

	fprintf(stream, "}\n");
}

void graficaSplay(splay* tree){

	FILE *archivo;
	archivo=fopen("Splay.dot","w");
	bst_print_dot(tree,archivo);
	fclose(archivo);
	system("dot -Tjpg Splay.dot -o Splay.jpg");
}


void GraficarArreglo(splay* node,FILE* stream){
	
fprintf(stream, "digraph BINARIO {\n");
fprintf(stream, "node [fontname=\"Arial\", color=gray30, style=	rounded];\n");
fprintf(stream, "%d -> %d;\n", node->key,node->key,"\"];\n");


fprintf(stream, "}\n");


}
void grafica(splay* tree){

	FILE *archivo;
	archivo=fopen("Arreglo.dot","w");
GraficarArreglo(tree,archivo);
	fclose(archivo);
	system("dot -Tjpg Arreglo.dot -o Arreglo.jpg");
}
int main(int argc, char* argv[])
{
	splay* root = NULL;
	KEY_TYPE vector[] = {5,10,96,30,2,63,85,47,20,3,4,19};///Este es El Arreglo que pidio
	const int length = sizeof(vector)/sizeof(int);
	int i;
	for(i = 0; i< length;i++)
		root = Insertar(vector[i], root);
	
	std::cout<<"\nInOrder: \n";
	InOrder(root);
	graficaSplay(root);
	//grafica(root);
	KEY_TYPE input;
	char type;

		
	while(1)
	{
		std::cout<<"\nSeleccione (S(s)/D(d)/I(i)) para Buscar Insertar y Borrar ";
		std::cin>>type>>input;
		switch(type)
		{
			case 'S':
			case 's':
				root = Buscar(input, root);
				std::cout<<"\nBuscado"<<input<<std::endl;
				InOrder(root);
				break;
			case 'I':
			case 'i':
				root = Insertar(input, root);
				std::cout<<"\nInsertar "<<input<<std::endl;
				InOrder(root);
				break;
			case 'D':
			case 'd':
				root = Borrar(input, root);
				std::cout<<"\nEliminar "<<input<<std::endl;		
				InOrder(root);
				break;
			default:
				std::cout<<"\nDato invalido s/S, i/I, d/D.\n";
		}
	}
	std::cout<<"\n";
	return 0;
}