#include "splay.h"
#include <iostream>
#include <cstdlib>
inline splay* Rotacion_Derecha(splay* k2)
{
	splay* k1 = k2->lchild;
	k2->lchild = k1->rchild;
	k1->rchild = k2;
	return k1;
}
inline splay* Rotacion_Izquierda(splay* k2)//LL izquierda
{
	splay* k1 = k2->rchild;
	k2->rchild = k1->lchild;
	k1->lchild = k2;
	return k1;
}
splay* Splay(int key, splay* root)
{
	if(!root)
		return NULL;
	splay header;
	header.lchild = header.rchild = NULL;
	splay* LeftTreeMax = &header;
	splay* RightTreeMin = &header;
	while(1)
	{
		if(key < root->key)
		{
			if(!root->lchild)
				break;
			if(key < root->lchild->key)
			{
				root = Rotacion_Derecha(root); 
				if(!root->lchild)
					break;
			}
			RightTreeMin->lchild = root;
			RightTreeMin = RightTreeMin->lchild;
			root = root->lchild;
			RightTreeMin->lchild = NULL;
		}
		else if(key > root->key)
		{
			if(!root->rchild)
				break;
			if(key > root->rchild->key)
			{
				root = Rotacion_Izquierda(root);
				if(!root->rchild)
					break;
			}
			LeftTreeMax->rchild = root;
			LeftTreeMax = LeftTreeMax->rchild;
			root = root->rchild;
			LeftTreeMax->rchild = NULL;
		}
		else
			break;
	}
	LeftTreeMax->rchild = root->lchild;
	RightTreeMin->lchild = root->rchild;
	root->lchild = header.rchild;
	root->rchild = header.lchild;
	return root;
}
splay* New_Node(KEY_TYPE key)
{
	splay* p_node = new splay;
	if(!p_node)
	{
		fprintf(stderr, "no memoria\n");
		exit(1);
	}
	p_node->key = key;
	p_node->lchild = p_node->rchild = NULL;
	return p_node;
}

splay* Insertar(KEY_TYPE key, splay* root)
{
	static splay* p_node = NULL;
	if(!p_node)
		p_node = New_Node(key);
	else 
		p_node->key = key;
	if(!root)
	{
		root = p_node;
		p_node = NULL;
		return root;
	}
	root = Splay(key, root);
	if(key < root->key)
	{
		p_node->lchild = root->lchild;
		p_node->rchild = root;
		root->lchild = NULL;
		root = p_node;
	}
	else if(key > root->key)
	{
		p_node->rchild = root->rchild;
		p_node->lchild = root;
		root->rchild = NULL;
		root = p_node;
	}
	else
		return root;
	p_node = NULL;
	return root;
}


splay* Borrar(KEY_TYPE key, splay* root)
{
	splay* temp;
	if(!root)
		return NULL;
	root = Splay(key, root);
	if(key != root->key) 
		return root;
	else
	{
		if(!root->lchild)
		{
			temp = root;
			root = root->rchild;
		}
		else
		{
			temp = root;
			
			root = Splay(key, root->lchild);
			root->rchild = temp->rchild;
		}
		free(temp);
		return root;
	}
}

splay* Buscar(KEY_TYPE key, splay* root)
{
	return Splay(key, root);
}

void InOrder(splay* root)
{
	if(root)
	{
		InOrder(root->lchild);
		std::cout<< "dato: " <<root->key<< "\n";
		if(root->lchild)
		if(root->rchild)
		std::cout<< "\n";
		InOrder(root->rchild);
	}

}

